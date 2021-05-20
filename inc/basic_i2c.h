#ifndef INC_I2C_H_
#define INC_I2C_H_

#include <stdbool.h>
#include <stdint.h>

void basic_i2c_initialize(void);

void basic_i2c_reset(void);

int basic_i2c_write_byte(uint8_t addr_dev, uint8_t address_reg, uint8_t val);

int basic_i2c_read_byte(uint8_t addr_dev, uint8_t address_reg, uint8_t *byte);

int basic_i2c_write_word(uint8_t addr_dev, uint8_t address_reg, uint16_t val);

int basic_i2c_read_word(uint8_t addr_dev, uint8_t address_reg, uint16_t *data);

int basic_i2c_read_array(uint8_t addr_dev, uint8_t address_reg, uint8_t *data, int len);

#endif /* INC_I2C_H_ */
