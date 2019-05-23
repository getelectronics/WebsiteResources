#include <SimpleDHT.h>

int pinDHT11 = 4;
float tempC;
int tempPin = 2;
byte temperature = 0;
byte humidity = 0;
SimpleDHT11 dht11;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{

  tempC = analogRead(tempPin);           //read the value from the sensor
  tempC = (5.0 * tempC * 100.0)/1024.0;  //convert the analog data to temperature
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) 
  {
    Serial.print("Read DHT11 failed.");
    return;
  }
  Serial.print("DHT11 - ");
  Serial.print((int)temperature); 
  Serial.print(" *C, ");
  Serial.print("LM35 - "); 
  Serial.print((byte)tempC);
  Serial.println(" *C");
  delay(1000);
}




