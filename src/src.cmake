set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR})

include(${SRC_DIR}/system/system.cmake)

include_directories(
        config
        inc
        inc/system
        src/ids_driver
        # usr/inc/calibration_clk
        # usr/inc/btstack
        # usr/inc/cryption
        # usr/inc/navigation
        # usr/inc/nbo_settings
        # usr/inc/power
        # usr/src/power/supply/power_supply_driver
        # usr/src/power/supply/bq2512x_driver
        # usr/src/power/battery/battery_states
        # usr/src/power/battery/battery_driver
        # usr/src/power/wireless_charger/wireless_charger_driver

        # usr/inc/pulse_oximetry
        # usr/src/pulse_oximetry/baby_mode
        # usr/inc/bluetooth/adv_data_manager
        # usr/inc/sound
        # usr/inc/sound/buzzer
        # usr/inc/temper
        # usr/inc/tests
        # usr/inc/status
        # usr/inc/logs
        # usr/inc/bluetooth
        # usr/inc/awake_health
        # usr/inc/ble_stream
        # usr/src/temper/temper_driver
        # usr/inc/low_power_hr
        # usr/inc/accelerometer/
        # usr/inc/awake_monitor/
        # usr/inc/activity_monitor/
        # usr/inc/motion_monitor/
        # usr/inc/accelerometer/acc_driver
        # usr/inc/pulse_oximetry/optic
        # usr/inc/pulse_oximetry/optic/afe_driver
        # usr/src/pulse_oximetry/respiratory_rate

        # usr/src/accelerometer/lis2de12_driver

        # usr/src/bluetooth/nbo_ble_wrapper/nbo_nrg_port
        # usr/src/bluetooth/nbo_ble_wrapper

        # usr/src/cli

        # usr/inc/port_freertos

        # usr/src/sound/microphone/nbo_speex

        # usr/src/logs/send_to_dev
)

# add_definitions(
#         -DHAS_NBO_CONFIG
# )

file(GLOB PROJ_SRC

        src/main.c
        # usr/src/iwdt.c
        src/console.c
        # usr/src/nbo_util.c
        # usr/src/kalman.c
        # usr/src/ring_buffer.c
        # usr/src/hw_version.c
        # usr/src/bootloader.c
        src/basic_i2c.c
        src/ids_driver/ids269.c
        # usr/src/adc.c
        # usr/src/nbo_debug.c
        src/printf-stdarg.c
        # usr/src/tickless.c

        # usr/src/bluetooth/nbo_ble_wrapper/nbo_nrg_port/bluenrg_driver/*.[ch]
        # usr/src/bluetooth/nbo_ble_wrapper/*.[ch]
        # usr/src/bluetooth/nbo_ble_wrapper/nbo_nrg_port/*.[ch]
        # usr/src/bluetooth/nbo_ble_wrapper/adv_data_manager/*.[ch]
        # usr/src/cryption/*.[ch]
        # usr/src/event/*.[ch]
        # usr/src/navigation/*.[ch]
        # usr/src/navigation/driver/*.[ch]
        # usr/src/nbo_settings/*.[ch]
        # usr/src/low_power_hw/*.[ch]

        # usr/src/power/*.[ch]
        # usr/src/power/wireless_charger/*.[ch]
        # usr/src/power/wireless_charger/wireless_charger_driver/*.[ch]
        # usr/src/power/wireless_charger/bq51003_driver/*.[ch]
        # usr/src/power/supply/*.[ch]
        # usr/src/power/supply/power_supply_driver/*.[ch]
        # usr/src/power/battery/*.[ch]
        # usr/src/power/battery/301120PL_driver/*.[ch]
        # usr/src/power/battery/BZ301120_driver/*.[ch]
        # usr/src/power/battery/battery_driver/*.[ch]
        # usr/src/power/battery/battery_states/*.[ch]
        # usr/src/power/supply/bq2512x_driver/*.[ch]
        # usr/src/backup_regs/*.[ch]
        # usr/src/pulse_oximetry/kalman/*.c
        # usr/src/pulse_oximetry/baby_mode/*.[ch]
        # usr/src/pulse_oximetry/*.[ch]
        # usr/src/pulse_oximetry/optic/optic_driver/afe4410_driver/*.[ch]
        # usr/src/pulse_oximetry/optic/*.[ch]
        # usr/src/pulse_oximetry/optic/calibration/*.[ch]
        # usr/src/pulse_oximetry/optic/surface_checks/*.[ch]
        # usr/src/pulse_oximetry/interval/*.[ch]
        # usr/src/pulse_oximetry/oxygen/*.[ch]
        # usr/src/pulse_oximetry/respiratory_rate/*.[ch]
        # usr/src/sound/*.[ch]
        # usr/src/sound/buzzer/*.[ch]
        # usr/src/sound/microphone/*.[ch]
        # usr/src/sound/microphone/nbo_speex/*.[ch]
        # usr/src/awake_monitor/*.[ch]
        # usr/src/status/*.[ch]
        # usr/src/temper/*.[ch]
        # usr/src/temper/tmp006_driver/*.[ch]
        # usr/src/temper/tmp108_driver/*.[ch]
        # usr/src/temper/temper_driver/*.[ch]
        # usr/src/logs/*.[ch]
        # usr/src/logs/send_to_dev/*.[ch]
        # usr/src/boot_update/*.[ch]
        # usr/src/awake_monitor/triggers/*.[ch]
        # usr/src/cli/*.[ch]
        # usr/src/ble_stream/*.[ch]
        # usr/src/accelerometer/*.[ch]
        # usr/src/motion_monitor/*.[ch]
        # usr/src/motion_monitor/bindings/*/*.[ch]
        # usr/src/accelerometer/lis2de12_driver/*.[ch]
        # usr/src/rtc/*.[ch]
        # usr/src/calibration_clk/*.[ch]
        # usr/src/activity_monitor/*.[ch]
        # usr/src/port_freertos/*.[ch]

        ${SYSTEM_SRC}
        )

# target_link_libraries(${FW_NAME}.elf c m respiratory_rate nbo_processing)

# file(GLOB BOOT_SRC
#         usr_boot/Src/main.c
#         usr_boot/Src/temp_hack.c

#         usr_boot/Src/hardware/flash.c
#         usr_boot/Src/nbo_transport/*.c
#         usr_boot/Src/programming/*.c
#         usr_boot/Src/settings/*.c

#         usr/src/bluetooth/nbo_ble_wrapper/mac_address.c
#         usr/src/bluetooth/nbo_ble_wrapper/nbo_nrg_port/bluenrg_driver/*.[ch]
#         usr/src/bluetooth/nbo_ble_wrapper/nbo_nrg_port/bluetooth.c
#         usr_boot/Src/bluetooth/*.[ch]
#         usr_boot/Src/bluetooth/nbo_ble_wrapper/*.[ch]
#         usr_boot/Src/bluetooth/nbo_ble_wrapper/nbo_nrg_port/*.[ch]
#         usr/src/nbo_settings/*.[ch]
#         usr/src/calibration_clk/*.[ch]

#         usr/src/iwdt.c
#         usr/src/backup_regs/backup_regs.c
#         usr/src/rtc/rtc.c

#         usr/src/adc.c
#         usr/src/console.c
#         usr/src/printf-stdarg.c
#         usr/src/pulse_oximetry/optic/afe_spi_gpio.c
#         usr/src/hw_version.c

#         usr/src/port_freertos/port_freertos.c
#         usr/src/port_freertos/low_power_tick.c

#         ${SYSTEM_SRC}
#         )

# include_directories(

#         usr_boot/Inc
#         usr_boot/Src/bluetooth/nbo_ble_wrapper/nbo_nrg_port
#         usr/src/bluetooth/nbo_ble_wrapper
#         usr_boot/Inc/hardware
#         usr_boot/Inc/programming
#         usr_boot/Inc/transport
#         ${CMAKE_SOURCE_DIR} #for key
# )