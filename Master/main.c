
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <myLCD.h>
#include <myTWI.h>
#include <string.h>

uint8_t data[1];
volatile uint8_t i = 1;
char buff[20];
char str[] = "trieu";

int main(void)
{ 
	
	TWI_Init();
	init_LCD();
	clr_LCD();
	
	// enable interrupt
	DDRD = 0x00; //input 
	PORTD = 0xff; // pull-up resistor
	MCUCR |= (1<<ISC01); // falling edge of INT0
	GICR |= (1<<INT0); // interrupt enable 0
	sei(); //global interrupt
	
	//_delay_ms(100); // wait for slave ready
	
	
	
	print_LCD("Transmitter: ");
	move_LCD(2,1);
	print_LCD("Trannum: 0");
	
    while (1) 
	{
		TWI_Master_Send_array(1, data, 1);	
    }
	return 0;
}
 
 ISR(INT0_vect){
	
	move_LCD(2,1);
	print_LCD("Trannum: ");
	data[0] = i * 2;
	
	sprintf(buff, "%i", data[0]);
	i++;
	print_LCD(buff);
	
	if (i >= 99){
		i = 1;
	}
 }

