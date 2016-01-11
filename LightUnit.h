// TempUnit contains TempSensor, HeatElement, Fan

#ifndef LIGHTUNIT_h
#define LIGHTUNIT_h

class LightUnit
{
  public:
    LightUnit();
    ~LightUnit();

    void setup(int PIN_lightSensor, int PIN_lightEmitter);
    void checkRespond(); //Needs to be called on every tick
    void resetLightTicksGot();
    void pulse();

    int getLightLevel(); // as a percentage

  private:
    int PIN_lightSensor;
    int PIN_lightEmitter;

    int lightTicksRequired; //expressed in the number of ticks
    int lightTicksGot; //expressed in the number of ticks
    
    void lightOn();
    void lightOff();

    int MIN_resistance;
};

#endif

