#ifndef __RichUNO_KNOB_H__
#define __RichUNO_KNOB_H__

#include <Arduino.h>

#define FULL_ANGLE 280//full value of the rotary angle is 280 degrees
class Knob{

private:

    int _pin;

public:

    Knob(int pin)
    {
      _pin = pin;
      pinMode(_pin, INPUT);
    }
    
/********************************************************************************/
/*Function: Get the angle between the mark on the potentiometer cap and the starting position	*/
/*Parameter:-void                                                                                                          */
/*Return:     -int,the range of degrees is 0~280                                                                 */
   inline int getAngle()
   {
	 int sensor_value = analogRead(_pin);
	 int angle;
	 angle = map(sensor_value, 0, 1023, 0, 280);
	 return angle;
   }
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/