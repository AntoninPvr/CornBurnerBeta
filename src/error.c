#include "error.h"

void check_error() {
    uint32_t error_sum = 0;
    error_sum += warn_low_ethanol_prop + warn_high_ethanol_prop
    + crit_low_ethanol_prop + crit_high_ethanol_prop;
    error_sum += warn_low_fuel_temp + warn_high_fuel_temp
    + crit_low_fuel_temp + crit_high_fuel_temp;
    if (error_sum > 0) {
        HAL_GPIO_WritePin(LED_ERROR_GPIO_Port, LED_ERROR_Pin, GPIO_PIN_SET);
    }
    else {
        HAL_GPIO_WritePin(LED_ERROR_GPIO_Port, LED_ERROR_Pin, GPIO_PIN_RESET);
    }
}