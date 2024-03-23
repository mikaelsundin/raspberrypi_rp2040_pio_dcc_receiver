
#ifndef DCC_RECEIVER_H
#define DCC_RECEIVER_H

#include "stdint.h"
#include "stdbool.h"
#include "hardware/pio.h"


uint dcc_receiver_add_program(PIO pio);
void dcc_receiver_begin(PIO pio, uint sm, uint dcc_pin, uint offset);
bool dcc_receiver_available(PIO pio, uint sm);
uint dcc_receiver_read(PIO pio, uint sm, uint8_t packet[8]);

#endif