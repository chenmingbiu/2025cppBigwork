#include "Item.h"
#include"Account.h"
#include"Pokemonclass.h"
#include<fstream>
#include<vector>
#include<cstring>
#include<cctype>
#include<random>
#include<ctime>
#include<iostream>
#include<algorithm>
#include"teamwork.h"

extern back Userback;
extern Account User;

class item
{
protected:
    int id;
    int price;
    char name[30] = { 0 };
    char describe[1000] = { 0 };
public:
    item(int a, char* b, int c, char* d) :id(a), price(c)
    {
        strncpy(name, b, 29);
        name[29] = '\0';
        strncpy(describe, d, 999);
        describe[999] = '\0';
    }
    int getprice();
    void showitem()
    {
        cout << name << "   " << describe << "  ";
    }
    
};
int item::getprice() {
    return price;
}
class restore_item :public item
{
    friend class back;

protected:

    int effect;

public:

    restore_item(int a, char* b, int c, char* d, int e) :item(a, b, c, d), effect(e) {}

    int geteffect()
    {
        return effect;
    }
};

class non_restore_item :public item
{
    friend class back;

protected:

    int success;

public:

    non_restore_item(int a, char* b, int c, char* d, int e) :item(a, b, c, d), success(e) {}

    int getsuccess()
    {
        return success;
    }
};

class back
{
public:
    vector<int> amounts = { 1000,3,2,1,3,2,1,3,2,1 };
    item* itemlist[10] =
    {
    new restore_item(1000,const_cast <char*>("���"),0,const_cast <char*>("������½����ͨ����"),0),
    new restore_item(1001,const_cast <char*>("СѪƿ"),30,const_cast <char*>("С�͵�Ѫ���ظ�ҩ�����Իָ�50��Ѫ��"),50),
    new restore_item(1002,const_cast <char*>("��Ѫƿ"),50,const_cast <char*>("���͵�Ѫ���ظ�ҩ�����Իָ�50��Ѫ��"),100),
    new restore_item(1003,const_cast <char*>("��Ѫƿ"),70,const_cast <char*>("���͵�Ѫ���ظ�ҩ�����Իָ�150��Ѫ��"),150),
    new restore_item(1004,const_cast <char*>("С��ƿ"),30,const_cast <char*>("С�͵�ħ���ظ�ҩ�����Իָ�50��ħ��"),50),
    new restore_item(1005,const_cast <char*>("����ƿ"),50,const_cast <char*>("���͵�ħ���ظ�ҩ�����Իָ�50��ħ��"),100),
    new restore_item(1006,const_cast <char*>("����ƿ"),70,const_cast <char*>("���͵�ħ���ظ�ҩ�����Իָ�150��ħ��"),150),
    new non_restore_item(1007, const_cast<char*>("����������"), 100, const_cast<char*>("��ͼ��ľ�����С���ʲ�׽������"), 20),
    new non_restore_item(1008, const_cast<char*>("���׾�����"),200,const_cast<char*>("���׵ľ����򣬴���ʲ�׽������"),50),
    new non_restore_item(1009,const_cast<char*>("��ʦ������"),300,const_cast<char*>("��߼��ľ����򣬱ض���׽������"),100)
    };

    void showback()
    {
        for (int i = 0; i < 10; i++)
        {
            if (amounts[i] != 0)
            {
                itemlist[i]->showitem();
                cout << amounts[i] << endl;
            }
        }
    }

    ~back()
    {
        for (item* x : itemlist)
        {
            delete x;
        }
    }
};

