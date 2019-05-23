/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 11: Test infrared remote keys 
*
* Learn how to get keys code of the buttons on the IR remote and display on the serial monitor of Arduino IDE.
*
* The following functions are available:
* IR.enableIRIn(); // Start the receiver
* IR.decode();//if no result, it return 0, otherwise it return 1; .
* IR.resume(); // so that it can receive the next value
* IR.isReleased();//if the button is not released yet, it return 1; otherwise it return 0;
*********************************************************************************************************/

#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOIRremote.h"

#define RECV_PIN 2
IRrecv IR(RECV_PIN);

void setup()
{
  Serial.begin(9600);
  IR.enableIRIn(); // Start the receiver
}

void loop()
{
  if (IR.decode()) {//If decode is valid

    if(IR.isReleased())//
	{
      Serial.print("user code is ");
      Serial.println(IR.usercode,HEX);
      Serial.print("key code is ");
      Serial.println(IR.keycode,HEX);
    }
	//else Serial.println("not released");
    IR.resume(); // Receive the next value
  }
}


/*********************************************************************************************************
The end of file
*********************************************************************************************************/
