/**
 ******************************************************************************
 * @file    UART/UART_TwoBoards_ComDMA/Src/stm32f4xx_hal_msp.c
 * @author  MCD Application Team
 * @brief   HAL MSP module.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stm32f4xx_hal.h>
#include <board.h>

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
        GPIO_InitTypeDef GPIO_InitStruct;

        if (huart->Instance == USART2) {
                /*##-1- Enable peripherals and GPIO Clocks
                 * #################################*/
                /* Enable GPIO TX/RX clock */
                __HAL_RCC_GPIOA_CLK_ENABLE();
                __HAL_RCC_USART2_CLK_ENABLE();

                /*##-2- Configure peripheral GPIO
                 * ##########################################*/
                /* UART TX GPIO pin configuration  */
                GPIO_InitStruct.Pin = GPIO_PIN_2;
                GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                GPIO_InitStruct.Pull = GPIO_PULLUP;
                GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
                GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
                HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
        }
}

void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
        GPIO_InitTypeDef GPIO_InitStruct;
        // RCC_PeriphCLKInitTypeDef RCC_PeriphCLKInitStruct;

        if (hi2c->Instance == BASIC_I2C) {
                // RCC_PeriphCLKInitStruct.PeriphClockSelection =
                //         BASIC_I2C_RCC_PERIPHCLK;
                // RCC_PeriphCLKInitStruct.I2c2ClockSelection =
                //         BASIC_I2C_CLKSOURCE_SYSCLK;
                // HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);

                BASIC_I2C_GPIO_SDA_I2C_RCC_ENABLE();
                BASIC_I2C_GPIO_SCL_I2C_RCC_ENABLE();
                BASIC_I2C_RCC_ENABLE();

                GPIO_InitStruct.Pin = BASIC_I2C_GPIO_SCL_PIN;
                GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
                GPIO_InitStruct.Pull = GPIO_PULLUP;
                GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
                GPIO_InitStruct.Alternate = BASIC_I2C_ALTERNATE;
                HAL_GPIO_Init(BASIC_I2C_GPIO_SCL_PORT, &GPIO_InitStruct);

                GPIO_InitStruct.Pin = BASIC_I2C_GPIO_SDA_PIN;
                GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
                GPIO_InitStruct.Pull = GPIO_PULLUP;
                GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
                GPIO_InitStruct.Alternate = BASIC_I2C_ALTERNATE;
                HAL_GPIO_Init(BASIC_I2C_GPIO_SDA_PORT, &GPIO_InitStruct);

                printf("init\n");
        }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c)
{
        if (hi2c->Instance == BASIC_I2C) {
                BASIC_I2C_FORCE_RESET();
                BASIC_I2C_RELEASE_RESET();

                HAL_GPIO_DeInit(BASIC_I2C_GPIO_SCL_PORT,
                                BASIC_I2C_GPIO_SCL_PIN);
                HAL_GPIO_DeInit(BASIC_I2C_GPIO_SDA_PORT,
                                BASIC_I2C_GPIO_SDA_PIN);
        }
}