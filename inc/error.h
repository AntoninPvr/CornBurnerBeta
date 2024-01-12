#ifndef ERROR_H
#define ERROR_H

#include "driver.h"

extern uint8_t warn_low_ethanol_prop;
extern uint8_t warn_high_ethanol_prop;
extern uint8_t crit_low_ethanol_prop;
extern uint8_t crit_high_ethanol_prop;

extern uint8_t warn_low_fuel_temp;
extern uint8_t warn_high_fuel_temp;
extern uint8_t crit_low_fuel_temp;
extern uint8_t crit_high_fuel_temp;

void check_error();

#endif // ERROR_H