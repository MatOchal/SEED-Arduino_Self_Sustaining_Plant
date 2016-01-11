#include "Monitor.h"
#include "Arduino.h"

Monitor::Monitor() { }
Monitor::~Monitor() { }

void Monitor::setup(int PIN_ledGreen, int PIN_ledRed, LiquidCrystal* PT_lcd)
{   
    this->PIN_ledGreen = PIN_ledGreen;
    this->PIN_ledRed = PIN_ledRed;

    this->PT_lcd = PT_lcd;

    pinMode(PIN_ledGreen, OUTPUT);
    pinMode(PIN_ledRed, OUTPUT);
}

void Monitor::updateMonitor(int temperature, int lightIntensity, int waterSaturation, bool emptyContainer)
{    
  // Update LCD
  (*PT_lcd).setCursor(0, 1);
  (*PT_lcd).print("TdC:"+ temperature);
  (*PT_lcd).setCursor(0, 8);
  (*PT_lcd).print("WT%:"+ waterSaturation);
  (*PT_lcd).setCursor(1, 1);
  (*PT_lcd).print("LI%:" + lightIntensity);
  (*PT_lcd).setCursor(1, 8);

  // Update LED indicators
  if (emptyContainer) {
    digitalWrite(PIN_ledGreen, LOW);
    digitalWrite(PIN_ledRed, HIGH);
    (*PT_lcd).print("WTR: YES");          // Water refil is set to yes
  } else {
    digitalWrite(PIN_ledGreen, HIGH);
    digitalWrite(PIN_ledRed, LOW);
    (*PT_lcd).print("WTR: NO");           // Water refil is set to no
  }
}
