/*
 * ADC_driver.c
 *
 * Created: 25/11/2019 05:04:58 م
 *  Author: new
 */ 

#include <avr/io.h>
#include "macros.h"

void ADC_init(void) 
{
	SET_BIT(ADMUX, REFS0); //configure vref
	SET_BIT(ADCSRA, ADEN); //enable ADC
	
	//adjust ADC clk
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
}

unsigned short ADC_read(void)
{
	unsigned short read_val;
	SET_BIT(ADCSRA, ADSC); //start conversion;
	//while(IS_BIT_CLR(ADCSRA, ADIF)); //still in your position till ADIF become 1
	//SET_BIT(ADCSRA, ADIF);
	while(READ_BIT(ADCSRA, ADSC) == 1);
	read_val = (ADCL);
	read_val|=(ADCH<<8);
	return read_val;
}