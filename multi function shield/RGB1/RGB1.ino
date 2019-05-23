#define redLed 9
#define greenLed 10
#define blueLed 11

void setup()
{

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);  
}
 
void loop()
{
  for (int i=0; i <= 255; i++)
  {
    setColor(i, 0, 0);  // red
    delay(10);
  }
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redLed, red);
  analogWrite(greenLed, green);
  analogWrite(blueLed, blue);  
}

