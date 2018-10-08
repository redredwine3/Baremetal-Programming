//Header file for an implementation of the switch 1 on the FRDM-KL25Z development board.
//Created by Dylan Pereiras

#ifndef SW1_H
#define SW1_H

void configure_sw1();
_Bool is_sw1_pressed();
_Bool is_sw1_released();

void wait_for_sw1_press_and_release();

#endif
