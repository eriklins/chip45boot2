// chip45boot2
//
// (c) by Dr. Erik Lins, chip45 GmbH & Co. KG
//
// chip45boot2 has been completely rewritten from chip45boot and provides the following features:
//
// AUTOMATIC BAUD RATE ADJUSTMENT
// After a reset the bootloader waits for at least four characters of 'U' at 19200 baud.
// The rising and falling edges of the received UART protocol at the RXD pin are used to calculate a baud rate devision factor.
// Due to this, only one precompiled hexfile is needed for a certain AVR device and works independently of the chosen clock source.
// The waiting for the four U's has a timeout of about three seconds. If no edges are detected on the RXD pin during this time,
// the bootloader checks flash address 0x0000 if there is an application available (content != 0xff).
// If so, it will jump to the application, if not, it will continue waiting for edges at RXD to start the timing measurement.
//
// MINIMALISTIC COMMAND SHELL
// After successful adjustment of the baudrate, a command prompt is shown.
// The bootloader uses XON/XOFF handshake, which is extremely important during reception of a hex file, since flash page writes take some more time.
// If you want to terminate a command (e.g. mistyped something) pressing ctrl-c will interrupt command line and the current command will not be executed and  a new prompt comes.
// Few but powerful commands can be entered:
//
// bNN		set baudrate to a new value.
//			NOTE: This command has been removed in V2.9A!!!
//
// mwAAAADD	write byte to address
//			AAAA is a two digit hexadecimal address valule
//			DD is a two digit hexadecimal data value
//			example:		w002a80		writes byte 0x80 to address 0x2a
//			return value:	wAAAADD+		DD is read from the address after the write operation and the + indicates successful operation
//
// mrAAAA		read byte from address
//			AAAA is a two digit hexadecimal address valule
//			example:		r002a		reads byte from address 0x2a
//			return value:	rAAAADD+		DD is the read value from address AAAA and the + indicates successful operation
//
// erAAAA		read byte from eeprom address
//			AAAA is a four digit hexadecimal address value
//			example:		er00a4		reads byte from eeprom address 0x00a4
//			return value:	er00a4DD+		DD is the hexadecimal read value from address AAAA and the '+' indicates successful operation
//
// ewAAAADD	write byte to eeprom address
//			AAAA is a four digit hexadecimal address value
//			DD is a two digit hexadecimal data value
//			example:		ew00a421		writes 0x21 to eeprom address 0x00a4
//			return value:	ew00a4DD+	DD is the hexadecimal read value from address AAAA and the '+' indicates successful operation
//
// pf			write hexfile to flash memory
//			return value:	pf+
//			The + indicates successful interpretation of the command.
//			Now an intel hex file can be send to the MCU over the UART.
//			For every successful read and parsed record line a '.' is printed. When a flash page write is done, a '*' is printed.
//			In case a checksum error is detected in a record line, a '-' is printed and the command is terminated.
//
// pe			write hexfile to eeprom memory
//			return value:	pe+
//			The + indicates successful interpretation of the command.
//			Now an intel hex file can be send to the MCU over the UART.
//			For every successful read and parsed record line a '.' is printed. When a record line was written to eeprom, a '*' is printed.
//			In case a checksum error is detected in a record line, a '-' is printed and the command is terminated.
//
// g			jump to application at bottom of flash
//			return value:	g+
//			The + indicates successful interpretation of the command.
//			All altered IO registers will be reset to it's reset default state and the bootloader jumps to flash address 0x0000 to start the programmed application.
//			Alternatively a reset can be performed.
//
//
// TOOL CHAIN
// - Atmel Studio 6.2 (Version: 6.2.1153)
// - AVR GNU Toolchain 3.4.1056
//
//
// REVISION HISTORY
// The major version number is 2 for chip45boot2, development started with 2.00, since the old chip45boot used version 1.xx
// The minor version number is the revision number from the svn repository.
// 2.53
// - first official release of chip45boot2
//
// 2.82
// - changed line ending of input hex files from '\r' (0x0d) to '\n' (0x0a)
//
// 2.83
// - added the version number to the welcome message
// - change line ending macro from '\n' to hex number 0x0a
// - reverted line endings for character output bach to '\r', only for hex file reading the '\n' should be used
// - use CR and LF macros instead of '\r' and '\n', to be independent of compiler handling
// - the command is now echoed immediately after reading the command and the command handling only appends the + or some return value
//
// 2.87
// - added internal RXD pin pullup activation to make it less sensitive against disturbances of a probably floating pin in the final application
//   accidental high->low transitions after reset could activate the bootloader instead of the application
//
// 2.90
// - renamed many variables and functions to indicate the data type and related module/header file
// - fixed a bug in command line reception
//
// 2.93
// - added short delay before jump to the application (command 'g') to avoid loss of XON transmission due to possible uart init in application
//
// 2.94
// - added cli(); at bootloader start, in case bootloader was called from an application and not due to a reset
// - added TXD pullup at bootloader start to avoid reading of wrong bootloader version by chip45boot2 GUI due to floating pin
//
// 2.95
// - complete rewrite of the startup code, now the timeout covers the full measurement of the U's, hence it is more reliable against disturbances on RXD
//
// 2.96
// - added Xmega128A1 support!
//
// 2.97
// - added check for correct reception of three more U's after baudrate adjustment (to avoid  bootloader start at mistuned baudrate)
//
// 2.98
// - reset PLL factor before jump to application
//
// 2.99
// - added RS485 support
//
// 2.9A
// - added watchdog disable on startup on all targets
// - removed command 'b'
//
// 2.9B
// - changed the RS485 direction control from stupid delay to checking of the transmit complete flag
//
// 2.9C
// - changed Xmega usart initialization with BSCALE=-5 to BSCALE=-4 and adjusted bsel calculation. Now xmega bootloader works down to 9600 baud.
//
// 2.9D
// - added support for xmegaA3 with errata workaround
// - added relocation of int vector table to app after timeout (not only for command 'g')
// - correct clock reset sequence before leaving the bootloader
//
// 2.9E
// - added clearing of WDRF bit in MCUSR
//
// 2.9F
// - added clearing of TCC0.CNT or TCNT1 register before application start
// - corrected clearing of TCC0.CTRLA and CTRLB registers (there was a typo TCC1...)
//
// 2.9G
// - corrected order of arguments in eeprom_write_block(...)
// - added clearing of USART registers before application start
// - added disabling RXD and TXD pull-ups before application start
//
// 2.9H
// - added eeprom_busy_wait() before eeprom_write_block(...)
// - added URSEL to reset of USART registers before application start
//
// 2.9I
// - changed myUSART.CTRLC register reset from 0x06 to 0x03 (the Xmega A Manual has the wrong reset default!)
//
// 2.9J
// - changed application start from goto *0; to app_start(); (goto *0 won't work anymore with the latest GCC version!)
//
// 2.9K
// - setting RS485 direction pin to input before starting application after command 'g' from GUI
//
// 2.9L
// - fix to avoid a page write in case an end-of-file recorde is being received right after the previous page write
//
// 2.9M
// - added EIND=0; for devices with >128k flash, due to GCC not handling EIND correctly before app_start();
//
// 2.9N
// - moved variable definitions from inside main() to outside, made them globally (this fixes a problem with ATxmega128A3 programming just few bytes, due to some compiler issue, maybe a heap vs. stack issue, unclear)
//
// 2.9P (we skip 2.9O since the O looks much like 0 (zero)
// - changed app_start(); call for start of application to ((void (*)())0x0)();, since latest avr-gcc (Studio 6.1) doesn't generate a proper jmp to address zero.

// 2.9Q
// - changed calculation of baud rate register for Xmegas (more precise now) and changed all variable types from e.g. unsigned short to uint16_t (same for 8 and 32 bit types)


///////////////////////////////////////////////////////////////////////////////
// includes
///////////////////////////////////////////////////////////////////////////////

// include system header files
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// include local header files
#include "usart.h"
#include "mcudefs.h"

#ifndef WORKAROUND
	// if workaround is required, we have a similar function in boot.c
	#include <avr/eeprom.h>
#else
	#include <avr/eeprom.h>
#endif

// functions in boot.h are not yet implemented on WinAVR 20100110, so we include our own boot.h
// the functions in the local boot.c are wrapper functions with the same names as the regular boot.h of the avr-libc, but they call the functions of sp_driver.h of AVR1605 app note
#ifdef XMEGA
	#include "boot.h"
#else
	#include <avr/boot.h>
#endif


///////////////////////////////////////////////////////////////////////////////
// definitions
///////////////////////////////////////////////////////////////////////////////

// bootloader uses XON/XOFF handshake
#define XON 17
#define XOFF 19

// other communication characters
#define BREAK 3
#define CARRIAGE_RETURN 0x0d
#define LINE_FEED 0x0a

// define the line ending, make sure to have set your terminal program to match this!
// 0x0a is '\n' - we write the hex number to avoid problems with different compilers handling the '\n' in different ways
#define LINE_ENDING 0x0a

// timeout delay in case we cannot use the watchdog timer (only for old AVRs...)
// newer atmegas use the watchdog timer, xmegas use the rtc timer
#ifndef XMEGA
	#define USART_TIMEOUT 1600000  // ~3 seconds at 8MHz
#endif


///////////////////////////////////////////////////////////////////////////////
// global functions
///////////////////////////////////////////////////////////////////////////////


#ifdef XMEGA
	// no memory saving stuff for xmega, since the bootblock is always at least 4k
#else
// ============================================================================
// the following code is needed to init the chip with (-nostartfiles, -nodefaultlibs) custom init routines
// in: nothing
// out: nothing
// ============================================================================
void _jumpMain(void) __attribute__ ((naked)) __attribute__ ((section (".init9")));

void _jumpMain(void)
{   
	// set stack to end of RAM
	asm volatile ( ".set __stack, %0" :: "i" (RAMEND) );

	// initialize  stack pointer 
	asm volatile ("ldi r28, lo8(__stack)");
	asm volatile ("ldi r29, hi8(__stack)");
	asm volatile ("out %0, r29" :: "i" (_SFR_IO_ADDR(SPH)) );
	asm volatile ("out %0, r28" :: "i" (_SFR_IO_ADDR(SPL)) );

	// GCC depends on register r1 set to 0
	asm volatile ( "clr __zero_reg__" );   

	// set SREG to 0
	asm volatile ( "out %0, __zero_reg__" :: "i" (_SFR_IO_ADDR(SREG)) );

	// jump to main()
	asm volatile ( "rjmp main");
}
#endif


// ============================================================================
// convert hex ascii nibble ('0' - 'f'/'F') into a number
// in: ascii character (nibble) to be converted
// out: 4 bit hex number
// ============================================================================
uint8_t asciiToHex(uint8_t ucNibble) {

	uint8_t ucHex = 0;

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
uint8_t asciiToHex2(uint8_t ucNibbleHigh, uint8_t ucNibbleLow) {
	return (asciiToHex(ucNibbleHigh) << 4) + asciiToHex(ucNibbleLow);  // just call the function for one nibble twice
}


///////////////////////////////////////////////////////////////////////////////
// global variables
///////////////////////////////////////////////////////////////////////////////

#ifdef XMEGA
	uint32_t uxBaudRateDivFactor;
#else
	uint16_t uxBaudRateDivFactor;
#endif
uint8_t ucEepromBuffer[20];  // buffer for 16 bytes to be written to eeprom
uint16_t usPageAddressOffset;  // address offset within the current page
uint32_t ulPageBaseAddress;  // base address of the current flash page
uint16_t usExtSegmentAddress;  // extended segment address in case hex file contains more that 64k of data bytes (i.e. for AVRs with more than 64k flash)
uint8_t ucBuffer[50];  // buffer for command line and hexfile reading ("regular" hexfiles have maximum 44 columns per line, plus some "fear" characters...)
uint8_t ucByteCount;
uint8_t ucRecordType;
uint8_t ucHexRecChecksum;  // checksum from the hex record
uint8_t ucComputedChecksum;  // own computed checksum
uint8_t ucFlagError;
uint8_t ucFlagEof;
uint8_t ucFlagWrite;
uint8_t ucFlagEepromWrite;

	
///////////////////////////////////////////////////////////////////////////////
// main program
///////////////////////////////////////////////////////////////////////////////


// ============================================================================
// main program function
// in: nothing
// out: nothing
// ============================================================================
int main(void) {

	// local variables
	uint8_t ucTmp;
	uint16_t usAddr;
	uint8_t ucDataByte;
	uint8_t ucTmpDataByte;


#ifdef WORKAROUND
	PMIC_SetVectorLocationToBoot();  // locate the interrupt vector table location to bootloader section
#endif

	// disable interrupts globally, in case the bootloader was called from an application and not due to a reset
	cli();


#ifdef XMEGA
	// change the XMega Clock. The controllers starts with 2MHz internal as a default

	// frequency range for external oscillator is not used, we set to default reset value
	OSC.XOSCCTRL = 0;	

	// switch to internal 2MHz oscillator, in case we come from application
	OSC.CTRL = (1<<OSC_RC2MEN_bp) | (1<<OSC_RC32KEN_bp);  // also enable the 32kHz RTC oscillator

	// configure the PLL
	// clock source - internal 2MHz RC clock source / PLL faktor x8
	OSC.PLLCTRL = (0b00<<OSC_PLLSRC_gp) | (8<<OSC_PLLFAC_gp);	
	// enable the PLL
	OSC.CTRL |= (1<<OSC_PLLEN_bp);	// enable the PLL

	// wait for the PLL to lock on the external oscillator
	while ((OSC.STATUS & (1<<OSC_PLLRDY_bp)) == 0);

	// switch the system clock from the 2MHz internal to the PLL created 16MHz;
	CCP = CCP_IOREG_gc;						// enable the change of a protected register
	CLK.CTRL = (0b100<<CLK_SCLKSEL_gp);		// PLL - Phase Locked Loop

#else
	// For normal AVRs we do not do any clock settings, since there is not much to do in software.
	// Clock setting is done by fusebits.

#endif

	// activate the internal IO pin pullup on the RXD pin to make it less sensitive for disturbances in case the pin is floating in the final application
	// accidental high->low transistions after reset might activate the bootloader unwantedly
	// also enable the TXD pullup, this avoids reading of a wrong bootloader version from the PC application due to interpreting low TXD as startbits and so on
#ifdef XMEGA
	myRXD_PINCTRL = PORT_OPC_PULLUP_gc;  // RXD gets a pullup
	myTXD_PINCTRL = PORT_OPC_PULLUP_gc;  // and TXD as well
	myTXD_DIRSET = (1<<myTXD);  // set TXD to output
	#ifdef RS485
	myDIR_DIRSET = (1<<myDIR);  // RS485 direction pin is output
	myDIR_OUTCLR = (1<<myDIR);  // pin is low -> RS485 receiver enable
	#endif
#else
	myRXDPORT |= ( (1<<myRXD) | (1<<myTXD) );  // both RXD and TXD get a pullup
	#ifdef RS485
	myDIRDDR |= (1<<myDIR);  // RS485 direction pin is output
	myDIRPORT &= ~(1<<myDIR);  // pin is low -> RS485 receiver enable
	#endif
#endif


#ifdef XMEGA
	// we use timer 0 for baudrate measurement
	TCC0.CTRLA = 1;  // turn timer on and no prescaler
	TCC0.CTRLB = TC_WGMODE_NORMAL_gc;  // normal mode
	TCC0.CTRLC = 0;  // no compare outputs
	TCC0.CTRLD = 0;  // we do not use events
	TCC0.CTRLE = 0;  // no byte mode
#else
	// init timer 1 (should be available on almost any AVR)
	// no prescaler, since we want to measure the RXD timing precisely
	TCCR1A = 0;  // normal mode
	TCCR1B = 1;
#endif

	
#ifdef XMEGA  // on Xmegas we do not use the watchdog for timeout, but the RTC clock
	CLK.RTCCTRL = (1<<CLK_RTCEN_bp) | (CLK_RTCSRC_RCOSC_gc);  // enable RTC clock and run with 1kHz
	#ifdef _AVR_ATxmega256A3B_H_
		RTC32.COMP = 3000;  // ~3secs
		RTC32.CTRL = 1;  // no prescaler
		RTC32.CNT = 0;  // clear counter
	#else
		RTC.COMP = 3000;  // ~3secs
		RTC.CTRL = 1;  // no prescaler
		RTC.CNT = 0;  // clear counter
	#endif
	// but nevertheless we try to disable a software activated watchdog!
	CCP = 0xD8;  // magic number for protected IO register
	WDT.CTRL = (0<<WDT_ENABLE_bp) | (1<<WDT_CEN_bp);  // set enable bit to zero at the same time with change enable bit
#else
	#ifdef WATCHDOG  // we may use the watchdog timer for timeout of RXD synchronisation only on modern CPUs with watchdog interrupt
		// init watchdog timer
		MCUSR &= ~(1<<WDRF);  // disable the WDRF flag, otherwise disabling WDE won't work
		WDTCSR |= (1<<WDCE) | (1<<WDE);	// timed sequence
		WDTCSR = (1<<WDIE) | (6<<WDP0);  // let the watchdog timer run with 2 seconds timeout and enable watchdog interrupt

	#else  // otherwise we use timer 1 (timeout depends on CPU clock) but we also try to disable the watchdog
		myMCUSR &= ~(1<<WDRF);  // disable the WDRF flag, otherwise disabling WDE won't work
		WDTCR |= (1<<myWDCE) | (1<<WDE);	// timed sequence
		WDTCR = 0;  // disable the watchdog
		uint32_t ulTimeoutCounter = 0;  // we need a long timeout counter
	#endif
#endif

	
	// now we try to measure the baud rate!
	// loop 17 times (i.e. ~four characters) and measure the low time between falling and rising edges
	// we drop the first measurement, so we divide by 16 later
	ucTmp = 17;  
	uxBaudRateDivFactor = 0;  // clear variable
	uint8_t ucFlagTimeout = 0;  // clear timeout flag
	do {

		// wait for low level with timeout
#ifdef XMEGA
		while(bit_is_set(myRXD_IN, myRXD)) {
#else	
		while(bit_is_set(myRXDPIN, myRXD)) {
#endif

			// check for timeout
#ifdef XMEGA
			#ifdef _AVR_ATxmega256A3B_H_
				if(bit_is_set(RTC32.INTFLAGS, RTC32_COMPIF_bp)) {  // on xmegas we use RTC timer for 3sec timeout
			#else
				if(bit_is_set(RTC.INTFLAGS, RTC_COMPIF_bp)) {  // on xmegas we use RTC timer for 3sec timeout
			#endif
#else
	#ifdef WATCHDOG
			if(bit_is_set(WDTCSR, WDIF)) {  // if we can use watchdog timer, we check it's interrupt bit
	#else
			if( (++ulTimeoutCounter) > (uint32_t)USART_TIMEOUT) {  // if not, we use a simple counter
	#endif
#endif
				ucFlagTimeout = 1;  // set timeout flag
				break;
			}
		}

#ifdef XMEGA
		TCC0.CNT = 0;  // clear timer
#else
		TCNT1 = 0;  // clear timer
#endif

		
		// wait for high level with timeout
#ifdef XMEGA
		while(bit_is_clear(myRXD_IN, myRXD)) {
#else	
		while(bit_is_clear(myRXDPIN, myRXD)) {
#endif

			// check for timeout
#ifdef XMEGA
			#ifdef _AVR_ATxmega256A3B_H_
				if(bit_is_set(RTC32.INTFLAGS, RTC32_COMPIF_bp)) {  // on xmegas we use RTC timer for 3sec timeout
			#else
				if(bit_is_set(RTC.INTFLAGS, RTC_COMPIF_bp)) {  // on xmegas we use RTC timer for 3sec timeout
			#endif
#else
	#ifdef WATCHDOG
			if(bit_is_set(WDTCSR, WDIF)) {  // if we can use watchdog timer, we check it's interrupt bit
	#else
			if( (++ulTimeoutCounter) > (uint32_t)USART_TIMEOUT) {  // if not, we use a simple counter
	#endif
#endif
				ucFlagTimeout = 1;  // set timeout flag
				break;
			}
		}
		// we ignore the first measurement, since it might have started somewhere within the low phase
		if(ucTmp < 17) {
#ifdef XMEGA
			uxBaudRateDivFactor += TCC0.CNT;  // add timer value to variable
#else
			uxBaudRateDivFactor += TCNT1;  // add timer value to variable
#endif
		}
		
	} while( (--ucTmp) && (ucFlagTimeout == 0) );


#ifdef WATCHDOG  // watchdog only on newer MCUs, see above
	WDTCSR |= (1<<WDCE) | (1<<WDE);  // timed sequence
	WDTCSR = 0;  // clear watchdog activities
#endif

	// if we had a timeout, we jump to 0x0000
TIMEOUT_CHECK:
	if(ucFlagTimeout == 1) {  // no edge detected

#ifdef XMEGA
		TCC0.CTRLA = 0;  // stop timer
		TCC0.CTRLB = 0;
		TCC0.CNT = 0;  // clear counter register
		myRXD_PINCTRL = PORT_OPC_TOTEM_gc;  // RXD goes back to regular totem pole mode
		myTXD_PINCTRL = PORT_OPC_TOTEM_gc;  // and TXD as well
		myUSART.CTRLA = 0x00;
		myUSART.CTRLB = 0x00;
		myUSART.CTRLC = 0x03;
		myUSART.BAUDCTRLA = 0x00;
		myUSART.BAUDCTRLB = 0x00;	

#else
		TCCR1B = 0;  // stop the timer 1 and set register to reset default
		TCNT1 = 0;  // clear counter register
		myRXDPORT &= ~( (1<<myRXD) | (1<<myTXD) );  // disable the pullups
		myUBRRH = 0;
		myUBRRL = 0;
		myUCSRB = 0;
		myUCSRC = myURSEL | 6;
#endif


#ifdef XMEGA
#ifdef WORKAROUND
		PMIC_SetVectorLocationToApplication();  // relocate the interrupt vector table location to application section
#endif
		#ifdef _AVR_ATxmega256A3B_H_
			RTC32.CTRL = 0;  // disable RTC timer
		#else
			RTC.CTRL = 0;  // disable RTC timer
		#endif
		EIND = 0x00;  // set Extended Indirect Jump register to zero
		// change the XMega Clock back to 2MHz
		CCP = CCP_IOREG_gc;  // enable the change of a protected register
		CLK.CTRL = 0;  // set clock source to 2MHz RC oscillator
		asm volatile ("nop");
        OSC.CTRL &= ~(1<<OSC_PLLEN_bp);   // disable the PLL
        OSC.PLLCTRL = 0;  // PLL factor reset
        OSC.CTRL = (1<<OSC_RC2MEN_bp);  // 2MHz RC and no pll
#endif
		#if (BOOTADDR >= 0x20000)
			EIND = 0;
		#endif
		((void (*)())0x0)();  // jump to bottom of flash, i.e. start of application
	}


	// divide usBaudRateDivFactor by 16 to get the average value
	uxBaudRateDivFactor >>= 4;


	// short delay to make sure the trailing edges of the remaining data bits and stop bit are gone
	_delay_ms(10);


	// intialize usart with the above calculated baudrate factor
	usartInit(uxBaudRateDivFactor);


	// check if we can receive three U's at the calculated baud rate
	ucTmp = usartGetChar();  // dump the first received character, since it might be garbage directly after USART initialization
	if(usartGetChar() == 'U')
		if(usartGetChar() == 'U')
			if(usartGetChar() == 'U')
				goto CORRECT;  // jump to label
	ucFlagTimeout = 1;  // set timeout flag and
	goto TIMEOUT_CHECK;  // jump to previous flag check (this avoid additional code for register default setting here)
CORRECT:


#ifdef RS485
	while(usartGetChar() == 'U');  // wait as long as we still receive U's (other side has to send any other character to proceed to welcome message)
#ifdef XMEGA
	myDIR_OUTSET = (1<<myDIR);  // set RS485 direction to output
#else
	myDIRPORT |= (1<<myDIR);  // set RS485 direction to output
#endif
#endif


	// welcome!
	// we use usartPutChar's instead of usartPutRamStr(""), because it makes problems with -nostartfiles linker option to save space
	usartPutChar('c');
	usartPutChar('4');
	usartPutChar('5');
	usartPutChar('b');
	usartPutChar('2');
	usartPutChar(' ');
	usartPutChar('v');
	usartPutChar('2');
	usartPutChar('.');
	usartPutChar('9');
	usartPutChar('Q');

	// init the buffer to empty buffer
	ucBuffer[0] = 0;


	// main loop
	while(1) {

#ifdef RS485
#ifdef XMEGA
		myDIR_OUTSET = (1<<myDIR);  // set RS485 direction to output
#else
		myDIRPORT |= (1<<myDIR);  // set RS485 direction to output
#endif
#endif

		// show a prompt
		usartPutChar(CARRIAGE_RETURN);
		usartPutChar('>');
		usartPutChar(XON);  // send XON to allow transmission

		
#ifdef RS485
#ifdef XMEGA
		myUSART.STATUS |= (1<<USART_TXCIF_bp);  // clear transmit complete flag
		loop_until_bit_is_set(myUSART.STATUS, USART_TXCIF_bp);  // and wait until flag is set
		myDIR_OUTCLR = (1<<myDIR);  // set RS485 direction to input
#else
		myUCSRA |= (1<<myTXC);  // clear transmit complete flag
		loop_until_bit_is_set(myUCSRA, myTXC);  // and wait until flag is set
		myDIRPORT &= ~(1<<myDIR);  // set RS485 direction to input
#endif
#endif

		// read one line from uart until line ending
		ucTmp = 0;
		do {
			// we have to ignore U's, which might be in the buffer due to holding U-key pressed too long.
			// loop until we receive other characters than a 'U'
			do {
				ucBuffer[ucTmp] = usartGetChar();
			} while(ucBuffer[ucTmp] == 'U');
			// if ctrl-c was pressed, we do not process the command
			if(ucBuffer[ucTmp] == BREAK) {
				ucBuffer[0] = 'X';  // set first character to 'X' to avoid any case match in switch
				break;
			}
		} while(ucBuffer[ucTmp++] != LINE_ENDING);
		ucBuffer[ucTmp-1] = 0;  // terminate the string at the new line position
		if(ucBuffer[ucTmp-2] == 0x0d) {  // if there was a carriage return before the new line, clear it too.
			ucBuffer[ucTmp-2] = 0;
		}

#ifdef RS485
#ifdef XMEGA
		myDIR_OUTSET = (1<<myDIR);  // set RS485 direction to output
#else
		myDIRPORT |= (1<<myDIR);  // set RS485 direction to output
#endif
#endif

		usartPutChar(XOFF);  // send XOFF to pause transmission
		usartPutRamStr(ucBuffer);  // echo the command

		// parse first character of command buffer
		switch(ucBuffer[0]) {
			
			// jump to application at flash start 0x0000
			case 'g':
				usartPutChar('+');
				usartPutChar(CARRIAGE_RETURN);
				usartPutChar(XON);
				_delay_ms(10);  // wait until last character is transmitted to avoid loss of XON due to uart initialization in main application
#ifdef XMEGA
				TCC0.CTRLA = 0;  // stop timer
				TCC0.CTRLB = 0;
				TCC0.CNT = 0;  // clear counter register
				#ifdef RS485
				myDIR_OUTCLR = (1<<myDIR);  // set RS485 direction to input
				#endif
				myRXD_PINCTRL = PORT_OPC_TOTEM_gc;  // RXD goes back to regular totem pole mode
				myTXD_PINCTRL = PORT_OPC_TOTEM_gc;  // and TXD as well
				myUSART.CTRLA = 0x00;
				myUSART.CTRLB = 0x00;
				myUSART.CTRLC = 0x03;
				myUSART.BAUDCTRLA = 0x00;
				myUSART.BAUDCTRLB = 0x00;	
#ifdef WORKAROUND
				PMIC_SetVectorLocationToApplication();  // relocate the interrupt vector table location to application section
#endif
				#ifdef _AVR_ATxmega256A3B_H_
					RTC32.CTRL = 0;  // disable RTC timer
				#else
					RTC.CTRL = 0;  // disable RTC timer
				#endif
				EIND = 0x00;
				// change the XMega Clock back to 2MHz
				CCP = CCP_IOREG_gc;  // enable the change of a protected register
				CLK.CTRL = 0;  // set clock source to 2MHz RC oscillator
				asm volatile ("nop");
				OSC.CTRL &= ~(1<<OSC_PLLEN_bp);   // disable the PLL
				OSC.PLLCTRL = 0;  // PLL factor reset
				OSC.CTRL = (1<<OSC_RC2MEN_bp);  // 2MHz RC and no pll
#else
				TCCR1B = 0;  // stop the timer 1 and set register to reset default
				TCNT1 = 0;  // clear counter register
				#ifdef RS485
				myDIRPORT &= ~(1<<myDIR);  // pin is low -> RS485 receiver enable
				#endif
				myRXDPORT &= ~( (1<<myRXD) | (1<<myTXD) );  // disable the pullups
				myUBRRH = 0;
				myUBRRL = 0;
				myUCSRB = 0;
				myUCSRC = myURSEL | 6;
#endif
				#if (BOOTADDR >= 0x20000)
					EIND = 0;
				#endif
				((void (*)())0x0)();  // jump to bottom of flash, i.e. start of application
				break;

			// read or write single byte to eeprom or memory
			case 'e':
			case 'm':
				ucTmp = asciiToHex2(ucBuffer[2], ucBuffer[3]);  // get the address high byte
				usAddr = (ucTmp << 8) + asciiToHex2(ucBuffer[4], ucBuffer[5]);  // get the address low byte
				if(ucBuffer[1] == 'w') {  // we want to write
					ucTmp = asciiToHex2(ucBuffer[6], ucBuffer[7]);  // get the data to write
					// we write to eeprom
					if(ucBuffer[0] == 'e') {
						eeprom_busy_wait();  // wait in case eeprom is busy
						eeprom_write_byte((uint8_t*)usAddr, ucTmp);  // write cell
					}
					// we write to ram
					if(ucBuffer[0] == 'm') {
						*(uint8_t*)usAddr = ucTmp;  // write data directly to destination address
					}
				}
				// read (back) from the address in eeprom or ram
				if(ucBuffer[0] == 'e') {
					ucTmp = eeprom_read_byte((uint8_t*)usAddr);  // read cell
				} else {
					ucTmp = *(uint8_t*)usAddr;  // read destination
				}
				usartPutChar('+');
				usartPutChar(CARRIAGE_RETURN);
				usartPutHex(ucTmp);  // and print the read back value
				break;
				
			// read hex file and write to flash or eeprom memory
			case 'p':
				usartPutChar('+');
				usartPutChar(CARRIAGE_RETURN);
				
				ucFlagEepromWrite = 0;  // default is flash programming
				if(ucBuffer[1] == 'e') {  // except we received an 'e' as second character
					ucFlagEepromWrite = 1;  // set eeprom flag
				}
				
				ulPageBaseAddress = 0xffffffff;  // preset page base address to impossible value
				usPageAddressOffset = 0;  // clear offset
				usExtSegmentAddress = 0;  // clear segment address
				
				do {
				
					ucFlagError = 0;  // clear error flag
					ucFlagEof = 0;  // clear end-of-file flag
					ucFlagWrite = 0;  // clear write flag
					
					// read one line from hex file into the buffer
					usartPutChar(XON);
#ifdef RS485
#ifdef XMEGA
					myUSART.STATUS |= (1<<USART_TXCIF_bp);  // clear transmit complete flag
					loop_until_bit_is_set(myUSART.STATUS, USART_TXCIF_bp);  // and wait until flag is set
					myDIR_OUTCLR = (1<<myDIR);  // set RS485 direction to input
#else
					myUCSRA |= (1<<myTXC);  // clear transmit complete flag
					loop_until_bit_is_set(myUCSRA, myTXC);  // and wait until flag is set
					myDIRPORT &= ~(1<<myDIR);  // set RS485 direction to input
#endif
#endif
					ucTmp = 0;
					do {
						ucBuffer[ucTmp] = usartGetChar();
					} while(ucBuffer[ucTmp++] != LINE_ENDING);
#ifdef RS485
#ifdef XMEGA
					myDIR_OUTSET = (1<<myDIR);  // set RS485 direction to output
#else
					myDIRPORT |= (1<<myDIR);  // set RS485 direction to output
#endif
#endif
					usartPutChar(XOFF);  // send XOFF to pause transmission
					ucBuffer[ucTmp-1] = 0;

					// grab hex record information, like byte count, address and type of record
					ucByteCount = asciiToHex2(ucBuffer[1], ucBuffer[2]);  // get the number of bytes
					ucComputedChecksum = ucByteCount;  // compute checksum
					usAddr = asciiToHex2(ucBuffer[3], ucBuffer[4]);  // get the address high byte
					ucComputedChecksum += (uint8_t)usAddr;  // compute checksum
					usAddr = (usAddr << 8) + asciiToHex2(ucBuffer[5], ucBuffer[6]);  // get the address low byte
					ucComputedChecksum += (uint8_t)(usAddr & 0xff);  // compute checksum
					ucRecordType = asciiToHex2(ucBuffer[7], ucBuffer[8]);  // get the record type
					ucComputedChecksum += ucRecordType;  // compute checksum
					ucHexRecChecksum = asciiToHex2(ucBuffer[(ucByteCount*2)+9], ucBuffer[(ucByteCount*2)+10]);  // get the checksum
					
					// check the record type
					if(ucRecordType == 2) {  // extendes segment address record
						usExtSegmentAddress = asciiToHex2(ucBuffer[9], ucBuffer[10]) << 8;
						ucComputedChecksum += (usExtSegmentAddress >> 8);  // compute checksum
						usExtSegmentAddress += asciiToHex2(ucBuffer[11], ucBuffer[12]);
						ucComputedChecksum += (usExtSegmentAddress & 0xff);  // compute checksum
					
					} else if(ucRecordType == 1) {  // end of file record
						ucFlagEof = 1;
						ucFlagWrite = 1;
						
					} else if(ucRecordType == 0) {  // data record
					
						// set base address for the flash page, if not set
						if(ulPageBaseAddress == 0xffffffff) {
							ulPageBaseAddress = usAddr;
						}
						
						// parse the data bytes
						for(ucTmp = 0; ucTmp < (2*ucByteCount); ucTmp += 4) {  // increment by four, since we parse the ascii buffer for four ascii character (i.e. two hex numbers)
							ucDataByte = asciiToHex2(ucBuffer[ucTmp+9], ucBuffer[ucTmp+10]);  // get the low data byte
							ucComputedChecksum += ucDataByte;  // compute checksum
							ucTmpDataByte = asciiToHex2(ucBuffer[ucTmp+11], ucBuffer[ucTmp+12]);  // get the high data byte
							ucComputedChecksum += ucTmpDataByte;  // compute checksum
							if(ucFlagEepromWrite == 1) {  // if we want to program eeprom, we store the data in another buffer
								ucEepromBuffer[usPageAddressOffset] = ucDataByte;
								ucEepromBuffer[usPageAddressOffset+1] = ucTmpDataByte;
							} else {  // flash programming
								boot_page_fill((uint32_t)(ulPageBaseAddress + usPageAddressOffset + usExtSegmentAddress * 16), (((uint16_t)ucTmpDataByte) << 8) + (((uint16_t)ucDataByte) & 0x00ff)); 
							}
							usPageAddressOffset += 2;
						}
						
					}
					
					// check checksum
					if((uint8_t)(ucComputedChecksum + ucHexRecChecksum) != 0x00) {  // computed checksum plus checksum from hexfile must be zero
						ucFlagError = 1;
						break;  // leave do loop, we do not program anything in case we get a checksum error
					}
					
					usartPutChar('.');  // progress indicator
					
					// check if page is filled, if so, we set the write flag
					if(usPageAddressOffset >= SPM_PAGESIZE) {
						ucFlagWrite = 1;
					}
					if(ucFlagEepromWrite == 1) {
						ucFlagWrite = 1;
					}
					
					
					// check if write flag is set
					if((ucFlagWrite == 1) && (ulPageBaseAddress != 0xffffffff)) {
						ulPageBaseAddress += ((uint32_t)usExtSegmentAddress * 16);  // add the extended segment address to the base address

						if(ucFlagEepromWrite == 1) {  // we want to write eeprom
							/*for(ucTmp = 0; ucTmp < usPageAddressOffset; ++ucTmp) {
								eeprom_busy_wait();  // wait in case eeprom is busy
								eeprom_write_byte((uint8_t*)(uint16_t)(ulPageBaseAddress+ucTmp), ucEepromBuffer[ucTmp]);  // write cell
							}*/
							eeprom_busy_wait();  // wait in case eeprom is busy
							eeprom_write_block(ucEepromBuffer, (uint8_t*)(uint16_t)ulPageBaseAddress, usPageAddressOffset);
						} else {  // we want to write flash

							// check if page base address exceeds maximum address before bootloader section begins (BOOTADDR comes from -D compiler option)
							if(ulPageBaseAddress >= (uint32_t)BOOTADDR) {
								ucFlagError = 1;
								break;
							}
						
							boot_page_erase((uint32_t)ulPageBaseAddress);  // do a page erase
							boot_spm_busy_wait();  // wait for page erase done
							boot_page_write((uint32_t)ulPageBaseAddress);  // do a page write
							boot_spm_busy_wait();  // wait for write completed
							boot_rww_enable();  // reenable rww section again
						}
						usartPutChar('*');  // * indicates a page write
						ulPageBaseAddress = 0xffffffff;
						usPageAddressOffset = 0;
					}
					
				} while(!ucFlagError && !ucFlagEof);  // in case of retval or end of file
				
				// test on error and print + or -
				if(!ucFlagError) {
					usartPutChar('+');
				} else {
					usartPutChar('-');
				}
				
				break;
			
			// no case found, so we return a fail indicator '-'
			default:
				usartPutChar('-');
		
		}
		
	}

	return 0;  // program should never come here...
}

// end of file: main.c
