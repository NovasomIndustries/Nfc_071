/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "NFC_Reader.h"
#include "NFC_EncDec.h"
#include "pn532_driver.h"
#include "usb_logger.h"
#include "ee24_driver.h"
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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define NFC_CARD_PRESENT_Pin GPIO_PIN_14
#define NFC_CARD_PRESENT_GPIO_Port GPIOC
#define NFC_CARD_DETECTED_Pin GPIO_PIN_0
#define NFC_CARD_DETECTED_GPIO_Port GPIOA
#define NFC_NSS_Pin GPIO_PIN_4
#define NFC_NSS_GPIO_Port GPIOA
#define NFC_SCK_Pin GPIO_PIN_5
#define NFC_SCK_GPIO_Port GPIOA
#define NFC_MISO_Pin GPIO_PIN_6
#define NFC_MISO_GPIO_Port GPIOA
#define NFC_MOSI_Pin GPIO_PIN_7
#define NFC_MOSI_GPIO_Port GPIOA
#define NFC1_Pin GPIO_PIN_0
#define NFC1_GPIO_Port GPIOB
#define P70_IRQ_Pin GPIO_PIN_1
#define P70_IRQ_GPIO_Port GPIOB
#define RSTPD_Pin GPIO_PIN_2
#define RSTPD_GPIO_Port GPIOB
#define P32_INT0_Pin GPIO_PIN_10
#define P32_INT0_GPIO_Port GPIOB
#define P33_INT1_Pin GPIO_PIN_11
#define P33_INT1_GPIO_Port GPIOB
#define NFC0_Pin GPIO_PIN_12
#define NFC0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
