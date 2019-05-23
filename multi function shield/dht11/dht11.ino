#include <SimpleDHT.h>

int pinDHT11 = 4;
SimpleDHT11 dht11;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{

  byte temperature = 0;
  byte humidity = 0;
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) 
  {
    Serial.print("Read DHT11 failed.");
    return;
  }
  
  Serial.print((int)temperature); 
  Serial.print(" *C, "); 
  Serial.print((int)humidity); 
  Serial.println(" %");
  delay(1000);
}
