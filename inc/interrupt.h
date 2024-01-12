#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "driver.h"

volatile uint16_t inj_time[] = {0, 0, 0, 0};

volatile uint8_t injector_state[] = {0, 0, 0, 0};

volatile float enrichment = 0.2f;

volatile uint16_t ethanol_period = 0;
volatile uint16_t ethanol_pulse_width = 0;

#endif // "INTERRUPT_H"