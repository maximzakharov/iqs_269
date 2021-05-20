/*
 *  i2c.c
 *
 *  Created on: 10-06-2016
 *  Author: Maxim Zakharov
 *  email:  zakharov.m89@gmail.com
 */
#include "board.h"
#include <stm32f4xx_hal.h>
#include <stdint.h>
// #include "cmsis_os.h"

static I2C_HandleTypeDef BasicI2cHandle;
// osMutexDef (MutexBasicI2c);
// static osMutexId mutexBasicI2c_id = NULL;

#define I2C_TIMING 0x10D55F7C

static int basic_i2c_write(uint8_t address, uint8_t *buf, int size)
{
        int i = 0;

        if (HAL_I2C_Master_Transmit(&BasicI2cHandle, (uint16_t)(address),
                                    (uint8_t *)buf, size, 10000) != HAL_OK) {
                return -1;
        }

        while (HAL_I2C_GetState(&BasicI2cHandle) != HAL_I2C_STATE_READY) {
                if (i++ > 100000)
                        return -1;
        }

        return 0;
}

static int basic_i2c_read(uint8_t address, uint8_t reg, uint8_t *buf, int size)
{
        int i = 0;

        if (HAL_I2C_Master_Transmit(&BasicI2cHandle, (uint16_t)address, &reg, 1,
                                    10000) != HAL_OK) {
                return -1;
        }

        while (HAL_I2C_GetState(&BasicI2cHandle) != HAL_I2C_STATE_READY) {
                if (i++ > 100000)
                        return -1;
        }

        if (HAL_I2C_Master_Receive(&BasicI2cHandle, (uint16_t)address,
                                   (uint8_t *)buf, size, 10000) != HAL_OK) {
                return -1;
        }

        i = 0;
        while (HAL_I2C_GetState(&BasicI2cHandle) != HAL_I2C_STATE_READY) {
                if (i++ > 100000)
                        return -1;
        }

        return 0;
}

void basic_i2c_initialize(void)
{
        // if (mutexBasicI2c_id == NULL) {

        //         mutexBasicI2c_id = osMutexCreate(osMutex (MutexBasicI2c));
        //         if (mutexBasicI2c_id == NULL) {
        //                 return;
        //         }

        //         osMutexRelease(mutexBasicI2c_id);
        // }

        BasicI2cHandle.Instance = BASIC_I2C;
        BasicI2cHandle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
        BasicI2cHandle.Init.ClockSpeed      = 100000;
        BasicI2cHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
        // BasicI2cHandle.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;
        BasicI2cHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
        BasicI2cHandle.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
        BasicI2cHandle.Init.OwnAddress1 = 0x0;
        BasicI2cHandle.Init.OwnAddress2 = 0x0;

        if (HAL_I2C_DeInit(&BasicI2cHandle) != HAL_OK) {
        }

        if (HAL_I2C_Init(&BasicI2cHandle) != HAL_OK) {
        }
}

void basic_i2c_reset(void)
{
        // osMutexWait(mutexBasicI2c_id, osWaitForever);
        // osDelay(200);
        // basic_i2c_initialize();
        // osDelay(200);
        // osMutexRelease(mutexBasicI2c_id);
}

int basic_i2c_write_byte(uint8_t addr_dev, uint8_t address_reg, uint8_t val)
{
        int ret = 0;
        uint8_t buf[2] = { address_reg, val };
        // osMutexWait(mutexBasicI2c_id, osWaitForever);
        ret = basic_i2c_write(addr_dev, buf, sizeof(buf));
        // osMutexRelease(mutexBasicI2c_id);
        return ret;
}

int basic_i2c_read_byte(uint8_t addr_dev, uint8_t address_reg, uint8_t *byte)
{
        // osMutexWait(mutexBasicI2c_id, osWaitForever);
        int res = basic_i2c_read(addr_dev, address_reg, byte, 1);
        // osMutexRelease(mutexBasicI2c_id);
        return res;
}

int basic_i2c_write_word(uint8_t addr_dev, uint8_t address_reg, uint16_t val)
{
        uint8_t buf[3] = { 0 };
        buf[0] = address_reg;
        buf[1] = (uint8_t)(val >> 8u);
        buf[2] = (uint8_t)(val);

        // osMutexWait(mutexBasicI2c_id, osWaitForever);
        int ret = basic_i2c_write(addr_dev, buf, sizeof(buf));
        // osMutexRelease(mutexBasicI2c_id);

        return ret;
}

int basic_i2c_read_word(uint8_t addr_dev, uint8_t address_reg, uint16_t *data)
{
        uint8_t buf[3] = { 0 };
        *data = 0;

        // osMutexWait(mutexBasicI2c_id, osWaitForever);
        int res = basic_i2c_read(addr_dev, address_reg, buf, 3);
        // osMutexRelease(mutexBasicI2c_id);

        if (res)
                return res;

        *data = (uint16_t)(buf[0] << 8u) | buf[1];

        return 0;
}

int basic_i2c_read_array(uint8_t addr_dev, uint8_t address_reg, uint8_t *data, int len)
{
        *data = 0;

        // osMutexWait(mutexBasicI2c_id, osWaitForever);
        int res = basic_i2c_read(addr_dev, address_reg, data, len);
        // osMutexRelease(mutexBasicI2c_id);

        if (res)
                return res;

        return 0;
}
