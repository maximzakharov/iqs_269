set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR})

#DRIVERS
file(GLOB DRIVERS_SRC

        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_adc.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_adc_ex.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_iwdg.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
        third_party/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart_ex.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim_ex.c
        third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_spi.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rtc.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rtc_ex.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dfsdm.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dfsdm_ex.c
        # third_party/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_lptim.c
        )

include_directories(
        third_party/Drivers/STM32F4xx_HAL_Driver/Inc
        third_party/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
        third_party/Drivers/CMSIS/Include
        third_party/Drivers/CMSIS/Device/ST/STM32F4xx/Include
)

#BSP
file(GLOB BSP_SRC

        third_party/Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.c
)

include_directories(
        third_party/Drivers/BSP/STM32F4-Discovery
)




# #FREERTOS
# file(GLOB FREERTOS_SRC
#         third_party/FreeRTOS/Source/*.[ch]
#         third_party/FreeRTOS/Source/CMSIS_RTOS/*.[ch]
#         third_party/FreeRTOS/Source/portable/MemMang/heap_4.c
# #        third_party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
#         third_party/FreeRTOS/Source/portable/port.c
#         )

# include_directories(
#         third_party/FreeRTOS/Source/include
#         third_party/FreeRTOS/Source/portable/GCC/ARM_CM4F
#         third_party/FreeRTOS/Source/CMSIS_RTOS
#         third_party/FreeRTOS/Source/portable
# )

# #BLE stuff
# file(GLOB BLE_SRC
#         third_party/STM32_BlueNRG/Interface/*.[ch]
#         third_party/STM32_BlueNRG/SimpleBlueNRG_HCI/hci/*.c
#         third_party/STM32_BlueNRG/SimpleBlueNRG_HCI/hci/controller/*.c
#         third_party/STM32_BlueNRG/SimpleBlueNRG_HCI/utils/*.c
#         third_party/STM32_BlueNRG/SimpleBlueNRG_HCI/includes/*.h
#         )

# include_directories(
#         third_party/STM32_BlueNRG/SimpleBlueNRG_HCI/includes
#         third_party/STM32_BlueNRG/Interface
# )

# #BSON
# file(GLOB BSON_SRC
#         third_party/bson/*.[ch]
#         )

# include_directories(
#         third_party/bson
# )

# #FFT
# file(GLOB FFT_SRC
#         third_party/fft/*.[ch]
#         )

# include_directories(
#         third_party/fft
# )

# #SPEEX
# file(GLOB SPEEX_SRC
#         third_party/speex/speex_src/*.[ch]
#         )

# include_directories(
#         third_party/speex/inc/speex
#         third_party/speex/speex_src
# )

# target_link_libraries(${BOOT_NAME}.elf
#         ${SRC_DIR}/STM32_Cryptographic/Lib/libSTM32CryptographicV3.0.0_CM4_GCC_ot.a)

#Cryptography
# file(GLOB CRYPTO_SRC
#         third_party/STM32_Cryptographic/Inc/*.h
#         third_party/STM32_Cryptographic/Inc/*/*.h
#         third_party/STM32_Cryptographic/Inc/*/*/*.h
#         )

# include_directories(
#         third_party/STM32_Cryptographic/Inc
# )

# add_definitions(
#         -DHAVE_CONFIG_H
# )

#FINAL
file(GLOB THIRD_PARTY_SRC
        ${DRIVERS_SRC}
        ${BSP_SRC}
        # ${FREERTOS_SRC}
        # ${BLE_SRC}
        # ${BSON_SRC}
        # ${FFT_SRC}
        # ${SPEEX_SRC}
        # ${CRYPTO_SRC}
        )
