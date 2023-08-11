//==============================================================================
//
// Title:       chip45boot2_gui
// Purpose:     A short description of the application.
//
// Created on:  29.08.2009 at 09:05:26 by Erik Lins.
// Copyright:   chip45 GmbH & Co. KG. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <rs232.h>
#include <ansi_c.h>
#include <cvirte.h>     
#include <userint.h>
#include <progressbar.h>
#include "inifile.h"
#include "chip45boot2_gui.h"
#include "vars.h"
#include "toolbox.h"
#include "bootloader.h"
#include "modify_controls.h"


//==============================================================================
// Constants
//==============================================================================


//==============================================================================
// Types
//==============================================================================


//==============================================================================
// Static global variables
//==============================================================================

// handles for the main UI panel and communication log panel


//==============================================================================
// Static functions
//==============================================================================


//==============================================================================
// Global variables
//==============================================================================

typeApplicationSettings config;

int poolHandle;
int threadFunctionID;

int flashOrEeprom = 0;

//==============================================================================
// Global functions
//==============================================================================

// get the available com ports with description from system
// and write them into the control list
int getAvailableComPorts()
{
	unsigned char string[512];
	unsigned char *buffer = NULL;
	unsigned int size1,size2,values,i;
	int type;
	char valueName[1024];
	int numberOfComPorts = 0, activeIndex = 0;

	// query the registry key, which contains values for all serial com ports
	if(RegQueryInfoOnKey (REGKEY_HKLM, "HARDWARE\\DEVICEMAP\\SERIALCOMM", NULL, &values, NULL, NULL, NULL) == 0) {

		// browse values
		for(i=0;i<values;i++) {

			size1 = 1024; size2 = 512;

			// get the value's type
			RegEnumerateValue (REGKEY_HKLM, "HARDWARE\\DEVICEMAP\\SERIALCOMM", i, valueName, &size1, string, &size2, &type);

			// is it a REG_SZ?
			if( type==_REG_SZ ) {
		
				unsigned int size;			

				// now we can read the size of the actual value (string)
				RegReadString (REGKEY_HKLM, "HARDWARE\\DEVICEMAP\\SERIALCOMM", valueName, NULL, 0, &size);
			
				// get some memory for the value buffer
				buffer = (unsigned char*) malloc(size * sizeof(unsigned char) + 1);

				// if we got memory
				if (buffer != NULL) {

					// we can finally read the actual value
					RegReadString (REGKEY_HKLM, "HARDWARE\\DEVICEMAP\\SERIALCOMM", valueName, buffer, size, &size);
					buffer[size] = 0;  // append zero byte to name of port

					char *tmp;
					tmp = buffer + 3;  // we need a temporary pointer to the com port number (after "COM")

					int comPortNumber;
					StrToInt(tmp, &comPortNumber);  // convert string to integer

					// insert the com port to the list control
					InsertListItem (tabMainPanelHandle, TABMAIN_SELECTCOMPORT, numberOfComPorts, buffer, comPortNumber);

					// check if the com port matches the currently selected com port number
					if(comPortNumber == config.selectedComPort)
						activeIndex = numberOfComPorts;
				
					++numberOfComPorts;
				
					//printf("%s:%d %d %d\n", buffer, comPortNumber, activeIndex, config.selectedComPort);
				}
				free (buffer);
			}
		}
		// set the active index to the currently selected com port
		SetCtrlIndex(tabMainPanelHandle, TABMAIN_SELECTCOMPORT, activeIndex);
		
		if(i == 0) {
			config.selectedComPort = 0;
			uiMayConnectBootloader(0);
		}
		
	}

	
	return 0;
}


//==============================================================================
/// HIFN The main entry-point function.
//==============================================================================
int main (int argc, char *argv[])
{
    int error = 0;
	
	// some variables for the ini file handling
	IniText iniHandle;
	char iniPathName[MAX_PATHNAME_LEN]; 
	char iniDirName[MAX_PATHNAME_LEN]; 

	// preset the config structure
	config.flagBootloaderConnected = 0;
	config.selectedComPort = 0;
	config.selectedBaudrate = 19200;
	config.flagNonStandardBaudrates = 0;
	strcpy(config.pathToFlashHexfile, "");
	strcpy(config.pathToEepromHexfile, "");
	strcpy(config.preString, "");
	config.flagPreStringIsAscii = 0;
	config.flagPreStringIsHex = 1;
	config.flagSendPreString = 0;
	config.flagLockElements = 0;
	config.milliseconds = 1000;
	
	// read the ini file
	GetProjectDir (iniDirName);
	MakePathname (iniDirName, "chip45boot2_gui.ini", iniPathName);

	iniHandle = Ini_New (TRUE);

	if (Ini_ReadFromFile (iniHandle, iniPathName) >= 0) {
		
		char *tmpBuffer = 0;
		Ini_GetInt(iniHandle, "basic_configuration", "selectedComPort", &config.selectedComPort);
		Ini_GetInt(iniHandle, "basic_configuration", "flagRS485", &config.flagRS485);
		Ini_GetInt(iniHandle, "basic_configuration", "selectedBaudrate", &config.selectedBaudrate);
		Ini_GetInt(iniHandle, "basic_configuration", "flagNonStandardBaudrates", &config.flagNonStandardBaudrates);
		if(Ini_GetStringCopy(iniHandle, "basic_configuration", "pathToFlashHexfile", &tmpBuffer) > 0)
			strcpy(config.pathToFlashHexfile, tmpBuffer);
		if(Ini_GetStringCopy(iniHandle, "basic_configuration", "pathToEepromHexfile", &tmpBuffer) > 0)
			strcpy(config.pathToEepromHexfile, tmpBuffer);
		if(Ini_GetStringCopy(iniHandle, "basic_configuration", "preString", &tmpBuffer) > 0)
			strcpy(config.preString, tmpBuffer);
		Ini_GetInt(iniHandle, "basic_configuration", "milliseconds", &config.milliseconds);
		Ini_GetInt(iniHandle, "basic_configuration", "flagPreStringIsAscii", &config.flagPreStringIsAscii);
		Ini_GetInt(iniHandle, "basic_configuration", "flagPreStringIsHex", &config.flagPreStringIsHex);
		Ini_GetInt(iniHandle, "basic_configuration", "flagSendPreString", &config.flagSendPreString);
		Ini_GetInt(iniHandle, "basic_configuration", "flagLockElements", &config.flagLockElements);

	}

	
	
	// create a thread pool for low level IO functions later
	if(CmtNewThreadPool(1, &poolHandle) < 0) {
		printf("Cannot create thread pool...\n");
		return 0;
	}
	
	
    /* initialize and load resources */
    nullChk (InitCVIRTE (0, argv, 0));
    errChk (panelHandle = LoadPanel (0, "chip45boot2_gui.uir", PANEL));
    errChk (panelLogHandle = LoadPanel (0, "chip45boot2_gui.uir", LOGPANEL));
    errChk (panelHelpHandle = LoadPanel (0, "chip45boot2_gui.uir", HELPPANEL));

	// get panel handle for the first tab
	GetPanelHandleFromTabPage (panelHandle, PANEL_TABS, 0, &tabMainPanelHandle);

	// search the PC for available com ports
	getAvailableComPorts();
	
	// preset the UI controls
	uiPreset();

	/* display the panel */
	DefaultPanel (panelHandle);

	// set flash and eeprom filenames (doesn't work to this in uiPreset() before DefaultPanel()...
	SetCtrlVal (tabMainPanelHandle, TABMAIN_FLASHHEXFILE, config.pathToFlashHexfile);
	SetCtrlVal (tabMainPanelHandle, TABMAIN_EEPROMHEXFILE, config.pathToEepromHexfile);
	SetCtrlVal (tabMainPanelHandle, TABMAIN_NONSTANDARDBAUDRATES, config.flagNonStandardBaudrates);
	SetCtrlVal (tabMainPanelHandle, TABMAIN_HALFDUPLEXRS485, config.flagRS485);

	// convert the slide control into a progress bar
	ProgressBar_ConvertFromSlide(tabMainPanelHandle, TABMAIN_PROGRESSBAR);  // convert
	ProgressBar_Start(tabMainPanelHandle, TABMAIN_PROGRESSBAR, "");  // start without a label
	ProgressBar_SetAttribute(tabMainPanelHandle, TABMAIN_PROGRESSBAR, ATTR_PROGRESSBAR_UPDATE_MODE, VAL_PROGRESSBAR_MANUAL_MODE);  // manual update mode
	ProgressBar_SetPercentage(tabMainPanelHandle, TABMAIN_PROGRESSBAR, 0, "");  // start at 0%

	// eeprom reading is not yet implemented
	SetCtrlAttribute(tabMainPanelHandle, TABMAIN_READEEPROM, ATTR_DIMMED, 1);  // disable

	// preset the pre string controls	
/*	unsigned char tmp[1024];
	strcpy(tmp, config.preString);
	if(config.flagPreStringIsHex == 1) {
		unsigned char *p;
		int i;
		p = tmp;
		for(i = 0; i < strlen(config.preString); ++i) {
			sprintf(p, "%02x", config.preString[i]);
			p += 2;
		}
		*p = 0;  // terminate string with zero

		SetCtrlVal (tabMainPanelHandle, TABMAIN_PRESTRING, tmp);

	} else {
		SetCtrlVal (tabMainPanelHandle, TABMAIN_PRESTRING, config.preString);
	}*/
		SetCtrlVal (tabMainPanelHandle, TABMAIN_PRESTRING, config.preString);
	
	SetCtrlVal (tabMainPanelHandle, TABMAIN_SENDPRESTRING, config.flagSendPreString);
	SetCtrlVal (tabMainPanelHandle, TABMAIN_MILLISECONDS, config.milliseconds);
	SetCtrlVal (tabMainPanelHandle, TABMAIN_RADIOBUTTON_ASCII, config.flagPreStringIsAscii);
	SetCtrlVal (tabMainPanelHandle, TABMAIN_RADIOBUTTON_HEX, config.flagPreStringIsHex);
	uiMayEnterPreString(1);
	

	// load an image file "logo.png"
	//DisplayImageFile (panelHandle, PANEL_PICTURE, "logo.png");


	
	// and run the user interface
	errChk (DisplayPanel (panelHandle));
    errChk (RunUserInterface ());

	
	
	// write current configuration to ini file
	char *tmpBuffer = 0;
	Ini_PutInt (iniHandle, "basic_configuration", "selectedComPort", config.selectedComPort);
	Ini_PutInt (iniHandle, "basic_configuration", "flagRS485", config.flagRS485);
	Ini_PutInt (iniHandle, "basic_configuration", "selectedBaudrate", config.selectedBaudrate);
	Ini_PutInt (iniHandle, "basic_configuration", "flagNonStandardBaudrates", config.flagNonStandardBaudrates);
	Ini_PutString (iniHandle, "basic_configuration", "pathToFlashHexfile", config.pathToFlashHexfile);
	Ini_PutString (iniHandle, "basic_configuration", "pathToEepromHexfile", config.pathToEepromHexfile);

	Ini_PutString (iniHandle, "basic_configuration", "preString", config.preString);
	Ini_PutInt(iniHandle, "basic_configuration", "milliseconds", config.milliseconds);
	Ini_PutInt(iniHandle, "basic_configuration", "flagPreStringIsAscii", config.flagPreStringIsAscii);
	Ini_PutInt(iniHandle, "basic_configuration", "flagPreStringIsHex", config.flagPreStringIsHex);
	Ini_PutInt(iniHandle, "basic_configuration", "flagSendPreString", config.flagSendPreString);
	Ini_PutInt(iniHandle, "basic_configuration", "flagLockElements", config.flagLockElements);

	
	Ini_WriteToFile(iniHandle, iniPathName);  // actually write to file
	Ini_Dispose(iniHandle);  // free the ini handle											    
	
Error:
    /* clean up */
    DiscardPanel (panelHandle);
    return 0;
}

//==============================================================================
// UI callback function prototypes
//==============================================================================

/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
        int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_CLOSE:
			if(config.flagProgrammingInProgress == 0) {
				if(config.flagBootloaderConnected) {
					bootloaderStartApp(); 
				}
	        	QuitUserInterface (0);
			}
			break;
	}
    return 0;
}

// callback for the communication log, just to handle the close event
int CVICALLBACK panelLogCB (int panel, int event, void *callbackData,
        int eventData1, int eventData2)
{
    if (event == EVENT_CLOSE)
		HidePanel(panelLogHandle);
    return 0;
}

// tabs callback, empty
int CVICALLBACK tabs (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	return 0;
}

// exit button
int CVICALLBACK buttonExit (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(config.flagProgrammingInProgress == 0) {
				if(config.flagBootloaderConnected) {
					bootloaderStartApp();
				}
		        QuitUserInterface(0);
			}
			break;
	}
	return 0;
}


/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelHelpCB (int panel, int event, void *callbackData,
        int eventData1, int eventData2)
{
    if (event == EVENT_CLOSE)
		HidePanel(panelHelpHandle);
    return 0;
}


	
//==============================================================================
// communication log
//==============================================================================

// button to show the communication log
int CVICALLBACK buttonShowCommunicationLog (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel(panelLogHandle);  // show it!
			break;
	}
	return 0;
}

// button to hide the communication log
int CVICALLBACK buttonCloseCommunicationLog (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(panelLogHandle);
			break;
	}
	return 0;
}

// communication log text field
int CVICALLBACK textCommunicationLog (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		break;
	}
	return 0;
}

// button to clear the log text
int CVICALLBACK buttonClearCommunicationLog (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			ResetTextBox(panelLogHandle, LOGPANEL_COMMUNICATIONLOG, "");
			break;
	}
	return 0;
}


//==============================================================================
// help panel
//==============================================================================

int CVICALLBACK buttonHelp (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel(panelHelpHandle);  // show it!
			break;
	}
	return 0;
}


//==============================================================================
// filename controls
//==============================================================================

// select filename for flash programming
int CVICALLBACK stringFlashHexfile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char buffer[1024];

	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (tabMainPanelHandle, TABMAIN_FLASHHEXFILE, buffer);
		    strcpy(config.pathToFlashHexfile, buffer);
			if(strlen(buffer) > 0) {
				strcpy(config.pathToFlashHexfile, buffer);
				uiMayProgramFlash(1);
			} else {
				uiMayProgramFlash(0);
			}

		break;
	}
	return 0;
}

// select filename for eeprom programming
int CVICALLBACK stringEepromHexfile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char buffer[1024];

	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (tabMainPanelHandle, TABMAIN_EEPROMHEXFILE, buffer);
		    strcpy(config.pathToEepromHexfile, buffer);
			if(strlen(buffer) > 0) {
				strcpy(config.pathToEepromHexfile, buffer);
				uiMayProgramEeprom(1);
			} else {
				uiMayProgramEeprom(0);
			}
		break;
	}
	return 0;
}

// button for flash programming
int CVICALLBACK buttonSelectFlashHexfile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			FileSelectPopup ("", "*.hex", "*.hex;*.a43", "Select Flash Hexfile", VAL_LOAD_BUTTON, 0, 0, 1, 1, config.pathToFlashHexfile);
			SetCtrlVal (tabMainPanelHandle, TABMAIN_FLASHHEXFILE, config.pathToFlashHexfile);
			uiMayProgramFlash(1);
		break;
	}
	return 0;
}

// button for eeprom programming
int CVICALLBACK buttonSelectEepromHexfile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			FileSelectPopup ("", "*.hex;*.eep", "*.hex;*.a43;*.eep", "Select Eeprom Hexfile", VAL_LOAD_BUTTON, 0, 0, 1, 1, config.pathToEepromHexfile);
			SetCtrlVal (tabMainPanelHandle, TABMAIN_EEPROMHEXFILE, config.pathToEepromHexfile);
			uiMayProgramEeprom(1);
		break;
	}
	return 0;
}


//==============================================================================
// communication controls
//==============================================================================

// list control for com port selection
int CVICALLBACK selectComPort (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		// we listen two both left click and value changed events!
		case EVENT_LEFT_CLICK:
		case EVENT_VAL_CHANGED:
			int selection;
			GetCtrlVal (tabMainPanelHandle, TABMAIN_SELECTCOMPORT, &selection);  // get selected value from control
			config.selectedComPort = selection;  // store com port number in config structure
			// the baudrate has to be stored in the config structure
			GetCtrlVal (tabMainPanelHandle, TABMAIN_INITIALBAUDRATE, &selection);
			config.selectedBaudrate = availableBaudrates[selection];
			// modify ui controls
			uiMayConnectBootloader(1);
			uiMaySelectInitialBaudrate(1);
			uiMayProgramFlash(1);
			uiMayProgramEeprom(1);
			break;
	}
	return 0;
}

// list control to select the initial baud rate
int CVICALLBACK selectInitialBaudrate (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			int selection;
			GetCtrlVal (tabMainPanelHandle, TABMAIN_INITIALBAUDRATE, &selection);
			config.selectedBaudrate = availableBaudrates[selection];
			break;
	}
	return 0;
}

// button to show non-standard baudrates
int CVICALLBACK toggleNonStandardBaudrates (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(config.flagNonStandardBaudrates)
				config.flagNonStandardBaudrates = 0;
			else
				config.flagNonStandardBaudrates = 1;
			uiShowBaudrates(config.flagNonStandardBaudrates);
			break;
	}
	return 0;
}

// button to toggle RS485 mode
int CVICALLBACK useHalfDuplexRS485 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(config.flagRS485)
				config.flagRS485 = 0;
			else
				config.flagRS485 = 1;
			break;
	}
	return 0;
}


//==============================================================================
// bootloader controls
//==============================================================================

// button to connect to the bootloader and to disconnect
int CVICALLBACK buttonConnectBootloader (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(flagConnectBootloaderButtonPressed == 0) {
				if(config.flagBootloaderConnected) {
					CmtScheduleThreadPoolFunction (poolHandle, (ThreadFunctionPtr)bootloaderStartApp, 0, &threadFunctionID);
				} else {

					flagConnectBootloaderButtonPressed = 1;
					CmtScheduleThreadPoolFunction (poolHandle, (ThreadFunctionPtr)bootloaderConnect, 0, &threadFunctionID);
				}
			} else {
				flagConnectBootloaderButtonPressed = 2;
			}
			break;
	}
	return 0;
}

// flash programming button
int CVICALLBACK buttonProgramFlash (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			flashOrEeprom = FLASH;
			CmtScheduleThreadPoolFunction (poolHandle, (ThreadFunctionPtr)bootloaderProgram, 0, &threadFunctionID);

			break;
	}
	return 0;
}

// eeprom programming button
int CVICALLBACK buttonProgramEeprom (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			flashOrEeprom = EEPROM;
			CmtScheduleThreadPoolFunction (poolHandle, (ThreadFunctionPtr)bootloaderProgram, 0, &threadFunctionID);

			break;
	}
	return 0;
}

// start application button
int CVICALLBACK buttonStartApplication (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			CmtScheduleThreadPoolFunction (poolHandle, (ThreadFunctionPtr)bootloaderStartApp, 0, &threadFunctionID);

			break;
	}
	return 0;
}


//==============================================================================
// LED indicators
//==============================================================================
int CVICALLBACK ledConnectBootloader (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

//==============================================================================
// Progress Bar
//==============================================================================
int CVICALLBACK buttonReadEeprom (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

//==============================================================================
// Timer
//==============================================================================

// a two second timer callback
int CVICALLBACK timer2secs (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			// look for change in com port list only if we have no connection yet
			if(config.flagBootloaderConnected == 0) {
				ClearListCtrl (tabMainPanelHandle, TABMAIN_SELECTCOMPORT);
				getAvailableComPorts();					
			}
			break;
	}
	return 0;
}

int CVICALLBACK stringPreString (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			char buffer[1024];
 			GetCtrlVal (tabMainPanelHandle, TABMAIN_PRESTRING, buffer);
		    strcpy(config.preString, buffer);
/*			if(config.flagPreStringIsHex == 1) {
				char tmp[1024], *p;
				int i;
				p = tmp;
				for(i = 0; i < strlen(config.preString); i+=2) {
					if(config.preString[i] >= 'a') {
						*p = (config.preString[i] - 'a' + 10) << 4;
					} else if(config.preString[i] >= 'A') {
						*p = (config.preString[i] - 'A' + 10) << 4;
					} else {
						*p = (config.preString[i] - '0') << 4;
					}
					if(config.preString[i+1] >= 'a') {
						*p += (config.preString[i+1] - 'a' + 10);
					} else if(config.preString[i+1] >= 'A') {
						*p += (config.preString[i+1] - 'A' + 10);
					} else {
						*p += (config.preString[i+1] - '0');
					}
					++p;
				}
				*p = 0;  // terminate string with zero
				strcpy(config.preString, tmp);

			}
*/			
			break;
	}
	return 0;
}

int CVICALLBACK buttonPreStringAscii (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			config.flagPreStringIsAscii = 1;
			config.flagPreStringIsHex = 0;
			SetCtrlVal (tabMainPanelHandle, TABMAIN_RADIOBUTTON_ASCII, config.flagPreStringIsAscii);
			SetCtrlVal (tabMainPanelHandle, TABMAIN_RADIOBUTTON_HEX, config.flagPreStringIsHex);
/*
			//strcpy(config.preString, tmp);
			SetCtrlVal (tabMainPanelHandle, TABMAIN_PRESTRING, config.preString);
*/
			break;
	}
	return 0;
}

int CVICALLBACK buttonPreStringHex (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			config.flagPreStringIsAscii = 0;
			config.flagPreStringIsHex = 1;
			SetCtrlVal (tabMainPanelHandle, TABMAIN_RADIOBUTTON_ASCII, config.flagPreStringIsAscii);
			SetCtrlVal (tabMainPanelHandle, TABMAIN_RADIOBUTTON_HEX, config.flagPreStringIsHex);
/*			unsigned char tmp[1024], *p;
			int i;
			p = tmp;
			for(i = 0; i < strlen(config.preString); ++i) {
				sprintf(p, "%02x", config.preString[i]);
				p += 2;
			}
			*p = 0;  // terminate string with zero
			//strcpy(config.preString, tmp);
			SetCtrlVal(tabMainPanelHandle, TABMAIN_PRESTRING, tmp);
*/
			break;
	}
	return 0;
}

int CVICALLBACK preStringWaitMilliseconds (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
 			int selection;
			GetCtrlVal (tabMainPanelHandle, TABMAIN_MILLISECONDS, &selection);
			config.milliseconds = selection;
			break;
	}
	return 0;
}

int CVICALLBACK toggleSendPreString (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(config.flagSendPreString)
				config.flagSendPreString = 0;
			else
				config.flagSendPreString = 1;
			uiMayEnterPreString(1);
			break;
	}
	return 0;
}

int CVICALLBACK cbPicture (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	return 0;
}
