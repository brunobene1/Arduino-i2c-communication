#include "slave_func.h"

//-------- global variables --------
uint8_t master_msg[10];
uint8_t slave_msg[10];
int master_length_request;
uint8_t crc8_var;

void slave_func_setup()
{
  Serial.begin(9600);        
  Wire.begin(SLAVES_ADRESS);          //Initializes the slave
  Wire.onReceive(slave_func_read);    //Its triggered when the master sends something
  Wire.onRequest(slave_func_write);   //Its triggered when the master request something
  master_length_request =10;          //Master message length (you can change) 
}

void slave_func_read(int bytes)
{
  Serial.println("---------------------///////---------------------");
  for(int i=0; i<bytes; i++)
  {
    master_msg[i] = Wire.read(); //reads from the Serial data bus
    Serial.print("I received: ");
    Serial.println(master_msg[i]); 
  }
}

void slave_func_write()
{
    //The slave message will be inside an array (you can change the array length)
    slave_msg[0] = SLAVES_ADRESS; //Random data
    slave_msg[1] = 2;             //Random data
    slave_msg[2] = 10;            //Random data
    slave_msg[3] = 30;            //Random data
    slave_msg[4] = 45;            //Random data
    slave_msg[5] = 12;            //Random data
    slave_msg[6] = 99;            //Random data
    slave_msg[7] = 66;            //Random data
    slave_msg[8] = 0;             //Random data
    slave_msg[9] = 23;            //Random data
    Serial.println("---------------------///////---------------------");
    for(int i=0; i<master_length_request ;i++)
    {
      Serial.print("sending: ");
      Serial.println(slave_msg[i]);
      Wire.write(slave_msg[i]);   //Sends to master
    }
}
