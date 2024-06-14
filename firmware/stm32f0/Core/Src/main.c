/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
//#include <rtc-module.h>
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "clock_types.h"
#include "doz_clock.h"
#include "event_queue.h"
#include "rtc_module.h"

#include "buzzer.h"
#include "display.h"
#include "gps.h"
#include "adc-light-sens.h"
#include "hub75-driver.h"
#include "hub75-driver.h"
#include "i2c-rtc.h"
#include "gpio-buttons.h"
#include "pwm-buzzer.h"
#include "rtc-internal.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
DozClock doz_clock;

Display rgb_matrix;
Gps neo6m;
Rtc rtc_internal;
Rtc ds3231;
Buzzer buzzer;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_ADC_Init();
  MX_TIM6_Init();
  MX_SPI2_Init();
  MX_TIM7_Init();
  MX_TIM15_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */



  // Buzzer
  PKM22E_Init(&htim3, TIM_CHANNEL_1);
  buzzer.setDutyCycle   = PKM22E_SetDutyCyle;
  buzzer.startPwm       = PKM22E_StartPwm;
  buzzer.stopPwm        = PKM22E_StopPwm;
  doz_clock.buzzer = &buzzer;

  // Internal RTC
   RTC_Init(&hrtc);
   rtc_internal.enableAlarm  = RTC_EnableAlarm;
   rtc_internal.getAlarm     = RTC_GetAlarm;
   rtc_internal.getDay       = RTC_GetDay;
   rtc_internal.getMonth     = RTC_GetMonth;
   rtc_internal.getTime      = RTC_GetTime;
   rtc_internal.setAlarm     = RTC_SetAlarm;
   rtc_internal.setDay       = RTC_SetDay;
   rtc_internal.setMonth     = RTC_SetMonth;
   rtc_internal.setRtcTime   = RTC_SetTime;
   doz_clock.rtc = &rtc_internal;

  // External RTC
//  DS3231_Init(&hi2c1);
//  ds3231.enableAlarm = DS3231_EnableAlarm;
//  ds3231.getAlarm = DS3231_GetAlarm;
//  ds3231.getTime = DS3231_GetTime;
//  ds3231.getDay = DS3231_GetDate;
//  ds3231.getMonth = DS3231_GetMonth;
//  ds3231.setAlarm = DS3231_SetAlarm;
//  ds3231.setDay = DS3231_SetDate;
//  ds3231.setMonth = DS3231_SetMonth;
//  ds3231.setRtcTime = DS3231_SetTime;
//  doz_clock.rtc = &ds3231;

  // Display
  HUB75_Init(&hspi2, &htim15, TIM_CHANNEL_1);
  rgb_matrix.displayOff     = HUB75_DisplayOff;
  rgb_matrix.displayOn      = HUB75_DisplayOn;
  rgb_matrix.setBrightness  = HUB75_SetDisplayBrightness;
  rgb_matrix.setBitmap      = HUB75_SetBitmap;
  rgb_matrix.setColour      = HUB75_SetColour;
  rgb_matrix.show           = HUB75_Show;
  rgb_matrix.hide           = HUB75_Hide;
  doz_clock.display = &rgb_matrix;


  // Doz Clock
  doz_clock.error_handler = Error_Handler;
  DozClock_Init(&doz_clock);


  // Buttons
  Buttons_Init();

  // Light sensor
  LightSens_Init(&hadc, 1600);

  // Start 2Hz timer
  HAL_TIM_Base_Start_IT(&htim6);

  // Start 6Hz timer
  HAL_TIM_Base_Start_IT(&htim7);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    DozClock_Update();

      utc = GPS_get_utc_time();
      status = GPS_get_gps_connected();
      HAL_Delay(500);
    /* USER CODE END WHILE */


    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14
                              |RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_I2C1
                              |RCC_PERIPHCLK_RTC;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t pin)
{
    if (pin != RTC_SQW_Pin)
    {
        Buttons_GpioCallback(pin);
    }
    else
    {
    	if (DS3231_IsAlarm1Triggered()) {
    		EventQ_TriggerAlarmEvent(ALARM_TRIG);
    	} else if (DS3231_IsAlarm2Triggered()) {
    		EventQ_TriggerAlarmEvent(TIMER_TRIG);
    	}
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == &htim7)
    {
        // 6 Hz freq
        Buttons_TimerCallback(167);
        DozClock_TimerCallback();
    }
    else if(htim == &htim6)
    {
        // 2 Hz freq
        LightSens_AdcStartConversion();
    }
    else if(htim == &htim15)
    {
        HUB75_PwmStartPulse();
    }
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
    LightSens_AdcConversionCallback();
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
