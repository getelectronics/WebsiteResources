/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 2: Display number
* You can learn how to display numbers, which can be displayed in bits, or you can display integers directly
*
* The following functions are available:
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

************************************************** **************************************************/
#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOTM1637.h"

#define CLK 10//CLK of the TM1637 IC connect to D10 of Arduino
#define DIO 11//DIO of the TM1637 IC connect to D11 of Arduino
TM1637 disp(CLK,DIO);

void setup()
{
  disp.init();//The initialization of the display
}

void loop()
{
  int8_t ListDisp[4] = {3,4,5,6};
  disp.display(ListDisp);//display array
  delay(1000);
  
  disp.display(-100);//Display integer
  delay(1000);

  disp.display(256);
  delay(1000);

}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
