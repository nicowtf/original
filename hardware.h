/*
 * hardware.h
 *
 *  Created on: 07/10/2017
 *      Author: Daniela
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_
#define setbit(reg,bit)  reg|=(1<<bit)
#define prendo_led()     setbit(portd,4)
#define clrbit(reg,bit)  reg&=~(1<<bit)
#define apago_led()      clrbit(portd,4)
#define tooglebit(reg,bit) reg^=(1<<bit)

#define sw1  PINE&(1<<5)
#define sw2  PINE&(1<<6)
#define sw3  PINE&(1<<7)

#define led4_on  clrbit(PORTD,7)
#define led3_on  clrbit(PORTD,6)
#define led2_on  clrbit(PORTD,5)
#define led1_on  clrbit(PORTD,4)
#define led4_off  setbit(PORTD,7)
#define led3_off  setbit(PORTD,6)
#define led2_off  setbit(PORTD,5)
#define led1_off  setbit(PORTD,4)

typedef struct
{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;
}bit_t;

#define regbit(reg,bit) ((volatile bit_t*)reg)-> B##bit

#define led1 regbit(PORTD,7)

#define init_externo() EIMSK|=(1<<INT7)|(1<<INT6)|(1<<INT5)
#define eicrb() EICRB|=(1<<ISC70)|(1<<ISC60)|(1<<ISC50)

#define timer()  TCCR1B|=(1<<WGM12) //seteo de timer
#define reset_timer() TCNT1 = 0 // cuenta igual a 0
#define timsk()  TIMSK|=(1<<OCIE1A) //habilito interrupcion
#define OCCR1A = 24999
#endif /* HARDWARE_H_ */
