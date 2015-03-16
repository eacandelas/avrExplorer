#include <avr/io.h>
#include <util/delay.h>

int main(){
	uint8_t r = 0, b = 255;

//set PB4 como salida
	DDRB = 1 << DDB4 | 1 << DDB0;

//configurasion de PWM en OC0A y OC0B
	TCCR0A = 2<<COM0A0 | 2<<COM0B0 | 3<<WGM00;
	TCCR0B = 0<<WGM02 | 1<<CS00;

//configuracion de PWM en OC1B
	TCCR1 = 0<<PWM1A | 0<<COM1A0 | 1<<CS10;
	GTCCR = 1<<PWM1B | 2<<COM1B0;

	while(1){
		if (--b<1){ 
			b=255;
			_delay_ms(500);
		};
		if (++r>255){
			 r=0;
			_delay_ms(500);
		}
		OCR0A = b;
		OCR1B = r;
		
		_delay_ms(10);
	}
	
	return 0;

}

