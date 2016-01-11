#include "WaterUnit.h"
#include "Arduino.h"

WaterUnit::WaterUnit() { }
WaterUnit::~WaterUnit() { }

void WaterUnit::setup(int PIN_soilResistor, int PIN_motor, int PIN_waterContainer){
  this->PIN_soilResistor = PIN_soilResistor;
  this->PIN_motor = PIN_motor;
  this->PIN_waterContainer = PIN_waterContainer;
  
  pinMode(PIN_soilResistor, INPUT);
  pinMode(PIN_waterContainer, INPUT);
  motor.attach(PIN_motor);

  openFor = 20; //ticks of the clock
  openedFor = 0;
  isValveOpen = 0;

  MAX_soilConductance = 400; // conductance of 100% water
}

void WaterUnit::checkRespond(){
  if (needsWater()){
    openValve();
  }
}

void WaterUnit::openValve()
{
  motor.write(45);
  isValveOpen = 1;
}

void WaterUnit::closeValve()
{
  motor.write(135);
  isValveOpen = 0;
  openedFor = 0;
}

bool WaterUnit::needsWater()
{
  int value = analogRead(PIN_soilResistor);

  if (value < 100){
    return 1;
  }
  else{
    return 0;
  } 
}

void WaterUnit::pulse()
{
  //Closes the valve after openFor amount of ticks, if the valve is open
  if ((isValveOpen) && (openedFor < openFor) ){
    openedFor++;
  } else if (openedFor == openFor) {
    closeValve();
  }
}

bool WaterUnit::containerEmpty(){
  int state = digitalRead(PIN_waterContainer); 

  if (PIN_waterContainer == LOW){
    return 1;
  } else {
    return 0;
  }
}

int WaterUnit::getWaterSaturation(){
  int value = analogRead(PIN_soilResistor);
  return (int) ((value/MAX_soilConductance)*100);
}
