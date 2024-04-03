# Thermistor library
## created by Vincent ROBERT, IT Teacher
## [Lycée Charles de Foucauld - Nancy (France)](https://www.cdfnancy.fr/)
This library allows extracting the temperature measured by a thermistor.

A voltage divider with a fixed resistor R0 is constructed. The thermistor must be connected to Vcc and R0. The other terminal of R0 is connected to ground. The point between the two resistors is connected to an analog input of an Arduino, ESP32, or other equipment.

![Connection diagram](https://github.com/VincentRobert54/Thermistor/blob/main/connectionDiagram.png?raw=true)

The constructor of the implemented class receives, in order:
- **Rref** : the value of the thermistor at its reference temperature
- **R0** : the value of the fixed resistor associated with the thermistor on the voltage divider
- **Beta** : the Beta value of the thermistor
- **samplingBitsNumber** : the number of bits of analog input sampling (10 by default)
- **Vcc** : the value of the supply voltage (5V by default)
- **T0** : the reference temperature of the thermistor in Kelvin (298.15 (25°C)  by default)


## Example
```
#include <Arduino.h>
#include "thermistor.h"

// Rref=10kohms, R0=15kohms, Beta=3950, default values for other parameters
Thermistor th(10000, 15000, 3950);

int analogPin = A0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  // print temperature in Celsius
  Serial.println(th.getTemperature(analogRead(analogPin), 'C'));

  delay(5000);
}
```

