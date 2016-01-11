#include "TempUnit.h"
#include "Arduino.h"

TempUnit::TempUnit() { }
TempUnit::~TempUnit() { }

void TempUnit::setup(int PIN_tempSensor, int PIN_heatElement)
{   
    this->PIN_tempSensor = PIN_tempSensor;
    this->PIN_heatElement = PIN_heatElement;

    pinMode(PIN_tempSensor, INPUT);
    pinMode(PIN_heatElement, OUTPUT);
}

void TempUnit::checkRespond()
{
    int value = analogRead(PIN_tempSensor);
    
    heaterOff();
    
    if (value > 200) // Too cold
    {
      heaterOn();
    }
    else 
    {
      heaterOff();
    }
}

void TempUnit::heaterOn(){
  digitalWrite(PIN_heatElement, HIGH);
}

void TempUnit::heaterOff(){
  digitalWrite(PIN_heatElement, LOW);
}

int TempUnit::getTemperature(){
  return analogRead(PIN_tempSensor);
}

