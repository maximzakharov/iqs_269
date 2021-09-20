//
// Created by Maxim Zakharov on 19.05.2021.
//

#include <basic_i2c.h>
#include <stdint.h>
#include <stm32f4_discovery.h>

#include <stdio.h>

static const uint8_t address_device = 0x88;
static const uint16_t DEVICE_ID = 0x4f03;

static uint8_t buf[200];

static int ids269_write(uint8_t reg, uint16_t value)
{
        return basic_i2c_write_word(address_device, reg, value);
}

static int ids269_read(uint8_t reg, uint16_t *data)
{
        return basic_i2c_read_word(address_device, reg, data);
}

static int ids269_read_array(uint8_t reg, uint8_t *data, int len)
{
        return basic_i2c_read_array(address_device, reg, data, len);
}

static int ids269_config(uint8_t reg, uint16_t value)
{
        uint16_t tmp;

        ids269_write(reg, value);

        if (ids269_read(reg, &tmp))
                return -1;

        if (tmp != value)
                return -1;

        return 0;
}

static int ids269_probe(void)
{
        uint16_t tmp = 0;

        if (ids269_read(0, &tmp))
                return -1;

        if (tmp != DEVICE_ID)
                return -1;

        return 0;
}

int ids269_initialize_button(void)
{
        int ret = 0;

        ret += ids269_write(0x86, 0x0010);
        ret += ids269_write(0x87, 0x0001);
        ret += ids269_write(0x88, 0x0000);
        ret += ids269_write(0x89, 0x0000);
        ret += ids269_write(0x8a, 0x197d);
        ret += ids269_write(0x8b, 0x8000);

        ids269_read_array(0x80, buf, 6);
        ids269_read_array(0x83, buf, 6);
        ids269_read_array(0x86, buf, 12);
        ids269_read_array(0x8c, buf, 14);
        ids269_read_array(0x93, buf, 14);
        ids269_read_array(0x9a, buf, 14);
        ids269_read_array(0xa1, buf, 14);
        ids269_read_array(0xa8, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xb6, buf, 14);
        ids269_read_array(0xbd, buf, 14);
        ids269_read_array(0xf2, buf, 1);
        ids269_read_array(0xf5, buf, 1);

        /* Change the CH0 Settings */
        ret += ids269_write(0x8c, 0x1080);
        ret += ids269_write(0x8d, 0xa349);
        ret += ids269_write(0x8e, 0x0410);
        ret += ids269_write(0x8f, 0x0000);
        ret += ids269_write(0x90, 0x0a08);
        ret += ids269_write(0x91, 0x1a04);
        ret += ids269_write(0x92, 0x0000);

        ids269_read_array(0x80, buf, 6);
        ids269_read_array(0x83, buf, 6);
        ids269_read_array(0x86, buf, 12);
        ids269_read_array(0x8c, buf, 14);
        ids269_read_array(0x93, buf, 14);
        ids269_read_array(0x9a, buf, 14);
        ids269_read_array(0xa1, buf, 14);
        ids269_read_array(0xa8, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xb6, buf, 14);
        ids269_read_array(0xbd, buf, 14);
        ids269_read_array(0xf2, buf, 1);
        ids269_read_array(0xf5, buf, 1);

        ids269_read_array(0x80, buf, 2);
        ret += ids269_write(0x80, 0x0304);
        HAL_Delay(1000);
        ids269_read_array(0x8b, buf, 2);
        ret += ids269_write(0x8b, 0x80ff);

        ids269_read_array(0x80, buf, 6);
        ids269_read_array(0x83, buf, 6);
        ids269_read_array(0x86, buf, 12);
        ids269_read_array(0x8c, buf, 14);
        ids269_read_array(0x93, buf, 14);
        ids269_read_array(0x9a, buf, 14);
        ids269_read_array(0xa1, buf, 14);
        ids269_read_array(0xa8, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xb6, buf, 14);
        ids269_read_array(0xbd, buf, 14);
        ids269_read_array(0xf2, buf, 1);
        ids269_read_array(0xf5, buf, 1);

        ids269_read_array(0x80, buf, 2);
        ret += ids269_write(0x80, 0x0301);
        HAL_Delay(1000);
        // ids269_read_array(0x8b, buf, 6);
        // ret += ids269_write(0x8b, 0x80ff);

        ids269_read_array(0x80, buf, 6);
        ids269_read_array(0x83, buf, 6);
        ids269_read_array(0x86, buf, 12);
        ids269_read_array(0x8c, buf, 14);
        ids269_read_array(0x93, buf, 14);
        ids269_read_array(0x9a, buf, 14);
        ids269_read_array(0xa1, buf, 14);
        ids269_read_array(0xa8, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xb6, buf, 14);
        ids269_read_array(0xbd, buf, 14);
        ids269_read_array(0xf2, buf, 1);
        ids269_read_array(0xf5, buf, 1);

        return ret;
}

static void all_led_on()
{
        BSP_LED_On(LED3);
        BSP_LED_On(LED4);
        BSP_LED_On(LED5);
        BSP_LED_On(LED6);
}

static void all_led_off()
{
        BSP_LED_Off(LED3);
        BSP_LED_Off(LED4);
        BSP_LED_Off(LED5);
        BSP_LED_Off(LED6);
}

int ids269_initialize_proximity(void)
{
        int ret = 0;

        ret += ids269_write(0x80, 0x0300);
        ret += ids269_write(0x81, 0x0300);
        ret += ids269_write(0x82, 0xff00);

        ret += ids269_write(0x83, 0x10a0);
        ret += ids269_write(0x84, 0x0a05);
        ret += ids269_write(0x85, 0x1440);

        ret += ids269_write(0x86, 0x0010);
        ret += ids269_write(0x87, 0x0001);
        ret += ids269_write(0x88, 0x0000);
        ret += ids269_write(0x89, 0x0000);
        ret += ids269_write(0x8a, 0x197d);
        ret += ids269_write(0x8b, 0x8000);

        ids269_read_array(0x80, buf, 6);
        ids269_read_array(0x83, buf, 6);
        ids269_read_array(0x86, buf, 12);
        ids269_read_array(0x8c, buf, 14);
        ids269_read_array(0x93, buf, 14);
        ids269_read_array(0x9a, buf, 14);
        ids269_read_array(0xa1, buf, 14);
        ids269_read_array(0xa8, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xb6, buf, 14);
        ids269_read_array(0xbd, buf, 14);
        ids269_read_array(0xf2, buf, 1);
        ids269_read_array(0xf5, buf, 1);

        /* Change the CH0 Settings */
        ret += ids269_write(0x8c, 0x40ff);
        ret += ids269_write(0x8d, 0xa340);
        ret += ids269_write(0x8e, 0x0650);
        ret += ids269_write(0x8f, 0x6750);
        ret += ids269_write(0x90, 0x0a08);
        ret += ids269_write(0x91, 0x1a04);
        ret += ids269_write(0x92, 0x0000);

        ids269_read_array(0x80, buf, 6);
        ids269_read_array(0x83, buf, 6);
        ids269_read_array(0x86, buf, 12);
        ids269_read_array(0x8c, buf, 14);
        ids269_read_array(0x93, buf, 14);
        ids269_read_array(0x9a, buf, 14);
        ids269_read_array(0xa1, buf, 14);
        ids269_read_array(0xa8, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xb6, buf, 14);
        ids269_read_array(0xbd, buf, 14);
        ids269_read_array(0xf2, buf, 1);
        ids269_read_array(0xf5, buf, 1);
        // /* Change the CH1 Settings */
        ret += ids269_config(0x93, 0x04ff);
        ret += ids269_config(0x94, 0xa340);
        ret += ids269_config(0x95, 0x0650);
        ret += ids269_config(0x96, 0x6758);
        ret += ids269_config(0x97, 0x0a08);
        ret += ids269_config(0x98, 0x1a04);
        ret += ids269_config(0x99, 0x0000);
        // /* Change the CH2 Settings */
        ret += ids269_config(0x9a, 0x04ff);
        ret += ids269_config(0x9b, 0xa340);
        ret += ids269_config(0x9c, 0x0250);
        ret += ids269_config(0x9d, 0x0000);
        ret += ids269_config(0x9e, 0x0a08);
        ret += ids269_config(0x9f, 0x1a04);
        ret += ids269_config(0xa0, 0x0000);
        // /* Change the CH3 Settings */
        ret += ids269_config(0xa1, 0x08ff);
        ret += ids269_config(0xa2, 0xa340);
        ret += ids269_config(0xa3, 0x0250);
        ret += ids269_config(0xa4, 0x0000);
        ret += ids269_config(0xa5, 0x0a08);
        ret += ids269_config(0xa6, 0x1a04);
        ret += ids269_config(0xa7, 0x0000);

        /* Change the CH4 Settings */
        ret += ids269_config(0xa8, 0x10ff);
        ret += ids269_config(0xa9, 0xa340);
        ret += ids269_config(0xaa, 0x0250);
        ret += ids269_config(0xab, 0x0000);
        ret += ids269_config(0xac, 0x0a08);
        ret += ids269_config(0xad, 0x1a04);
        ret += ids269_config(0xae, 0x0000);

        /* Change the CH5 Settings */
        ret += ids269_config(0xaf, 0x20ff);
        ret += ids269_config(0xb0, 0xa340);
        ret += ids269_config(0xb1, 0x0250);
        ret += ids269_config(0xb2, 0x0000);
        ret += ids269_config(0xb3, 0x0a08);
        ret += ids269_config(0xb4, 0x1a04);
        ret += ids269_config(0xb5, 0x0000);
        /* Change the CH6 Settings */
        ret += ids269_config(0xb6, 0x40ff);
        ret += ids269_config(0xb7, 0xa340);
        ret += ids269_config(0xb8, 0x0250);
        ret += ids269_config(0xb9, 0x0000);
        ret += ids269_config(0xba, 0x0a08);
        ret += ids269_config(0xbb, 0x1a04);
        ret += ids269_config(0xbc, 0x0000);
        /* Change the CH7 Settings */
        ret += ids269_config(0xbd, 0x80ff);
        ret += ids269_config(0xbe, 0xa340);
        ret += ids269_config(0xbf, 0x0250);
        ret += ids269_config(0xc0, 0x0000);
        ret += ids269_config(0xc1, 0x0a08);
        ret += ids269_config(0xc2, 0x1a04);
        ret += ids269_config(0xc3, 0x0000);
        // ids269_read_array(0x80, buf, 6);

        ids269_read_array(0x80, buf, 2);
        ret += ids269_write(0x80, 0x0304);
        HAL_Delay(1000);
        ids269_read_array(0x8b, buf, 2);
        ret += ids269_write(0x8b, 0x80ff);

        ids269_read_array(0x80, buf, 6);
        ids269_read_array(0x83, buf, 6);
        ids269_read_array(0x86, buf, 12);
        ids269_read_array(0x8c, buf, 14);
        ids269_read_array(0x93, buf, 14);
        ids269_read_array(0x9a, buf, 14);
        ids269_read_array(0xa1, buf, 14);
        ids269_read_array(0xa8, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xb6, buf, 14);
        ids269_read_array(0xbd, buf, 14);
        ids269_read_array(0xf2, buf, 1);
        ids269_read_array(0xf5, buf, 1);

        ids269_read_array(0x80, buf, 2);
        ret += ids269_write(0x80, 0x0301);
        HAL_Delay(1000);
        // ids269_read_array(0x8b, buf, 6);
        // ret += ids269_write(0x8b, 0x80ff);

        ids269_read_array(0x80, buf, 6);
        ids269_read_array(0x83, buf, 6);
        ids269_read_array(0x86, buf, 12);
        ids269_read_array(0x8c, buf, 14);
        ids269_read_array(0x93, buf, 14);
        ids269_read_array(0x9a, buf, 14);
        ids269_read_array(0xa1, buf, 14);
        ids269_read_array(0xa8, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xaf, buf, 14);
        ids269_read_array(0xb6, buf, 14);
        ids269_read_array(0xbd, buf, 14);
        ids269_read_array(0xf2, buf, 1);
        ids269_read_array(0xf5, buf, 1);

        return ret;
}

int ids269_read_counts_button(void)
{
        uint16_t tmp;

        ids269_read_array(0x02, buf, 60);
        // printf("buf 02 - ");
        // for (size_t i = 0; i < 60; i++) {
        //         printf("%02x ", buf[i]);
        // }
        // printf("\n");

        // if (buf[7]) {
        //         all_led_on();
        // } else {
        //         all_led_off();
        // }

        int rrr = buf[33+12] << 8 | buf[32+12];

        if (rrr & 0x8000) {
                rrr = (rrr - 0xffff);
        }

        if (rrr > 100) {
               all_led_on();
        } else {
               all_led_off();
        }

        return 0;
}

int ids269_read_counts_proximity(void)
{
        uint16_t tmp;

        ids269_read_array(0x02, buf, 60);
        // printf("buf 02 - ");
        // for (size_t i = 0; i < 60; i++) {
        //         printf("%02x ", buf[i]);
        // }
        // printf("\n");

        if (buf[7]) {
                all_led_on();
        } else {
                all_led_off();
        }
}