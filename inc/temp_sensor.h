#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "driver.h"

uint32_t NTC_temp_LUT(uint32_t adc_value);

#endif // TEMP_SENSOR_H