// Container has a lighting, temperature and watering unit
#include "TempUnit.h"
#include "WaterUnit.h"
#include "LightUnit.h"
#include "Arduino.h"
#include "Monitor.h"

class Container
{
  public:
    Container();
    ~Container();
  
    void setup(Monitor* PT_monitorUnit);
    void checkRespond(int tickCount);
    void updateMonitor();
    
    TempUnit tempUnit;
    LightUnit lightUnit;
    WaterUnit waterUnit;
    
    Monitor* PT_monitorUnit;
    
    int PIN_tempSensor;
    int PIN_heatElement;
    int PIN_lightEmitter;
    int PIN_lightSensor;
    int PIN_soilResistor;
    int PIN_motor;
    int PIN_waterContainer;
};
