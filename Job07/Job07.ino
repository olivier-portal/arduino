// Ardwinner LED-008-Bouton.
// code Arduino pour allumer une LED avec un bouton poussoir.

/* note de montage : brancher le Bouton poussoir sur la PIN 2, allimenter le Bouton poussoir en le branchant sur la PIN 5V, et reparter par sa troisième broche vers la résistance, la LED et finallement le Gnd. La quatrième broche du Bouton poussoir n’est pas utilisée*/


int bouton = 5;                       // constante indiquant que le bouton est sur la broche 2
int led;                              // déclare la LED, crée donc une constante appelé led
int etatbouton;                       // variable représentant le bouton, soit ouvert ou fermé

void setup() {
  pinMode (bouton, INPUT);            // on indique que le bouton est une entrée
  pinMode (led, OUTPUT);              // on indique que la LED est une sortie
}

void loop() {
  etatbouton = digitalRead (bouton);  // On lit l’état du bouton pour savoir s’il est ouvert ou fermé

  if (etatbouton==LOW) {              // Si la variable “etatbouton” est fermé
    digitalWrite (led, HIGH);         // alors le logiciel “écrit” Haut, c’est à dire qu’il allume la LED, qu’il laisse passer l’électricité
  }
  
  else {
    digitalWrite(led, LOW);           // Sinon le logiciel “écrit” Bas, c’est à dire qu’il éteint la LED, qu’il ne laisse pas passer l’électricité
  }
  
  delay(100) ;                        // on attend un délais de 100 millisecondes avant de relancer la boucle et tester l’état du bouton.

}
