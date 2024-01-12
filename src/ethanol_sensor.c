#include "ethanol_sensor.h"

float read_ethanol_prop() {
    return (float) (ETHANOL_PERIOD_S/ethanol_period)-50;
}

float read_fuel_temp() {
    return (float) ((ethanol_pulse_width-1000)*41.25)-40;
}