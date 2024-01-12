#include "fuel.h"
#include "ethanol_sensor.h"

float computeEnrichment(float ethanol) {
    float afr_query = afr_ethanol*ethanol + (1-ethanol)*afr_gasoline; // 14.7 is the stoichiometric ratio for gasoline
    return afr_gasoline/afr_query;
}

float flashpoint(float ethanol) {
    return flashpoint_ethanol*ethanol + (1-ethanol)*flashpoint_gasoline;
}

void updateEthProp() {
    float tmp_eth = read_ethanol_prop();
    if (tmp_eth > 1.0f) {
        tmp_eth = 1.0f;
        warn_high_ethanol_prop = 1;
        if (tmp_eth > crit_high_eth_prop_thresh) {
            crit_high_ethanol_prop = 1;
        }
    }
    else if (tmp_eth < 0.0f) {
        tmp_eth = 0.0f;
        warn_low_ethanol_prop = 1;
        if (tmp_eth < crit_low_eth_prop_thresh) {
            crit_low_ethanol_prop = 1;
        }
    }
    else {
        warn_high_ethanol_prop = 0;
        warn_low_ethanol_prop = 0;
        crit_high_ethanol_prop = 0;
        crit_low_ethanol_prop = 0;
    }
    ethanol_prop = tmp_eth;
}

void updateFuelTemp() {
    float tmp_fuel_temp = read_fuel_temp();
    if (tmp_fuel_temp > warn_high_fuel_temp_thresh) {
        warn_high_fuel_temp = 1;
        if (tmp_fuel_temp > crit_high_fuel_temp_thresh) {
            crit_high_fuel_temp = 1;
        }
    }
    else if (tmp_fuel_temp < warn_low_fuel_temp_thresh) {
        warn_low_fuel_temp = 1;
        if (tmp_fuel_temp < crit_low_fuel_temp_thresh) {
            crit_low_fuel_temp = 1;
        }
    }
    else {
        warn_high_fuel_temp = 0;
        warn_low_fuel_temp = 0;
        crit_high_fuel_temp = 0;
        crit_low_fuel_temp = 0;
    }
    fuel_temp = tmp_fuel_temp;
}

void coldStart() {
    if (fuel_temp < flashpoint(ethanol_prop) + cold_start_offset) {
        need_cold_start = 1;
        HAL_GPIO_WritePin(LED_COLD_START_GPIO_Port, LED_COLD_START_Pin, GPIO_PIN_SET);
    }
    else {
        need_cold_start = 0;
        HAL_GPIO_WritePin(LED_COLD_START_GPIO_Port, LED_COLD_START_Pin, GPIO_PIN_RESET);
    }
}