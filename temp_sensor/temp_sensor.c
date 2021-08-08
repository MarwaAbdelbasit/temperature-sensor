/*
 * temp_sensor.c
 *
 * Created: 25/11/2019 08:19:19 م
 *  Author: new
 */ 


#include <avr/io.h>
#include "ADC_driver.h"
#include "LCD.h"

char read_val;
unsigned short temperature;

int main(void)
{
	LCD_init();
	ADC_init();
	LCD_send_string("temperature=");
    while(1)
    {
        temperature = (ADC_read()*0.25);
		if(temperature<10)
		{
			LCD_move_cursor(1, 13);
			LCD_send_char(0x30);
			LCD_send_char((temperature%10)+48);
			LCD_send_char(0xdf);
			LCD_send_char(0x43);
		}
		else if (temperature<100)
		{
			LCD_move_cursor(1, 13);
			LCD_send_char((temperature/10)+48);
			LCD_send_char((temperature%10)+48);
			LCD_send_char(0xdf);
			LCD_send_char(0x43);
		}
		else
		{
		}						 
    }
}