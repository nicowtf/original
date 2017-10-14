/*
 * main.c
 *
 *  Created on: 30/09/2017
 *      Author: Daniela
 */


/*
 * main.c
 *
 *  Created on: 30/09/2017
 *      Author: Daniela
 */
#include <avr/io.h>
#include <util/delay.h>
#include "hardware.h"
#include <avr/interrupt.h>

int main (void){

	init_externo();
	eicrb();
    timer();
	timsk();
	reset_timer();

	 sei();
	 //DDRE |=(1<<5)|(1<<6)|(1<<7);
	DDRD |=(1<<4)|(1<<5)|(1<<6)|(1<<7);


	led1_off;
	led2_off;
	led3_off;
	led4_off;




	while(1){                              //while infinito
		//led1_on;
		//_delay_ms(500);

//led1_off;
	//_delay_ms(500);

	}
	return 1;


}

ISR(INT7_vect) {
	if (sw3) {
		led4_off;
	} else {
		led4_on;
	}
}
ISR(INT6_vect) {
	if (sw2) {
		led3_off;
	} else {
		led3_on;
	}
}
ISR(INT5_vect) {
	if (sw1) {
		led2_off;
	} else {
		led2_on;
	}
}
ISR(TIMER1_COMPA_vect){
	led1^=1;
}

