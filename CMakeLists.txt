cmake_minimum_required(VERSION 3.0.0)
project(iqs_test C ASM)
set(CMAKE_C_STANDARD 99)

include(version.cmake)

add_executable(${FW_NAME}.elf)

include(src/src.cmake)
include(third_party/third_party.cmake)

target_sources(${FW_NAME}.elf PRIVATE ${PROJ_SRC} ${THIRD_PARTY_SRC})

target_compile_definitions(
        ${FW_NAME}.elf
        PRIVATE
        MAJOR_VERSION=${FW_MAJOR_VERSION}
        MINOR_VERSION=${FW_MINOR_VERSION}
        RELEASE_VERSION=${FW_RELEASE_VERSION}
)

ADD_CUSTOM_COMMAND(TARGET ${FW_NAME}.elf
        POST_BUILD COMMAND ${CMAKE_OBJCOPY}
        ARGS -Oihex ${FW_NAME}.elf ${FW_NAME}.hex
        )

ADD_CUSTOM_COMMAND(TARGET ${FW_NAME}.elf
        POST_BUILD COMMAND ${CMAKE_OBJCOPY}
        ARGS -Obinary ${FW_NAME}.elf ${FW_NAME}.bin
        )

ADD_CUSTOM_COMMAND(TARGET ${FW_NAME}.elf
        POST_BUILD COMMAND ${CMAKE_SIZE} --format=berkeley
        "$<TARGET_FILE:${FW_NAME}.elf>"
        COMMENT "Invoking: Cross ARM GNU Print Size")

# add_executable(iqs_test main.c)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
