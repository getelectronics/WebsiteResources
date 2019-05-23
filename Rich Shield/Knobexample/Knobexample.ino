#define KNOB_PIN A0//SIG pin of Rotary Angle Sensor module connect to A0 of IO Shield
#define FULL_ANGLE 280//full value of the rotary angle is 280 degrees

void setup()
{
  Serial.begin(9600);
  pinMode(KNOB_PIN, INPUT);
}

void loop()
{
  int angle;
  angle = getAngle();
  Serial.println(angle);
  delay(500);
}

inline int getAngle()
{
  int sensor_value = analogRead(KNOB_PIN);
  int angle;
  angle = map(sensor_value, 0, 1023, 0, 280);
  
  return angle;
}
