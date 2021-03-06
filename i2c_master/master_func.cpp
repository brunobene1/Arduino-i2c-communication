#include "master_func.h"

void master_func_setup()
{
  Serial.begin(9600); //Initializes Serial communication
  Wire.begin(); //Initializes as master
}

void master_func_write(int slave_adress, uint8_t* master_message, int master_msg_length)
{
  Wire.beginTransmission(slave_adress); //Starts the communication with the slave
  Serial.print("Sending message: ");
  for(int i=0; i<master_msg_length; i++)
  {
     Serial.print(master_message[i]);
     if(i!= master_msg_length-1)
     {
        Serial.print(", ");
     }
     Wire.write(master_message[i]); //Sends the message in the Serial Data bus
  }
  Serial.println();
  Serial.print("To slave: ");
  Serial.println(slave_adress);
  Wire.endTransmission();
}

void master_func_read(int slave_adress, uint8_t slave_msg_length, uint8_t* slave_msg)
{
  Wire.requestFrom(slave_adress, slave_msg_length); //Request from slave adress
  //int slave_msg[slave_msg_length];
  Serial.println("Received: ");
  for(int i=0; i < slave_msg_length; i++)
  {
    slave_msg[i] = Wire.read(); //reads the slave message
    Serial.print("Byte ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(slave_msg[i]); 
  }
  Wire.endTransmission();
}

void master_func_all_zeros (uint8_t *master_message)
{
  master_message[0] = 0;              //*
  master_message[1] = 0;              //* 
  master_message[2] = 0;  
  master_message[3] = 0;              //*
  master_message[4] = 0;              //* 
  master_message[5] = 0;  
  master_message[6] = 0;              //*
  master_message[7] = 0;              //* 
  master_message[8] = 0;  
  master_message[9] = 0;
}
