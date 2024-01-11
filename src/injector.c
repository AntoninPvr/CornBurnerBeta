#include "injector.h"
#include "gpio.h"
#include "driver.h"
#include "tim.h"

void HAL_GPTIO_EXTI_Callback(uint16_t GPIO_Pin) {
    switch (GPIO_Pin)
    {
    case INJ_IN_0_Pin:
        if (HAL_GPIO_ReadPin(INJ_IN_0_GPIO_Port, INJ_IN_0_Pin) == GPIO_PIN_SET) {
            injector_state[0] = 1;
            time_init[0] = __HAL_TIM_GET_COUNTER(&htim2);
        }
        else {
            time_end[0] = __HAL_TIM_GET_COUNTER(&htim2);
        }
        break;
    case INJ_IN_1_Pin:
        if (HAL_GPIO_ReadPin(INJ_IN_1_GPIO_Port, INJ_IN_1_Pin) == GPIO_PIN_SET) {
            injector_state[1] = 1;
            time_init[1] = __HAL_TIM_GET_COUNTER(&htim2);
        }
        else {
            time_end[1] = __HAL_TIM_GET_COUNTER(&htim2);
        }
        break;
    case INJ_IN_2_Pin:
        if (HAL_GPIO_ReadPin(INJ_IN_2_GPIO_Port, INJ_IN_2_Pin) == GPIO_PIN_SET) {
            injector_state[2] = 1;
            time_init[2] = __HAL_TIM_GET_COUNTER(&htim2);
        }
        else {
            time_end[2] = __HAL_TIM_GET_COUNTER(&htim2);
        }
        break;
    case INJ_IN_3_Pin:
        if (HAL_GPIO_ReadPin(INJ_IN_3_GPIO_Port, INJ_IN_3_Pin) == GPIO_PIN_SET) {
            injector_state[3] = 1;
            time_init[3] = __HAL_TIM_GET_COUNTER(&htim2);
        }
        else {
            time_end[3] = __HAL_TIM_GET_COUNTER(&htim2);
        }
        break;
    default:
        break;
    }
}
