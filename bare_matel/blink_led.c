#include <avr/io.h>
#include <util/delay.h>

#define MS_DELAY 5000

/*
* DDB5 and PORTB5 are just macros and their value is 5
*/


int	main()
{
	DDRB |= _BV(DDB5);
	while (1)
	{
		PORTB |= _BV(PORTB5);
		_delay_ms(MS_DELAY);
		PORTB &= ~_BV(PORTB5);
		_delay_ms(MS_DELAY);
	}
}
