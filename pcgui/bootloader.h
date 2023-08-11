//==============================================================================
//
// Title:       bootloader.h
// Purpose:     communication routines with the bootloader.
//
// Created on:  01.09.2009 at 13:56:38 by Erik Lins.
// Copyright:   chip45 GmbH & Co. KG. All Rights Reserved.
//
//==============================================================================

#ifndef __bootloader_H__
#define __bootloader_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include "chip45boot2_gui.h"
#include "vars.h"
		
		
//==============================================================================
// Constants

#define FLASH 1
#define EEPROM 2
		
//==============================================================================
// Types

//==============================================================================
// External variables

extern int panelHandle, panelLogHandle;
extern typeApplicationSettings config;
extern int flashOrEeprom;


//==============================================================================
// Global functions

int bootloaderConnect(void);
int bootloaderProgram(void);
unsigned char asciiToHex(unsigned char);
unsigned char asciiToHex2(unsigned char, unsigned char);
int bootloaderStartApp(void);


#ifdef __cplusplus
    }
#endif
int bootloaderConnect();

#endif  /* ndef __bootloader_H__ */
