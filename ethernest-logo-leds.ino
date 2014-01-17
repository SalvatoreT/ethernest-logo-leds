/*
 * This is the code for a 50 LED chain made 
 * of two 25-pixel of WS2801-powered LED strings.
 * The configuration is below.
 * 
 * LED wire layout:
 * 	Red=5V DC
 * 	Green=Clock
 * 	Yellow=Data
 * 	Blue=Ground
 * 	
 * MSP430G2553:
 * 	PIN1.5=Clock/Green
 * 	PIN1.7=Data/Yellow
 * 	GND=Ground/Blue
 * 	
 * Arduino Uno:
 * 	PIN13=Clock/Green
 * 	PIN11=Data/Yellow
 * 	GND=Ground/Blue
 * 	
 * LED number to corresponding letter
 * 	[0,4] + 5*i => i'th letter (not E)
 * 	[30,49] => the letter E
 */
#include <SPI.h>

int offset = 0;

void setup() 
{
	SPI.begin();
}

void loop() 
{
	int delaySpeed = 500;
 	
 	// For the letters THRNST
	for(int i=0; i < 6; i++){
		for(int j=0; j<5; j++){
		    color((i + offset) % 7);
		}
	}

	// For the E
	for(int i=0; i<20; i++){
	    color((6 + offset) % 7);
	}
	offset = (offset + 1) % 7;
	delay(delaySpeed);
}

void red() {
  SPI.transfer(0xFF);       
  SPI.transfer(0x00);       
  SPI.transfer(0x00);     
}
void orange() {
  SPI.transfer(0xFF);       
  SPI.transfer(0x63);       
  SPI.transfer(0x00);     
}
void yellow() {
  SPI.transfer(0xFF);       
  SPI.transfer(0xFF);       
  SPI.transfer(0x00);     
}
void green() {
  SPI.transfer(0x00);       
  SPI.transfer(0xFF);       
  SPI.transfer(0x00);     
}
void blue() {
  SPI.transfer(0x00);       
  SPI.transfer(0x00);       
  SPI.transfer(0xFF);     
}
void indigo() {
  SPI.transfer(0x4B);       
  SPI.transfer(0x00);       
  SPI.transfer(0x82);     
}
void violet() {
  SPI.transfer(0xAF);       
  SPI.transfer(0x00);       
  SPI.transfer(0xFF);     
}
void black() {
  SPI.transfer(0x00);       
  SPI.transfer(0x00);       
  SPI.transfer(0x00);     
}
void white() {
  SPI.transfer(0xFF);       
  SPI.transfer(0xFF);       
  SPI.transfer(0xFF);     
}

void color(int color) {
	switch (color) {
		case 0:
			red();
			break;
		case 1:
			orange();
			break;
		case 2:
			yellow();
			break;
		case 3:
			green();
			break;
		case 4:
			blue();
			break;
		case 5:
			indigo();
			break;
		case 6:
			violet();
			break;
		default:
			black();
	}
}

