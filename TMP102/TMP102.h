#ifndef Sensor_H

#define Sensor_H

#include <Arduino.h>
#include <Wire.h>

// les registres

#define SENSOR_VAL_REG 0x00
#define SENSOR_CONFIG_REG 0x01

class TMP102
{

public:
    // constructeur
    TMP102();

    // méthodes
    bool begin(uint8_t Adress);
    float getTemperature();

private:
    uint8_t _adress;
    float _temperature;
};

#endif