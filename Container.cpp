#include "Container.h"

Container::Container() { }
Container::~Container() { }

void Container::setup(Monitor* PT_monitorUnit)
{
    PIN_tempSensor = 0;
    PIN_heatElement = 0;
    PIN_lightEmitter =  7;
    PIN_lightSensor = 0;
    PIN_soilResistor = 1;
    PIN_motor = 6;
    PIN_waterContainer = 0;

    this->PT_monitorUnit = PT_monitorUnit;
    
    tempUnit.setup(PIN_tempSensor, PIN_heatElement);
    lightUnit.setup(PIN_lightSensor, PIN_lightEmitter);
    waterUnit.setup(PIN_soilResistor, PIN_motor, PIN_waterContainer);
}

void Container::checkRespond(int tickCount)
{
  // Manipulate how often the module will check for light, temperature and water level
  if (tickCount % 1 == 0){
    //lightUnit.checkRespond();
  }
  
  if (tickCount % 50 == 0){
    //tempUnit.checkRespond();
  }

  if (tickCount % 100 == 0){
    waterUnit.checkRespond();
  }

  waterUnit.pulse();

  if (tickCount % 100 == 0){
    //lightUnit.resetLightTicksGot();
  }
}

void Container::updateMonitor(){
  int temp = tempUnit.getTemperature();
  int light = lightUnit.getLightLevel();
  int water = waterUnit.getWaterSaturation();
  bool empty = waterUnit.containerEmpty();
  
  (*PT_monitorUnit).updateMonitor(temp, light, water, empty);

  Serial.print("water = ");
  Serial.print(water);
  Serial.print("\t");
  Serial.print("empty = ");
  Serial.print(empty);
  Serial.print("\n");
}
