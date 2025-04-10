/*
  LiquidCrystal Library - Immersive systems G1

 This sketch prints "Immersive system" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 https://docs.arduino.cc/learn/electronics/lcd-displays

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin = 8;
const int ledPinRed = 6;
const int ledPinGreen = 7;

int currentButtonState;
int lastButtonState;

bool isPaused = false;
unsigned long startTime = 0;
unsigned long pausedTime = 0;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Immersive system");

    pinMode(buttonPin, INPUT_PULLUP);
    // read button's state
    currentButtonState = digitalRead(buttonPin);

    pinMode(ledPinGreen, OUTPUT);
    pinMode(ledPinRed, OUTPUT);

    // Turn on green LED with counter
    digitalWrite(ledPinGreen, HIGH);

    startTime = millis();
}

void loop() {
    // read button state
    currentButtonState = digitalRead(buttonPin);

    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);

    // add a condition to know if the button is pushed
    if (lastButtonState == HIGH && currentButtonState == LOW)
    // button has been pressed
    {
        if (!isPaused)
        {
            // stop the timer:
            pausedTime = millis() - startTime;
            isPaused = true;
            digitalWrite(ledPinGreen, LOW);
            digitalWrite(ledPinRed, HIGH);
        }
        else
        {
            startTime = millis();
            pausedTime = 0;
            isPaused = false;
            digitalWrite(ledPinGreen, HIGH);
            digitalWrite(ledPinRed, LOW);
        }
    delay(200);
    }

    lastButtonState = currentButtonState;

    unsigned long currentSeconds;
    if (isPaused) {
        currentSeconds = pausedTime / 1000;
    }
    else
    {
        currentSeconds = (millis() - startTime) / 1000;
    }

    lcd.setCursor(0, 1);
    lcd.print("Timer: ");
    lcd.print(currentSeconds);
    lcd.print(" s");
}