#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <vector>
#include <cstring>
#include <cctype>
#include <random>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;

class item
{
public:
    int id;
    int price;
    char name[30];
    char describe[1000];
    item(int a, char* b, int c, char* d);
    virtual void showitem() {};
    virtual ~item() {}
};

class restore_item : public item
{
    friend class back;
public:
    int effect;
    restore_item(int a, char* b, int c, char* d, int e);
    void showitem();
};

class non_restore_item : public item
{
    friend class back;
public:
    int success;
    non_restore_item(int a, char* b, int c, char* d, int e);
    void showitem();
};

class back
{
public:
    vector<int> amounts;
    item* itemlist[10];
    back();
    ~back();
    void showback();
};

class Account
{
    friend void registeraccount();
    friend void accountread(ifstream& opf, Account& temp);
public:
    char name[30];
    int account;
    char password[30];
};

int getmenuchoice();
int getnumber(int max);
void clearInputBuffer();
void savedata(Account& accounts, back& backs);
void place(Account& tempaccount, back& backs);
void readdata(Account& accounts, back& backs);
void game_begin(Account& tempaccount, back& backs);
string encryption(const string& text);
void registeraccount();
void exitgame();
void login();
void changepassword();

#endif // GAME_H