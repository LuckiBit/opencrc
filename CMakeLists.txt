cmake_minimum_required(VERSION 3.14)

project(crc C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -------- Configurable variables --------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# -------- Manually list all source files --------
set(SOURCE_FILES
    main.c
    color.c
    crc.c
    linenoise.c
    font_ansi_shadow.c
    ht.c
    help.c
)

# -------- Build executable --------
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
