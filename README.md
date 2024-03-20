# raspberrypi_rp2040_pio_dcc_receiver
Nmra DCC receiver running inside RP2040 PIO statemachine.

Code will take 20 instruction of 32 avaiable in PIO block.
Communication to C-code is done via RX-FIFO and PIO interrupt flag.

The interrupt index is the same as state machine index. 
This makes it possible to run up to four DCC receivers on same PIO block.


