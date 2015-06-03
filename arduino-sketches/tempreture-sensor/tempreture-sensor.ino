// Project Seven - temperature
//

int a;
int del=1000; // duration between temperature readings
float ctemperature;
float ftemperature;
int B=3975; 
float resistance;

void setup()
{
  Serial.begin(9600);  
}

void loop()
{
  a=analogRead(0);
  resistance=(float)(1023-a)*10000/a; 
  ctemperature=1/(log(resistance/10000)/B+1/298.15)-273.15;
  ftemperature=ctemperature*9/5+32;
  Serial.print(ctemperature);
  Serial.write(186);
  Serial.print("C ");
  Serial.print(ftemperature);
  Serial.write(186);
  Serial.println("F");
  delay(del);
}
