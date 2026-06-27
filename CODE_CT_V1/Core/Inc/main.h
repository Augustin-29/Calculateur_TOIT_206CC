/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IN_VITESSE_Pin GPIO_PIN_13
#define IN_VITESSE_GPIO_Port GPIOC
#define IN_MOTEUR_TOURNANT_Pin GPIO_PIN_14
#define IN_MOTEUR_TOURNANT_GPIO_Port GPIOC
#define IN_BTN_TOIT_FERMER_Pin GPIO_PIN_15
#define IN_BTN_TOIT_FERMER_GPIO_Port GPIOC
#define OUT_RELAIS_POMPE_Pin GPIO_PIN_0
#define OUT_RELAIS_POMPE_GPIO_Port GPIOC
#define OUT_RELAI_POMPE_0_Pin GPIO_PIN_1
#define OUT_RELAI_POMPE_0_GPIO_Port GPIOC
#define OUT_RELAI_POMPE_1_Pin GPIO_PIN_2
#define OUT_RELAI_POMPE_1_GPIO_Port GPIOC
#define OUT_ALIM_VANNE_Pin GPIO_PIN_3
#define OUT_ALIM_VANNE_GPIO_Port GPIOC
#define ADC_TABLETTE_RANGEE_SORTIE_Pin GPIO_PIN_0
#define ADC_TABLETTE_RANGEE_SORTIE_GPIO_Port GPIOA
#define ADC_TEMP_MOTEUR_POMPE_Pin GPIO_PIN_1
#define ADC_TEMP_MOTEUR_POMPE_GPIO_Port GPIOA
#define ADC_COURANT_1_Pin GPIO_PIN_2
#define ADC_COURANT_1_GPIO_Port GPIOA
#define ADC_COURANT_2_Pin GPIO_PIN_3
#define ADC_COURANT_2_GPIO_Port GPIOA
#define IN_TOIT_OUVERT_Pin GPIO_PIN_4
#define IN_TOIT_OUVERT_GPIO_Port GPIOC
#define IN_COFFRE_FERME_Pin GPIO_PIN_5
#define IN_COFFRE_FERME_GPIO_Port GPIOC
#define IN_VITRE_1_Pin GPIO_PIN_0
#define IN_VITRE_1_GPIO_Port GPIOB
#define IN_VITRE_2_Pin GPIO_PIN_1
#define IN_VITRE_2_GPIO_Port GPIOB
#define IN_VITRE_3_Pin GPIO_PIN_2
#define IN_VITRE_3_GPIO_Port GPIOB
#define UART_AD_TX_Pin GPIO_PIN_10
#define UART_AD_TX_GPIO_Port GPIOB
#define UART_AD_RX_Pin GPIO_PIN_11
#define UART_AD_RX_GPIO_Port GPIOB
#define OUT_BSI_1_Pin GPIO_PIN_12
#define OUT_BSI_1_GPIO_Port GPIOB
#define OUT_BSI_0_Pin GPIO_PIN_13
#define OUT_BSI_0_GPIO_Port GPIOB
#define IN_TOIT_VERROUILLE_G_Pin GPIO_PIN_6
#define IN_TOIT_VERROUILLE_G_GPIO_Port GPIOC
#define IN_TOIT_VERROUILLE_D_Pin GPIO_PIN_7
#define IN_TOIT_VERROUILLE_D_GPIO_Port GPIOC
#define IN_RIDEAU_Pin GPIO_PIN_8
#define IN_RIDEAU_GPIO_Port GPIOC
#define IN_BTN_TOIT_OUVRIR_Pin GPIO_PIN_9
#define IN_BTN_TOIT_OUVRIR_GPIO_Port GPIOC
#define BT_RESET_Pin GPIO_PIN_8
#define BT_RESET_GPIO_Port GPIOA
#define UART_BT_TX_Pin GPIO_PIN_9
#define UART_BT_TX_GPIO_Port GPIOA
#define UART_BT_RX_Pin GPIO_PIN_10
#define UART_BT_RX_GPIO_Port GPIOA
#define UART_BT_CTS_Pin GPIO_PIN_11
#define UART_BT_CTS_GPIO_Port GPIOA
#define UART_BT_RTS_Pin GPIO_PIN_12
#define UART_BT_RTS_GPIO_Port GPIOA
#define IN_MALLE_VERROUILLEE_G_D_Pin GPIO_PIN_10
#define IN_MALLE_VERROUILLEE_G_D_GPIO_Port GPIOC
#define IN_TOIT_FERME_Pin GPIO_PIN_11
#define IN_TOIT_FERME_GPIO_Port GPIOC
#define IN_MALLE_OUVERTE_Pin GPIO_PIN_12
#define IN_MALLE_OUVERTE_GPIO_Port GPIOC
#define IN_VITRE_4_Pin GPIO_PIN_3
#define IN_VITRE_4_GPIO_Port GPIOB
#define OUT_3B_Pin GPIO_PIN_4
#define OUT_3B_GPIO_Port GPIOB
#define OUT_3A_Pin GPIO_PIN_5
#define OUT_3A_GPIO_Port GPIOB
#define OUT_2B_Pin GPIO_PIN_6
#define OUT_2B_GPIO_Port GPIOB
#define OUT_2A_Pin GPIO_PIN_7
#define OUT_2A_GPIO_Port GPIOB
#define OUT_1B_Pin GPIO_PIN_8
#define OUT_1B_GPIO_Port GPIOB
#define OUT_1A_Pin GPIO_PIN_9
#define OUT_1A_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
