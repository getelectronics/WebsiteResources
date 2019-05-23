/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 7: Knob angle display
* You can learn get the angle of the knob(rotary angle sensor) and display.
*
* The following functions are available:
*
* knob.getAngle();//read the angle of the knob, the range of angle is 0~280 degrees
* 
* disp.init(); // initialization
* disp.display(int Decimal);   // display range: -999 ~ 9999
* disp.clearDisplay(); // clear the display
* disp.set(uint8_t brightness); // set the brightness, 0 ~ 7, the greater the value, the higher the brightness, 
                                       //the next display takes effect
************************************************** **************************************************/
#include <Wire.h>
#include <SoftwareSerial.h>
#include "RichUNOTM1637.h"
#include "RichUNOKnob.h"
#define KNOB_PIN A0
Knob knob(KNOB_PIN);

#define CLK 10//CLK of the TM1637 IC connect to D10 of Arduino
#define DIO 11//DIO of the TM1637 IC connect to D11 of Arduino
TM1637 disp(CLK,DIO);

void setup()
{
  disp.init();//The initialization of the display
}

void loop()
{
  int angle;
  angle = knob.getAngle();
  disp.display(angle);
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
