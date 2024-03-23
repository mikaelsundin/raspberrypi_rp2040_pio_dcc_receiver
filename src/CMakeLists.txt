#Library
add_library(dcc_receiver INTERFACE)

#Generate PIO header file
pico_generate_pio_header(dcc_receiver ${CMAKE_CURRENT_LIST_DIR}/dcc_receiver.pio)

#Include files
target_include_directories(
    dcc_receiver
    INTERFACE
    ${CMAKE_CURRENT_LIST_DIR})

#Source files
target_sources(
    dcc_receiver
    INTERFACE
    dcc_receiver.c
)

#Required Libraries
target_link_libraries(
    dcc_receiver
    INTERFACE
    hardware_pio
    hardware_gpio
)



