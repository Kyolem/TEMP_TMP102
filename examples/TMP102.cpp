#include <Wire.h>
#include <Arduino.h>
#include <Ticker.h>
#include "TMP102.h"

// constantes
const uint32_t PERIOD = 1000;
const uint8_t TMP102_Addr = 0x48;

// prototypes
void action();

// objets
Ticker myTick(action, PERIOD, 0, MILLIS);
TMP102 TMP;
// variables
//**********************************************************************

//**********************************************************************

void action()
{
  float temp = TMP.getTemperature();
  Serial.print(temp);
  Serial.println("°C");
}

//**********************************************************************
void setup()
{
  // put your setup code here, to run once:
  myTick.start();
  Serial.begin(115200);
  Serial.println(TMP.begin(TMP102_Addr));
}

//**********************************************************************
void loop()
{
  myTick.update();
}
