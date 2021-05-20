/*
 *  console.c
 *
 *  Created on: 10-06-2016
 *  Author: Maxim Zakharov
 *  email:  zakharov.m89@gmail.com
 */

#include <stm32f4xx_hal.h>

static UART_HandleTypeDef console_handle;

// osPoolDef(mpool, 100, uint8_t);
// osPoolId  mpool;

// osMessageQDef(console_q, 100, uint8_t *);
// osMessageQId (console_q_id);

// static int queue_config(void)
// {
//         mpool = osPoolCreate(osPool(mpool));

//         if (console_q_id == NULL)
//                 console_q_id = osMessageCreate(osMessageQ(console_q), NULL);

//         if (console_q_id)
//                 return 0;
//         return -1;
// }

// void console_task(void const *argument)
// {
//         UNUSED(argument);

//         cli_init();
//         queue_config();

//         while (1) {

//                 osEvent evt = osMessageGet(console_q_id, osWaitForever);

//                 if (evt.status == osEventMessage) {

//                         uint8_t byte = *(uint8_t *)evt.value.p;
//                         cli_insert_char(byte);
//                         osPoolFree(mpool, evt.value.p);
//                 }
//         }
// }

// void console_callback(void)
// {
//         uint8_t *mptr = osPoolAlloc(mpool);
//         *mptr = LL_USART_ReceiveData8(DEBUG_UART_BASE);
//         osMessagePut(console_q_id, (uint32_t) mptr, 0);
// }

void console_initialize(void)
{
        const int baud = 115200;

        console_handle.Instance = USART2;

        console_handle.Init.BaudRate = baud;
        console_handle.Init.WordLength = UART_WORDLENGTH_8B;
        console_handle.Init.StopBits = UART_STOPBITS_1;
        console_handle.Init.Parity = UART_PARITY_NONE;
        console_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
#ifdef DEBUG_PIN
        console_handle.Init.Mode = UART_MODE_TX;
#else
        console_handle.Init.Mode = UART_MODE_TX;
#endif
        console_handle.Init.OverSampling = UART_OVERSAMPLING_16;

        if (HAL_UART_DeInit(&console_handle) != HAL_OK) {
        }

        if (HAL_UART_Init(&console_handle) != HAL_OK) {
        }

        // LL_USART_EnableIT_RXNE(DEBUG_UART_BASE);
}

void console_putchar(const char sym)
{
        HAL_UART_Transmit(&console_handle, (uint8_t *) &sym, 1, 0xFFFF);
}

void console_puts(const char *buf)
{
        while (*buf) {

                console_putchar(*buf++);
        }
}

void console_write(uint8_t *p, uint16_t len)
{
        HAL_UART_Transmit(&console_handle, p, len, 0xFFFF);
}

void console_read(uint8_t *p, uint16_t len)
{
        HAL_UART_Receive(&console_handle, p, len, 0xFFFF);
}

uint8_t console_getchar(void)
{
        uint8_t sym = 0;
        HAL_UART_Receive(&console_handle, (uint8_t *) &sym, 1, 0xFFFF);
        return sym;
}
