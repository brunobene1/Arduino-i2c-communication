#include "requests.h"

//-------- global variables --------
int slave_adress;
uint8_t master_message[10];
int master_msg_length;
uint8_t slave_msg_length;
uint8_t slave_msg[10];
uint8_t crc8_var;

void requests(int* current_request)
{
  switch(*current_request)
  {
    case 1:       
    Serial.println("---------------------///////---------------------");
    Serial.println("Request 1 (EXAMPLE):");
    
    //------------------ variable values -----------------
    slave_adress          = 9;   //Slave adress
    master_msg_length     = 3;   //Number of bytes the master will send
    slave_msg_length      = 2;   //Number of bytes the slave will send
    //The master message will be inside an array (you can change the array length)
    master_message[0]     = 39;  //Random data               
    master_message[1]     = 18;  //Random data            
    master_message[2]     = 3;   //Random data             
    //----------------- variables end -----------------
    
    master_func_write(slave_adress, master_message, master_msg_length);
    master_func_read(slave_adress, slave_msg_length, slave_msg);
    break;
    
    default:
    *current_request = 0; // 0 beacuse once the code gets out of this function
    // there will be an increment in the curren_request variable
    Serial.println("---------------------///////---------------------");
    Serial.println("The requests have ended, restarting...");
    break;
  }
}
