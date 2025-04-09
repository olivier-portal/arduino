const int buttonPin = 12;
const int ledPin = 11;
const int fanPin = 3;

int ledState = LOW;
int fanState = LOW;

int currentButtonState;
int lastButtonState;
int fanOn = 0;
long buttonTimer = 0;


void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, INPUT);
  currentButtonState = digitalRead(buttonPin);
  Serial.begin(9600);
}

void loop()
{
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(buttonPin);
  
  if (lastButtonState == HIGH && currentButtonState == LOW)
  {
    if (fanOn == 0)
    {
      buttonTimer = millis();
      if (ledState == LOW)
      {
        ledState = HIGH;
      }
    }
    else
    {
      fanState = LOW;
      fanOn = 0;
      buttonTimer = 0;
    }
  }
  else if (millis() - buttonTimer > 3000)
  {
    if (ledState == HIGH)
    {
      ledState = LOW;
      fanState = HIGH;
      fanOn = 1;
    }
  }
  digitalWrite(ledPin, ledState);
  digitalWrite(fanPin, fanState);

}