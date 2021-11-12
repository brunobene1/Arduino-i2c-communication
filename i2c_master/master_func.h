#ifndef MASTER_FUNC_H
#define MASTER_FUNC_H

#include <Arduino.h>
#include "Wire.h"

/**
 * \brief Setup the master
 */
void master_func_setup();

/**
 * \brief Writes on the Serial data bus
 * 
 * \param[in] slave_adress Every slave has its unique adress
 * 
 * \param[in] master_message Master's message to the slave
 * 
 * \param[in] master_msg_length Master's message length in number of bytes
 */
void master_func_write(int slave_adress, int* master_message, int master_msg_length);


/**
 * \brief Reads the Serial data bus
 * 
 * \param[in] slave_adress Every slave has its unique adress
 * 
 * \param[in] slave_msg_length Slave message length in number of bytes
 */
void master_func_read(int slave_adress, int slave_msg_length);

#endif /* MASTER_FUNC_H */
