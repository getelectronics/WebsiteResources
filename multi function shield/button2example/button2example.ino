const int button1Pin = 2;     // the number of the pushbutton pin
const int button2Pin = 3;
const int led1Pin =  12;      // the number of the LED pin
const int led2Pin =  13;
 
int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;
 
void setup() 
{
  // initialize the LED pin as an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
}
 
void loop() 
{
  // read the state of the pushbutton value:
  button1State = digitalRead(button1Pin);
 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (button1State == LOW) 
  {
    digitalWrite(led1Pin, HIGH);
  } 
  else 
  {
    digitalWrite(led1Pin, LOW);
  }

    // read the state of the pushbutton value:
  button2State = digitalRead(button2Pin);
 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (button2State == LOW) 
  {
    digitalWrite(led2Pin, HIGH);
  } 
  else 
  {
    digitalWrite(led2Pin, LOW);
  }
}

