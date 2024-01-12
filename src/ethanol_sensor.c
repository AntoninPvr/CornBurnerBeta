#include "ethanol_sensor.h"

uint32_t ethanol_prop() {
    return (uint32_t) (ETHANOL_PERIOD_S/ethanol_period)-50;
}

uint32_t fuel_temp() {
    return (uint32_t) ((ethanol_pulse_width-1000)*41.25)-40;
}