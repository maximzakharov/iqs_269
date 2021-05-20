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

        printf("======= %d\n", HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1));
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

        printf("Hello, world!\n");

        uint8_t buf[10];

        proximity = is_proximity();

        if (proximity)
                ids269_initialize_proximity();
        else
                ids269_initialize_button();

        while (1) {
                // HAL_Delay(1000);

                // BSP_LED_Off(LED4);
                // BSP_LED_On(LED3);
                // HAL_Delay(50);
                // BSP_LED_Off(LED3);
                // BSP_LED_On(LED5);
                // HAL_Delay(50);
                // BSP_LED_Off(LED5);
                // BSP_LED_On(LED6);
                // HAL_Delay(50);
                // BSP_LED_Off(LED6);
                // BSP_LED_On(LED4);
                // HAL_Delay(50);

                // basic_i2c_read_array(0x44<<1, 1, buf, 4);

                uint16_t reg = 0;
                // basic_i2c_read_word(0x88, 0x0, &reg);

                if (proximity)
                        ids269_read_counts_proximity();
                else
                        ids269_read_counts_button();

                HAL_Delay(100);

                // ids269_initialize_button();

                // BSP_LED_Toggle(LED3);
                // BSP_LED_Toggle(LED4);
                // BSP_LED_Toggle(LED5);
                // BSP_LED_Toggle(LED6);
                // printf("tick %02x %02x %02x %02x\n", buf[0], buf[1], buf[2],
                // buf[3]); printf("Helflo, wotrld! %04x\n", reg);
        }
}
