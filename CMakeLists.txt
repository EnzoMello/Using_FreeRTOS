# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(atividadeFreeRTOS C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(atividadeFreeRTOS atividadeFreeRTOS.c )

pico_set_program_name(atividadeFreeRTOS "atividadeFreeRTOS")
pico_set_program_version(atividadeFreeRTOS "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(atividadeFreeRTOS 0)
pico_enable_stdio_usb(atividadeFreeRTOS 0)

# Definir variável para o caminho do FreeRTOS-Kernel
SET(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeRTOS-Kernel)

# Importar o SDK da Raspberry Pi Pico (deve ser antes do projeto)
include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)


# Add the standard library to the build
target_link_libraries(atividadeFreeRTOS
        pico_stdlib
        FreeRTOS-Kernel
        FreeRTOS-Kernel-Heap4
        hardware_adc
        hardware_pwm)

# Add the standard include files to the build
target_include_directories(atividadeFreeRTOS PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(atividadeFreeRTOS 
        
        )

pico_add_extra_outputs(atividadeFreeRTOS)

