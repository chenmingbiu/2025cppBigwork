#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class back; 

class Account
{
    friend void registeraccount(); 
public:
    char name[30] = { 0 }; 
    int account;         
    char password[30] = { 0 };
};
void login();

void changepassword();

void registeraccount();

std::string encryption(const std::string& text);

#endif