
#include <avr/io.h>

#define Check_t 50

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6

uint8_t matrix(void);
void num(uint8_t);



int main(void)
{
	DDRB = 0xFF;
	PORTB = 0xFF;
	DDRD = 0xFF;
	while(1)
	{
		num(matrix());
	}
}

uint8_t matrix(void)
{
	volatile uint8_t temp = 0;
	volatile uint8_t some = 1;
	for (uint8_t i = 0; i<3; i++)
	{
		DDRB = 1<<i;
		PORTB = ~(1<<i);
		temp = (~PINB & 0x78)>>3;
		if (temp != 0)
		{
			
			while (temp)
			{
				some ++;
				temp >>= 1; 
			}
			some --;
			switch(some)
			{
				case 1:
				some += i;
				break;
				
				case 2:
				some += i + 2;
				break;
				
				case 3:
				some += i + 4;
				break;
				
				case 4:
				some += i + 6;
				break;
				
				default:
				some = 0;
				break; 
			}
			return some;
		}
	}
	
	return 0x00;
}

void num (uint8_t some)
{
	switch(some)
	{
		case 1:
		PORTD = (1<<B | 1<<C);
		break;
		
		case 2:
		PORTD = (1<<A | 1<<B | 1<<G | 1<<E | 1<<D);
		break;
		
		case 3:
		PORTD = (1<<A | 1<<B | 1<<C | 1<<D |1<<G);
		break;
		
		case 4:
		PORTD = (1<<B | 1<<C | 1<<F | 1<<G);
		break;
		
		case 5:
		PORTD = (1<<A | 1<<F | 1<<G | 1<<C | 1<<D);
		break;
		
		case 6:
		PORTD = (1<<A | 1<<F | 1<<G | 1<<C | 1<<D | 1<<E);
		break;
		
		case 7:
		PORTD = (1<<B | 1<<C | 1<<A);
		break;
		
		case 8:
		PORTD = (1<<A | 1<<F | 1<<G | 1<<C | 1<<D | 1<<E | 1<<B);
		break;
		
		case 9:
		PORTD = (1<<A | 1<<F | 1<<G | 1<<C | 1<<B | 1<<D);
		break;
		
		case 11:
		PORTD = (1<<A | 1<<F | 1<<C | 1<<D | 1<<E | 1<<B);
		break;
		
		default:
		PORTD = (1<<G);
		break;
	}
}
