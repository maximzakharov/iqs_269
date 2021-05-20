#ifndef BOARD_H_
#define BOARD_H_

#define BASIC_I2C_GPIO_SDA_PIN  GPIO_PIN_9
#define BASIC_I2C_GPIO_SDA_PORT GPIOC
#define BASIC_I2C_GPIO_SDA_I2C_RCC_ENABLE()      __HAL_RCC_GPIOC_CLK_ENABLE()
#define BASIC_I2C_GPIO_SCL_PIN  GPIO_PIN_8
#define BASIC_I2C_GPIO_SCL_PORT GPIOA
#define BASIC_I2C_GPIO_SCL_I2C_RCC_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()

#define BASIC_I2C                   I2C3
#define BASIC_I2C_RCC_ENABLE       __HAL_RCC_I2C3_CLK_ENABLE
#define BASIC_I2C_ALTERNATE         GPIO_AF4_I2C3
#define BASIC_I2C_RCC_PERIPHCLK     RCC_PERIPHCLK_I2C3
#define BASIC_I2C_CLKSOURCE_SYSCLK  RCC_I2C3CLKSOURCE_SYSCLK

#define BASIC_I2C_FORCE_RESET()     __HAL_RCC_I2C3_FORCE_RESET()
#define BASIC_I2C_RELEASE_RESET()   __HAL_RCC_I2C3_RELEASE_RESET()

#endif