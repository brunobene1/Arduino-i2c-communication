#include "master_func.h"

void master_func_setup()
{
  Serial.begin(9600); //Initializes Serial communication
  Wire.begin(); //Initializes as master
}

void master_func_write(int slave_adress, int master_message)
{
  //--------- General info printed on the serial monitor ---------
  Serial.print("Sending message: ");
  Serial.print(master_message);
  Serial.print(", to slave: ");
  Serial.println(slave_adress);
  //--------------------------------------------------------------
  Wire.beginTransmission(slave_adress); //Starts the communication with the slave
  Wire.write(master_message); //Sends the message in the Serial Data bus
  Wire.endTransmission();
}

void master_func_read(int slave_adress)
{
  Wire.requestFrom(slave_adress, 1); //Request from slave adress, 1 byte
  int slave_msg;
  slave_msg = Wire.read(); //reads the slave message
  Serial.print("Received: ");
  Serial.println(slave_msg);
  Wire.endTransmission();
}
