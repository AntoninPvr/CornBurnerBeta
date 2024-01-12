#ifndef INJECTOR_H
#define INJECTOR_H

#include "driver.h"

volatile uint16_t inj_time[] = {0, 0, 0, 0};

volatile uint8_t injector_state[] = {0, 0, 0, 0};

volatile float enrichment = 0.2f;

#endif // INJECTOR_H