# Thermistor library
## created by Vincent ROBERT, IT Teacher
## [Lycée Charles de Foucauld - Nancy (France)](https://www.cdfnancy.fr/)
This library allows extracting the temperature measured by a thermistor.

A voltage divider with a fixed resistor R0 is constructed. The thermistor must be connected to Vcc and R0. The other terminal of R0 is connected to ground. The point between the two resistors is connected to an analog input of an Arduino, ESP32, or other equipment.

![Connection diagram](https://github.com/VincentRobert54/Thermistor/connectionDiagram.png)

The constructor of the implemented class receives, in order:
- the value of the thermistor at its reference temperature (Rref)
- the value of the fixed resistor associated with the thermistor on the voltage divider
- the Beta value of the thermistor
- the number of bits of analog input sampling (10 by default)
- the value of the supply voltage (5V by default)
- the reference temperature of the thermistor in Kelvin (298.15 by default)



