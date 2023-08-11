//==============================================================================
//
// Title:       vars.h
// Purpose:     A short description of the interface.
//
// Created on:  01.09.2009 at 14:36:25 by Erik Lins.
// Copyright:   chip45 GmbH & Co. KG. All Rights Reserved.
//
//==============================================================================

#ifndef __vars_H__
#define __vars_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

#define defTimeoutConnectBootloader 15.0

//==============================================================================
// Types

// config structure (will be stored in file later)
typedef struct {
	int selectedComPort;
	int flagRS485;
	int selectedBaudrate;
	int flagNonStandardBaudrates;
	char pathToFlashHexfile[1024];
	char pathToEepromHexfile[1024];
	int flagBootloaderConnected;
	int flagProgrammingInProgress;
	int flagSendPreString;
	int flagPreStringIsAscii;
	int flagPreStringIsHex;
	int flagLockElements;
	unsigned char preString[1024];
	int milliseconds;
} typeApplicationSettings;


int panelHandle, panelLogHandle, panelHelpHandle, tabMainPanelHandle;



//==============================================================================
// External variables

extern unsigned long availableBaudrates[];
extern unsigned char baudrateIsStandard[];
extern int flagConnectBootloaderButtonPressed;



//==============================================================================
// Global functions



#ifdef __cplusplus
    }
#endif

#endif  /* ndef __vars_H__ */
