//C file for an implementation of the tri-color LED on the FRDM-KL25Z development board. Includes configuration, on, off, and toggle functions. 
//Created by Dylan Pereiras

#include "MKL25Z4.h"
#include "rgbled.h"

#define RED_LED_SHIFT 18
#define GREEN_LED_SHIFT 19
#define BLUE_LED_SHIFT 1

#define MASK(x) (1UL << (x))
void configure_rgbled()
{
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;
	PORTB->PCR[RED_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_SHIFT] |= PORT_PCR_MUX(1);
	PORTB->PCR[GREEN_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_SHIFT] |= PORT_PCR_MUX(1);
	PORTD->PCR[BLUE_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_SHIFT] |= PORT_PCR_MUX(1);

	PTB->PDDR |= (MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT));
	PTD->PDDR |= MASK(BLUE_LED_SHIFT);

}
void turn_on_green_led()
{
	PTB->PCOR |= MASK(GREEN_LED_SHIFT);
}
void turn_off_green_led()
{
	PTB->PSOR |= MASK(GREEN_LED_SHIFT);
}
void toggle_green_led()
{
	PTB->PTOR |= MASK(GREEN_LED_SHIFT);
}

void turn_on_red_led()
{
	PTB->PCOR |= MASK(RED_LED_SHIFT);
}
void turn_off_red_led()
{
	PTB->PSOR |= MASK(RED_LED_SHIFT);
}
void toggle_red_led()
{
	PTB->PTOR |= MASK(RED_LED_SHIFT);
}
void turn_on_blue_led()
{
	PTD->PCOR |= MASK(BLUE_LED_SHIFT);
}
void turn_off_blue_led()
{
	PTD->PSOR |= MASK(BLUE_LED_SHIFT);
}
void toggle_blue_led()
{
	PTD->PTOR |= MASK(RED_LED_SHIFT);
}


void set_rgbled_color_to(RGBLED_COLOR color)
{

	switch(color)
	{
		case RGBLED_COLOR_BLACK:
			turn_off_red_led();
			turn_off_green_led();
			turn_off_blue_led();
			break;
		case RGBLED_COLOR_BLUE:
			turn_off_red_led();
			turn_off_green_led();
			turn_on_blue_led();
			break;
		case RGBLED_COLOR_GREEN:
			turn_off_red_led();
			turn_off_blue_led();
			turn_on_green_led();
			break;
		case RGBLED_COLOR_CYAN:
			turn_off_red_led();
			turn_on_green_led();
			turn_on_blue_led();
			break;
		case RGBLED_COLOR_RED:
			turn_off_blue_led();
			turn_off_green_led();
			turn_on_red_led();
			break;
		case RGBLED_COLOR_MAGNETA:
			turn_off_green_led();
			turn_on_red_led();
			turn_on_blue_led();
			break;
		case RGBLED_COLOR_YELLOW:
			turn_off_blue_led();
			turn_on_red_led();
			turn_on_green_led();
			break;
		case RGBLED_COLOR_WHITE:
			turn_on_blue_led();
			turn_on_red_led();
			turn_on_green_led();
			break;
		default:
			turn_off_blue_led();
			turn_off_green_led();
			turn_off_red_led();
			break;
	}


}




