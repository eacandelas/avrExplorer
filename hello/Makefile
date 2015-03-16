TARGET	= hello

MCU		= attiny85
F_CPU	= 1000000L
BAUD	= 19200

PROGRAMMER_TYPE = avrisp
PROGRAMMER_PORT = /dev/ttyACM0
PROGRAMMER_BAUD	= 19200

CFLAGS	= -Os -g -Wall


all: hex

object:
	avr-gcc $(CFLAGS) -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c $(TARGET).c -o $(TARGET).o

elf: object
	avr-gcc $(CFLAGS) -DF_CPU=$(F_CPU) -mmcu=$(MCU) -o $(TARGET).elf $(TARGET).o

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex
	

clean:
	rm -f $(TARGET).elf $(TARGET).hex $(TARGET).o

flash: 
	avrdude -p $(MCU) -c $(PROGRAMMER_TYPE) -P $(PROGRAMMER_PORT) -b $(PROGRAMMER_BAUD) -U flash:w:$(TARGET).hex:i
