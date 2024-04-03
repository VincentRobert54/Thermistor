/*======================================
Sample test
Author : Vincent ROBERT
Date : 2024-04-03
*/
#include <Arduino.h>
#include "thermistance.h"

// A 10 kohm thermistor with a Beta of 3950.
// Voltage divider with a fixed resistor connected to ground of 15 kohms.
// The number of sampling bits, the supply voltage, and the reference temperature for the thermistor are default values.
Thermistance th(10000, 15000, 3950);
int analogPin = A0;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
}

void loop()
{
    Serial.println(th.getTemperature(analogRead(analogPin)));

    delay(5000);
}
