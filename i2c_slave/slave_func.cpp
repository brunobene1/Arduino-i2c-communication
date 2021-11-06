#include "slave_func.h"

//-------- global variables --------
int master_msg;
int slave_msg;

void slave_func_setup()
{
  Serial.begin(9600);
  Wire.begin(SLAVES_ADRESS); //Initializes the slave
  Wire.onReceive(slave_func_read); //Its triggered when the master sends something
  Wire.onRequest(slave_func_write); //Its triggered when the master request something
}

void slave_func_read(int bytes)
{
  master_msg = Wire.read(); //reads from the Serial data bus
  Serial.print("I received: ");
  Serial.println(master_msg);
}

void slave_func_write()
{
  //Just some random values
  //If the master sends 1, send back a 2
  //If the master sends 2, send back a 4
  //If the master sends 3, send back a 6
  switch(master_msg)
  {
    case 1:
    slave_msg = 2;
    Serial.print("sending: ");
    Serial.println(slave_msg);
    Wire.write(slave_msg);
    break;
    
    case 2:
    slave_msg = 4;
    Serial.print("sending: ");
    Serial.println(slave_msg);
    Wire.write(slave_msg);
    break;
    
    case 3:
    slave_msg = 6;
    Serial.print("sending: ");
    Serial.println(slave_msg);
    Wire.write(slave_msg);
    break;
    
    default:
    slave_msg = 0;
    Serial.print("sending: ");
    Serial.println(slave_msg);
    Wire.write(slave_msg);
    break;
  }
}
