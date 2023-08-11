/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2014. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  HELPPANEL                        1       /* callback function: panelHelpCB */
#define  HELPPANEL_TAB                    2       /* control type: tab, callback function: (none) */

#define  LOGPANEL                         2       /* callback function: panelLogCB */
#define  LOGPANEL_COMMUNICATIONLOG        2       /* control type: textBox, callback function: textCommunicationLog */
#define  LOGPANEL_CLEARCOMUNICATIONLOG    3       /* control type: command, callback function: buttonClearCommunicationLog */
#define  LOGPANEL_CLOSECOMUNICATIONLOG    4       /* control type: command, callback function: buttonCloseCommunicationLog */

#define  PANEL                            3       /* callback function: panelCB */
#define  PANEL_PROGNAME                   2       /* control type: textMsg, callback function: (none) */
#define  PANEL_PROGVERSION                3       /* control type: textMsg, callback function: (none) */
#define  PANEL_TIMER2SECS                 4       /* control type: timer, callback function: timer2secs */
#define  PANEL_PICTURE                    5       /* control type: picture, callback function: cbPicture */
#define  PANEL_TABS                       6       /* control type: tab, callback function: tabs */
#define  PANEL_SHOWCOMMUNICATIONLOG       7       /* control type: command, callback function: buttonShowCommunicationLog */
#define  PANEL_TEXTMSG                    8       /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_2                  9       /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_3                  10      /* control type: textMsg, callback function: (none) */
#define  PANEL_EXIT                       11      /* control type: command, callback function: buttonExit */

     /* tab page panel controls */
#define  TABMAIN_SELECTCOMPORT            2       /* control type: listBox, callback function: selectComPort */
#define  TABMAIN_INITIALBAUDRATE          3       /* control type: listBox, callback function: selectInitialBaudrate */
#define  TABMAIN_SENDPRESTRING            4       /* control type: radioButton, callback function: toggleSendPreString */
#define  TABMAIN_HALFDUPLEXRS485          5       /* control type: radioButton, callback function: useHalfDuplexRS485 */
#define  TABMAIN_NONSTANDARDBAUDRATES     6       /* control type: radioButton, callback function: toggleNonStandardBaudrates */
#define  TABMAIN_HELP                     7       /* control type: command, callback function: buttonHelp */
#define  TABMAIN_FLASHHEXFILE             8       /* control type: string, callback function: stringFlashHexfile */
#define  TABMAIN_SELECTFLASHFILE          9       /* control type: command, callback function: buttonSelectFlashHexfile */
#define  TABMAIN_PRESTRING                10      /* control type: string, callback function: stringPreString */
#define  TABMAIN_EEPROMHEXFILE            11      /* control type: string, callback function: stringEepromHexfile */
#define  TABMAIN_SELECTEEPROMFILE         12      /* control type: command, callback function: buttonSelectEepromHexfile */
#define  TABMAIN_CONNECTBOOTLOADER        13      /* control type: command, callback function: buttonConnectBootloader */
#define  TABMAIN_PROGRAMFLASH             14      /* control type: command, callback function: buttonProgramFlash */
#define  TABMAIN_READEEPROM               15      /* control type: command, callback function: buttonReadEeprom */
#define  TABMAIN_PROGRAMEEPROM            16      /* control type: command, callback function: buttonProgramEeprom */
#define  TABMAIN_STARTAPPLICATION         17      /* control type: command, callback function: buttonStartApplication */
#define  TABMAIN_LEDCONNECTBOOTLOADER     18      /* control type: LED, callback function: ledConnectBootloader */
#define  TABMAIN_PROGRESSBAR              19      /* control type: scale, callback function: (none) */
#define  TABMAIN_RADIOBUTTON_ASCII        20      /* control type: radioButton, callback function: buttonPreStringAscii */
#define  TABMAIN_RADIOBUTTON_HEX          21      /* control type: radioButton, callback function: buttonPreStringHex */
#define  TABMAIN_MILLISECONDS             22      /* control type: numeric, callback function: preStringWaitMilliseconds */

     /* tab page panel controls */
#define  TABPANEL_TEXTMSG_2               2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_TEXTMSG                 3       /* control type: textMsg, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_2_TEXTMSG               2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_2_TEXTMSG_2             3       /* control type: textMsg, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_3_TEXTMSG_2             2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_3_TEXTMSG               3       /* control type: textMsg, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_4_TEXTMSG_2             2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_4_TEXTMSG               3       /* control type: textMsg, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_5_TEXTMSG_2             2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_5_TEXTMSG               3       /* control type: textMsg, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_6_TEXTMSG_2             2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_6_TEXTMSG               3       /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK buttonClearCommunicationLog(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonCloseCommunicationLog(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonConnectBootloader(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonExit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonHelp(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonPreStringAscii(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonPreStringHex(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonProgramEeprom(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonProgramFlash(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonReadEeprom(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonSelectEepromHexfile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonSelectFlashHexfile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonShowCommunicationLog(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buttonStartApplication(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK cbPicture(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ledConnectBootloader(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelHelpCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelLogCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK preStringWaitMilliseconds(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK selectComPort(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK selectInitialBaudrate(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK stringEepromHexfile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK stringFlashHexfile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK stringPreString(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK tabs(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK textCommunicationLog(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK timer2secs(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK toggleNonStandardBaudrates(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK toggleSendPreString(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK useHalfDuplexRS485(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
