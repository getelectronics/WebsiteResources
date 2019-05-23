/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 4: Touch and debounce
* Learn about software debounce method to achieve the number increasing step by step.
*
* The following functions are available:
*
* touch.get(); / / return is the touch area corresponding Arduino pin number, if not then return -1
* touch.getLongPress(); / / return long press the corresponding Arduino pin number, if not return -1
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
#include "RichUNOTouchSensor.h"
#include "RichUNOTM1637.h"
		
#define CLK 10//CLK of the TM1637 IC connect to D10 of Arduino
#define DIO 11//DIO of the TM1637 IC connect to D11 of Arduino
TM1637 disp(CLK,DIO);
	
#define TOUCH_OUT1 3//out1-TCH1 area corresponds to the number increase
#define TOUCH_OUT2 4//out2-TCH2 area not use now
#define TOUCH_OUT3 5//out3-TCH3 area not use now
#define TOUCH_OUT4 6//out4-TCH4 area not use now
TouchSensor touch(TOUCH_OUT1,TOUCH_OUT2, TOUCH_OUT3,TOUCH_OUT4);

int count = 0;

void setup()
{
  disp.init();//The initialization of the display
  disp.display(count);//display counter number
}

void loop()
{
  int button;
  button = touch.get();
  if(button == TOUCH_OUT1) //if touch the TCH1 area
  {
    delay(10);//delay for 10ms
    if(touch.get() == TOUCH_OUT1)//check it again
    {
      count++;
	  disp.display(count);
    }
	while(touch.get() == TOUCH_OUT1);//Wait for the button to be released
  }
  
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/

