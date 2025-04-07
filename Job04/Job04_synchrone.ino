// C++ code
//
int Speed = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);

  Speed = 400;
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  delay(Speed); // Wait for Speed millisecond(s)
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  delay(Speed);
}