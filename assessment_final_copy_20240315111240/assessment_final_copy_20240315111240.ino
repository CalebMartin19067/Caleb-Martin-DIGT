#19067
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h>

LPS25HB pressureSensor;

const String DATAFILE = "calebdata.csv";
OpenLog sdCard;  //Create an instance of the openlog board

void setup() {

  Wire.begin();
  sdCard.begin();
  sdCard.create(DATAFILE);
  sdCard.append(DATAFILE); //Upload all further sdCard print statements to this file 
  sdCard.println("Data file created");
  sdCard.syncFile(); //buffer synced to the sdCard
  Serial.begin(9600);
  Serial.println("LPS25HB Pressure Sensor - Basic Readings");
  Serial.println("sdCard should have a file now");
  
  
  if (pressureSensor.isConnected() == false) // if the pressure module is not connected, create error "DISCONNECTED"
  {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");     // Alert the user that the module isnt connected
    Serial.println("Are you using the right Wire port and I2C address?");      // Suggest possible fixes
    Serial.println("See Example2_I2C_Configuration for how to change these."); // Suggest possible fixes
    Serial.println("");
    while (1)
      ;
  }
}

void loop() {

  Serial.print("Pressure in hPa:");
  sdCard.println("Pressure in hPa:");
  Serial.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa
  sdCard.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa

  Serial.print(", Temperature (degC): ");
  sdCard.print(", Temperature (degC): ");
  Serial.println(pressureSensor.getTemperature_degC()); // Get the temperature in degrees C
  sdCard.println(pressureSensor.getTemperature_degC());
  sdCard.syncFile();

  delay(40); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}
}

