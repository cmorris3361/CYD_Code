/* ***********************************
   *** CYD RGB LED CLASS DEMO      ***
   *** Author: Charlie Morris      ***
   *** https://debugdiaries.co.uk/ ***
   *** Version: 0.1                ***
   *** Last update: 17/12/24       ***
   ***************************************************************************************************
   *** Permission is hereby granted, free of charge, to any person obtaining a copy of this        ***
   *** software and associated documentation files. The above copyright notice and this permission ***
   *** notice shall be included in all copies or substantial portions of the Software.             ***
   ***************************************************************************************************
*/

#include <Arduino.h>

  #include "CYD_RGBLED.h"

CYD_LED LED;

void setup() {
  Serial.begin(115200); // Initialise Serial port
  Serial.println("CYD RGB LED Demo");

  LED.begin();          // Initialise LED Object
}

void loop() {
  LED.set_Color(RED);
  delay(1000);
  
  LED.set_Color(GREEN);
  delay(1000);

  LED.set_Color(BLUE);
  delay(1000);

  LED.set_Color(YELLOW);
  delay(1000);

  LED.set_Color(PURPLE);
  delay(1000);

  LED.set_Color(CYAN);
  delay(1000);

  LED.set_Color(WHITE);
  delay(1000);

  LED.turnOff();
  delay(1000);



}
