//==============================================================================
//
// Title:       modify_controls.c
// Purpose:     A short description of the implementation.
//
// Created on:  02.09.2009 at 13:37:43 by Erik Lins.
// Copyright:   chip45 GmbH & Co. KG. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <progressbar.h>
#include <ansi_c.h>
#include <userint.h>
#include "modify_controls.h"
#include "vars.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

unsigned long availableBaudrates[] = { 500000, 250000, 230400, 125000, 115200, 76800, 64000, 62500, 57600, 38400, 32000, 28800, 19200, 16000, 14400, 9600, 4800, 2400, 0 };

unsigned char baudrateIsStandard[] = {      0,      0,      1,      0,      1,     1,     0,     0,     1,     1,     0,     1,     1,     0,     1,    1,    1,    1, 0 };
	
//==============================================================================
// Global functions


// if flag is set in ini file, several GUI elements must no longer be changed!
void uiCheckLockFlag (void) {
	if(config.flagLockElements == 1) {

		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTCOMPORT, ATTR_DIMMED, 1);  // disable com ports
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_INITIALBAUDRATE, ATTR_DIMMED, 1);  // disable initial baud rate
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_NONSTANDARDBAUDRATES, ATTR_DIMMED, 1);  // disable checkbox non standard baud rates
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_HALFDUPLEXRS485, ATTR_DIMMED, 1);  // disable checkbox RS485
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_FLASHHEXFILE, ATTR_DIMMED, 1);  // disable flash file name
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTFLASHFILE, ATTR_DIMMED, 1);  // disable flash file select button
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_EEPROMHEXFILE, ATTR_DIMMED, 1);  // disable eeprom file name
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTEEPROMFILE, ATTR_DIMMED, 1);  // disable eeprom file select button
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SENDPRESTRING, ATTR_DIMMED, 1);  // disable prestring
	}
}


// fill the list controls for the baudrate selection with the available values
void uiPreset (void)
{

	uiShowBaudrates (config.flagNonStandardBaudrates);  // show standard baudrates by default
	
	// disable many controls
	if(config.selectedComPort >= 1) {
		uiMayConnectBootloader(1);
		uiMaySelectInitialBaudrate(1);
	} else {
		uiMayConnectBootloader(0);
		uiMaySelectInitialBaudrate(0);
	}
	uiMayProgramFlash(0);
	uiMayProgramEeprom(0);
	uiMayStartApplication(0);
	uiMaySelectFlash(1);
	uiMaySelectEeprom(1);
	uiCheckLockFlag();
}	

void uiShowBaudrates (unsigned char nonStandard)
{
	
	int i = 0, j = 0, defaultBaudrateIndex = 0;
	char baudstring[10];
	
	DeleteListItem(tabMainPanelHandle, TABMAIN_INITIALBAUDRATE, 0, -1);  // delete all list items before creating new ones
	
	do {
		sprintf(baudstring, "%d", availableBaudrates[i]);
		if( (baudrateIsStandard[i] == 1) || (nonStandard == 1) ) {
			InsertListItem (tabMainPanelHandle, TABMAIN_INITIALBAUDRATE, j, baudstring, i);
			if(availableBaudrates[i] == config.selectedBaudrate) {
				defaultBaudrateIndex = j;
			}
			++j;
		}
	} while(availableBaudrates[++i] != 0);

	// and set the default indexes
	SetCtrlAttribute (tabMainPanelHandle, TABMAIN_INITIALBAUDRATE, ATTR_DFLT_INDEX, defaultBaudrateIndex);

	uiCheckLockFlag();
}

void uiMayEnterPreString (int flag)
{
	if(config.flagSendPreString && flag) {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_PRESTRING, ATTR_DIMMED, 0);	
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_RADIOBUTTON_ASCII, ATTR_DIMMED, 0);	
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_RADIOBUTTON_HEX, ATTR_DIMMED, 0);	
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_MILLISECONDS, ATTR_DIMMED, 0);
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_PRESTRING, ATTR_DIMMED, 1);	
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_RADIOBUTTON_ASCII, ATTR_DIMMED, 1);	
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_RADIOBUTTON_HEX, ATTR_DIMMED, 1);	
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_MILLISECONDS, ATTR_DIMMED, 1);
	}
	uiCheckLockFlag();
}

void uiMayEnablePreString (int flag)
{
	if(flag) {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SENDPRESTRING, ATTR_DIMMED, 0);	
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SENDPRESTRING, ATTR_DIMMED, 1);	
	}
	uiCheckLockFlag();
}


void uiMaySelectFlash (int flag)
{
	if(flag) {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTFLASHFILE, ATTR_DIMMED, 0);	
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTFLASHFILE, ATTR_DIMMED, 1);	
	}
	uiCheckLockFlag();
}

void uiMayProgramFlash (int flag)
{
	if(flag) {
		if(strlen(config.pathToFlashHexfile) > 0) {
			if(config.selectedComPort != 0) {
				if(config.flagBootloaderConnected != 0) {
					SetCtrlAttribute(tabMainPanelHandle, TABMAIN_PROGRAMFLASH, ATTR_DIMMED, 0);  // enable button
				}
			}
		}
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_PROGRAMFLASH, ATTR_DIMMED, 1);  // disable
	}

	uiCheckLockFlag();
}

void uiMaySelectEeprom (int flag)
{
	if(flag) {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTEEPROMFILE, ATTR_DIMMED, 0);	
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTEEPROMFILE, ATTR_DIMMED, 1);	
	}	uiCheckLockFlag();
}

void uiMayProgramEeprom (int flag)
{
	if(flag) {
		if(strlen(config.pathToEepromHexfile) > 0) {
			if(config.selectedComPort != 0) { 
				if(config.flagBootloaderConnected != 0) {
					SetCtrlAttribute(tabMainPanelHandle, TABMAIN_PROGRAMEEPROM, ATTR_DIMMED, 0);  // enable
				}
			}
		}
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_PROGRAMEEPROM, ATTR_DIMMED, 1);  // disable
	}

	uiCheckLockFlag();
}

void uiMayConnectBootloader (int flag) 
{
	if(flag) {
		if(config.selectedComPort > 0) {
			SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_DIMMED, 0);  // enable
		}
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_CONNECTBOOTLOADER, ATTR_DIMMED, 1);  // disable
	}
	
	uiCheckLockFlag();
}

void uiMayStartApplication (int flag)
{
	if(flag) {
		if(config.flagBootloaderConnected != 0) {
			SetCtrlAttribute(tabMainPanelHandle, TABMAIN_STARTAPPLICATION, ATTR_DIMMED, 0);  // enable
		}
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_STARTAPPLICATION, ATTR_DIMMED, 1);  // disable
	}

	uiCheckLockFlag();
}

void uiMaySelectInitialBaudrate (int flag)
{
	if(flag) {
		if(config.selectedComPort > 0) {
			SetCtrlAttribute(tabMainPanelHandle, TABMAIN_INITIALBAUDRATE, ATTR_DIMMED, 0);  // enable
			SetCtrlAttribute(tabMainPanelHandle, TABMAIN_NONSTANDARDBAUDRATES, ATTR_DIMMED, 0);  // enable
		}
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_INITIALBAUDRATE, ATTR_DIMMED, 1);  // disable
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_NONSTANDARDBAUDRATES, ATTR_DIMMED, 1);  // disable
	}
		
	uiCheckLockFlag();
}

void uiMaySelectComport (int flag)
{
	if(flag) {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTCOMPORT, ATTR_DIMMED, 0);  // enable
	} else {
		SetCtrlAttribute(tabMainPanelHandle, TABMAIN_SELECTCOMPORT, ATTR_DIMMED, 1);  // disable
	}
	
	uiCheckLockFlag();
}

