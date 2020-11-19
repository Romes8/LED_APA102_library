/*
 * LED_Apa102.cpp
 *
 * Created: 17/11/2020 11:53:39
 *  Author: roman
 */ 

#include "LED_Apa102.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

void SPI_masterTransmitByte(uint8_t data)
{
	// load data into register
	SPDR = uint8_t(data);

	// Wait for transmission complete
	while(!(SPSR & (1 << SPIF)));
}



void my_delay_ms(int n) {
	while(n--) {
		_delay_ms(1);
	}
}

void LED::blink(unsigned char m)
{
	
	
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	
	for (int i = 1; i <= number; i++)
	{
		SPI_masterTransmitByte(255);
		SPI_masterTransmitByte(0);
		SPI_masterTransmitByte(0);
		SPI_masterTransmitByte(0);
	}
	
	// end bits
	SPI_masterTransmitByte(255);
	SPI_masterTransmitByte(255);
	SPI_masterTransmitByte(255);

	
	my_delay_ms(m);
	
	
	
}

void LED::amount(unsigned char a)
{
	number = a;
}

void LED::color(unsigned char r, unsigned char g, unsigned char b, unsigned char power)
{
	//start bit
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	
	for (int i = 1; i <= number; i++)
	{
		//led frame
		SPI_masterTransmitByte(power);
		SPI_masterTransmitByte(b);
		SPI_masterTransmitByte(g);
		SPI_masterTransmitByte(r);
		
	}
	// end bits
	SPI_masterTransmitByte(255);
	SPI_masterTransmitByte(255);
	SPI_masterTransmitByte(255);
	//SPI_masterTransmitByte(255);
	
	_delay_ms(1000);
	
	
}

void LED::mix(unsigned char power,unsigned char fb, unsigned char fg, unsigned char fr, unsigned char sb, unsigned char sg, unsigned char sr)
{
	//start bit
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	
	for (int i = 1; i <= number; i++)
	{
		if (i % 2 == 0){
			SPI_masterTransmitByte(power);
			SPI_masterTransmitByte(fb);
			SPI_masterTransmitByte(fg);
			SPI_masterTransmitByte(fr);
		}
		else {
			SPI_masterTransmitByte(power);
			SPI_masterTransmitByte(sb);
			SPI_masterTransmitByte(sg);
			SPI_masterTransmitByte(sr);
		}
	}
	// end bits
	SPI_masterTransmitByte(255);
	SPI_masterTransmitByte(255);
	SPI_masterTransmitByte(255);
	
	
	
}

void LED::snail(unsigned char r, unsigned char g, unsigned char b, unsigned char power)
{
	
	
	if (i == 1)
	{
		
		SPI_masterTransmitByte(0);
		SPI_masterTransmitByte(0);
		SPI_masterTransmitByte(0);
		SPI_masterTransmitByte(0);
		
		for (int i = 1; i <= number; i++)
		{
			//led frame
			SPI_masterTransmitByte(power);
			SPI_masterTransmitByte(b);
			SPI_masterTransmitByte(g);
			SPI_masterTransmitByte(r);
			_delay_ms(10);
			
		}
		// end bits
		SPI_masterTransmitByte(255);
		SPI_masterTransmitByte(255);
		SPI_masterTransmitByte(255);
		SPI_masterTransmitByte(255);
		
	}
	
	if (i == 2)
	{
		SPI_masterTransmitByte(0);
		SPI_masterTransmitByte(0);
		SPI_masterTransmitByte(0);
		SPI_masterTransmitByte(0);
		
		for (int i = 1; i <= number; i++)
		{
			//led frame
			SPI_masterTransmitByte(255);
			SPI_masterTransmitByte(0);
			SPI_masterTransmitByte(0);
			SPI_masterTransmitByte(0);
			_delay_ms(10);
			
		}
		// end bits
		SPI_masterTransmitByte(255);
		SPI_masterTransmitByte(255);
		SPI_masterTransmitByte(255);
		SPI_masterTransmitByte(255);
		
		
		
		i = 0;
		
	}
	else
	{
		i++;
	}
}

void LED::random_colours(unsigned char power)
{
	//start bit
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	SPI_masterTransmitByte(0);
	
	for (int i = 1; i <= number; i++)
	{
		random_b = (rand()% 255) + 1;
		random_g = (rand()% 255) + 1;
		random_r = (rand()% 255) + 1;
		
		SPI_masterTransmitByte(power);
		SPI_masterTransmitByte(random_b);
		SPI_masterTransmitByte(random_g);
		SPI_masterTransmitByte(random_r);
		_delay_ms(100);
	}
	// end bits
	
	SPI_masterTransmitByte(255);
	SPI_masterTransmitByte(255);
	SPI_masterTransmitByte(255);
	
}
