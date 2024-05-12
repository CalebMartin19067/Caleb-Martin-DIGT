//19067
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h>

//TEACHER COMMENT what is this line of code doing?
LPS25HB pressureSensor; // Initiate an object of the LPS25HB class,

//TEACHER COMMENT what about these?
const String DATAFILE = "calebdata.csv";
const String DATAFILE2 = "calebdata.txt";
OpenLog sdCard;  //Create an instance of the openlog board

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("<LPS25HB Pressure Sensor Code>");

  // Initialize SD card //TEACHER COMMENT any checks you should do for the sdcard?
  sdCard.begin();
  sdCard.create(DATAFILE);
  sdCard.append(DATAFILE);  // Upload all further sdCard print statements to this file
  sdCard.create(DATAFILE2);
  sdCard.append(DATAFILE2);  // Upload all further sdCard print statements to this file
  Serial.println("Data file created");
  sdCard.syncFile();  // Buffer synced to the SD card

  // Initialize pressure sensor //TEACHER COMMENT and do a check
  if (pressureSensor.begin() == false) {
    Serial.println("LPS25HB not detected. Please check wiring.");
    while (1); // Stop here if the sensor is not detected
  }

  Serial.println("LPS25HB Connected");
  Serial.print("Millis,Pressure,Temp");
  sdCard.print("Millis,Pressure,Temp");//TEACHER COMMENT anything else you should sync up here?
}


void loop() {
  Serial.print(", ");
  Serial.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa
  Serial.print(", ");
  Serial.println(pressureSensor.getTemperature_degC());  // Get the temperature in degrees C
  Serial.print(millis());
  Serial.print(" ");

  // Write data to SD card
  sdCard.print(""); //TEACHER COMMENT why these 2 lines of code? is it issues around print and println?
  sdCard.print(", ");
  sdCard.print(pressureSensor.getPressure_hPa());  
  sdCard.print(", ");
  sdCard.println(pressureSensor.getTemperature_degC());
  sdCard.print(millis());
  sdCard.print(" ");
  sdCard.syncFile();

  delay(40);  // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}