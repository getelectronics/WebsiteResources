#define KEY1_PIN 9//
#define KEY2_PIN 8//

uint8_t out[2];
int count = 0;

void setup()
{
  Serial.begin(9600);
  out[0] = KEY1_PIN;
  out[1] = KEY2_PIN;
  for(uint8_t i=0; i < 2; i++)
  {
        pinMode(out[i], INPUT);
        digitalWrite(out[i], HIGH);
  }
}

void loop()
{
  int keynum;
  keynum = get();
  if(keynum == 1) //if you press K1
  {
    delay(10);//delay for 10ms
    if(get() == 1)//check it again
    {
      count++;
    Serial.println(count);
    }
  while(get() == 1);//Wait for the button to be released
  }
  
}

uint8_t get()                        
{
  for(uint8_t i=0; i < 2; i++)
  {
      if(!digitalRead(out[i]))
      {
        delay(10);
        if(!digitalRead(out[i])) return i+1;
      }
}
return 0;
}
