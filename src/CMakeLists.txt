#Library
add_library(dcc_receiver INTERFACE)

pico_generate_pio_header(dcc_receiver ${CMAKE_CURRENT_LIST_DIR}/dcc_receiver.pio)


#Include files
target_include_directories(
    dcc_receiver
    INTERFACE
    ${CMAKE_CURRENT_LIST_DIR})

#
target_sources(
    dcc_receiver
    INTERFACE
)


#Libraries we need
target_link_libraries(
    dcc_receiver
    INTERFACE
    hardware_pio
    hardware_gpio
)

