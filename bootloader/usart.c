// usart.c
//
// usart communication routines


// system includes
#include <avr/io.h>
#include <avr/pgmspace.h>


// include the definitions for the MCU specific USART registers and bits
#include "mcudefs.h"
#include "usart.h"


// ============================================================================
// initialize the uart with the measured baudrate division factor
// in: measured division factor
// out: nothing
// ============================================================================
#ifdef XMEGA
void usartInit(uint32_t uxDiv) {
#else
void usartInit(uint16_t uxDiv) {
#endif

#ifdef XMEGA
	uint16_t bsel = (uint16_t)(((100000UL*(uxDiv+1UL))/8UL-100000UL)/6250UL-1UL);

	// baud rate registers
	myUSART.BAUDCTRLA = bsel & 0xff;
	myUSART.BAUDCTRLB = (-4<<USART_BSCALE_gp) | (bsel >> 8);	

	// control registers
	myUSART.CTRLA = 0;  // no interrupts used, we write the default reset value here
  	myUSART.CTRLC = (myUSART.CTRLC & ~USART_CHSIZE_gm) | USART_CHSIZE_8BIT_gc;  // 8 data bits, 1 stop bit
	myUSART.CTRLB = (1<<USART_RXEN_bp) | (1<<USART_TXEN_bp) | (1<<USART_CLK2X_bp);	// receiver enable, transmitter enable, usart 2x
#else
	uxDiv >>= 4;  // devide by 16 to get the actual baud rate divider
    myUBRRH = (uint8_t)(uxDiv>>8);
    myUBRRL = (uint8_t)uxDiv;
    myUCSRA = 0;
    myUCSRB = (1<<myTXEN) | (1<<myRXEN);
    myUCSRC = myURSEL | (3<<myUCSZ0);
#endif
}


// ============================================================================
// send a character over the usart
// in: character to be sent
// out: nothing
// ============================================================================
void usartPutChar(char c) {

    if(c == '\r')
		usartPutChar('\n');

#ifdef XMEGA
	// wait for transmit buffer empty (in case a previous transmission is not yet completed)
	loop_until_bit_is_set(myUSART.STATUS, USART_DREIF_bp);
	// put character into data register and send
	myUSART.DATA = c;
#else
    loop_until_bit_is_set(myUCSRA, myUDRE);
    myUDR = c;
#endif
}


// ============================================================================
// receive a character from the usart (and wait for it!)
// in: nothing
// out: the received character
// ============================================================================
char usartGetChar(void) {

#ifdef XMEGA
	// wait for data to be received
	loop_until_bit_is_set(myUSART.STATUS, USART_RXCIF_bp);
	// get and return the recieved data
	return myUSART.DATA;
#else
    loop_until_bit_is_set(myUCSRA, myRXC);  // wait until character is received
    return myUDR;                           // return the character
#endif
}


// ============================================================================
// print a 4 bit data word as ascii character over the usart
// in: 4 bit nibble
// out: nothing
// ============================================================================
void usartPutNibble(uint8_t ucNibble)
{
    ucNibble &= 0x0f;

    if(ucNibble > 9) {
        ucNibble += ('a' - 10);
    } else {
        ucNibble += '0';
    }

    usartPutChar(ucNibble);
}


// ============================================================================
// print an 8 bit word as two ascii characters over the usart
// in: 8 bit word
// out: nothing
// ============================================================================
void usartPutHex(uint8_t ucHex)
{
    usartPutNibble (ucHex >> 4);
    usartPutNibble (ucHex);
}


/*
// ============================================================================
// print a 16 bit word as four ascii characters over the usart
// in: 16 bit word
// out: nothing
// ============================================================================
void usartPutHex16 (uint16_t usHex)
{
    usartPutNibble(usHex >> 12);
    usartPutNibble(usHex >> 8);
    usartPutNibble(usHex >> 4);
    usartPutNibble(usHex);
}
*/


/*
// ============================================================================
// print a 16 bit word as decimal value over the usart
// in: 16 bit word
// out: nothing
// ============================================================================
void usartPutDec(uint16_t usDec)
{
    uint8_t ucBuffer[6];
    uint8_t ucLoop = 5;
    
	ucBuffer[5] = '\0';
    
    while (ucLoop)
    {
        --ucLoop;
        ucBuffer[ucLoop] = (usDec % 10) + '0';
        usDec /= 10;
        if (usDec == 0)
            break;
    }
    usartPutRamStr(&ucBuffer[ucLoop]);
}
*/


/*
// ============================================================================
// print a string from program memory over the usart
// in: pointer to string in program memory
// out: nothing
// ============================================================================
void usartPutProgStr(const prog_char *pcStr)
{
	while(pgm_read_byte(pcStr)) {
		usartPutChar(pgm_read_byte(pcStr));
		pcStr++;
	}
}
*/


// ============================================================================
// print a string from sram memory over the usart
// in: pointer to string in sram memory
// out: nothing
// ============================================================================
void usartPutRamStr(uint8_t *ucStr)
{
	while (*ucStr) {
		usartPutChar(*ucStr++);
	}
}


// end of file: usart.c
