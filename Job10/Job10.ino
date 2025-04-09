int ledPin1 = 10;
int ledPin2 = 9;     // On renomme la broche 9 en "ledPin"
int analogPin = 0;  // Le potentiomètre est connecté à la broche analogue 0
int value;        // la variable qui stocke la valeur lue est mise à 0

void setup()
{
  	pinMode(ledPin1, OUTPUT);
  	pinMode(ledPin2, OUTPUT);
  	Serial.begin(9600);
}

void loop()
{
    value = map(analogRead(analogPin), 0, 1023, 0, 255);  //lecture de la valeur analogue (potentiomètre)
    analogWrite(ledPin1, value);  // valeur analogue lue (0 à 1023) divisée par 4 (0 à 255)
  	analogWrite(ledPin2, 255 - value);
}