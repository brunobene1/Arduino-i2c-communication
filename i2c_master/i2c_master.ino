/**
 * \brief Arduino_i2c_communication
 * 
 * \author Bruno Benedetti <brunobenedetti45@gmail.com>
 * 
 * \version 1.0.1
 * 
 * \date 06/11/2021
 * 
 */

#include "master_func.h"
#include "requests.h"


void setup()
{
  master_func_setup();
}

void loop() 
{
  request_1(9,3,2);
  delay(5000); //Waits 5 seconds
  request_2(9,1,3);
  delay(5000); //Waits 5 seconds
  request_3(9,4,5);
  delay(5000); //Waits 5 seconds
}
