#include "LightUnit.h"
#include "Arduino.h"

LightUnit::LightUnit() { }
LightUnit::~LightUnit() { }

void LightUnit::setup(int PIN_lightSensor, int PIN_lightEmitter)
{   
    this->PIN_lightSensor = PIN_lightSensor;
    this->PIN_lightEmitter = PIN_lightEmitter;

    pinMode(PIN_lightSensor, INPUT);
    pinMode(PIN_lightEmitter, OUTPUT);

    MIN_resistance = 100; // is the min light resistance, any more than that and the bold has to light up
    lightTicksRequired = 50;
    resetLightTicksGot();
}

//Needs to be called on every tick
void LightUnit::checkRespond()
{
    if (lightTicksGot < lightTicksRequired){ 
      int value = analogRead(PIN_lightSensor);
      
      if (value < MIN_resistance)
      {
        lightOff();
      }
      else
      {
        lightOn();
      }
      lightTicksGot++;
      
    } else {
      lightOff();
    }
}

void LightUnit::lightOn(){
  digitalWrite(PIN_lightEmitter, HIGH);
}

void LightUnit::lightOff(){
  digitalWrite(PIN_lightEmitter, LOW);
}

void LightUnit::resetLightTicksGot(){
  lightTicksGot = 0;
}

void LightUnit::pulse(){
  // no implementation
}

int LightUnit::getLightLevel(){
  return analogRead(PIN_lightSensor);
}

