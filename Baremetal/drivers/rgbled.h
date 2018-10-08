//Header file for an implementation of the tri-color LED on the FRDM-KL25Z development board.
//Created by Dylan Pereiras

#ifndef RGBLED_H
#define RGBLED_H

typedef enum RGB_COLORS
{
	RGBLED_COLOR_BLACK=0b000,
	RGBLED_COLOR_BLUE=0b001,
	RGBLED_COLOR_GREEN=0b010,
	RGBLED_COLOR_CYAN=0b011,
	RGBLED_COLOR_RED=0b100,
	RGBLED_COLOR_MAGNETA=0b101,
	RGBLED_COLOR_YELLOW=0b110,
	RGBLED_COLOR_WHITE=0b111
} RGBLED_COLOR;

void configure_rgbled();
void set_rgbled_color_to(RGBLED_COLOR color);

void turn_on_green_led();
void turn_off_green_led();
void toggle_green_led();

void turn_on_red_led();
void turn_off_red_led();
void toggle_red_led();

void turn_on_blue_led();
void turn_off_blue_led();
void toggle_blue_led();


#endif
