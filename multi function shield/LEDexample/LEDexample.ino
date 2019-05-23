#define redLed 12
#define blueLed 13

void setup() 
{
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}
 
void loop() 
{
  digitalWrite(redLed, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(blueLed, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(redLed, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(blueLed, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
}

