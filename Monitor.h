#include "Arduino.h"
#include <LiquidCrystal.h>

#ifndef MONITOR_h
#define MONITOR_h

class Monitor
{
  public:
    Monitor();
    ~Monitor();

    void setup(int PIN_ledGreen, int PIN_ledRed, LiquidCrystal* PT_lcd);

    void updateMonitor(int temperature, int lightIntensity, int waterSaturation, bool emptyContainer); 

    LiquidCrystal* PT_lcd;
    
  private:
    int PIN_ledGreen;
    int PIN_ledRed;
};

#endif
