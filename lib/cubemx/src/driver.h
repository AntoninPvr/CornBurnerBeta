/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : driver.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
int driver(void);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENGINE_TEMP_Pin GPIO_PIN_0
#define ENGINE_TEMP_GPIO_Port GPIOA
#define AMBIENT_TEMP_Pin GPIO_PIN_1
#define AMBIENT_TEMP_GPIO_Port GPIOA
#define LED_ERROR_Pin GPIO_PIN_2
#define LED_ERROR_GPIO_Port GPIOB
#define LED_COLD_START_Pin GPIO_PIN_10
#define LED_COLD_START_GPIO_Port GPIOB
#define INJ_IN_0_Pin GPIO_PIN_12
#define INJ_IN_0_GPIO_Port GPIOB
#define INJ_IN_0_EXTI_IRQn EXTI15_10_IRQn
#define INJ_IN_1_Pin GPIO_PIN_13
#define INJ_IN_1_GPIO_Port GPIOB
#define INJ_IN_1_EXTI_IRQn EXTI15_10_IRQn
#define INJ_IN_2_Pin GPIO_PIN_14
#define INJ_IN_2_GPIO_Port GPIOB
#define INJ_IN_2_EXTI_IRQn EXTI15_10_IRQn
#define INJ_IN_3_Pin GPIO_PIN_15
#define INJ_IN_3_GPIO_Port GPIOB
#define INJ_IN_3_EXTI_IRQn EXTI15_10_IRQn
#define ETH_IN_Pin GPIO_PIN_8
#define ETH_IN_GPIO_Port GPIOA
#define INJ_OUT_0_Pin GPIO_PIN_10
#define INJ_OUT_0_GPIO_Port GPIOA
#define INJ_OUT_1_Pin GPIO_PIN_11
#define INJ_OUT_1_GPIO_Port GPIOA
#define INJ_OUT_2_Pin GPIO_PIN_12
#define INJ_OUT_2_GPIO_Port GPIOA
#define INJ_OUT_3_Pin GPIO_PIN_13
#define INJ_OUT_3_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
