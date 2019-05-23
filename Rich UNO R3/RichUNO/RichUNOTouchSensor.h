#ifndef _RichUNO_TOUCHSENSOR_H__
#define _RichUNO_TOUCHSENSOR_H__

#include <Arduino.h>


class TouchSensor{

private:

    int out[4];

public:

    TouchSensor(int out1, int out2, int out3, int out4)
    {
        out[0] = out1;
		out[1] = out2;
		out[2] = out3;
		out[3] = out4;
		for(unsigned int i=0; i < 4; i++){
          pinMode(out[i], INPUT);
          digitalWrite(out[i], HIGH);
		}
        
    }
    
    int get()                        
    {
      for(unsigned int i=0; i < 4; i++){
          if(digitalRead(out[i])){
		  	delay(10);
		  	if(digitalRead(out[i])) return out[i];
          }
		}
	  return -1;
    }
    int getLongPress()
    {
      for(unsigned int i=0; i < 4; i++){
          if(digitalRead(out[i])){
		  	for(unsigned int j=0; j < 150; j++){
		  	delay(20);
		  	if(digitalRead(out[i]) == LOW) return - 1;
		  	}
			return out[i];
          }
		}
    }
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/