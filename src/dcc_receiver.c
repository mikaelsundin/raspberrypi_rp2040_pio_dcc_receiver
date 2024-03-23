#include <stdint.h>

#include "dcc_receiver.h"
#include "dcc_receiver.pio.h"



/**
 * @brief initlize the dcc receiver for specific PIO, only required to call one for same PIO.
 * @return Program offset the program is added
 */
uint dcc_receiver_add_program(PIO pio)
{
    return pio_add_program(pio0, &dcc_receiver_program);
}



/**
 * @brief Initilize DCC reciver. @Note IRQ[SM] will be used by this state machine. 
 * @param pio pio device to use
 * @param sm statemachine index in pio device
 * @param offset where the program exist. see dcc_receiver_add_program load program
 */
void dcc_receiver_begin(PIO pio, uint sm, uint dcc_pin, uint offset)
{
    //Configure pin as input with pull-up.
    gpio_init(dcc_pin);
    gpio_set_pulls(dcc_pin, true, false);
 
    //Call PIO code
    dcc_receiver_pio_init(pio, sm, dcc_pin, offset);
}

/**
 * @brief Check if we have received a packet.
 * @param pio pio device to use
 * @param sm statemachine index in pio device
 * @return True if a packet exist
 */
bool dcc_receiver_available(PIO pio, uint sm)
{
    return pio_interrupt_get(pio, sm);
    
    
}

/**
 * @brief Read DCC packet.
 * @param pio pio device to use
 * @param sm statemachine index in pio device
 * @return 
 */
uint dcc_receiver_read(PIO pio, uint sm, uint8_t packet[8])
{
    //Check if we got data.
    if(dcc_receiver_available(pio, sm) == false)
    {
        return 0;
    }
    
 
    //Get number of samples in RX-FIFO
    uint length = pio_sm_get_rx_fifo_level(pio, sm);
    
    //copy data from FIFO, ignore RX underrun.
    for(int i=0;i<8;i++)
    {
        packet[i] = pio_sm_get(pio, sm);
    }

    //Clear flag
    pio_interrupt_clear(pio, sm);
    
    //Return the length of the DCC packet
    return length;
}
