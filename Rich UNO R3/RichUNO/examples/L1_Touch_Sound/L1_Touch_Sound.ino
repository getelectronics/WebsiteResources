/************************************************* *************************************************
* OPEN-SMART Rich UNO R3 Lesson 1: Touch and sound
* You can learn about the touch pad control method, how to turn on and turn off the buzzer. 
*
* The following functions are available:
*
* buzzer.on();//turn on the buzzer
* buzzer.off();//turn off the buzzer
* touch.get(); // return is the touch area corresponding Arduino pin number, if not then return -1
* touch.getLongPress(); // return long press the corresponding Arduino pin number, if not return -1
*
************************************************** ************************************************** *****/
#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOTouchSensor.h"
#include "RichUNOBuzzer.h"

#define BUZZER_PIN 9          //buzzer connect to D9 of Arduino
Buzzer buzzer(BUZZER_PIN);

#define TOUCH_OUT1 3//out1-TCH1 area corresponds to turn on the buzzer
#define TOUCH_OUT2 4//out2-TCH2 area corresponds to turn off the buzzer
#define TOUCH_OUT3 5//out3-TCH3 area not use now
#define TOUCH_OUT4 6//out4-TCH4 area not use now
TouchSensor touch(TOUCH_OUT1,TOUCH_OUT2, TOUCH_OUT3,TOUCH_OUT4);


void setup()
{

}

void loop()
{
  int button;
  button = touch.get();
  if(button == TOUCH_OUT1) //if touch the TCH1 area
  {
    buzzer.on();//turn on the buzzer
  }
  else if(button == TOUCH_OUT2) //if touch the TCH2 area
  {
    buzzer.off();//turn off the buzzer
  }
  else if(button == TOUCH_OUT3) //if touch the TCH3 area
  {
  
  }
  else if(button == TOUCH_OUT4) //if touch the TCH4 area
  {
  }
 
  delay(50);//
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
