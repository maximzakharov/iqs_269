SET(TOOLCHAIN_DIR $ENV{GNU_INSTALL_ROOT})
SET(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_DIR}/bin)
SET(TOOLCHAIN_INC_DIR ${TOOLCHAIN_LIBC_DIR}/include)

SET(CMAKE_SYSTEM_NAME Generic CACHE INTERNAL "system name")
SET(CMAKE_SYSTEM_PROCESSOR arm CACHE INTERNAL "processor")

SET(CMAKE_C_COMPILER ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-gcc )
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-g++ )
SET(CMAKE_ASM_COMPILER ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-gcc )

SET(CMAKE_OBJCOPY ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objcopy CACHE INTERNAL "")
SET(CMAKE_OBJDUMP ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objdump CACHE INTERNAL "")

SET(CMAKE_SIZE ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-size )

SET(COMMON_FLAGS "-mthumb -mcpu=cortex-m4 -mfloat-abi=softfp -mfpu=fpv4-sp-d16")
SET(SPEC_FLAGS  "-ffunction-sections -fdata-sections -g -fno-common -fmessage-length=0 ")

SET(CMAKE_C_FLAGS "${COMMON_FLAGS} ${SPEC_FLAGS} " CACHE INTERNAL "c compiler flags")
SET(CMAKE_CXX_FLAGS "${COMMON_FLAGS}  ${SPEC_FLAGS}" CACHE INTERNAL "cxx compiler flags")
SET(CMAKE_ASM_FLAGS "-x assembler-with-cpp  ${COMMON_FLAGS}" CACHE INTERNAL "asm compiler flags")


SET(CMAKE_EXE_LINKER_FLAGS "${COMMON_FLAGS}  --specs=nosys.specs" CACHE INTERNAL "exe link flags")

