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
    new restore_item(1000,const_cast <char*>("金币"),0,const_cast <char*>("各个大陆的流通货币"),0),
    new restore_item(1001,const_cast <char*>("小血瓶"),30,const_cast <char*>("小型的血量回复药，可以恢复50点血量"),50),
    new restore_item(1002,const_cast <char*>("中血瓶"),50,const_cast <char*>("中型的血量回复药，可以恢复50点血量"),100),
    new restore_item(1003,const_cast <char*>("中血瓶"),70,const_cast <char*>("大型的血量回复药，可以恢复150点血量"),150),
    new restore_item(1004,const_cast <char*>("小蓝瓶"),30,const_cast <char*>("小型的魔力回复药，可以恢复50点魔力"),50),
    new restore_item(1005,const_cast <char*>("中蓝瓶"),50,const_cast <char*>("中型的魔力回复药，可以恢复50点魔力"),100),
    new restore_item(1006,const_cast <char*>("大蓝瓶"),70,const_cast <char*>("大型的魔力回复药，可以恢复150点魔力"),150),
    new non_restore_item(1007, const_cast<char*>("基础精灵球"), 100, const_cast<char*>("最低级的精灵球，小概率捕捉到精灵"), 20),
    new non_restore_item(1008, const_cast<char*>("进阶精灵球"),200,const_cast<char*>("进阶的精灵球，大概率捕捉到精灵"),50),
    new non_restore_item(1009,const_cast<char*>("大师精灵球"),300,const_cast<char*>("最高级的精灵球，必定捕捉到精灵"),100)
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

