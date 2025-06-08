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

    cout << "1:�����˺�" << endl;
    cout << "0:�������˵�" << endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }

shuru1: cout << "�������˺ţ�" << endl;
    cin >> x;
    if (x.length() != 7 || !all_of(x.begin(), x.end(), ::isdigit))
    {
        cout << "�˺ű���Ϊ7λ���֣�" << endl;
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
        cout << "���˺�δע�ᣡ" << endl;
        goto shuru1;
    }

    readdata(templog, backs);

shurumima:cout << "���������룺" << endl;
    cin >> temppassword;
    clearInputBuffer();
    char temp_password[30];
    strncpy(temp_password, &encryption(temppassword)[0], 29);
    temp_password[29] = '\0';

    if (strcmp(templog.password, temp_password) == 0)
        cout << "��¼�ɹ�,��ӭ���汾��Ϸ��" << endl;
    else
    {
        cout << "�������" << endl;
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

    cout << "1:�޸�����" << endl;
    cout << "0:�������˵�" << endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }

shuru2: cout << "�������˺�" << endl;
    cin >> x.account;
    clearInputBuffer();
    filename = to_string(x.account) + ".txt";
    test.open(filename, ios::in | ios::binary);
    bool isopen = test.is_open();
    test.close();
    if (!isopen)
    {
        cout << "���˺Ų�����,����������" << endl;
        goto shuru2;
    }
    readdata(x, backs);

shuruyuanmima:cout << "������ԭ����:" << endl;
    cin >> oldpassword;
    clearInputBuffer();
    char old_password[30];
    strncpy(old_password, &encryption(oldpassword)[0], 29);
    old_password[29] = '\0';

shuruxinmima:cout << "������������:" << endl;
    cin >> newpassword;
    clearInputBuffer();
    if (newpassword.length() > 29)
    {
        cout << "�����볤�ȳ���29�����������룺" << endl;
        goto shuruxinmima;
    }
    char new_password[30];
    strncpy(new_password, &encryption(newpassword)[0], 29);
    new_password[29] = '\0';

    if (strcmp(old_password, x.password) == 0)
    {
        strncpy(x.password, &encryption(newpassword)[0], 30);
        savedata(x, backs);
        cout << "�����޸ĳɹ�" << endl;
    }
    else
    {
        cout << "ԭʼ�����������,���������룺" << endl;
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

    cout << "1:ע���˺�" << endl;
    cout << "0:�������˵�" << endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }
shuru: cout << "�������˺�(�������֣�����7λ):" << endl;
    cin >> x;
    clearInputBuffer();
    if (x.length() != 7 || !all_of(x.begin(), x.end(), ::isdigit))
    {
        cout << "�˺ű���Ϊ7λ���֣�" << endl;
        goto shuru;
    }
    else temp.account = stoi(x);
    string temp_account = to_string(temp.account) + ".txt";
    opf.open(temp_account, ios::in | ios::binary);
    bool isopen = opf.is_open();
    opf.close();
    if (isopen)
    {
        cout << "���˺��ѱ�ע�ᣬ���������룺" << endl;
        goto shuru;
    }
shurumima:cout << "���������룺" << endl;
    cin >> temp_password;
    clearInputBuffer();
    if (temp_password.length() > 29)
    {
        cout << "���볤�ȳ���29�����������룺" << endl;
        goto shurumima;
    }
    strncpy(temp.password, &encryption(temp_password)[0], 29);
    temp.password[29] = '\0';
shurunicheng:cout << "�������ǳƣ�" << endl;
    cin >> temp_name;
    clearInputBuffer();
    if (temp_name.length() > 29)
    {
        cout << "�ǳƳ��ȳ���29�����������룺" << endl;
        goto shurunicheng;
    }
    strncpy(temp.name, &temp_name[0], 29);
    temp.name[29] = '\0';
    savedata(temp, backs);
    cout << "ע��ɹ�����ӭʹ��" << endl;
}
