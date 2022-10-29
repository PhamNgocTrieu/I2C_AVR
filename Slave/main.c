

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <myLCD.h>
#include <myTWI.h>

	char buff[20];
	volatile uint8_t temp = 0;
	uint8_t i = 0;

int main(void)
{
	
	Device_Addr = 1;
	TWI_Init();
	init_LCD();
	clr_LCD();
	
	sei();
	
	/*for (int i = 0; i < 20; i++)
	{
		Slave_Wdata[i] = i;
	}*/
	
	print_LCD("Receiver:");
	
    while (1) 
    {
		move_LCD(2, 1);
		print_LCD("Recnum: ");
		//Rec_Num = temp;
		sprintf(buff, "%i", SLAVE_buff[temp]);
		print_LCD(buff);
    }

}
	