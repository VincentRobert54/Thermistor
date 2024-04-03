/*==================================================
This library allows extracting the temperature measured by a thermistor.
A voltage divider with a fixed resistor R0 is constructed. 
The thermistor must be connected to Vcc and R0. 
The other terminal of R0 is connected to ground. 
The point between the two resistors is connected to an analog input of an Arduino, ESP32, or other equipment.

The constructor of the implemented class receives, in order:

- the value of the thermistor at its reference temperature (Rref)
- the value of the fixed resistor associated with the thermistor on the voltage divider
- the Beta value of the thermistor
- the number of bits of analog input sampling (10 by default)
- the value of the supply voltage (5V by default)
- the reference temperature of the thermistor in Kelvin (298.15 by default)
===================================================*/
#include <Arduino.h>

const double ZERO_CELSIUS=273.15;

class Thermistor
{
    private:
    double Rref, R0, Beta, T0 , Vcc;
    unsigned samplingBitsNumber;

    public:
    // CONSTRUCTOR 
    Thermistor(double Rref, double R0, double Beta , unsigned samplingBitsNumber=10 , double Vcc=5, double T0=298.15);
    
    // GET TEMPERATURE (unit : 'K' for Kelvin, 'C' for Celsius, 'F' for Fahrenheit)
    double getTemperature(double adc, char unit='K');   

};