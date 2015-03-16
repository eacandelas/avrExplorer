#include <avr/io.h>
#include <util/delay.h>


int main(){
    DDRB |= (1 << PB4);
    DDRB |= (1 << PB3);

    while(1){
        PORTB |= (1 << PB4);
        PORTB &= ~(1 << PB3);
        _delay_ms(500);
        PORTB &= ~(1 << PB4);
        PORTB |= (1 << PB3);
        _delay_ms(500);
    }

    return 0;

}

void setInput(int pin){
    DDRB &= ~(0 << pin);
}

void setOutput(int pin){
    DDRB |= (1 << pin);
}

void toggle(int pin){
    PORTB ^= (1 << pin);
}

void setHigh(int pin){
    PORTB |= (1 <<pin);
}   

void setLow(int pin){
    PORTB &= ~(1 << pin);
}

int getValue(int pin){
    int value = PINB &(1 << pin);
    return value;
}
