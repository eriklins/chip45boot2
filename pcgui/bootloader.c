//==============================================================================
//
// Title:       bootloader.c
// Purpose:     communication routines with the bootloader.
//
// Created on:  01.09.2009 at 13:56:38 by Erik Lins.
// Copyright:   chip45 GmbH & Co. KG. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <progressbar.h>
#include <utility.h>
#include <rs232.h>
#include <formatio.h>
#include <ansi_c.h>
#include <userint.h>
#include "bootloader.h"
#include "modify_controls.h"


//==============================================================================
// Constants

// currently the biggest AVR controller has 256k Flash (we use the double amount, since there might come bigger xmega devices
#define MAX_FLASH_BYTES 524288

#define XON 17
#define XOFF 19

//#define DEBUG

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

int flagConnectBootloaderButtonPressed = 0;


//==============================================================================
// Global functions



// ============================================================================
// convert hex ascii nibble ('0' - 'f'/'F') into a number
// in: ascii character (nibble) to be converted
// out: 4 bit hex number
// ============================================================================
unsigned char asciiToHex(unsigned char ucNibble) {

	unsigned char ucHex = 0;

	// check if ascii character is a lower case letter a-f
	if(ucNibble >= 'a') {
		ucHex = (ucNibble - 'a') + 0x0a;
	// or an upper case letter A-F
	} else if(ucNibble >= 'A') {
		ucHex = (ucNibble - 'A') + 0x0a;
	// or if it is a number 0-9
	} else if((ucNibble >= '0')) {
		ucHex = (ucNibble - '0');
	}
	
	return ucHex;  // return the hex number
}


// ============================================================================
// convert two hex ascii nibbles into a number
// in: two ascii characters (high, low nibble) to be converted
// out: 8 bit hex number
// ============================================================================
unsigned char asciiToHex2(unsigned char ucNibbleHigh, unsigned char ucNibbleLow) {
	return (asciiToHex(ucNibbleHigh) << 4) + asciiToHex(ucNibbleLow);  // just call the function for one nibble twice
}



/// HIFN  Connect to the bootloader
/// HIRET returns 0 on success or -1 in case of failure
int bootloaderConnect (void)
{
	char line[1000], buffer[1000], *tmp;
	int error = 0, i = 0;
	double timeout = 0;

	
	// if we are already connected, it must be a disconnect!
	if(config.flagBootloaderConnected) {
		ProgressBar_SetPercentage(tabMainPanelHandle, TABMAIN_PROGRESSBAR, 0, "");  // clear progress bar
		uiMayConnectBootloader(1);
		uiMayProgramFlash(0);
		uiMayProgramEeprom(0);
		uiMayStartApplication(0);
		uiMaySelectComport(1),
		uiMaySelectInitialBaudrate(1);
		uiMayEnablePreString(1);
		uiMayEnterPreString(1);
		SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 0);
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Connect to Bootloader"); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Status"); 
		CloseCom (config.selectedComPort);
		config.flagBootloaderConnected = 0;
		Fmt(line, "Disconnecting bootloader.\r\n");
		SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, line);
		flagConnectBootloaderButtonPressed = 0;
		return 0;
	}

	// modify ui controls
	uiMaySelectComport(0);  // may not select comport
	uiMaySelectInitialBaudrate(0);  // may not change baudrate
	uiMayEnablePreString(0);
	uiMayEnterPreString(0);
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Stop Connecting"); 
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Status"); 
	SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 0);

	config.flagBootloaderConnected = 1;
	
	
	// communication log
	Fmt(line, "Trying to open port COM%d with %d baud...", config.selectedComPort, config.selectedBaudrate);
	InsertTextBoxLine (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, -1, line);

	
	// try to open the com port
	if(OpenComConfig (config.selectedComPort, "", config.selectedBaudrate, 0, 8, 1, 512, 44) < 0) {  // output queue >44 forces the bootloader to respond with an error, no idea why...
		Fmt(buffer, "Cannot open Port: COM%d!\n\nProbably used by another application?", config.selectedComPort);
		MessagePopup("chip45boot2 GUI Message", buffer);
		config.flagBootloaderConnected = 0;
		uiMayProgramFlash(0);
		uiMayProgramEeprom(0);
		uiMayStartApplication(0);
		uiMaySelectComport(1),
		uiMaySelectInitialBaudrate(1);
		uiMayEnablePreString(1);
		uiMayEnterPreString(1);
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Connect to Bootloader"); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "No Port"); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
		SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
		flagConnectBootloaderButtonPressed = 0;
		return -1;
	}
	SetComTime (config.selectedComPort, 1);  // 1 secs for com port operations
	
	
	// check if the pre string should be sent
	if(config.flagSendPreString == 1) {
	
		int i;
		unsigned char c1, c2;
		
		// write the prestring
		if(config.flagPreStringIsAscii == 1) {
			Fmt(line, "Sending ASCII Prestring: '%s'", config.preString);
			InsertTextBoxLine (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, -1, line);
			ComWrt(config.selectedComPort, config.preString, strlen(config.preString));
		} else {
			if(config.flagPreStringIsHex == 1) {
				Fmt(line, "Sending HEX Prestring: '%s'", config.preString);
				InsertTextBoxLine (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, -1, line);
				if((strlen(config.preString) % 2) != 0) {
					Fmt(line, "Error: Hex prestring length must be even!", config.preString);
					InsertTextBoxLine (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, -1, line);
					config.flagBootloaderConnected = 0;
					uiMayProgramFlash(0);
					uiMayProgramEeprom(0);
					uiMayStartApplication(0);
					uiMaySelectComport(1),
					uiMaySelectInitialBaudrate(1);
					uiMayEnablePreString(1);
					uiMayEnterPreString(1);
					SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Connect to Bootloader"); 
					SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Prestring"); 
					SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
					SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
					flagConnectBootloaderButtonPressed = 0;
					return -1;
				}
				for(i = 0; i < strlen(config.preString); i += 2) {
					c1 = config.preString[i];
					c2 = config.preString[i+1];
					if((c1 >= '0') && (c1 <= '9')) {
						c1 = c1 - '0';
					} else if((c1 >= 'A') && (c1 <= 'F')) {
						c1 = c1 - 'A' + 10;
					} else if((c1 >= 'a') && (c1 <= 'f')) {
						c1 = c1 - 'a' + 10;
					} else {
						Fmt(line, "Error: Invalid hex character found! Aborting prestring...", config.preString);
						InsertTextBoxLine (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, -1, line);
						config.flagBootloaderConnected = 0;
						uiMayProgramFlash(0);
						uiMayProgramEeprom(0);
						uiMayStartApplication(0);
						uiMaySelectComport(1),
						uiMaySelectInitialBaudrate(1);
						uiMayEnablePreString(1);
						uiMayEnterPreString(1);
						SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Connect to Bootloader"); 
						SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Prestring"); 
						SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
						SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
						flagConnectBootloaderButtonPressed = 0;
						return -1;
					}
					if((c2 >= '0') && (c2 <= '9')) {
						c2 = c2 - '0';
					} else if((c2 >= 'A') && (c2 <= 'F')) {
						c2 = c2 - 'A' + 10;
					} else if((c2 >= 'a') && (c2 <= 'f')) {
						c2 = c2 - 'a' + 10;
					} else {
						Fmt(line, "Error: Invalid hex character found! Aborting prestring...", config.preString);
						InsertTextBoxLine (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, -1, line);
						config.flagBootloaderConnected = 0;
						uiMayProgramFlash(0);
						uiMayProgramEeprom(0);
						uiMayStartApplication(0);
						uiMaySelectComport(1),
						uiMaySelectInitialBaudrate(1);
						uiMayEnablePreString(1);
						uiMayEnterPreString(1);
						SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Connect to Bootloader"); 
						SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Prestring"); 
						SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
						SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
						flagConnectBootloaderButtonPressed = 0;
						return -1;
					}
					ComWrtByte(config.selectedComPort, c1 * 16 + c2);
					//printf("%2x ", c1 * 16 + c2);
				}
			}
		}
	
		// and wait milliseconds
		Fmt(line, "Waiting %d milliseconds.", config.milliseconds);
		InsertTextBoxLine (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, -1, line);
		Delay((float)(config.milliseconds / 1000));
	
	}

	
	// communication log
	Fmt(line, "Trying to connect to bootloader at COM%d with %d baud...", config.selectedComPort, config.selectedBaudrate);
	InsertTextBoxLine (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, -1, line);
	

	
	FlushInQ(config.selectedComPort);  // empty input queue
	timeout = Timer();  // get actual timer value


	if(config.flagRS485 == 0) {
		// normal full duplex USART mode, no RS485
		// send U's and wait for response or timeout
		do {
			ComWrtByte(config.selectedComPort, 'U');
			if(flagConnectBootloaderButtonPressed == 2)
				break;
		} while((GetInQLen(config.selectedComPort) == 0) && ((Timer()-timeout)<defTimeoutConnectBootloader));
	} else {
		// half duplex RS485 mode
		int i = 0;
		do {
			// first send 10 U's and one space
			for(i = 0; i < 10; ++i) {
				ComWrtByte(config.selectedComPort, 'U');
			}
			Delay((float)0.1);  // wait 1/10 second
			FlushInQ(config.selectedComPort);  // empty input queue
			ComWrtByte(config.selectedComPort, ' ');
			if(flagConnectBootloaderButtonPressed == 2)
				break;
			Delay((float)0.1);  // wait 1/10 second
		} while((GetInQLen(config.selectedComPort) == 0) && ((Timer()-timeout)<defTimeoutConnectBootloader));
	}
	
	// read the response
	int len = ComRdTerm(config.selectedComPort, buffer, 20, '>');
	
#ifdef DEBUG
	printf("len = %d   buffer = %c %c %c %c / %d %d %d %d\n", len, buffer[0], buffer[1], buffer[2], buffer[3], buffer[0], buffer[1], buffer[2], buffer[3]);
#endif
	
	// if no response, print message and return
	if(len == 0) {
		Fmt(line, "No bootloader found.\r\n");
		SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, line);
		config.flagBootloaderConnected = 0;
		// close the com port
		CloseCom (config.selectedComPort);
		uiMayProgramFlash(0);
		uiMayProgramEeprom(0);
		uiMayStartApplication(0);
		uiMaySelectComport(1),
		uiMaySelectInitialBaudrate(1);
		uiMayEnablePreString(1);
		uiMayEnterPreString(1);
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Connect to Bootloader"); 
		if(flagConnectBootloaderButtonPressed == 2) {
			SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Stopped");
		} else {
			SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Timeout");
		}
		flagConnectBootloaderButtonPressed = 0;
		return -1;
	}
	if(len < 2)
		len = 2;
	buffer[len-2] = 0;  // terminate the string at the termination character position
	tmp = buffer;  // we use a temporary pointer
	
	while( (tmp[0] == 0) && (tmp < (buffer+len) )) {
		++tmp;
	}
	
#ifdef DEBUG
	printf("tmp = %s\n", tmp);
#endif
	
	// check for correct bootloader identifier
	if(strncmp(tmp, "c45b2", 5)) {
		tmp[5] = 0;
		Fmt(line, "Wrong bootloader found: %s.\r\n", tmp);
		SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, line);
		config.flagBootloaderConnected = 0;
		// close the com port
		CloseCom (config.selectedComPort);
		uiMayProgramFlash(0);
		uiMayProgramEeprom(0);
		uiMayStartApplication(0);
		uiMaySelectComport(1),
		uiMaySelectInitialBaudrate(1);
		uiMayEnablePreString(1);
		uiMayEnterPreString(1);
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Connect to Bootloader"); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Failed"); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
		SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
		flagConnectBootloaderButtonPressed = 0;
		return -1;
	}

	// the correct bootloader was found, print the version and switch led control on!
	tmp += 6;
	Fmt(line, "Found chip45boot2 bootloader version %s\r\n", tmp);
	SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, line);
	SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Connected!"); 
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_GREEN); 
	SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Disconnect Bootloader"); 
	uiMayProgramFlash(1);
	uiMayProgramEeprom(1);
	uiMayStartApplication(1);
	uiMaySelectComport(0);
	uiMaySelectInitialBaudrate(0);
	uiMayEnablePreString(0);
	uiMayEnterPreString(0);

	flagConnectBootloaderButtonPressed = 0;
	// return
	return 0;

}


/// HIFN  transmit a line to the bootloader
/// HIRET returns 0 on success or -1 in case of failure
int uploadHexLine(char *buffer) {

	int c = 0;
	char line[1000];
	
	Delay(0.008);
	
	// send the hex record
	ComWrt(config.selectedComPort, buffer, strlen(buffer));

	
	// read until XON, 10 characters or timeout
	c = ComRdTerm(config.selectedComPort, line, 10, XON);
	
	if(c == -99) {
		printf("uploadHexLine -> timeout\n");
#ifdef DEBUG
		printf("%2x %c ", c, c);
#endif
		Fmt(line, "uploadHexLine -> timeout.\r\n");
		SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, line);
		
		return -3;
	}
	
	
	return (c & 0xff);
}


/// HIFN  Connect to the bootloader
/// HIRET returns 0 on success or -1 in case of failure
int bootloaderProgram (void)
{
	
	unsigned char hexFileLine[255], tmpBuffer[255], serBuffer[150];
	int hexFileReadStatus = 0;
	unsigned long highestFlashAddress = 0;

	FILE *hexFile;


	// variables for hex file line parsing
	unsigned char hexFileByteCount;
	unsigned char hexFileMyCheckSum;
	unsigned short hexFileAddress;
	unsigned char hexFileRecordType;
	unsigned char hexFileChecksum;
	unsigned long hexFilePageBaseAddress = 0xffffffff;  // preset page base address to impossible value
	unsigned short hexFileExtSegmentAddress = 0;  // clear segment address
	unsigned char flagEndOfFile = 0;
	unsigned char hexFileDataByte;
	unsigned char flagChecksumError = 0;
	unsigned long flashBufferEndAddress = 0x00000000;
	unsigned char flagFlashBufferOverflow = 0;
	
	unsigned char *flashBuffer = malloc(MAX_FLASH_BYTES/16*46);  // get a buffer for maximum flash size

	int ec = 0;
	
	// disable most of the controls	
	uiMayConnectBootloader(0);
	uiMayProgramFlash(0);
	uiMayProgramEeprom(0);
	uiMayStartApplication(0);
	
	uiMaySelectEeprom(0);
	uiMaySelectFlash(0);
	
	config.flagProgrammingInProgress = 1;
	
	
	// initialize the flash buffer to 0xff
	for(long i=0; i<MAX_FLASH_BYTES/16*46; ++i) {
		flashBuffer[i] = 0xff;
	}



	FlushInQ(config.selectedComPort);  // empty input queue
	ComWrtByte(config.selectedComPort, '\n');
	Delay(1.0);
	int dummy = ComRdTerm(config.selectedComPort, serBuffer, 100, XON);
	//Fmt(tmpBuffer, "ComRdTerm before command = %d\r\n");
	//SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);

	if(flashOrEeprom == FLASH) {
		Fmt(serBuffer, "pf\n");
	}
	if(flashOrEeprom == EEPROM) {
		Fmt(serBuffer, "pe\n");
	}
	ComWrt(config.selectedComPort, serBuffer, strlen(serBuffer));
	if(config.flagRS485 == 1) {
		Delay(0.1);	
	}
	int c = 0;
	
	do {
		c = ComRdByte(config.selectedComPort);
#ifdef DEBUG
		printf("%c:%d\n", c, c);
#endif
		// timeout?
		if(c == -99) {
			Fmt(tmpBuffer, "Timeout when waiting for XOFF after command.\r\n");
			SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);
			if(flashOrEeprom == FLASH) {
				SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
				SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "XOFF Error"); 
				SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
			}
			if(flashOrEeprom == EEPROM) {
				SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
				SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "XOFF Error"); 
				SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
			}
			// enable the controls again
			uiMayConnectBootloader(1);
			uiMayProgramFlash(1);
			uiMayProgramEeprom(1);
			uiMayStartApplication(1);
			uiMaySelectFlash(1);
			uiMaySelectEeprom(1);
	
			config.flagProgrammingInProgress = 0;
			return -1;
		}
	
	} while(c != XOFF);

	// read the response
	int len = ComRdTerm(config.selectedComPort, serBuffer, 10, '\r');
	serBuffer[len] = 0;
	
#ifdef DEBUG
	printf("len = %d  serBuffer = %x %x %x %x = %c%c%c%c\n", len, serBuffer[0], serBuffer[1], serBuffer[2], serBuffer[3], serBuffer[0], serBuffer[1], serBuffer[2], serBuffer[3]);
#endif
	
	// if no response, we output an error message
	if(len == 0) {
		Fmt(tmpBuffer, "Timeout when entering programming mode.\r\n");
		SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Mode Fail"); 
		SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);

		// enable the controls again
		uiMayConnectBootloader(1);
		uiMayProgramFlash(1);
		uiMayProgramEeprom(1);
		uiMayStartApplication(1);
		uiMaySelectFlash(1);
		uiMaySelectEeprom(1);
	
		config.flagProgrammingInProgress = 0;
		return -1;
	}
	
	
	// check for postive px+ response
	if( (strncmp(serBuffer, "pf+", 3)) && (strncmp(serBuffer, "pe+", 3)) ) {
		Fmt(tmpBuffer, "Could not enter programming mode: %s\r\n", serBuffer);
		SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Mode Fail"); 
		SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);

		// enable the controls again
		uiMayConnectBootloader(1);
		uiMayProgramFlash(1);
		uiMayProgramEeprom(1);
		uiMayStartApplication(1);
		uiMaySelectFlash(1);
		uiMaySelectEeprom(1);
	
		config.flagProgrammingInProgress = 0;
		return -1;
	}
	
	
	// wait for XON, so that we can start hex file sending
	do {
		c = ComRdByte(config.selectedComPort);

		// timeout?
		if(c == -99) {
			Fmt(tmpBuffer, "Timeout when waiting for XON after command.\r\n");
			SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);
			SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
			SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "XON Error"); 
			SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);

			// enable the controls again
			uiMayConnectBootloader(1);
			uiMayProgramFlash(1);
			uiMayProgramEeprom(1);
			uiMayStartApplication(1);
			uiMaySelectFlash(1);
			uiMaySelectEeprom(1);
	
			config.flagProgrammingInProgress = 0;
			return -1;
		}
	
	} while(c != XON);
		
	
	// status message in communication log
	if(flashOrEeprom == FLASH) {
		Fmt(tmpBuffer, "Loading hex file %s...\r\n", config.pathToFlashHexfile);
	}
	if(flashOrEeprom == EEPROM) {
		Fmt(tmpBuffer, "Loading hex file %s...\r\n", config.pathToEepromHexfile);
	}
	SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);

	
	// open file
	if(flashOrEeprom == FLASH) {
		hexFile = fopen(config.pathToFlashHexfile, "r");
	}
	if(flashOrEeprom == EEPROM) {
		hexFile = fopen(config.pathToEepromHexfile, "r");
	}

	// if an error occured print status log and return
	if(hexFile == NULL) {
		// turn led on and make it red
		if(flashOrEeprom == FLASH) {
			Fmt(tmpBuffer, "Could not open file %s.\r\n", config.pathToFlashHexfile);
			SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);
		}
		if(flashOrEeprom == EEPROM) {
			Fmt(tmpBuffer, "Could not open file %s.\r\n", config.pathToEepromHexfile);
			SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);
		}
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "File Error"); 
		SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);

		// enable the controls again
		uiMayConnectBootloader(1);
		uiMayProgramFlash(1);
		uiMayProgramEeprom(1);
		uiMayStartApplication(1);
		uiMaySelectFlash(1);
		uiMaySelectEeprom(1);
		
		config.flagProgrammingInProgress = 0;
		return -1;
	}
	
	// update control
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_YELLOW); 
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Reading..."); 
	SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
	
	// status message in communication log
	Fmt(tmpBuffer, "Parsing hex file...\r\n");
	SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);

	// read and parse the hexfile and write it into a buffer
	do {

		// read one line until end-of-line
		hexFileReadStatus = fscanf(hexFile, "%s", hexFileLine);
		
		// if no additional line could be read, break
		if(hexFileReadStatus == -1) {
			break;
		}

		// grab hexfile information
		hexFileByteCount = asciiToHex2(hexFileLine[1], hexFileLine[2]);  // get number of bytes
		hexFileMyCheckSum = hexFileByteCount;  // start checksum computation
		hexFileAddress = asciiToHex2(hexFileLine[3], hexFileLine[4]);  // get address high byte
		hexFileMyCheckSum += (unsigned char)hexFileAddress;  // checksum...
		hexFileAddress = (hexFileAddress<<8) + asciiToHex2(hexFileLine[5], hexFileLine[6]);  // get address low byte   
		hexFileMyCheckSum += (unsigned char)(hexFileAddress & 0xff);  // checksum...
		hexFileRecordType = asciiToHex2(hexFileLine[7], hexFileLine[8]);  // get record type
		hexFileMyCheckSum += hexFileRecordType;
		hexFileChecksum = asciiToHex2(hexFileLine[(hexFileByteCount*2)+9], hexFileLine[(hexFileByteCount*2)+10]);  // get the checksum

#ifdef DEBUG
		// debug output
		printf(":%2x %4x %2x ... %2x\n", hexFileByteCount, hexFileAddress, hexFileRecordType, hexFileChecksum);
#endif

		if(hexFileRecordType == 2) {  // extended segment address record
			hexFileExtSegmentAddress = asciiToHex2(hexFileLine[9], hexFileLine[10]) << 8;
			hexFileMyCheckSum += (hexFileExtSegmentAddress >> 8);  // chechsum...
			hexFileExtSegmentAddress += asciiToHex2(hexFileLine[11], hexFileLine[12]);
			hexFileMyCheckSum += (hexFileExtSegmentAddress & 0xff);  // chechsum...

		} else if(hexFileRecordType == 1) {  // end of file record
			flagEndOfFile = 1;
			break;  // leave while loop
			
		} else if(hexFileRecordType == 0) {  // data record
					
			int i;

			// parse the data bytes and write to flash buffer
			for(i = 0; i < (2 * hexFileByteCount); i += 2) {  // increment by two
				unsigned char dataByte = asciiToHex2(hexFileLine[i+9], hexFileLine[i+10]);  // get the low data byte
				hexFileMyCheckSum += dataByte;  // compute checksum
				flashBuffer[hexFileAddress + (hexFileExtSegmentAddress * 16) + (i>>1)] = dataByte;
			}
			
			// in case the hex file is unordered, 
			if(flashBufferEndAddress < hexFileAddress + (hexFileExtSegmentAddress * 16) + (i>>1)) {
				flashBufferEndAddress = hexFileAddress + (hexFileExtSegmentAddress * 16) + (i>>1);
			}
			
			if(flashBufferEndAddress > (MAX_FLASH_BYTES/16*46)) {
				flagFlashBufferOverflow = 1;
				break;
			}
			
		}

		
		// check if checksum error
		if( ((hexFileMyCheckSum + hexFileChecksum) & 0xff) != 0) {
			flagChecksumError = 1;
			break;  // leave while loop
		}
		
		
	} while(1);
		
	// close file
	fclose(hexFile);
		
#ifdef DEBUG	
	// debug output
	printf("eof:%d overflow:%d checksum:%d readbytes:%d endaddress:%x\n", flagEndOfFile, flagFlashBufferOverflow, flagChecksumError, hexFileReadStatus, flashBufferEndAddress);
#endif


	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Uploading"); 
	
	// status message in communication log
	Fmt(tmpBuffer, "Uploading hex file to bootloader:\r\n");
	SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);

	
	hexFileExtSegmentAddress = 0x00000000;
	hexFileByteCount = 0x10;  // byte count is fixed to 16 bytes
	unsigned long flashBufferAddress = 0;  // we always start at bottom of flash
	unsigned char flagErrorUploading = 0;
	
	
	// outer loop for each 16 byte hex file lines
	for(unsigned short hexFileLineCounter = 0; (hexFileLineCounter <= ((flashBufferEndAddress-1) / 16)) && (flagErrorUploading == 0); ++hexFileLineCounter) {

		char i = 0;
		unsigned short hexFileDataByteCounter = 0;
		char *buffer = hexFileLine;  // temporary buffer now points to hex line buffer
		
		flashBufferAddress = hexFileLineCounter * 16;
		
		// start printing normal data record
		i = sprintf(buffer, ":%02X%04X%02X", hexFileByteCount, (unsigned short)(flashBufferAddress & 0xffff), 0x00);
		buffer += i;

		// checksum...
		hexFileChecksum = hexFileByteCount;
		hexFileChecksum += (flashBufferAddress >> 8);
		hexFileChecksum += (flashBufferAddress & 0xff);
		
		// inner loop for the 16 data bytes
		for(hexFileDataByteCounter = 0; hexFileDataByteCounter < 16; ++hexFileDataByteCounter) {
			
			unsigned char c = flashBuffer[flashBufferAddress + hexFileDataByteCounter];
			
			i = sprintf(buffer, "%02X", c);
			buffer += i;
			hexFileChecksum += c;
			
		}
		
		// append the calculated checksum and line ending
		sprintf(buffer, "%02X\n", (0x100 - hexFileChecksum) & 0xff);

		// increment hex file address
		//hexFileAddress += hexFileDataByteCounter;
		
#ifdef DEBUG
		printf("\n%s", hexFileLine);
#endif
		// now hexFileLine contains all the stuff printed
		ec = uploadHexLine(hexFileLine);
		if(ec < 0) {
			flagErrorUploading = 1;
			break;
		};

		
		
		// check if we would exceed the 64k page address range with the next hex file line and insert a 
		if( ((flashBufferAddress & 0xffff) + 16) == 0x10000) {
			hexFileExtSegmentAddress += 0x1000;  // the segment address is later multiplied by 16 and added to the hex record address
			sprintf(hexFileLine, ":02000002%04X%02X\n", hexFileExtSegmentAddress, (unsigned char)(0x100 - (4 + (hexFileExtSegmentAddress >> 8) + (hexFileExtSegmentAddress & 0xff))));

			if(uploadHexLine(hexFileLine) < 0) {
				flagErrorUploading = 1;
				break;
			};
		
#ifdef DEBUG
			printf("%s", hexFileLine);
#endif
		}

		// set progress bar
		ProgressBar_SetPercentage(tabMainPanelHandle, TABMAIN_PROGRESSBAR, (float)hexFileLineCounter*100 / (((float)flashBufferEndAddress-1) / 16), "");

		
	}
	
	// if no error occured, we may append the end record
	if(flagErrorUploading == 0) {

		sprintf(hexFileLine, ":00000001FF\n");
		if(uploadHexLine(hexFileLine) < 0) {
			flagErrorUploading = 1;
		}
	}

	// if any error occured, print error message and return
	if(flagErrorUploading) {
		Fmt(tmpBuffer, "Error during upload.\r\n");
		SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_RED); 
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Upload Error"); 
		SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
		
		// enable the controls again
		uiMayConnectBootloader(1);
		uiMayProgramFlash(1);
		uiMayProgramEeprom(1);
		uiMayStartApplication(1);
		uiMaySelectFlash(1);
		uiMaySelectEeprom(1);
	
		config.flagProgrammingInProgress = 0;
		return 0;
	}

	// status message in communication log
	Fmt(tmpBuffer, "+\r\nUpload successful!\r\n");
	SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, tmpBuffer);

	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_ON_COLOR, VAL_GREEN); 
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, ATTR_LABEL_TEXT, "Done!"); 
	SetCtrlVal(tabMainPanelHandle, TABMAIN_LEDCONNECTBOOTLOADER, 1);
	
#ifdef DEBUG
	printf("%s", hexFileLine);
#endif
	

	// enable the controls again
	uiMayConnectBootloader(1);
	uiMayProgramFlash(1);
	uiMayProgramEeprom(1);
	uiMayStartApplication(1);
	uiMaySelectFlash(1);
	uiMaySelectEeprom(1);
	
	config.flagProgrammingInProgress = 0;
	return 0;
}


/// HIFN  Starts the application
/// HIRET returns 0 on success or -1 in case of failure
int bootloaderStartApp(void) {

	unsigned char serBuffer[50];

	// status message in communication log
	Fmt(serBuffer, "Starting application...\r\n");
	SetCtrlVal (panelLogHandle, LOGPANEL_COMMUNICATIONLOG, serBuffer);

	ComWrtByte(config.selectedComPort, '\n');
	Delay(1);
	FlushInQ(config.selectedComPort);  // empty input queue
	
	Fmt(serBuffer, "g\n");
	ComWrt(config.selectedComPort, serBuffer, strlen(serBuffer));
	
	if(bootloaderConnect() < 0) {
		return -1;
	}
	
	return 0;
}

