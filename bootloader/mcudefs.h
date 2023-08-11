// mcudefs.h
//
// MCU register definitions or the usart registers and for the rxd pin
// MCU types which can use the watchdog timer for interrupt generation get a #define WATCHDOG
// this allows for a more precise 3 secs timeout than the delay functions


// make sure to include just once!
#ifndef _MCUDEFS_
#define _MCUDEFS_


// set of definition for ATmega8
#ifdef __AVR_ATmega8__
	#define myMCUSR MCUCSR
	#define myWDCE WDCE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL (1<<URSEL) // MCU requires this bit
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN4
#endif

// set of definition for ATmega88
#ifdef __AVR_ATmega88__
	#define WATCHDOG
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN4
#endif

// set of definition for ATmega88P
#ifdef __AVR_ATmega88P__
	#define WATCHDOG
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN4
#endif

// set of definition for ATmega8515
#ifdef __AVR_ATmega8515__
	#define myMCUSR MCUCSR
	#define myWDCE WDCE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL (1<<URSEL) // MCU requires this bit
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN4
#endif

// set of definition for ATmega8535
#ifdef __AVR_ATmega8535__
	#define myMCUSR MCUCSR
	#define myWDCE WDCE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL (1<<URSEL) // MCU requires this bit
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRB
	#define myDIRPORT PORTB
	#define myDIR PIN0
#endif

// set of definition for ATmega16
#ifdef __AVR_ATmega16__
	#define myMCUSR MCUCSR
	#define myWDCE WDTOE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL (1<<URSEL) // MCU requires this bit
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRB
	#define myDIRPORT PORTB
	#define myDIR PIN0
#endif

// set of definition for ATmega16AP
#ifdef __AVR_ATmega16A__
	#define myMCUSR MCUCSR
	#define myWDCE WDTOE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL (1<<URSEL) // MCU requires this bit
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRB
	#define myDIRPORT PORTB
	#define myDIR PIN0
#endif

// set of definition for ATmega162
#ifdef __AVR_ATmega162__
	#define myMCUSR MCUCSR
	#define myWDCE WDCE
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL (1<<URSEL0) // MCU requires this bit
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL (1<<URSEL1) // MCU requires this bit
		#define myRXDPIN PINB
		#define myRXDPORT PORTB
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN4
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega164a
#ifdef _AVR_IOM164_H_
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRB
		#define myDIRPORT PORTB
		#define myDIR PIN0
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN4
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega164P
#ifdef __AVR_ATmega164P__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRB
		#define myDIRPORT PORTB
		#define myDIR PIN0
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN4
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega165
#ifdef __AVR_ATmega165__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL 1
	#define myRXDPIN PINE
	#define myRXDPORT PORTE
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRE
	#define myDIRPORT PORTE
	#define myDIR PIN2
#endif

// set of definition for ATmega168
#ifdef __AVR_ATmega168__
	#define WATCHDOG
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN4
#endif

// set of definition for ATmega168P
#ifdef __AVR_ATmega168P__
	#define WATCHDOG
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN4
#endif

// set of definition for ATmega32
#ifdef __AVR_ATmega32__
	#define myMCUSR MCUCSR
	#define myWDCE WDTOE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL (1<<URSEL) // MCU requires this bit
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRB
	#define myDIRPORT PORTB
	#define myDIR PIN0
#endif

// set of definition for ATmega324P
#ifdef __AVR_ATmega324P__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRB
		#define myDIRPORT PORTB
		#define myDIR PIN0
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN4
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega325
#ifdef __AVR_ATmega325__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0
	#define myRXDPIN PINE
	#define myRXDPORT PORTE
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRE
	#define myDIRPORT PORTE
	#define myDIR PIN2
#endif

// set of definition for ATmega3250
#ifdef __AVR_ATmega3250__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0
	#define myRXDPIN PINE
	#define myRXDPORT PORTE
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRE
	#define myDIRPORT PORTE
	#define myDIR PIN2
#endif

// set of definition for ATmega328
#ifdef __AVR_ATmega328__
	#define WATCHDOG
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN4
#endif

// set of definition for ATmega328P
#ifdef __AVR_ATmega328P__
	#define WATCHDOG
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN4
#endif

// set of definition for ATmega3290P
#ifdef __AVR_ATmega3290P__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PINE
	#define myRXDPORT PORTE
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRE
	#define myDIRPORT PORTE
	#define myDIR PIN2
#endif

// set of definition for ATmega32U4
#ifdef _AVR_IOM32U4_H_
	#define WATCHDOG
	#define myUDR   UDR1
	#define myUBRRH UBRR1H
	#define myUBRRL UBRR1L
	#define myUCSRA UCSR1A
	#define myUCSRB UCSR1B
	#define myUCSRC UCSR1C
	#define myUDRE  UDRE1
	#define myRXC   RXC1
	#define myTXC	TXC1
	#define myRXEN  RXEN1
	#define myTXEN  TXEN1
	#define myUCSZ0 UCSZ10
	#define myUCSZ1 UCSZ11
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN2
	#define myTXD PIN3
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN5
#endif

// set of definition for ATmega64
#ifdef __AVR_ATmega64__
	#define myMCUSR MCUCSR
	#define myWDCE WDCE
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega640
#ifdef __AVR_ATmega640__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUDR   UDR2
		#define myUBRRH UBRR2H
		#define myUBRRL UBRR2L
		#define myUCSRA UCSR2A
		#define myUCSRB UCSR2B
		#define myUCSRC UCSR2C
		#define myUDRE  UDRE2
		#define myRXC   RXC2
		#define myTXC	TXC2
		#define myRXEN  RXEN2
		#define myTXEN  TXEN2
		#define myUCSZ0 UCSZ20
		#define myUCSZ1 UCSZ21
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINH
		#define myRXDPORT PORTH
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRH
		#define myDIRPORT PORTH
		#define myDIR PIN2
	#elif(SERIALPORT == 3)
		#define myUDR   UDR3
		#define myUBRRH UBRR3H
		#define myUBRRL UBRR3L
		#define myUCSRA UCSR3A
		#define myUCSRB UCSR3B
		#define myUCSRC UCSR3C
		#define myUDRE  UDRE3
		#define myRXC   RXC3
		#define myTXC	TXC3
		#define myRXEN  RXEN3
		#define myTXEN  TXEN3
		#define myUCSZ0 UCSZ30
		#define myUCSZ1 UCSZ31
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINJ
		#define myRXDPORT PORTJ
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRJ
		#define myDIRPORT PORTJ
		#define myDIR PIN2
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega644
#ifdef __AVR_ATmega644__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRB
		#define myDIRPORT PORTB
		#define myDIR PIN0
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega644A
#ifdef __AVR_ATmega644A__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRB
		#define myDIRPORT PORTB
		#define myDIR PIN0
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN4
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega644P
#ifdef __AVR_ATmega644P__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRB
		#define myDIRPORT PORTB
		#define myDIR PIN0
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN4
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega645
#ifdef __AVR_ATmega645__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0
	#define myRXDPIN PINE
	#define myRXDPORT PORTE
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRE
	#define myDIRPORT PORTE
	#define myDIR PIN2
#endif

// set of definition for ATmega645
#ifdef __AVR_ATmega6450__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#define myUDR   UDR0
	#define myUBRRH UBRR0H
	#define myUBRRL UBRR0L
	#define myUCSRA UCSR0A
	#define myUCSRB UCSR0B
	#define myUCSRC UCSR0C
	#define myUDRE  UDRE0
	#define myRXC   RXC0
	#define myTXC	TXC0
	#define myRXEN  RXEN0
	#define myTXEN  TXEN0
	#define myUCSZ0 UCSZ00
	#define myUCSZ1 UCSZ01
	#define myURSEL 0
	#define myRXDPIN PINE
	#define myRXDPORT PORTE
	#define myRXD PIN0
	#define myTXD PIN1
	#define myDIRDDR DDRE
	#define myDIRPORT PORTE
	#define myDIR PIN2
#endif

// set of definition for ATmega128
#ifdef __AVR_ATmega128__
	#define myMCUSR MCUCSR
	#define myWDCE WDCE
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega128rfa1
#ifdef __AVR_ATmega128RFA1__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega1280
#ifdef __AVR_ATmega1280__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUDR   UDR2
		#define myUBRRH UBRR2H
		#define myUBRRL UBRR2L
		#define myUCSRA UCSR2A
		#define myUCSRB UCSR2B
		#define myUCSRC UCSR2C
		#define myUDRE  UDRE2
		#define myRXC   RXC2
		#define myTXC	TXC2
		#define myRXEN  RXEN2
		#define myTXEN  TXEN2
		#define myUCSZ0 UCSZ20
		#define myUCSZ1 UCSZ21
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINH
		#define myRXDPORT PORTH
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRH
		#define myDIRPORT PORTH
		#define myDIR PIN2
	#elif(SERIALPORT == 3)
		#define myUDR   UDR3
		#define myUBRRH UBRR3H
		#define myUBRRL UBRR3L
		#define myUCSRA UCSR3A
		#define myUCSRB UCSR3B
		#define myUCSRC UCSR3C
		#define myUDRE  UDRE3
		#define myRXC   RXC3
		#define myTXC	TXC3
		#define myRXEN  RXEN3
		#define myTXEN  TXEN3
		#define myUCSZ0 UCSZ30
		#define myUCSZ1 UCSZ31
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINJ
		#define myRXDPORT PORTJ
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRJ
		#define myDIRPORT PORTJ
		#define myDIR PIN2
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega1281
#ifdef __AVR_ATmega1281__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega1284
#ifdef __AVR_ATmega1284__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRB
		#define myDIRPORT PORTB
		#define myDIR PIN0
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN4
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega1284P
#ifdef __AVR_ATmega1284P__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRB
		#define myDIRPORT PORTB
		#define myDIR PIN0
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN4
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega2560
#ifdef __AVR_ATmega2560__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUDR   UDR2
		#define myUBRRH UBRR2H
		#define myUBRRL UBRR2L
		#define myUCSRA UCSR2A
		#define myUCSRB UCSR2B
		#define myUCSRC UCSR2C
		#define myUDRE  UDRE2
		#define myRXC   RXC2
		#define myTXC	TXC2
		#define myRXEN  RXEN2
		#define myTXEN  TXEN2
		#define myUCSZ0 UCSZ20
		#define myUCSZ1 UCSZ21
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINH
		#define myRXDPORT PORTH
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRH
		#define myDIRPORT PORTH
		#define myDIR PIN2
	#elif(SERIALPORT == 3)
		#define myUDR   UDR3
		#define myUBRRH UBRR3H
		#define myUBRRL UBRR3L
		#define myUCSRA UCSR3A
		#define myUCSRB UCSR3B
		#define myUCSRC UCSR3C
		#define myUDRE  UDRE3
		#define myRXC   RXC3
		#define myTXC	TXC3
		#define myRXEN  RXEN3
		#define myTXEN  TXEN3
		#define myUCSZ0 UCSZ30
		#define myUCSZ1 UCSZ31
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINJ
		#define myRXDPORT PORTJ
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRJ
		#define myDIRPORT PORTJ
		#define myDIR PIN2
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATmega2561
#ifdef __AVR_ATmega2561__
	#define WATCHDOG
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for AT90CAN32
#ifdef __AVR_AT90CAN32__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for AT90CAN64
#ifdef __AVR_AT90CAN64__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for AT90CAN128
#ifdef __AVR_AT90CAN128__
	#define myMCUSR MCUSR
	#define myWDCE WDCE
	#if(SERIALPORT == 0)
		#define myUDR   UDR0
		#define myUBRRH UBRR0H
		#define myUBRRL UBRR0L
		#define myUCSRA UCSR0A
		#define myUCSRB UCSR0B
		#define myUCSRC UCSR0C
		#define myUDRE  UDRE0
		#define myRXC   RXC0
		#define myTXC	TXC0
		#define myRXEN  RXEN0
		#define myTXEN  TXEN0
		#define myUCSZ0 UCSZ00
		#define myUCSZ1 UCSZ01
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PINE
		#define myRXDPORT PORTE
		#define myRXD PIN0
		#define myTXD PIN1
		#define myDIRDDR DDRE
		#define myDIRPORT PORTE
		#define myDIR PIN2
	#elif(SERIALPORT == 1)
		#define myUDR   UDR1
		#define myUBRRH UBRR1H
		#define myUBRRL UBRR1L
		#define myUCSRA UCSR1A
		#define myUCSRB UCSR1B
		#define myUCSRC UCSR1C
		#define myUDRE  UDRE1
		#define myRXC   RXC1
		#define myTXC	TXC1
		#define myRXEN  RXEN1
		#define myTXEN  TXEN1
		#define myUCSZ0 UCSZ10
		#define myUCSZ1 UCSZ11
		#define myURSEL 0          // MCU type does not require URSEL bit to be set
		#define myRXDPIN PIND
		#define myRXDPORT PORTD
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIRDDR DDRD
		#define myDIRPORT PORTD
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for AT90PWM216
#ifdef __AVR_AT90PWM216__
	#define WATCHDOG
	#define myWDCE WDCE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN4
	#define myTXD PIN3
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN0
#endif

// set of definition for AT90PWM316
#ifdef __AVR_AT90PWM316__
	#define WATCHDOG
	#define myWDCE WDCE
	#define myUDR   UDR
	#define myUBRRH UBRRH
	#define myUBRRL UBRRL
	#define myUCSRA UCSRA
	#define myUCSRB UCSRB
	#define myUCSRC UCSRC
	#define myUDRE  UDRE
	#define myRXC   RXC
	#define myTXC	TXC
	#define myRXEN  RXEN
	#define myTXEN  TXEN
	#define myUCSZ0 UCSZ0
	#define myUCSZ1 UCSZ1
	#define myURSEL 0          // MCU type does not require URSEL bit to be set
	#define myRXDPIN PIND
	#define myRXDPORT PORTD
	#define myRXD PIN4
	#define myTXD PIN3
	#define myDIRDDR DDRD
	#define myDIRPORT PORTD
	#define myDIR PIN0
#endif

// set of definition for ATXMEGA64A1 mask revision H
#ifdef _AVR_ATxmega64A1_H_
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 7)
		#define myUSART USARTF1
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN6CTRL
		#define myTXD_PINCTRL PORTF.PIN7CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA128A1 mask revision H
#ifdef _AVR_ATxmega128A1_H_
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 7)
		#define myUSART USARTF1
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN6CTRL
		#define myTXD_PINCTRL PORTF.PIN7CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA128A1U
#ifdef _AVR_ATXMEGA128A1U_H_INCLUDED
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 7)
		#define myUSART USARTF1
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN6CTRL
		#define myTXD_PINCTRL PORTF.PIN7CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN5
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA64A3
#ifdef _AVR_ATxmega64A3_H_
	#define XMEGA
	#define WORKAROUND
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA64A3U
#ifdef _AVR_ATXMEGA64A3U_H_INCLUDED
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif
// set of definition for ATXMEGA128A3
#ifdef _AVR_ATxmega128A3_H_
	#define XMEGA
	#define WORKAROUND
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA128A3U
#ifdef _AVR_ATXMEGA128A3U_H_INCLUDED
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA192A3
#ifdef _AVR_ATxmega192A3_H_
	#define XMEGA
	#define WORKAROUND
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA256A3
#ifdef _AVR_ATxmega256A3_H_
	#define XMEGA
	#define WORKAROUND
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA256A3B
#ifdef _AVR_ATxmega256A3B_H_
	#define XMEGA
	#define WORKAROUND
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 5)
		#define myUSART USARTE1
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN6CTRL
		#define myTXD_PINCTRL PORTE.PIN7CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 6)
		#define myUSART USARTF0
		#define myRXD_DIRSET PORTF_DIRSET
		#define myTXD_DIRSET PORTF_DIRSET
		#define myRXD_PINCTRL PORTF.PIN2CTRL
		#define myTXD_PINCTRL PORTF.PIN3CTRL
		#define myRXD_IN PORTF_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTF_DIRSET
		#define myDIR_OUTSET PORTF_OUTSET
		#define myDIR_OUTCLR PORTF_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA16A4
#ifdef _AVR_ATxmega16A4_H_
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA16A4U
#ifdef _AVR_ATXMEGA16A4U_H_INCLUDED
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA32A4
#ifdef _AVR_ATxmega32A4_H_
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA32A4U
#ifdef _AVR_ATXMEGA32A4U_H_INCLUDED
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA128A4U
#ifdef _AVR_ATXMEGA128A4U_H_INCLUDED
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 1)
		#define myUSART USARTC1
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN6CTRL
		#define myTXD_PINCTRL PORTC.PIN7CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 3)
		#define myUSART USARTD1
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN6CTRL
		#define myTXD_PINCTRL PORTD.PIN7CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN6
		#define myTXD PIN7
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN5
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA64D3
#ifdef _AVR_ATxmega64D3_H_
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

// set of definition for ATXMEGA128D3
#ifdef _AVR_ATxmega128D3_H_
	#define XMEGA
	#if(SERIALPORT == 0)
		#define myUSART USARTC0
		#define myRXD_DIRSET PORTC_DIRSET
		#define myTXD_DIRSET PORTC_DIRSET
		#define myRXD_PINCTRL PORTC.PIN2CTRL
		#define myTXD_PINCTRL PORTC.PIN3CTRL
		#define myRXD_IN PORTC_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTC_DIRSET
		#define myDIR_OUTSET PORTC_OUTSET
		#define myDIR_OUTCLR PORTC_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 2)
		#define myUSART USARTD0
		#define myRXD_DIRSET PORTD_DIRSET
		#define myTXD_DIRSET PORTD_DIRSET
		#define myRXD_PINCTRL PORTD.PIN2CTRL
		#define myTXD_PINCTRL PORTD.PIN3CTRL
		#define myRXD_IN PORTD_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTD_DIRSET
		#define myDIR_OUTSET PORTD_OUTSET
		#define myDIR_OUTCLR PORTD_OUTCLR
		#define myDIR PIN1
	#elif(SERIALPORT == 4)
		#define myUSART USARTE0
		#define myRXD_DIRSET PORTE_DIRSET
		#define myTXD_DIRSET PORTE_DIRSET
		#define myRXD_PINCTRL PORTE.PIN2CTRL
		#define myTXD_PINCTRL PORTE.PIN3CTRL
		#define myRXD_IN PORTE_IN
		#define myRXD PIN2
		#define myTXD PIN3
		#define myDIR_DIRSET PORTE_DIRSET
		#define myDIR_OUTSET PORTE_OUTSET
		#define myDIR_OUTCLR PORTE_OUTCLR
		#define myDIR PIN1
	#else
		#error Invalid serial port definition!
	#endif
#endif

#endif  // #ifndef MCUDEFS

// end of file mcudefs.h
