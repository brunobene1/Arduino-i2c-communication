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
    Serial.println("Request 1:");
    //-------- variable values --------
    slave_adress = 9;
    master_msg_length = 3;
    slave_msg_length =2;
    master_message[0] = 39;              //*
    master_message[1] = 18;              //* 
    master_message[2] = 3;               //*  
    //-------- variables end --------
    master_func_write(slave_adress, master_message, master_msg_length);
    master_func_read(slave_adress, slave_msg_length, slave_msg);
    break;

    case 2:
    Serial.println("---------------------///////---------------------");
    Serial.println("Request 2:");
    //-------- variable values --------
    slave_adress = 9;
    master_msg_length = 1;
    slave_msg_length =2;
    master_message[0] = 1;                //*
    //-------- variables end --------
    master_func_write(slave_adress, master_message, master_msg_length);
    master_func_read(slave_adress, slave_msg_length, slave_msg);
    break;

    case 3://crc check
    Serial.println("---------------------///////---------------------");
    Serial.println("Request 3 (Crc8 check):");
    //-------- variable values --------
    slave_adress = 9;
    master_msg_length = 2;
    slave_msg_length =1;
    master_func_all_zeros(master_message);
    //-------- Master main message will be -------- :
    master_message[0] = 4;
    //-------- variables end --------
    //-------- crc8 message -------- : 
    crc8_var = crc8(master_message, master_msg_length);
    Serial.println("Crc8 result : ");
    Serial.println(crc8_var);
    master_message[0] = crc8_var;
    master_func_write(slave_adress, master_message, 1);
    //-------- Master main message -------- :
    master_message[0] = 4;
    master_func_write(slave_adress, master_message, master_msg_length);
    master_func_read(slave_adress, slave_msg_length, slave_msg);
    check_crc_result(check_crc(master_message, master_msg_length, slave_msg[0]));
    
    default:
    *current_request = 0; // 0 beacuse once the code gets out of this function
    // there will be an increment in the curren_request variable
    Serial.println("---------------------///////---------------------");
    Serial.println("The requests have ended, restarting...");
    break;
  }
}
