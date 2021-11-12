#include "slave_func.h"

//-------- global variables --------
int master_msg;
int slave_msg[10];
int master_length_request;

void slave_func_setup()
{
  Serial.begin(9600);
  Wire.begin(SLAVES_ADRESS); //Initializes the slave
  Wire.onReceive(slave_func_read); //Its triggered when the master sends something
  Wire.onRequest(slave_func_write); //Its triggered when the master request something
  slave_msg[0] = SLAVES_ADRESS;
  master_length_request =10;
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
  switch(master_msg)
  {
    case 1:
    slave_msg[1] = 2;
    slave_msg[2] = 10;
    slave_msg[3] = 30;
    slave_msg[4] = 45;
    slave_msg[5] = 12;
    slave_msg[6] = 99;
    slave_msg[7] = 66;
    slave_msg[8] = 0;
    slave_msg[9] = 23;
    for(int i=0; i<master_length_request ;i++)
    {
      Serial.print("sending: ");
      Serial.println(slave_msg[i]);
      Wire.write(slave_msg[i]); 
    }
    break;
    
    case 2:
    slave_msg[1] = 4;
    slave_msg[2] = 0;
    slave_msg[3] = 20;
    slave_msg[4] = 75;
    slave_msg[5] = 19;
    slave_msg[6] = 92;
    slave_msg[7] = 6;
    slave_msg[8] = 13;
    slave_msg[9] = 40;
    for(int i=0; i<master_length_request ;i++)
    {
      Serial.print("sending: ");
      Serial.println(slave_msg[i]);
      Wire.write(slave_msg[i]); 
    }
    break;
    
    case 3:
    slave_msg[1] = 6;
    slave_msg[2] = 23;
    slave_msg[3] = 24;
    slave_msg[4] = 8;
    slave_msg[5] = 34;
    slave_msg[6] = 12;
    slave_msg[7] = 15;
    slave_msg[8] = 4;
    slave_msg[9] = 3;
    for(int i=0; i<master_length_request ;i++)
    {
      Serial.print("sending: ");
      Serial.println(slave_msg[i]);
      Wire.write(slave_msg[i]); 
    }
    break;
    
    default:
    slave_msg[1] = 0;
    slave_msg[2] = 0;
    slave_msg[3] = 0;
    slave_msg[4] = 0;
    slave_msg[5] = 0;
    slave_msg[6] = 0;
    slave_msg[7] = 0;
    slave_msg[8] = 0;
    slave_msg[9] = 0;
    for(int i=0; i<master_length_request ;i++)
    {
      Serial.print("sending: ");
      Serial.println(slave_msg[i]);
      Wire.write(slave_msg[i]); 
    }
    break;
  }
}
