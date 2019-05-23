#include <Wire.h>

void EEwrite(byte data_addr, byte data, byte address=0x57)
{
    Wire.beginTransmission(address);
    Wire.write(data_addr);
    Wire.write(data);
    Wire.endTransmission();
}

byte EEread(int data_addr, byte address=0x57)
{
    Wire.beginTransmission(address);
    Wire.write(data_addr);
    Wire.endTransmission();
  
    Wire.requestFrom(address, 1);
    if(Wire.available())
      return Wire.read();
    else
      return 0xFF;
}

void setup() 
{
  Wire.begin();
  Serial.begin(9600);

  for(int addr = 0; addr < 10; addr++) 
  {
    EEwrite(addr, 10+addr);
    delay(100);
  }

  Serial.println("Have writen to memory!");

  for(int addr = 0; addr < 10; addr++) 
  {
    byte r = EEread(addr);
    Serial.print("address = ");
    Serial.print(addr);
    Serial.print(" - ");
    Serial.print("number = ");
    Serial.print(r);
    Serial.print("\n");
    delay(1000);
  }
  Serial.println("Have read 10 number from AT24C02!");
}

void loop() {
  
}


