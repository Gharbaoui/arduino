#include <avr/io.h>
#include <util/delay.h>

#define MS_DELAY 5000

/*
* DDB5 and PORTB5 are just macros and their value is 5
*/


int	main()
{
	*( (volatile uint8_t *) 0x24 ) |= _BV(DDB5);
	while (1)
	{
		*( (volatile uint8_t *) 0x25 ) |= _BV(PORTB5);
		_delay_ms(MS_DELAY);
		*( (volatile uint8_t *) 0x25 ) &= ~_BV(PORTB5);
		_delay_ms(MS_DELAY);
	}
}
