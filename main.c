#include<avr/io.h>
#include<avr/interrupt.h>
//#define F_CPU 8000000L
#define LED PB1

void main(void)
{
	DDRB |= (1 << LED);
	PORTB |= (1 << LED);
	//timer settings
	TCCR0 |= (1 << CS02) | (0 << CS01); //prescaler 64 
	TIMSK |= (1 << TOIE0);
	sei();
	while(1)
	{
		//
	}
}

ISR(TIMER0_OVF_vect)
{
	PORTB ^= (1 << LED);
}

