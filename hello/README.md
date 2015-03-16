compiler

avr-gcc -g -Wall -Os -DF_CPU=1000000L -mmcu=attiny85  -c hello.c -o hello.o
avr-gcc -g -Wall -Os -DF_CPU=1000000L -mmcu=attiny85 -o main.elf hello.o

avr-objcopy -j .text -j .data -O ihex hello.elf hello.hex
avr-size --format=avr --mcu=attiny85 hello.elf


avrdude -p avrisp2 -p t85 -U flash:w:hello.hex:i
check up connection to the target
avrdude -p t85 -c avrisp -P /dev/ttyACM0 -b 19200 
program target
avrdude -p t85 -c avrisp -P /dev/ttyACM0 -U flash:w:hello.hex:i
