/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 12: Infrared remote control and display
* You can learn how to recoginze the key on the IR remote control and display the number on the display.
*
* The following functions are available:

* buzzer.on();//turn on the buzzer
* buzzer.off();//turn off the buzzer

* IR.enableIRIn(); // Start the receiver
* IR.decode();//if no result, it return 0, otherwise it return 1; .
* IR.resume(); // so that it can receive the next value
* IR.isReleased();//if the button is not released yet, it return 1; otherwise it return 0;
*
* disp.init (); // initialization
* disp.display (int8_t DispData []); // display the numbers in the array
* // For example, the array is {1,2,3,4}, then show 1234
* disp.display(uint8_t BitAddr, int8_t DispData); // bit by bit to display numbers, characters, BitAddr range is 0 ~ 3,
* // Parameter DispData range is 0 ~ 17 represents 0 ~ 9, A, b, c, d, E, F, -, space
* disp.display (int Decimal);   // display range: -999 ~ 9999
* disp.clearDisplay (); // clear the display
* disp.set (uint8_t brightness); // set the brightness, 0 ~ 7, the greater the value, the higher the brightness, 
                                       //the next display takes effect
* disp.point (0); // Turn off the display colon and the next display takes effect
* disp.point (1); // Turn on the display colon and the next display takes effect
************************************************** **************************************************/
#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOTM1637.h"
#include "RichUNOIRremote.h"
#include "RichUNOBuzzer.h"

#define BUZZER_PIN 9          //buzzer connect to D9 of Arduino
Buzzer buzzer(BUZZER_PIN);

#define RECV_PIN 2
IRrecv IR(RECV_PIN);

#define CLK 10//CLK of the TM1637 IC connect to D10 of Arduino
#define DIO 11//DIO of the TM1637 IC connect to D11 of Arduino
TM1637 disp(CLK,DIO);

unsigned char num = 0;
void setup()
{
  disp.init();//The initialization of the display
  IR.enableIRIn(); // Start the receiver
}

void loop()
{
  if (IR.decode()) {//If decode is valid

    if(IR.isReleased())//
	{
	  buzzer.on();//every time you press the key, the buzzer will beep
	  switch(IR.keycode)
	  {
	    case KEY_ZERO:  num = 0;break;
		case KEY_ONE:   num = 1;break;
		case KEY_TWO:   num = 2;break;
		case KEY_THREE: num = 3;break;
		case KEY_FOUR:  num = 4;break;
		case KEY_FIVE:  num = 5;break;
		case KEY_SIX:   num = 6;break;
		case KEY_SEVEN: num = 7;break;
		case KEY_EIGHT: num = 8;break;
		case KEY_NINE:  num = 9;break;
		case KEY_PLUS:  num = num+1;break;
		case KEY_MINUS: num = num-1;break;
		default: break;
	  }
	  disp.display(num);
	  delay(100);   //buzzer beep for 100ms
	  buzzer.off(); //turn off the buzzer
    }
    IR.resume(); // Receive the next value
  }
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
