#define LED1 7
#define LED2 6
#define LED3 5
#define LED4 4

uint8_t led[4];

void setup() 
{
  led[0] = LED1;
  led[1] = LED2;
  led[2] = LED3;
  led[3] = LED4;
  for(unsigned int i=0; i < 4; i++)
  {
        pinMode(led[i], OUTPUT);
        LEDoff(i+1);
  }
}

void loop() 
{
  for(uint8_t i=1;i < 5; i++)
  {
    LEDon(i);//turn on LED i
    delay(500);
    LEDoff(i);//turn off it.
  }
}

void LEDon(uint8_t num)//num = 1, 2, 3, 4
{
 if((num > 0) && (num < 5))
digitalWrite(led[num-1], HIGH);
}

void LEDoff(uint8_t num)//num = 1, 2, 3, 4
{
 if((num > 0) && (num < 5))
   digitalWrite(led[num-1], LOW);
}
