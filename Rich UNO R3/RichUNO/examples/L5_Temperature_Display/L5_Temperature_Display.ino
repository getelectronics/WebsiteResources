/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 5: Temperature measurement and display
* Through the DS18B20 temperature measurement module to obtain the temperature, so that four digital display, and because the digital tube is no decimal point, so only show the integer part of the temperature
*
* The following functions are available:
* temper.getTemperature(); / / get the temperature value, the return of the float is the decimal
*
* displayTemperature(int8_t temperature); / / display temperature, at the end of the value of the word added C is the degree of Celsius
*
* disp.init(); // initialization
* disp.display(int8_t DispData []); // display the numbers in the array
* // For example, the array is {1,2,3,4}, then show 1234
* disp.display(uint8_t BitAddr, int8_t DispData); // bit by bit to display numbers, characters, BitAddr range is 0 ~ 3,
* // Parameter DispData range is 0 ~ 17 represents 0 ~ 9, A, b, c, d, E, F, -, space
* disp.display(int Decimal);   // display range: -999 ~ 9999
* disp.clearDisplay(); // clear the display
* disp.set(uint8_t brightness); // set the brightness, 0 ~ 7, the greater the value, the higher the brightness, 
                                       //the next display takes effect
* disp.point(0); // Turn off the display colon and the next display takes effect
* disp.point(1); // Turn on the display colon and the next display takes effect
************************************************** ************************************************** *****/
#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOTM1637.h"
#include "RichUNOLM75.h"

LM75 temper;  // initialize an LM75 object "temper" for temperature

#define CLK 10//CLK of the TM1637 IC connect to D10 of Arduino
#define DIO 11//DIO of the TM1637 IC connect to D11 of Arduino
TM1637 disp(CLK,DIO);

void setup()
{
  Wire.begin();//you should run this function first, so that I2C device can use the I2C bus
  disp.init();//The initialization of the display
  delay(1000);//
}

void loop()
{
  float celsius;
  celsius = temper.getTemperatue();//get temperature
  displayTemperature((int8_t)celsius);//
  delay(1000);//delay 1000ms
}
/************************************************* *********************/
/* Function: Display temperature on 4-digit digital tube */
/* Parameter: -int8_t temperature, temperature range is -40 ~ 125 degrees celsius */
/* Return Value: void */

void displayTemperature(int8_t temperature)
{
  int8_t temp[4];
  if(temperature < 0)
	{
		temp[0] = INDEX_NEGATIVE_SIGN;
		temperature = abs(temperature);
	}
	else if(temperature < 100)temp[0] = INDEX_BLANK;
	else temp[0] = temperature/100;
	temperature %= 100;
	temp[1] = temperature / 10;
	temp[2] = temperature % 10;
	temp[3] = 12;	          //index of 'C' for celsius degree symbol.
	disp.display(temp);
}
/*********************************************************************************************************
The end of file
*********************************************************************************************************/
