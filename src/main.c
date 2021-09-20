#include <stdio.h>
#include <system.h>
#include <stm32f4xx_hal.h>
#include <console.h>
#include <stm32f4_discovery.h>
#include <basic_i2c.h>
#include <ids269.h>

void jamper_init(void)
{
        GPIO_InitTypeDef GPIO_InitStruct;

        GPIO_InitStruct.Pin = GPIO_PIN_1;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = 0;
        GPIO_InitStruct.Alternate = 0;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

static bool is_proximity(void)
{
        return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
}

int main(void)
{
        bool proximity = false;
        HAL_Init();
        system_clock_config();
        console_initialize();
        basic_i2c_initialize();
        jamper_init();
        BSP_LED_Init(LED3);
        BSP_LED_Init(LED4);
        BSP_LED_Init(LED5);
        BSP_LED_Init(LED6);

        proximity = is_proximity();

        if (proximity)
                ids269_initialize_proximity();
        else
                ids269_initialize_button();

        while (1) {

                uint16_t reg = 0;

                if (proximity)
                        ids269_read_counts_proximity();
                else
                        ids269_read_counts_button();

                HAL_Delay(100);
        }
}
