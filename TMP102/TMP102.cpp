#include <TMP102.h>

TMP102 ::TMP102()
{
    _adress = 0;
    _temperature = 0;
}
//************************************
bool TMP102 ::begin(uint8_t adress)
{
    _adress = adress; // chaque objet aura sa propre adresse
    bool res = false;
    Wire.begin();
    Wire.beginTransmission(adress);
    uint8_t val = Wire.endTransmission();
    if (val == 0)
    {
        res = true;
    }
    else
    {
        res = false;
    }
    return res;
}
//***************************************
float TMP102 ::getTemperature()
{
    float val = 0;
    uint8_t Upper = 0;
    uint8_t Lower = 0;
    uint16_t Data = 0;
    Wire.begin();
    Wire.beginTransmission(_adress);
    Wire.endTransmission();
    Wire.requestFrom(_adress, 2);
    Upper = Wire.read();
    Lower = Wire.read();
    Wire.endTransmission();
    Data = ((Upper << 8) | Lower) >> 4;
    bool signe = (Data & 0x800) >> 11;
    if (signe == 1)
    {
        val = -(((Data ^ 0xFFFF) + 1) * 0.0625);
    }
    else
    {
        val = Data * 0.0625;
    }
    _temperature = val;
    return val;
}