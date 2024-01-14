#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "driver.h"

// Parameters
#define V25 0.76 // from datasheet 
#define VSENSE 3.3/4096 // VSENSE value
#define AVG_SLOPE .0025 // 4.3mV from datasheet

// Global variables
uint32_t buffer_dma_adc[] = {0, 0};
uint16_t engine_temp = 0;
uint16_t ambient_temp = 0;
uint16_t uc_temp = 0;

// Function prototypes
uint32_t NTC_temp_LUT(uint32_t adc_value);
void update_adc_buffer();
void engine_temp_update();
void ambient_temp_update();
void uc_temp_sensor_update();
#endif // TEMP_SENSOR_H