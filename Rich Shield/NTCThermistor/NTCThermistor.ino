#define NTC_PIN A1 //SIG pin of NTC module connect to A1 of IO Shield, that is pin A1 of OPEN-SMART UNO R3
#define SAMPLING_RESISTOR  10000//the sampling resistor is 10k ohm
#define NTC_R25 10000//the resistance of the NTC at 25'C is 10k ohm
#define NTC_B   3950

void setup()
{
  Serial.begin(9600);
  delay(1000);//
}

void loop()
{
  float celsius;
  celsius = getTemperature();//get temperature
  Serial.println((int8_t)celsius);//
  delay(1000);//delay 1000ms
}


float getTemperature()
{
  float temperature,resistance;
  int a;
  a = analogRead(NTC_PIN);
  resistance   = (float)a*SAMPLING_RESISTOR/(1024-a); //Calculate the resistance of the thermistor
  /*Calculate the temperature according to the following formula.*/
  temperature  = 1/(log(resistance/NTC_R25)/NTC_B+1/298.15)-273.15;
  return temperature;
}
