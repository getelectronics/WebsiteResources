const int buttonPin = 3;     // the number of the pushbutton pin
const int ledPin =  12;      // the number of the LED pin
 
int buttonState = 0;         // variable for reading the pushbutton status
 
void setup() 
{
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
 
void loop() 
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (buttonState == LOW) 
  {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } 
  else 
  {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

