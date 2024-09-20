/// Simple 'Hello, world' program
/**
 * This program prints "Hello, world" to the LCD screen
 * @author Chad Nelson
 * @date 06/26/2012
 *
 * updated: phjones 9/3/2019
 * Describtion: Added timer_init call, and including Timer.h
 */

#include "Timer.h"
#include "lcd.h"


int main (void) {
    int startPos = 19;
    char message[] = "                    Microcontrollers are lots of fun!";
    int i = 0;
    int index = 0;

	timer_init(); // Initialize Timer, needed before any LCD screen fucntions can be called 
	              // and enables time functions (e.g. timer_waitMillis)

	lcd_init();   // Initialize the the LCD screen.  This also clears the screen. 

	while(true){
	    while(message[i] != 0 && i < index + 20){
	        lcd_putc(message[i]);
	        i++;
	    }

	    if(message[index] != 0){
	        index++;
	    }else{
	        index = 0;
	    }

	    i = index;

	    timer_waitMillis(300);
	    lcd_clear();
	}

    
	// NOTE: It is recommended that you use only lcd_init(), lcd_printf(), lcd_putc, and lcd_puts from lcd.h.
    // NOTE: For time fuctions see Timer.h

	return 0;
}
