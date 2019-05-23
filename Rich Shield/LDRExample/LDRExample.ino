#include <math.h>

#define LIGHTSENSOR_PIN A2

void setup() 
{
  Serial.begin(9600); 
  pinMode(LIGHTSENSOR_PIN, INPUT);
}

void loop() 
{
  float Rsensor = getRes();//if Rsensor is larger than 40 KOhm, the ambient light is very dark.
                                       //if Rsensor is smaller than 10 KOhm, the ambient light is bright.
  Serial.println("The resistance of the Light sensor is "); 
  Serial.print(Rsensor,1);
  Serial.println(" KOhm");
  
  float lux;
  lux = 325*pow(Rsensor,-1.4);
  
  Serial.print("Illuminance is  ");
  Serial.print(lux,1);
  Serial.println(" lux");
  delay(1000);  
}

float getRes()
{
  int sensorValue = analogRead(LIGHTSENSOR_PIN);
  float Rsensor;
  Rsensor=(float)(1023-sensorValue)*10/sensorValue;
  return Rsensor;//unit is KOhm
}
