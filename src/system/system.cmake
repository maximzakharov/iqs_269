set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR})

SET(SYSTEM_FLAGS
        "-Os -g0 -Wall\
        -DSTM32F407xx \
        -DUSE_HAL_DRIVER \
        -DSTM32 -DARM_MATH_CM4 \
        -D__packed=\"__attribute__\(\(__packed__\)\)\"\
        -DFREERTOS"
        )

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SYSTEM_FLAGS}")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${SYSTEM_FLAGS}")

target_compile_definitions(${FW_NAME}.elf PRIVATE -DNBO_ENTRY_OFFSET=0x0)

file(GLOB SYSTEM_SRC
        ${SRC_DIR}/stm32f4xx_it.c
        ${SRC_DIR}/system_stm32f4xx.c
        ${SRC_DIR}/stm32f4xx_hal_msp.c
        ${SRC_DIR}/startup_stm32f407xx.s
        )

target_link_directories(
        ${FW_NAME}.elf PUBLIC nbo_common/linker/
)

set_target_properties(
        ${FW_NAME}.elf
        PROPERTIES
        LINK_FLAGS
        "-T${SRC_DIR}/linker_main.ld -Wl,--gc-sections"
)

target_link_libraries(${FW_NAME}.elf c m)