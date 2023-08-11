//==============================================================================
//
// Title:       modify_controls.h
// Purpose:     A short description of the interface.
//
// Created on:  02.09.2009 at 13:37:43 by Erik Lins.
// Copyright:   chip45 GmbH & Co. KG. All Rights Reserved.
//
//==============================================================================

#ifndef __modify_controls_H__
#define __modify_controls_H__

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

//==============================================================================
// Types

//==============================================================================
// External variables

extern typeApplicationSettings config;
extern int flashOrEeprom;


//==============================================================================
// Global functions

void uiPreset (void);
void uiShowBaudrates (unsigned char);
void uiMayProgramFlash (int);
void uiMaySelectFlash (int);
void uiMaySelectEeprom (int);
void uiMayProgramEeprom (int);
void uiMayConnectBootloader (int);
void uiMayStartApplication (int);
void uiMaySelectInitialBaudrate (int);
void uiMaySelectComport (int);
void uiMayEnterPreString(int);
void uiMayEnablePreString(int);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __modify_controls_H__ */
