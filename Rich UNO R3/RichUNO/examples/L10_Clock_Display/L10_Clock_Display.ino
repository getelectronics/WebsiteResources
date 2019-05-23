/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 10: Clock display
*
* Learn how to get the date and time from DS1307 module and display time on the 4-digit display.
*
* The following functions are available:

* timer1.initialize(unsigned long microseconds); // set the timed length, the unit is subtle
* timer1.attachInterrupt (TimingISR); // set interrupt routine function name, is the timing interrupt entry

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

* clock.begin(); // The clock is on and the function must be called first
* clock.startClock(void); // clock start, if you stop the clock need to call this function
* clock.stopClock(void); // clock stop timing
* clock.getTime(void); / / read the clock and time, will be saved in the clock class variable
* clock.fillByHMS(uint8_t _hour, uint8_t _minute, uint8_t _second); // write minutes
* clock.fillByYMD(uint16_t _year, uint8_t _month, uint8_t _day); // write clock
* clock.fillDayOfWeek(uint8_t _dow); // write week
* clock.setTime(void); // write the clock and time that have been written to the clock chip

*********************************************************************************************************/
#include <TimerOne.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOTM1637.h"
#include "RichUNODS1307.h"

DS1307 clock;//define a object of DS1307 class

#define CLK 10//CLK of the TM1637 IC connect to D10 of Arduino
#define DIO 11//DIO of the TM1637 IC connect to D11 of Arduino
TM1637 disp(CLK,DIO);

#define ON 1
#define OFF 0

int8_t TimeDisp[] = {0x00,0x00,0x00,0x00};
unsigned char ClockPoint = 1;
unsigned char Update;

void setup()
{
  disp.init();//The initialization of the display
  clock.begin();
  Timer1.initialize(500000);//timing for 500ms
  Timer1.attachInterrupt(TimingISR);//declare the interrupt serve routine:TimingISR  
}

void loop()
{
  if(Update == ON)//Update the display time, is to flash the clock porint
  {
    TimeUpdate();
    disp.display(TimeDisp);
  }
}
/**********Timer 1 interrupt routine*********/
void TimingISR()
{
  Update = ON;
  ClockPoint = !ClockPoint;
}

void TimeUpdate(void)
{
  if(ClockPoint)disp.point(POINT_ON);
  else disp.point(POINT_OFF);
  clock.getTime();
  TimeDisp[0] = clock.hour / 10;
  TimeDisp[1] = clock.hour % 10;
  TimeDisp[2] = clock.minute / 10;
  TimeDisp[3] = clock.minute % 10;
  Update = OFF;
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
