- bare metal
    
    i have used `arduino` IDE but i never been comfortable so now i want to program `arduino` without IDE but i have no idea how !!!
    
    - how `arduino` IDE works
        
        the IDE uses `avr-gcc` compiler and `avrdude` to upload our program in the micro controller
        
        so `avr-gcc` will output object file and will use it also to link to system libraries to produce ELF file
        
        then we’ll use `avr-objcopy` to translate the ELF file to binary file that can be uploaded to `arduino` board using `avrdude`
        
    - a little bit of theory
        
        before starting writing c code we need to know what we will do because `avr` tool chain has no idea about `arduino` IDE so we need to control the micro controller mounted on it directly, my `arduino`  has `atm328p`  micro controller and here is the datasheet for it which is quite large [https://www.microchip.com/wwwproducts/en/ATmega328P#datasheet-toggle](https://www.microchip.com/wwwproducts/en/ATmega328P#datasheet-toggle)
        
        fortunately we do not read all of that this is enough [https://www.arduino.cc/en/uploads/Main/arduino-uno-schematic.pdf](https://www.arduino.cc/en/uploads/Main/arduino-uno-schematic.pdf)
        
        as you can see on the right if you followed the pin 13 you can see that it directly connected to the built in led and after that goes to `PORTB`  to be exact bit 5 of `PORTB` so all we need is to set bit 5 on `PORTB` that will lead to pin 13 high simple ? well no because we need to specify if we want to use pin 13 as input or output 
        
        that’s why micro controller have `ddr` registers `ddr` stands for data direction register we set 1 in the 5 bit of `DDRB` register this tells the micro controller to use `PORTB` 5 bit as output 
        
        you can see for arduino reference that each port register maps to a particular block of pins the IOA block to PORTB and so on
        
        - to handle each block of pins we need 3 registers the DDR , PORT and the input register PIN but what is input register this used  to read the input value when we use that pin in input mode
