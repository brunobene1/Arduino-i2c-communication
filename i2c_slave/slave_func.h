#ifndef SLAVE_FUNC_H
#define SLAVE_FUNC_H

#include <Arduino.h>
#include "Wire.h"

#define SLAVES_ADRESS 9

/**
 * \brief Setup the slave
 */
void slave_func_setup();

/**
 * \brief Its triggered when the master sends something
 */
void slave_func_read(int bytes);

/**
 * \brief Its triggered when the master request something
 * 
 */
void slave_func_write();

#endif /* SLAVE_FUNC_H */
