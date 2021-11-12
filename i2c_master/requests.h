#ifndef REQUESTS_H
#define REQUESTS_H

#include <Arduino.h>
#include "Wire.h"
#include "master_func.h"

/**
 * \brief Request 1
 * 
 * \param[in] slave_adress Every slave has its unique adress
 * 
 * \param[in] master_msg_length Master's message length in number of bytes
 * 
 * \param[in] slave_msg_length Slave's message length in number of bytes
 */
void request_1(int slave_adress, int master_msg_length, int slave_msg_length);

/**
 * \brief Request 2
 * 
 * \param[in] slave_adress Every slave has its unique adress
 * 
 * \param[in] master_msg_length Master's message length in number of bytes
 * 
 * \param[in] slave_msg_length Slave's message length in number of bytes
 */
void request_2(int slave_adress, int master_msg_length, int slave_msg_length);

/**
 * \brief Request 3
 * 
 * \param[in] slave_adress Every slave has its unique adress
 * 
 * \param[in] master_msg_length Master's message length in number of bytes
 * 
 * \param[in] slave_msg_length Slave's message length in number of bytes
 */
void request_3(int slave_adress, int master_msg_length, int slave_msg_length);

#endif /* REQUESTS_H */
