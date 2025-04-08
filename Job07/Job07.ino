// C++ code
//
int Speed = 0;

void setup()
{
  int i = 0;
  for (i=2; i<10; i++)
  {
    pinMode(i, OUTPUT); // Declare LED from 2 to 9
  }

  Speed = 400; // Wait for Speed millisecond(s)
}

void loop()
{
  int i = 0;
  for (i=2; i<10; i++)
  {
    digitalWrite(i, HIGH); // Turn on Led
    delay(Speed); 
    digitalWrite(i, LOW); // Turn off Led
    delay(Speed); 
  }
}