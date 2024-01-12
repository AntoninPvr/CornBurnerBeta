#include "injector.h"
#include "gpio.h"
#include "driver.h"
#include "tim.h"

// Firing order: 1-3-4-2 : 0-2-3-1

void HAL_GPTIO_EXTI_Callback(uint16_t GPIO_Pin) {
    switch (GPIO_Pin)
    {
    case INJ_IN_0_Pin: // Injector 0
        if (HAL_GPIO_ReadPin(INJ_IN_0_GPIO_Port, INJ_IN_0_Pin) == GPIO_PIN_SET) {
            injector_state[0] = 1;
            HAL_GPIO_WritePin(INJ_OUT_0_GPIO_Port, INJ_OUT_0_Pin, GPIO_PIN_SET);
            HAL_TIM_Base_Start(&htim3);
            __HAL_TIM_SET_COUNTER(&htim3, 0);
        }
        else {
            inj_time[0] = __HAL_TIM_GET_COUNTER(&htim3);
            __HAL_TIM_SET_COUNTER(&htim3, (uint16_t) 65536 - (inj_time[0] * enrichment));
        }
        break;
    case INJ_IN_1_Pin: // Injector 1
        if (HAL_GPIO_ReadPin(INJ_IN_1_GPIO_Port, INJ_IN_1_Pin) == GPIO_PIN_SET) {
            injector_state[1] = 1;
            HAL_GPIO_WritePin(INJ_OUT_1_GPIO_Port, INJ_OUT_1_Pin, GPIO_PIN_SET);
            HAL_TIM_Base_Start(&htim4);
            __HAL_TIM_SET_COUNTER(&htim4, 0);
        }
        else {
            inj_time[1] = __HAL_TIM_GET_COUNTER(&htim4);
            __HAL_TIM_SET_COUNTER(&htim4, (uint16_t) 65536 - (inj_time[1] * enrichment));
        }
        break;
    case INJ_IN_2_Pin: // Injector 2
        if (HAL_GPIO_ReadPin(INJ_IN_2_GPIO_Port, INJ_IN_2_Pin) == GPIO_PIN_SET) {
            injector_state[2] = 1;
            HAL_GPIO_WritePin(INJ_OUT_2_GPIO_Port, INJ_OUT_2_Pin, GPIO_PIN_SET);
            HAL_TIM_Base_Start(&htim4);
            __HAL_TIM_SET_COUNTER(&htim4, 0);
        }
        else {
            inj_time[2] = __HAL_TIM_GET_COUNTER(&htim4);
            __HAL_TIM_SET_COUNTER(&htim4, (uint16_t) 65536 - (inj_time[2] * enrichment));
        }
        break;
    case INJ_IN_3_Pin: // Injector 3
        if (HAL_GPIO_ReadPin(INJ_IN_3_GPIO_Port, INJ_IN_3_Pin) == GPIO_PIN_SET) {
            injector_state[3] = 1;
            HAL_GPIO_WritePin(INJ_OUT_3_GPIO_Port, INJ_OUT_3_Pin, GPIO_PIN_SET);
            HAL_TIM_Base_Start(&htim3);
            __HAL_TIM_SET_COUNTER(&htim3, 0);
        }
        else {
            inj_time[3] = __HAL_TIM_GET_COUNTER(&htim3);
            __HAL_TIM_SET_COUNTER(&htim3, (uint16_t) 65536 - (inj_time[3] * enrichment));
        }
        break;
    default:
        break;
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
        if (injector_state[0] == 1) {
            injector_state[0] = 0;
            HAL_GPIO_WritePin(INJ_OUT_0_GPIO_Port, INJ_OUT_0_Pin, GPIO_PIN_RESET);
        }
        if (injector_state[3] == 1) {
            injector_state[3] = 0;
            HAL_GPIO_WritePin(INJ_OUT_3_GPIO_Port, INJ_OUT_3_Pin, GPIO_PIN_RESET);
        }
    }
    else if (htim->Instance == TIM4) {
        if (injector_state[1] == 1) {
            injector_state[1] = 0;
            HAL_GPIO_WritePin(INJ_OUT_1_GPIO_Port, INJ_OUT_1_Pin, GPIO_PIN_RESET);
        }
        if (injector_state[2] == 1) {
            injector_state[2] = 0;
            HAL_GPIO_WritePin(INJ_OUT_2_GPIO_Port, INJ_OUT_2_Pin, GPIO_PIN_RESET);
        }
    }
}