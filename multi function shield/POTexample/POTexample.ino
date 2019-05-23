#define vrPin A0

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
 
void loop() 
{
  // read the variable resistor on analog pin 0:
  float vrValue = analogRead(vrPin);
  // Convert the analog reading to a voltage
  float vrVoltage = vrValue * (5.0 / 1023.0); 
  // print out the Variable resistor value you read:
  Serial.print("Variable resistor : ");
  Serial.println(vrVoltage);
  delay(1000);
}

