#include"Pokemonclass.h"
#include<fstream>
#include<vector>
#include<cstring>
#include<cctype>
#include<random>
#include<ctime>
#include<iostream>
#include<algorithm>
#include "teamwork.h"
#include "Account.h"
#include "Item.h"

class Account
{
    friend void registeraccount();
public:
    char name[30] = { 0 };
    int account;
    char password[30] = { 0 };
};

void login()
{
    Account templog;
    back backs;
    int tempaccount;
    string tempfilename, temppassword, x;
    ifstream opf;

    cout << "1:输入账号" << endl;
    cout << "0:返回主菜单" << endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }

shuru1: cout << "请输入账号：" << endl;
    cin >> x;
    if (x.length() != 7 || !all_of(x.begin(), x.end(), ::isdigit))
    {
        cout << "账号必须为7位数字！" << endl;
        goto shuru1;
    }
    else templog.account = stoi(x);
    clearInputBuffer();
    tempfilename = to_string(templog.account) + ".txt";
    opf.open(tempfilename, ios::in | ios::binary);
    bool islog = opf.is_open();
    opf.close();
    if (!islog)
    {
        cout << "该账号未注册！" << endl;
        goto shuru1;
    }

    readdata(templog, backs);

shurumima:cout << "请输入密码：" << endl;
    cin >> temppassword;
    clearInputBuffer();
    char temp_password[30];
    strncpy(temp_password, &encryption(temppassword)[0], 29);
    temp_password[29] = '\0';

    if (strcmp(templog.password, temp_password) == 0)
        cout << "登录成功,欢迎游玩本游戏！" << endl;
    else
    {
        cout << "密码错误" << endl;
        system("pause");
        goto shurumima;
    }
    game_begin(templog, backs);
}

void changepassword()
{
    size_t len = 0;
    ifstream test;
    ofstream opf;
    Account x;
    back backs;
    string oldpassword, newpassword, filename;

    cout << "1:修改密码" << endl;
    cout << "0:返回主菜单" << endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }

shuru2: cout << "请输入账号" << endl;
    cin >> x.account;
    clearInputBuffer();
    filename = to_string(x.account) + ".txt";
    test.open(filename, ios::in | ios::binary);
    bool isopen = test.is_open();
    test.close();
    if (!isopen)
    {
        cout << "该账号不存在,请重新输入" << endl;
        goto shuru2;
    }
    readdata(x, backs);

shuruyuanmima:cout << "请输入原密码:" << endl;
    cin >> oldpassword;
    clearInputBuffer();
    char old_password[30];
    strncpy(old_password, &encryption(oldpassword)[0], 29);
    old_password[29] = '\0';

shuruxinmima:cout << "请输入新密码:" << endl;
    cin >> newpassword;
    clearInputBuffer();
    if (newpassword.length() > 29)
    {
        cout << "新密码长度超过29，请重新输入：" << endl;
        goto shuruxinmima;
    }
    char new_password[30];
    strncpy(new_password, &encryption(newpassword)[0], 29);
    new_password[29] = '\0';

    if (strcmp(old_password, x.password) == 0)
    {
        strncpy(x.password, &encryption(newpassword)[0], 30);
        savedata(x, backs);
        cout << "密码修改成功" << endl;
    }
    else
    {
        cout << "原始密码输入错误,请重新输入：" << endl;
        goto shuruyuanmima;
    }
}

string encryption(const string& text)
{
    string result;
    result.reserve(text.length());
    for (char c : text)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            char encrypted = (c - base + 5) % 26;
            if (encrypted < 0)encrypted += 26;
            encrypted += base;
            result += encrypted;
        }
        else
        {
            result += c;
        }
    }
    return result;
}

void registeraccount()
{
    Account temp;
    back backs;
    ifstream opf;
    string temp_password, temp_name, x;

    cout << "1:注册账号" << endl;
    cout << "0:返回主菜单" << endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }
shuru: cout << "请输入账号(仅限数字，长度7位):" << endl;
    cin >> x;
    clearInputBuffer();
    if (x.length() != 7 || !all_of(x.begin(), x.end(), ::isdigit))
    {
        cout << "账号必须为7位数字！" << endl;
        goto shuru;
    }
    else temp.account = stoi(x);
    string temp_account = to_string(temp.account) + ".txt";
    opf.open(temp_account, ios::in | ios::binary);
    bool isopen = opf.is_open();
    opf.close();
    if (isopen)
    {
        cout << "该账号已被注册，请重新输入：" << endl;
        goto shuru;
    }
shurumima:cout << "请输入密码：" << endl;
    cin >> temp_password;
    clearInputBuffer();
    if (temp_password.length() > 29)
    {
        cout << "密码长度超过29，请重新输入：" << endl;
        goto shurumima;
    }
    strncpy(temp.password, &encryption(temp_password)[0], 29);
    temp.password[29] = '\0';
shurunicheng:cout << "请输入昵称：" << endl;
    cin >> temp_name;
    clearInputBuffer();
    if (temp_name.length() > 29)
    {
        cout << "昵称长度超过29，请重新输入：" << endl;
        goto shurunicheng;
    }
    strncpy(temp.name, &temp_name[0], 29);
    temp.name[29] = '\0';
    savedata(temp, backs);
    cout << "注册成功，欢迎使用" << endl;
}
