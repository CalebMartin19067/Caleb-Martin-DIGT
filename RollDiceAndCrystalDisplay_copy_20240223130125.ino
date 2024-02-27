#include <Adafruit_LiquidCrystal.h>

const byte BTNPIN = 1;
const byte NOISEPIN = A0;
const byte POTPIN = A1;

Adafruit_LiquidCrystal screen(0);

void setup() {
  pinMode(BTNPIN, INPUT);
  pinMode(POTPIN, INPUT);

  randomSeed(analogRead(NOISEPIN));

  Serial.begin(9600);

  if (!screen.begin(16, 2)) {
    Serial.println("couldn't start the screen - check wiring");
     while (1);
  }
}

void loop() {
  if (digitalRead(BTNPIN) == HIGH) {
    Serial.println("Rolling dice");
    int diceType = analogRead(POTPIN);
    diceType = map(diceType, 0, 1023, 1, 6);
    rollDice(diceType);
  }
}

void rollDice(byte numSides) {
  byte diceRoll = 255;

  switch (numSides) {
    case 1:
    screen.print("Roll is: ");
    diceRoll = random (1, 4);
    break;
    case 2:
    screen.print("Roll is: ");
    diceRoll = random (1, 6);
    break;
    case 3:
    screen.print("Roll is: ");
    diceRoll = random (1, 8);
    break;
    case 4:
    screen.print("Roll is: ");
    diceRoll = random (1, 10);
    break;
    case 5:
    screen.print("Roll is: ");
    diceRoll = random (1, 12);
    break;
    case 6:
    screen.print("Roll is: ");
    diceRoll = random (1, 20);
    break;
  }
  //HAN COMMENT you were missing the code I added below
  screen.print(diceRoll);
}
