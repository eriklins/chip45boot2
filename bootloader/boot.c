// boot.c
//
// own boot.c functions for xmega
// these functions are implemented as wrapper functions 

#include <avr/interrupt.h>

#include "sp_driver.h"
#include "mcudefs.h"

// on A3 devices with die revision B a workaround is required
#ifdef WORKAROUND

//Temporary storage used for NVM-workaround
uint8_t sleepCtr;
uint8_t statusStore;
uint8_t pmicStore;
uint8_t globalInt;
uint8_t spmintStore;

// SPM wakeup interrupt
ISR(NVM_SPM_vect) {
	NVM.INTCTRL = (NVM.INTCTRL & ~NVM_SPMLVL_gm);  // Disable the SPM interrupt
	SLEEP.CTRL = sleepCtr;  // Restore sleep settings
	// Restore PMIC status and control registers
	PMIC.STATUS = statusStore;
	PMIC.CTRL = pmicStore;
	NVM.INTCTRL = spmintStore;  // Restore SPM interruptsettings
	SREG = globalInt;  // Restore global interrupt settings
}

// Set interrupt vector location to boot section of flash
void PMIC_SetVectorLocationToBoot( void ) {
	uint8_t temp = PMIC.CTRL | PMIC_IVSEL_bm;
	CCP = CCP_IOREG_gc;
	PMIC.CTRL = temp;
}

// Set interrupt vector location to application section of flash
void PMIC_SetVectorLocationToApplication( void ) {
	uint8_t temp = PMIC.CTRL & ~PMIC_IVSEL_bm;
	CCP = CCP_IOREG_gc;
	PMIC.CTRL = temp;
}

// Save register settings before entering sleep mode
void Prepare_to_Sleep( void ) {
	sleepCtr = SLEEP.CTRL;
	SLEEP.CTRL =  0x00;  // Set sleep mode to IDLE
	// Save the PMIC Status and control registers
	statusStore = PMIC.STATUS;								
	pmicStore = PMIC.CTRL;		
	PMIC.CTRL = (PMIC.CTRL & ~(PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm)) | PMIC_HILVLEN_bm;  // Enable only the highest level of interrupts
	globalInt = SREG;  // Save SREG for later use
	sei();  // Enable global interrupts
	spmintStore = NVM.INTCTRL;  // Save SPM interrupt settings for later
}
#endif  // WORKAROUND


void boot_page_fill(uint32_t ulAddress, uint16_t usData) {

#ifdef WORKAROUND
	Prepare_to_Sleep();
#endif
	SP_LoadFlashWord(ulAddress, usData);
}


void boot_page_erase(uint32_t ulAddress) {  // do a page erase

#ifdef WORKAROUND
	Prepare_to_Sleep();
#endif
	SP_EraseApplicationPage(ulAddress);
}


void boot_spm_busy_wait() {  // wait for page erase done

#ifdef WORKAROUND
	Prepare_to_Sleep();
#endif
	SP_WaitForSPM();
}


void boot_page_write(uint32_t ulAddress) {  // do a page write

#ifdef WORKAROUND
	Prepare_to_Sleep();
#endif
	SP_WriteApplicationPage(ulAddress);
}


void boot_rww_enable() {  // reenable rww section again
}


// end of file: boot.c
