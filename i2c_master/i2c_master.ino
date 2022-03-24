/**
 * \brief Arduino_i2c_communication
 * 
 * \author Bruno Benedetti <brunobenedetti45@gmail.com>
 * 
 * \version 2.0.0
 * 
 * \date 06/11/2021
 * 
 */

#include "master_func.h"
#include "requests.h"

int current_request;

void setup()
{
  master_func_setup();
  current_request = 1;
}

void loop() 
{
  requests(&current_request);
  current_request++;
  delay(5000); //Waits 5 seconds
}
