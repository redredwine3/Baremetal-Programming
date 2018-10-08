//Main file for an implementation of using a switch to change colors of a tri-colored LED for the FRDM-KL25Z development board. Two drivers for switch 1 and tri-color LED are used.  
//Created by Dylan Pereiras

#include "sw1.h"
#include "rgbled.h"

void main()
{
	configure_rgbled();
	configure_sw1();
	while(1)
	{
		//set_rgbled_color_to(RGBLED_COLOR_BLACK);
		for(int i=0; i <=(int)RGBLED_COLOR_WHITE; i++)
		{
			wait_for_sw1_press_and_release();
			set_rgbled_color_to(i);
		}

	}

}
