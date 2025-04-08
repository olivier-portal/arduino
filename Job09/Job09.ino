const int buttonPin = 2;
const int ledPin = 8;

enum LedState { OFF, ON, BLINK };
LedState currentState = OFF;

unsigned long pressStartTime = 0;
unsigned long lastClickTime = 0;
unsigned long clickWindowStart = 0;

int lastButtonState = HIGH;
int clickCount = 0;
bool waitingClickSequence = false;

const unsigned long debounceDelay = 50;
const unsigned long clickDelay = 400;
const unsigned long longPressTime = 1000;

bool ledOn = false;
unsigned long lastBlink = 0;
const unsigned long blinkInterval = 500;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();
  int reading = digitalRead(buttonPin);

  // === GESTION APPUI ===
  if (reading != lastButtonState) {
    delay(debounceDelay); // anti-rebond simple
    if (reading == LOW) {
      pressStartTime = now;
      Serial.println("↓ Pression détectée");
    } else {
      unsigned long pressDuration = now - pressStartTime;
      if (pressDuration >= longPressTime) {
        currentState = OFF;
        clickCount = 0;
        waitingClickSequence = false;
        Serial.println("→ Appui long → OFF");
      } else {
        clickCount++;
        lastClickTime = now;
        if (!waitingClickSequence) {
          waitingClickSequence = true;
          clickWindowStart = now;
        }
        Serial.print("→ Clic #");
        Serial.println(clickCount);
      }
    }
    lastButtonState = reading;
  }

  // === TRAITEMENT SÉQUENCE DE CLICS ===
  if (waitingClickSequence && (now - lastClickTime > clickDelay)) {
    Serial.print("==> Fin de séquence : ");
    Serial.print(clickCount);
    Serial.println(" clic(s)");

    switch (clickCount) {
      case 1:
        currentState = ON;
        break;
      case 2:
        currentState = ON;
        break;
      case 3:
        currentState = BLINK;
        break;
      default:
        currentState = OFF;
        break;
    }

    clickCount = 0;
    waitingClickSequence = false;
  }

  // === COMPORTEMENT LED ===
  switch (currentState) {
    case OFF:
      digitalWrite(ledPin, LOW);
      break;
    case ON:
      digitalWrite(ledPin, HIGH);
      break;
    case BLINK:
      if (now - lastBlink >= blinkInterval) {
        ledOn = !ledOn;
        digitalWrite(ledPin, ledOn ? HIGH : LOW);
        lastBlink = now;
      }
      break;
  }
}
