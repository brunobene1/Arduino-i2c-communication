/**
 * \brief Arduino_i2c_communication
 * 
 * \author Bruno Benedetti <brunobenedetti45@gmail.com>
 * 
 * \version 1.0.0
 * 
 * \date 06/11/2021
 * 
 */

#include "master_func.h"

//-------- global variables --------
int slave_adress;
int master_message;

void setup()
{
  master_func_setup();

  //-------- variable values --------
  slave_adress = 9;   //Change manually the slave Adress
  master_message = 4; //Change manually the master message
  
}

void loop() 
{
  master_func_write(slave_adress, master_message);
  master_func_read(slave_adress);
  delay(5000); //Waits 5 seconds
  Serial.println("---------------------///////---------------------");
}
