//19067
#include <Servo.h>


//setting up pins
const byte LEDPIN = 13;
const byte BTNPIN  = 1;
const byte MICROPIN = 2;
const byte SERVOPIN = 2;
const byte LOCK = 0;
const byte UNLOCK = 90;
const byte LOUDENOUGH = 512;
Servo latch; //Create a servo for the latch



//setting pins as inputs and outputs
void setup() {
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  pinMode(BTNPIN, INPUT);
  pinMode(MICROPIN, INPUT);
  latch.attach(SERVOPIN);
  
}
// put your setup code here, to run once:


void loop() {
if(digitalRead(BTNPIN) == HIGH);
  Serial.print("Button has been pressed, locking") 
}
if (analogRead(MICROPIN) == 512);

Serial.print("Heard a knock")
Serial.print(analogRead(MICROPIN)
Serial.print(" is the loudness")
digtialWrite(LEDPIN, HIGH);
latch.write(UNLOCK);
analogWrite(BUZZER, 162)
for(pos = 155; pos>=130; pos-=3)     
    {                                
    doorServo.write(pos);   

}
