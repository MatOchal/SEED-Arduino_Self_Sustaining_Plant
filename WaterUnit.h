#include <Servo.h> 

#ifndef WATERUNIT_h
#define WATERUNIT_h

class WaterUnit
{
  public:
    WaterUnit();
    ~WaterUnit();

    void setup(int PIN_soilResistor, int PIN_motor, int PIN_waterContainer);
    void checkRespond();
    bool isValveOpen;
    void pulse();

    bool containerEmpty();

    int getWaterSaturation();
    
  private:
    int PIN_soilResistor;
    int PIN_motor;
    int PIN_waterContainer;

    void openValve();
    void closeValve();
    bool needsWater();

    int openFor;
    int openedFor;

    int MAX_soilConductance;
    
    Servo motor;
};

#endif

