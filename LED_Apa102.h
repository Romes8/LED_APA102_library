/*
 * LED_Apa102.h
 *
 * Created: 17/11/2020 11:49:39
 *  Author: roman
 */ 


#ifndef LED_APA102_H_
#define LED_APA102_H_
class LED
{
	private:
	unsigned char result_r;
	unsigned char result_g;
	unsigned char result_b;
	unsigned char b128;
	unsigned char b64;
	unsigned char b32;
	unsigned char b16;
	unsigned char b8;
	unsigned char b4;
	unsigned char b2;
	unsigned char b1;
	unsigned char number = 1;
	int i;
	int random_b;
	int random_g;
	int random_r;
	public:
	void color(unsigned char r, unsigned char g, unsigned char b);
	void blink(unsigned char m);
	void amount(unsigned char a);
	void snail(unsigned char r, unsigned char g, unsigned char b);
	void mix(unsigned char fb, unsigned char fg, unsigned char fr, unsigned char sb, unsigned char sg, unsigned char sr);
	void random_colours();
	
};

#endif /* LED_APA102_H_ */