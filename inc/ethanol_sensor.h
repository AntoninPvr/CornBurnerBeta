#ifndef ETHANOL_SENSOR_H
#define ETHANOL_SENSOR_H

#include "driver.h"

#define ETHANOL_PERIOD_S 16000 // to be change assuming 1600 PSC and 16MHz clock

extern volatile uint16_t ethanol_period;
extern volatile uint16_t ethanol_pulse_width;

float read_ethanol_prop();
float read_fuel_temp();

#endif // ETHANOL_SENSOR_H