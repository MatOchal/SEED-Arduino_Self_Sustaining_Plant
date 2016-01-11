// TempUnit contains TempSensor, HeatElement, Fan

#ifndef TEMPUNIT_h
#define TEMPUNIT_h

class TempUnit
{
  public:
    TempUnit();
    ~TempUnit();

    void setup(int PIN_tempSensor, int PIN_heatElement);
    void checkRespond();

    int getTemperature();

  private:
    int PIN_tempSensor;
    int PIN_heatElement;

    void heaterOn();
    void heaterOff();
};

#endif

