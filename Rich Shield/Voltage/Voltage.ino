#define VOL_SENSOR A3
#define GAIN 0.18// Vread = VIN * GAIN
#define ADC_REF 5  //reference voltage of ADC is 5v

uint8_t samples = 10;

void setup(){
  Serial.begin(9600);
}

void loop(){  
   float vol;
   vol = readValue();
   Serial.println(vol);
   delay(1000);
}

float readValue()
{
  int sensorValue;
  long  sum=0;
    for(uint8_t i = 0;i < samples;i ++)
    {  
      sensorValue=analogRead(VOL_SENSOR);
      sum += sensorValue;
      delay(2);
    }   
    sensorValue = sum / samples;//Calculate the average
    float vol = sensorValue*ADC_REF/1023.00/GAIN;
    return vol;
}
