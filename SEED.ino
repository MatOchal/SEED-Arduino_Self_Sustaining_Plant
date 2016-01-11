#include "Container.h"
#include "Monitor.h"
#include <Servo.h>
#include <LiquidCrystal.h>

Container container; 
Monitor monitorUnit;

int tickCount;
int ticksDay;
int ticksNight;
int interval;

int PIN_ledGreen;
int PIN_ledRed;

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16,2);
  
  monitorUnit.setup(PIN_ledGreen, PIN_ledRed, &lcd);
  container.setup(&monitorUnit);
  
  tickCount = 0;
  interval = 100;
}

void loop() {
  tickCount++;
  container.checkRespond(tickCount);
  container.updateMonitor();
  delay(interval);
}
