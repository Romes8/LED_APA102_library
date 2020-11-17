  /*
 * LED_strip.cpp
 *
 * Created: 02/11/2020 10:48:08
 * Author : roman
 */ 

#include <stdio.h>
#include <stdlib.h>

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define SPI_DDR DDRB
#define CS      PINB2
#define MOSI    PINB3
#define MISO    PINB4
#define SCK     PINB5
#include <string.h>

#include "LED_Apa102.h"


void SPI_init()
{
	// set CS, MOSI and SCK to output
	SPI_DDR |= (1 << CS) | (1 << MOSI) | (1 << SCK);

	// enable SPI, set as master, and clock to fosc/128
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);
}


//class declarations into LED.h
//method declarations into LED.cpp
//in main include LED.h
//in LED.cpp include LED.h
//in LED.cpp include #include <avr/io.h>


int main(void)
{
	LED led;
	SPI_init();
	
	while(1)
	{
		led.amount(30); //choose amount
		//led.color(235, 0, 0); //pick color of leds
		//led.blink(10); // blink and pick time
		//led.snail(255, 0, 255); // snail motion . pick color
		//led.mix(0,153,76,204,0,0); //choose 2 own colors to change
		led.random_colours(); //random colours
	}
	
}


