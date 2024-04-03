#include "thermistor.h"

/*=======================================================================
\brief CONSTRUCTOR
\param Rref value of the thermistor at its reference temperature
\param R0 value of the fixed resistor associated with the thermistor on the voltage divider
\param Beta Beta value of the thermistor
\param number of bits of analog input sampling (10 by default)
\param Vcc value of the supply voltage (5V by default)
\param T0 reference temperature of the thermistor in Kelvin (298.15 by default)
========================================================================*/
Thermistor::Thermistor(double Rref, double R0, double Beta , unsigned samplingBitsNumber , double Vcc, double T0)
{
    this->Rref=Rref;
    this->R0=R0;
    this->Beta=Beta;
    this->samplingBitsNumber=samplingBitsNumber;
    this->Vcc=Vcc;
    this->T0=T0;
}

/*=======================================================================
\brief GET TEMPERATURE
\param adc analog input value
\param unit temperature unit ('K' for Kelvin (default) , 'C' for celsius, 'F' for fahrenheit)
========================================================================*/
double Thermistor::getTemperature(double adc, char unit)
{
    double temperature , tmp , nbEchantillonsMax;
    nbEchantillonsMax=pow(2,this->samplingBitsNumber);
    tmp=this->R0*(nbEchantillonsMax/adc - 1);
    tmp=(log(tmp/this->Rref)) / this->Beta;
    temperature=1/(1/this->T0 + tmp);
  
    switch(unit)
    {
        case 'K':
        case 'k': return temperature;break;
        case 'c':
        case 'C': return temperature-ZERO_CELSIUS;break;
        case 'F':
        case 'f': return (temperature - ZERO_CELSIUS)*1.8 + 32; break;
        default : return -99e99;

    }
  

}