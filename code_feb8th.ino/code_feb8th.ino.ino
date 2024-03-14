#include <Servo.h>

//shared with Mr Hansen successfully :)
// 19067
//setting up pins
const byte LEDPIN = 13;
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;
const byte LEFTEARPIN = 9;
const byte RIGHTEARPIN = 10;

Servo leftEar;
Servo rightEar;

//setting pins as inputs and outputs
void setup() {
  pinMode(13, OUTPUT);
  pinMode(PAWPIN1, INPUT);
  pinMode(PAWPIN2, INPUT);
  pinMode(PAWPIN3, INPUT);
  pinMode(PAWPIN4, INPUT);
  leftEar.attach(LEFTEARPIN);
  rightEar.attach(RIGHTEARPIN);
}
// put your setup code here, to run once:


void loop() {
  if (digitalRead(LEDPIN) == HIGH) {
    digitalWrite(LEDPIN, LOW);
  }
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  if (digitalRead(PAWPIN3) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  if (digitalRead(PAWPIN4) == HIGH) {
    int score = playGame();
  }
}

void playMusic() {
}
int playGame() {
  byte score = 99;
  return score;
}
