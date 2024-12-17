/* ********************************************
   *** CYD DS18B20 Temperature Sensor DEMO. ***
   *** Author: Charlie Morris               ***
   *** https://debugdiaries.co.uk/          ***
   *** Version: 0.1                         ***
   *** Last update: 17/12/24                ***
   ***************************************************************************************************
   *** This program will read the Temperature from a DS18B20 Temperature sensor and display the    ***
   *** Temperature when it changes, togeather with the Minimum, Maximum and Range Temperatures.    *** 
   ***************************************************************************************************
   *** Permission is hereby granted, free of charge, to any person obtaining a copy of this        ***
   *** software and associated documentation files. The above copyright notice and this permission ***
   *** notice shall be included in all copies or substantial portions of the Software.             ***
   ***************************************************************************************************
  */

#include <Arduino.h>

#include <OneWire.h>              // Used for DS18B20
#include <DallasTemperature.h>    // Used for DS18B20

// DS18B20 Temperature Sensor GPIO Pin 
#define DS18B20PIN 27 
#define noSensor -127 


// Setup DS18B20 Temperature Sensor
OneWire oneWire(DS18B20PIN);            // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire); 


void setup() {
  Serial.begin(115200);       // Start the Serial Monitor
  Serial.println("CYD Temperature Sensor Demo");

}

float tempC, tempLast;
float tempCMin = 999;
float tempCMax = -999;
float tempRange;

void loop() {
  sensors.requestTemperatures(); 
  tempC = sensors.getTempCByIndex(0);
  // Check the Sensor is connected and functioning
  if (tempC == noSensor) {
    Serial.println(" No Sensor detected, please check the wiring.");
  } else {
    // We are all good have a vaild Temperature
    if (tempC != tempLast) {
      tempLast = tempC; // Save the Temperature to compare agaest teh next Temperature read
      if (tempC < tempCMin) { tempCMin = tempC; } // Check for new Minimum Temperaure
      if (tempC > tempCMax) { tempCMax = tempC; } // Check for new Maximum Temperaure
      tempRange = tempCMax - tempCMin;
      // Display Temperature as it has changed
      Serial.printf("New Temperature: %.1fC - Min: %.1fC - Max: %.1fC, Range: %.1fC\n", tempC, tempCMin, tempCMax, tempRange);

    }
  }

  delay(500);
}
