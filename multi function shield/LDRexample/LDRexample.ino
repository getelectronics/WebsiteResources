#define ldrPin A1

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
 
void loop() 
{
  // read the LDR on analog pin 1:
  float ldrValue = analogRead(ldrPin);
  // Convert the analog reading to a voltage
  float ldrVoltage = ldrValue * (5.0 / 1023.0);
  // print out the LDR value you read:
  Serial.print("LDR value : ");
  Serial.println(ldrVoltage);
  delay(1000);
}

