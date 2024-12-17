  /* ***********************************
    *** CYD RGB LED CLASS           ***
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

  #ifndef CYD_RGBLED_H
  #define CYD_RGBLED_H

  #include <Arduino.h>

  // Define LED Color GPIO pins
  #define CYD_LED_BLUE  17
  #define CYD_LED_RED   4
  #define CYD_LED_GREEN 16

  // Setting the LED GPIO PIN LOW turns to the LED
  #define LED_ON      LOW
  #define LED_OFF     HIGH

  // Define the allowed LED Colors
  enum LED_Color{ RED, GREEN, BLUE, PURPLE, YELLOW, CYAN, WHITE };


  class CYD_LED{
    public:
    // Turn off all LEDs
    void turnOff(){
      digitalWrite(CYD_LED_RED, LED_OFF);
      digitalWrite(CYD_LED_GREEN, LED_OFF);
      digitalWrite(CYD_LED_BLUE, LED_OFF);
    }

    void begin() {
      // Configure RGB LED GPIOs as outputs
      pinMode(CYD_LED_RED, OUTPUT);
      pinMode(CYD_LED_GREEN, OUTPUT);
      pinMode(CYD_LED_BLUE, OUTPUT);
    
      // Turn off the LED
      turnOff();
      }

    void set_Color(LED_Color color) {
      if (color == RED)         { setLEDRed();    }
      else if (color == GREEN)  { setLEDGreen();  }
      else if (color == BLUE)   { setLEDBlue();   }
      else if (color == PURPLE) { setLEDPurple(); }
      else if (color == YELLOW) { setLEDYELLOW(); }
      else if (color == CYAN)   { setLEDCYAN();   }
      else if (color == WHITE)  { setLEDWHITE();  }
      else { turnOff(); }
    }

    private:

    // Set LED to RED
    void setLEDRed(){
      digitalWrite(CYD_LED_RED, LED_ON);
      digitalWrite(CYD_LED_GREEN, LED_OFF);
      digitalWrite(CYD_LED_BLUE, LED_OFF);
    }
  
    // Set LED to GREEEN
    void setLEDGreen(){
      digitalWrite(CYD_LED_RED, LED_OFF);
      digitalWrite(CYD_LED_GREEN, LED_ON);
      digitalWrite(CYD_LED_BLUE, LED_OFF);
    }
    
    // Set LED BLUE
    void setLEDBlue(){
      digitalWrite(CYD_LED_RED, LED_OFF);
      digitalWrite(CYD_LED_GREEN, LED_OFF);
      digitalWrite(CYD_LED_BLUE, LED_ON); 
    }
  
    // Set LED CYAN (Blue and Green)
    void setLEDCYAN(){
      digitalWrite(CYD_LED_RED, LED_OFF);
      digitalWrite(CYD_LED_GREEN, LED_ON);
      digitalWrite(CYD_LED_BLUE, LED_ON);
    }

    // Set LED PURPLE (Red and Blue)
    void setLEDPurple(){
      digitalWrite(CYD_LED_RED, LED_ON);
      digitalWrite(CYD_LED_GREEN, LED_OFF);
      digitalWrite(CYD_LED_BLUE, LED_ON);
    }

    // Set LED YELLOW (Red and Green)
    void setLEDYELLOW(){
      digitalWrite(CYD_LED_RED, LED_ON);
      digitalWrite(CYD_LED_GREEN, LED_ON);
      digitalWrite(CYD_LED_BLUE, LED_OFF);
    }

    // Set LED WHITE (Red and Blue and Green)
    void setLEDWHITE(){
      digitalWrite(CYD_LED_RED, LED_ON);
      digitalWrite(CYD_LED_GREEN, LED_ON);
      digitalWrite(CYD_LED_BLUE, LED_ON);
    }

  }; // End of CYD_LED Class

  #endif