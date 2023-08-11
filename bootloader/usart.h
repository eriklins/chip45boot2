// usart.h
//
// header file for usart communication routines

// system includes
#include <avr/pgmspace.h>

// local includes
#include "mcudefs.h"


// make sure to include just once!
#ifndef _USART_
#define _USART_


// functions prototypes
#ifdef XMEGA
void usartInit(uint32_t uxDiv);
#else
void usartInit(uint16_t uxDiv);
#endif

void usartPutChar(char c);
char usartGetChar(void);

void usartPutNibble(uint8_t nibble);
void usartPutHex(uint8_t hex);
//void usartPutHex16 (uint16_t hex);
//void usartPutDec(uint16_t dec);

//void usartPutProgStr(PGM_P str);
void usartPutRamStr(uint8_t *str);


#endif


// end of file: usart.h
