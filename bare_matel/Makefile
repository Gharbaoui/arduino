all: blink_led.hex

blink_led.hex: blink_led
	avr-objcopy -O ihex -R .eeprom $^ $@ 

blink_led: blink_led.o
	avr-gcc -mmcu=atmega328p $^ -o $@

blink_led.o: blink_led.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c $^ -o $@
	
upload: blink_led.hex
	 avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:blink_led.hex

clean:
	rm -f *.o *.hex blink_led
