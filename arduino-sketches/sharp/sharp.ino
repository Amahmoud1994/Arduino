int x;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main codere, to run repeatedly:
  x =  digitalRead(2);
  double d = 1309/(x-3);
  Serial.println(d);
  
}
