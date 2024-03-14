#19067
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"

const String FILENAME = "jokes.txt";
OpenLog sdCard;  //Create an instance of the openlog board

void setup() {
 
  Wire.begin();
  sdCard.begin();
  sdCard.create(FILENAME);
  sdCard.append(FILENAME); //Upload all further sdCard print statements to this file 
  sdCard.println("knock knock");
  sdCard.syncFile(); //buffer synced to the sdCard
  Serial.begin(9600);
  Serial.println("sdCard should have a file now, knock knock");
}

void loop() {
  sdCard.println("Knock knock");
  Serial.println("Knock knock");

  sdCard.println("Who's there?");
  Serial.println("Who's there?");

  sdCard.println("South african wimpering");
  Serial.println("South african wimpering");

  sdCard.println("South african wimpering who?");
  Serial.println("South african wimpering who?");

  sdCard.println("Justin");
  Serial.println("Justin");
  sdCard.syncFile();
}
