//19067 Caleb Martin
// FINAL ITERATION 6
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

// Constants
const String DATAFILE = "rocket_data.csv";  // Set file name as "rocket_data.csv"
const int UPDATE_INTERVAL = 40;             // Interval between data logging as 40ms corresponds to the maximum update rate of the sensor (25 Hz)
const int BUZZER_PIN = 8;                   // set buzzer pin as 8

// Objects
LPS25HB pressureSensor;  // Start instance of LPS25HB module 
OpenLog sdCard;          // Create instance of OpenLog class to data log

// Functions  
void setup() {                  //setup
  Wire.begin();                 // Start I2C communication
  Serial.begin(9600);           // Begin serial monitor
  pinMode(BUZZER_PIN, OUTPUT);  // Set the buzzer pin as an output

  sdCard.begin();           // Begin communication with the OpenLog board
  sdCard.create(DATAFILE);  // Create a data file
  sdCard.append(DATAFILE);  // Append data file
  sdCard.syncFile();        // Sync the file with the OpenLog board

  if (!pressureSensor.begin()) {  // Checking if the pressure sensor has successfully initialized
    Serial.println("LPS25HB module not detected. Please check wiring.");
    while (1);  // Stop here if the sensor is not detected
  }

  Serial.println("Initialization complete.");  //Print if successful
}

void loop() {
  logData(false);               // Call the function for logging data: if false testing. If true normal function
  delay(UPDATE_INTERVAL);  // Wait for the specified interval at setup
}

//parameter
void logData(bool testing) {
  // Read pressure and temperature data
  float pressure = pressureSensor.getPressure_hPa();         // Grab pressure reading in hPa
  float temperature = pressureSensor.getTemperature_degC();  // Grab temperature reading

  //I used float particularly because I thought they offer greater resolution than integers. And to meet assesment stuff.

  unsigned long currentTime = millis();  // Get the current time in millis
  if(testing){
  // Print pressure and temperature readings to serial monitor
  Serial.print("Pressure (hPa): ");
  Serial.print(pressure);
  Serial.print(", Temperature (°C): ");
  Serial.println(temperature);
  }
  // Write data to the data file on the OpenLog board, done in .CSV format as per the ","
  sdCard.print(currentTime);  // Write current time tracked to the sdCard
  sdCard.print(",");
  sdCard.print(pressure);  // Write pressure reading to the data sdCard
  sdCard.print(",");
  sdCard.println(temperature);  // Write temperature reading to the sdCard
  sdCard.syncFile();            // Sync file now

  // Safety iteration: Checking for unsafe temperature or pressure levels, or buzzer will go
  if (temperature > 40 || pressure > 1200) {  // if temperature exceeds 40°C or pressure exceeds 1200 hPa
    digitalWrite(BUZZER_PIN, HIGH);           // Turn on the buzzer
    delay(500);                               // Keep the buzzer on for 500 milliseconds
    digitalWrite(BUZZER_PIN, LOW);            // Turn off the buzzer
  }
}