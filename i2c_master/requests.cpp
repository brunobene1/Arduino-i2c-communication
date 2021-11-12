#include "requests.h"

//-------- global variables --------
int slave_adress;
int master_message[10];
int master_msg_length;
int slave_msg_length;

void request_1(int slave_adress, int master_msg_length, int slave_msg_length)
{
  Serial.println("---------------------///////---------------------");
  Serial.println("Request 1:");
  //-------- variable values --------
  master_message[0] = 2;                //*
  master_message[1] = 18;                //* 
  master_message[2] = 39;                //*  
  //-------- variables end --------
  master_func_write(slave_adress, master_message, master_msg_length);
  master_func_read(slave_adress, slave_msg_length);
}

void request_2(int slave_adress, int master_msg_length, int slave_msg_length)
{
  Serial.println("---------------------///////---------------------");
  Serial.println("Request 2:");
  //-------- variable values --------
  //Change manually the master message    *
  master_message[0] = 1;                //*
  //-------- variables end --------
  master_func_write(slave_adress, master_message, master_msg_length);
  master_func_read(slave_adress, slave_msg_length);
}

void request_3(int slave_adress, int master_msg_length, int slave_msg_length)
{
  Serial.println("---------------------///////---------------------");
  Serial.println("Request 3:");
  //-------- variable values --------
  master_message[0] = 3;                //*
  master_message[1] = 130;              //* 
  master_message[2] = 2;                //*
  master_message[3] = 15;               //*  
  //-------- variables end --------
  master_func_write(slave_adress, master_message, master_msg_length);
  master_func_read(slave_adress, slave_msg_length);
}
