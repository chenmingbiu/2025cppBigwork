#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <cstring>
#include <iostream>
#include"Account.h"

class back;
class Account;

extern back Userback;
extern Account User;

class item {
protected:
    int id;
    int price;
    char name[30] = { 0 };
    char describe[1000] = { 0 };

public:
    item(int a, char* b, int c, char* d);
    virtual ~item() = default;

    int getprice();
    virtual void showitem();
};

class restore_item : public item {
    friend class back;

protected:
    int effect;

public:
    restore_item(int a, char* b, int c, char* d, int e);
    int geteffect();
};

class non_restore_item : public item {
    friend class back;

protected:
    int success;

public:
    non_restore_item(int a, char* b, int c, char* d, int e);
    int getsuccess();
};

class back {
public:
    std::vector<int> amounts;
    item* itemlist[10];

    void showback();
    ~back();
};

#endif