# ------------------------------------------------------------------------------
# MCU_NAME platform library
#
# This library contains:
#   - CMSIS headers
#   - startup code
#   - linker script
#   - MCU specific configuration
# ------------------------------------------------------------------------------

add_library(platform_mcu_name STATIC)

# ------------------------------------------------------------------------------
# Source files
# ------------------------------------------------------------------------------

file(GLOB CMSIS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/cmsis/device/src/*.c
)

target_sources(platform_mcu_name PRIVATE

    ${CMAKE_CURRENT_SOURCE_DIR}/clock.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/interrupt.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/startup/startup_mcu_name.s

    ${CMSIS_SOURCES}
)

# ------------------------------------------------------------------------------
# Include directories
# ------------------------------------------------------------------------------

target_include_directories(platform_mcu_name PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}/cmsis/core
    ${CMAKE_CURRENT_SOURCE_DIR}/cmsis/device/inc
)

# ------------------------------------------------------------------------------
# Preprocessor definitions
# ------------------------------------------------------------------------------

target_compile_definitions(platform_mcu_name PUBLIC
    MCU_NAME
)

# ------------------------------------------------------------------------------
# Compiler flags
# ------------------------------------------------------------------------------

target_compile_options(platform_mcu_name PUBLIC

    -Wall
    -Wextra
    -Wpedantic

    -ffunction-sections
    -fdata-sections
)

# ------------------------------------------------------------------------------
# Linker script
# ------------------------------------------------------------------------------

set(LINKER_SCRIPT
    ${CMAKE_CURRENT_SOURCE_DIR}/linker/linkerscript.ld
)

target_link_options(platform_mcu_name PUBLIC

    -T${LINKER_SCRIPT}

    -Wl,--gc-sections
    -Wl,-Map=${CMAKE_BINARY_DIR}/firmware.map

    --specs=nano.specs
    --specs=nosys.specs
)
