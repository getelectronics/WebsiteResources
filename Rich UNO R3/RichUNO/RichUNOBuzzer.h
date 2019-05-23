#ifndef __RichUNO_BUZZER_H__
#define __RichUNO_BUZZER_H__

#include <Arduino.h>


class Buzzer{

private:

    int _pin;

public:

    Buzzer(int pin)
    {
      _pin = pin;
      pinMode(_pin, OUTPUT);
      off();
    }
    
    inline void on()                        
    {
      digitalWrite(_pin, HIGH);
    }
    inline void off()                        
    {
      digitalWrite(_pin, LOW);
    }
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/