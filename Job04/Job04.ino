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
  delay(Speed); // Wait for Speed millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(Speed); // Wait for Speed millisecond(s)
  digitalWrite(7, HIGH);
  delay(Speed); // Wait for Speed millisecond(s)
  digitalWrite(7, LOW);
  delay(Speed); // Wait for Speed millisecond(s)
  digitalWrite(10, HIGH);
  delay(Speed); // Wait for Speed millisecond(s)
  digitalWrite(10, LOW);
  delay(Speed); // Wait for Speed millisecond(s)
  digitalWrite(12, HIGH);
  delay(Speed); // Wait for Speed millisecond(s)
  digitalWrite(12, LOW);
  delay(Speed); // Wait for Speed millisecond(s)
}