/* ***********************************
   *** CYD LDR DEMO.               ***
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

#include "CYDLDR.h"

CYD_LDR LDR;

void setup() {
	Serial.begin(115200);   // Initialise Serial Port

  Serial.println("CYD LDR Demo");
  LDR.set_isDarkTreshold(10);

}

void loop() {
  int ldrValue = LDR.get_LDR();
  String dark;
  if (LDR.get_isDark()) { dark = "Dark"; } else { dark = "Light"; } 
  Serial.printf("LDR Value: %i and is %s (threshold: %i)\n", ldrValue, dark, LDR.get_isDarkThreshold());

delay(500);

}    
