/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 9: Clock input
* Note: Make sure you have plugged the CR1220 battery onto the battery holder.
* Learn to use the touch button to enter the year, month, day, week, hour, minute, to initialize the clock module data,
*  and you can see whether your setting is ok from the serial monitor of Arduino IDE.
*
* The following functions are available:

* timer1.initialize(unsigned long microseconds); / / set the timed length, the unit is subtle
* timer1.attachInterrupt (TimingISR); / / set interrupt routine function name, is the timing interrupt entry
* timer1.stop(); // Timer 1 stops timing
* timer1.start(); // Start Timer 1

* disp.init(); // initialization
* disp.display(int Decimal); / / display range: -999 ~ 9999
* disp.clearDisplay(); // clear the display
* disp.set(uint8_t brightness); / / set the brightness, 0 ~ 7, the greater the value, the higher the brightness, the next display

* clock.begin(); // The clock is on and the function must be called first
* clock.startClock(void); / / clock start, if you stop the clock need to call this function
* clock.stopClock(void); // clock stop timing
* clock.getTime(void); / / read the clock and time, will be saved in the clock class variable
* clock.fillByHMS(uint8_t _hour, uint8_t _minute, uint8_t _second); // write minutes
* clock.fillByYMD(uint16_t _year, uint8_t _month, uint8_t _day); // write clock
* clock.fillDayOfWeek(uint8_t _dow); // write week
* clock.setTime(void); // write the clock and time that have been written to the clock chip

* touch.get(); / / return is the touch area corresponding Arduino pin number, if not then return -1
* touch.getLongPress(); / / return long press the corresponding Arduino pin number, if not return -1
************************************************** ************************************************** *****/


#include <TimerOne.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOTM1637.h"
#include "RichUNOTouchSensor.h"
#include "RichUNODS1307.h"

DS1307 clock;//define a object of DS1307 class

#define CLK 10//CLK of the TM1637 IC connect to D10 of Arduino
#define DIO 11//DIO of the TM1637 IC connect to D11 of Arduino
TM1637 disp(CLK,DIO);

#define TOUCH_OUT1 3//out1-TCH1 area corresponds to the number increase
#define TOUCH_OUT2 4//out2-TCH2 area corresponds to the number decrease
#define TOUCH_OUT3 5//out3-TCH3 area corresponds to confirm the number you set (OK Button)
#define TOUCH_OUT4 6//out4-TCH4 area corresponds to make it enter next step("next step button")
TouchSensor touch(TOUCH_OUT1,TOUCH_OUT2, TOUCH_OUT3,TOUCH_OUT4);

uint8_t flag_disp = 0;     // display flag, 0 = display off, 1 = display on
uint8_t flag_monitor = 0;    //
uint8_t flag_ok = 0;       // confirm flag, 1 = just press the OK button
uint8_t flag_next = 0;     // next step flag, 1 = just press the NEXT button
uint8_t flag_change = 0;   // digital modification flag, 1 = number can be modified by key, 0 = number can not be modified by key
uint8_t flag_monitor_end = 0;//
uint8_t flag_write = 0;    // 1 = You can write the clock and time to the DS1307 clock module

uint8_t next = 0;          // Each time you press the button, it increments by one, and if it is equal to 7 it returns to 0
#define YEAR      1 
#define MONTH     2
#define DAY       3
#define DAYOFWEEK 4
#define HOUR      5
#define MINUTE    6

int num = 2017;




void setup()
{
  Serial.begin(9600);//the baud rate of serial monitor is 9600bps
  disp.init();//The initialization of the display
  clock.begin();
  Timer1.initialize(500000);//timing for 500ms
  Timer1.attachInterrupt(TimingISR);
  Timer1.stop();
  flag_disp = 1;
  
  clock.year = 2017;// The clock initial value is set to be Sunday, January 1, 2017
  clock.month = 1;
  clock.dayOfMonth = 1;
  clock.dayOfWeek = 7;
  clock.hour = 12;// The time initial value is set to 12:30
  clock.minute = 30;
}

void loop()
{
/*---------------------------------------------------*/
  int button;
  button = touch.get();
  if(button != -1)// there is a touch
  {
    delay(10);
	if(button == touch.get())// Check again if there is a touch
	{
	  switch(button)
	  {
	    case TOUCH_OUT1: if(flag_change)num++; break;//touch TCH1 area corresponds to the number increase
		case TOUCH_OUT2: if(flag_change)num--; break;//touch TCH2 area corresponds to the number decrease
		case TOUCH_OUT3: if(next == 6)flag_monitor = 1;
		                 flag_ok = 1;
		                 if(flag_monitor_end) 
						 {flag_write = 1; flag_monitor_end = 0;}
						 flag_change = 0;//Has been confirmed, can not be adjusted
						 break;//
		case TOUCH_OUT4: flag_next = 1; next++;
		                 flag_change = 1;//You can adjust the number
		                 break;//touch TCH4 area, each time you press the button will enter the next set process
		default: break;
	  }
      if(next == 7)next = 0;
	}
	while(button == touch.get());//Wait for the button to be released
  }
/*---------------------------------------------------*/

  if(flag_disp) disp.display(num);
  else disp.clearDisplay();
/*---------------------------------------------------*/
  if((next!=0) && (next < 7))
  {
    if(flag_next)
    {
      Timer1.start();//start timer1
	  
      flag_next = 0;
      
	  switch(next)
	  {
	    case YEAR: num = clock.year; Serial.println("year is");break;
		case MONTH: num = clock.month;Serial.println("month is");break;
		case DAY: num = clock.dayOfMonth;Serial.println("dayOfMonth is");break;
		case DAYOFWEEK: num = clock.dayOfWeek;Serial.println("dayOfWeek is");break;
		case HOUR: num = clock.hour;Serial.println("hour is");break;
		case MINUTE: num = clock.minute;Serial.println("minute is");break;
		default: break;
	  }
    }
/*---------------------------------------------------*/	
	if(flag_ok)
    {
      Timer1.stop();// timer stops timing
	  flag_disp = 1;// Let the number stop flashing and keep it steady
	  
      switch(next)
	  {
	    case YEAR: clock.year=num; break;
		case MONTH: clock.month=num;break;
		case DAY: clock.dayOfMonth=num;break;
		case DAYOFWEEK: clock.dayOfWeek=num;break;
		case HOUR: clock.hour=num;break;
		case MINUTE: clock.minute=num;break;
		default: break;
	  }
	  Serial.println(num);
	  flag_ok = 0;
    }
/*---------------------------------------------------*/	
	if(flag_monitor)
	{
	  flag_monitor = 0;
	  Serial.print("Your setting clock is ");
	  Serial.print(clock.year);
	  Serial.print("/");
	  Serial.print(clock.month);
	  Serial.print("/");
	  Serial.print(clock.dayOfMonth);
	  Serial.print(" ");
	  switch (clock.dayOfWeek)// Friendly printout the weekday
	{
		case MON:
		  Serial.print("MON");
		  break;
		case TUE:
		  Serial.print("TUE");
		  break;
		case WED:
		  Serial.print("WED");
		  break;
		case THU:
		  Serial.print("THU");
		  break;
		case FRI:
		  Serial.print("FRI");
		  break;
		case SAT:
		  Serial.print("SAT");
		  break;
		case SUN:
		  Serial.print("SUN");
		  break;
	}
	Serial.print(" ");
	Serial.print(clock.hour, DEC);
	Serial.print(":");
	Serial.print(clock.minute, DEC);

	  flag_monitor_end = 1;
	}
	
	if(flag_write)
	{
	  num = 0;
	  flag_write = 0;
	  clock.fillByYMD(clock.year,clock.month,clock.dayOfMonth);//
	  clock.fillDayOfWeek(clock.dayOfWeek);//
	  clock.fillByHMS(clock.hour,clock.minute,0);//
	  clock.setTime();//write time to the RTC chip
	  Serial.println(" Your date and time is wrote to the DS1307 chip");
	}
  }
/*---------------------------------------------------*/  

}
/**********Timer 1 interrupt routine*********/
void TimingISR()
{
  flag_disp = !flag_disp;
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
