#ifndef FUEL_H
#define FUEL_H

#include "driver.h"

// Parameters
const float afr_ethanol = 9.0f;
const float afr_gasoline = 14.7f;
const float flashpoint_ethanol = 13.0f;
const float flashpoint_gasoline = -43.0f;

const float crit_low_eth_prop_thresh = -0.1f;
const float crit_high_eth_prop_thresh = 1.1f;
const float warn_low_fuel_temp_thresh = -20.0f;
const float warn_high_fuel_temp_thresh = 80.0f;
const float crit_low_fuel_temp_thresh = -40.0f;
const float crit_high_fuel_temp_thresh = 100.0f;

const float cold_start_offset = 10.0f;

// Function prototypes
float computeEnrichment(float ethanol);
float flashpoint(float ethanol);

// Global variables
float ethanol_prop = 0.0f;
float fuel_temp = 0.0f;

float cold_start_enrichment = 0.0f;

uint8_t need_cold_start = 0;

// Error flags
uint8_t warn_low_ethanol_prop = 0;
uint8_t warn_high_ethanol_prop = 0;
uint8_t crit_low_ethanol_prop = 0;
uint8_t crit_high_ethanol_prop = 0;

uint8_t warn_low_fuel_temp = 0;
uint8_t warn_high_fuel_temp = 0;
uint8_t crit_low_fuel_temp = 0;
uint8_t crit_high_fuel_temp = 0;

#endif // FUEL_H