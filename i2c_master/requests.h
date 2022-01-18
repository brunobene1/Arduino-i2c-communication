#ifndef REQUESTS_H
#define REQUESTS_H

#include <Arduino.h>
#include "Wire.h"
#include "master_func.h"
#include "crc8.h"

/**
 * \brief All the i2c requests
 * 
 * \param[in] current_request Current request variable
 */
void requests(int* current_request);

#endif /* REQUESTS_H */
