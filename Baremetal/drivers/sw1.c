//C file for an implementation of the switch 1 on the FRDM-KL25Z development board. Contains configuration function, and additional functions for testing whether the button is pressed, released, or if one needs to poll for those former processes. 
//Created by Dylan Pereiras

#include "MKL25Z4.h"
#include "sw1.h"
#define MASK(x) (1UL << (x))
#define SW1_SHIFT 20 

void configure_sw1()
{
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	PORTA->PCR[SW1_SHIFT] &= ~PORT_PCR_MUX_MASK;
       	PORTA->PCR[SW1_SHIFT] |= PORT_PCR_MUX(1);
	PTA->PDDR &= ~MASK(SW1_SHIFT);
}
_Bool is_sw1_pressed()
{
	return (!(PTA->PDIR & MASK(SW1_SHIFT)));

}
_Bool is_sw1_released()
{
	return !(is_sw1_pressed());
}

void wait_for_sw1_press_and_release()
{
	while(!is_sw1_pressed());
	while(!is_sw1_released());
}



