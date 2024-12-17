  /* ***********************************
    *** CYD LDR CLASS           ***
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
  
#ifndef CYDLDR_H
#define CYDLDR_H

#include <Arduino.h>

#define LDR_PIN 34  // GPIO Pin of the LDR

class CYD_LDR
{
  public:
  void begin() {
    pinMode(LDR_PIN, INPUT);
    set_isDarkTreshold(400);    // Set the inital is Dark Threshold
  }

  // *** SETTERS ***
  void set_isDarkTreshold(uint16_t value){
    isDarkThreshold = value;
  };

  // *** Getters ***
  
  // Retruns boolean True if Dark , False is Light
  bool get_isDark(){ return isDark; }

  // Retruns the value of the is Dark Threshold
  uint16_t get_isDarkThreshold() { return isDarkThreshold; }

  // Retruns the value of the LDR
  uint16_t get_LDR(){
    uint16_t ldr = analogRead(LDR_PIN);
    if (ldr > isDarkThreshold) { isDark = true; } else { isDark = false; }
    //Serial.printf("Debug: V: %i, T: %i, Dark: %i\n", ldr, isDarkThreshold, isDark);
    return ldr;
  }

  private:
  bool isDark;
  uint16_t isDarkThreshold;

};


#endif // End of LSR Class
