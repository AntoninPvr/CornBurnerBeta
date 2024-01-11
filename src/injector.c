#include "injector.h"
#include "gpio.h"
#include "driver.h"
#include "tim.h"

void HAL_GPTIO_EXTI_Callback(uint16_t GPIO_Pin) {
    switch (GPIO_Pin)
    {
    case INJ_IN_0_Pin:
        injector_state[0] = 1;
        time_init[0] = HAL_TIM_GET_COUNTER(&htim2);
        break;
    case INJ_IN_1_Pin:
        injector_state[1] = 1;
        time_init[1] = HAL_TIM_GET_COUNTER(&htim2);
        break;
    case INJ_IN_2_Pin:
        injector_state[2] = 1;
        time_init[2] = HAL_TIM_GET_COUNTER(&htim2);
        break;
    case INJ_IN_3_Pin:
        injector_state[3] = 1;
        time_init[3] = HAL_TIM_GET_COUNTER(&htim2);
        break;
    default:
        break;
    }
}
