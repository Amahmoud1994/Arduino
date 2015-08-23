const int button_pin = 7;

void setup()
{
  pinMode(button_pin, INPUT);
  digitalWrite (button_pin, HIGH);
  Serial.begin (9600);
}

void loop()
{
  Serial.println (digitalRead (button_pin));
  delay (100);
}
