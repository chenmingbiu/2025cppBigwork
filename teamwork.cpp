#include<iostream>
#include "Pokemonclass.h"
#include"Fight.h"
#include<fstream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

class item
{
public:
    int id;
    int price;
    string name;
    string describe;
    item(int a,string b,int c,string d):id(a),name(b),price(c),describe(d){}
    virtual void showitem(){};
};

class restore_item:public item
{
    friend class back;

public:
    int effect;
    
    restore_item(int a,string b,int c,string d,int e):item(a,b,c,d),effect(e){}

    void showitem()
    {
        cout<<name<<"   "<<describe<<"  ";
    }
};

class non_restore_item:public item
{
    friend class back;

public:
    int success;

    non_restore_item(int a,string b,int c,string d,int e):item(a,b,c,d),success(e){}
    
    void showitem()
    {
        cout<<name<<"   "<<describe<<"  ";
    }
};

class back
{
public:
    vector<int> amounts={1000,3,2,1,3,2,1,3,2,1};
    item* itemlist[10]=
    {
    new restore_item(1000,"���",0,"������½����ͨ����",0),
    new restore_item(1001,"СѪƿ",30,"С�͵�Ѫ���ظ�ҩ�����Իָ�50��Ѫ��",50),
    new restore_item(1002,"��Ѫƿ",50,"���͵�Ѫ���ظ�ҩ�����Իָ�50��Ѫ��",100),
    new restore_item(1003,"��Ѫƿ",70,"���͵�Ѫ���ظ�ҩ�����Իָ�150��Ѫ��",150),
    new restore_item(1004,"С��ƿ",30,"С�͵�ħ���ظ�ҩ�����Իָ�50��ħ��",50),
    new restore_item(1005,"����ƿ",50,"���͵�ħ���ظ�ҩ�����Իָ�50��ħ��",100),
    new restore_item(1006,"����ƿ",70,"���͵�ħ���ظ�ҩ�����Իָ�150��ħ��",150),
    new non_restore_item(1007,"����������",100,"��ͼ��ľ�����С���ʲ�׽������",20),
    new non_restore_item(1008,"���׾�����",200,"���׵ľ����򣬴���ʲ�׽������",50),
    new non_restore_item(1009,"��ʦ������",300,"��߼��ľ����򣬱ض���׽������",100)
    };
    // restore_item gold=restore_item(1000,"���","������½����ͨ����",0);
    // restore_item blood_l=restore_item(1001,"СѪƿ","С�͵�Ѫ���ظ�ҩ�����Իָ�50��Ѫ��",50);
    // restore_item blood_m=restore_item(1002,"��Ѫƿ","���͵�Ѫ���ظ�ҩ�����Իָ�50��Ѫ��",100);
    // restore_item blood_x=restore_item(1003,"��Ѫƿ","���͵�Ѫ���ظ�ҩ�����Իָ�150��Ѫ��",150);
    // restore_item mana_l=restore_item(1004,"С��ƿ","С�͵�ħ���ظ�ҩ�����Իָ�50��ħ��",50);
    // restore_item mana_m=restore_item(1005,"����ƿ","���͵�ħ���ظ�ҩ�����Իָ�50��ħ��",100);
    // restore_item mana_x=restore_item(1006,"����ƿ","���͵�ħ���ظ�ҩ�����Իָ�150��ħ��",150);
    // non_restore_item ball_l=non_restore_item(1007,"����������","��ͼ��ľ�����С���ʲ�׽������",20);
    // non_restore_item ball_m=non_restore_item(1008,"���׾�����","���׵ľ����򣬴���ʲ�׽������",50);
    // non_restore_item ball_x=non_restore_item(1009,"��ʦ������","��߼��ľ����򣬱ض���׽������",100);
    void showback()
    {
        for(int i=0;i<10;i++)
        {
            if(amounts[i]!=0)
            {
                itemlist[i]->showitem();
                cout<<amounts[i]<<endl;
            }
        }
    }
};

class elf_pack
{
public:

};

class Account
{
    friend void registeraccount();
    friend void accountread(ifstream& opf,Account& temp);
public:
    string name;
    int account;
    string password;
};

int getmenuchoice() 
{
    string input;
    while (true) 
    {
        cout << "������ѡ�";
        getline(cin, input);
        if (input.length() == 1) 
        {
            char c = input[0];
            if (c>='0'&&c<='9') 
            {
                return c-'0';
            }
        }
        cout<<"����0-9֮�������"<<endl;
    }
}

int getnumber(int max) 
{
    string input;
    while (true) 
    {
        cout<<"���ɹ�������Ϊ"<<max<<endl;
        getline(cin, input);
        if (input.empty()) 
        {
            cout<<"���벻��Ϊ�գ�����������"<<endl;
            continue;
        }
        bool isnumber=true;
        for (char c:input) 
        {
            if (!isdigit(c)) 
            {
                isnumber=false;
                break;
            }
        }
        
        if(isnumber) 
        {
            int i=stoi(input);
            if(i<=max)return i;
            else cout<<"������������"<<endl;
        }
        else 
        {
            cout<<"������������"<<endl;
        }
    }
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(1024,'\n');
}

void savedata(Account& accounts, back& backs) 
{
    string filename=to_string(accounts.account)+".txt";
    ofstream file(filename,ios::out|ios::binary|ios::trunc);
    
    size_t len=accounts.password.size();
    file.write((const char*)&len,sizeof(size_t));
    file.write(&accounts.password[0],len);
    
    len=accounts.name.size();
    file.write((const char*)&len, sizeof(size_t));
    file.write(&accounts.name[0],len);

    for(int i:backs.amounts)
    {
        file.write((const char*)&i,sizeof(int));
    }

    file.close();
}

void place(Account& tempaccount,back& backs)
{
    cout<<"1:�̵�"<<endl;
    cout<<"2:ҽԺ"<<endl;
    cout<<"3:����"<<endl;
    cout<<"4:ɭ��"<<endl;
    cout<<"5:�����"<<endl;
    cout<<"6:��ɽ"<<endl;
    cout<<"7:ԭʼɽ��"<<endl;
    cout<<"0:��԰"<<endl;
    int choice=getmenuchoice();
    switch(choice)
    {
        case 1:
        {
            cout<<"1:������Ʒ"<<endl;
            cout<<"0:�뿪�̵�"<<endl;
            int choice1=getmenuchoice();
            if(choice1!=1)return;
            else
            {
                while(true)
                {
                cout<<"��ѡ��Ҫ�������Ʒ"<<endl;
                cout<<"1:СѪƿ"<<endl;
                cout<<"2:��Ѫƿ"<<endl;
                cout<<"3:��Ѫƿ"<<endl;
                cout<<"4:Сħ��ƿ"<<endl;
                cout<<"5:��ħ��ƿ"<<endl;
                cout<<"6:��ħ��ƿ"<<endl;
                cout<<"7:����������"<<endl;
                cout<<"8:���׾�����"<<endl;
                cout<<"9:��ʦ������"<<endl;
                cout<<"0:�˳��̵�"<<endl;
                int choice11=getmenuchoice();
                if(choice11!=0)
                {
                int max=9999-backs.amounts[choice11];
                int number=getnumber(max);
                if(backs.amounts[0]<number*backs.itemlist[choice11]->price)
                {
                    cout<<"��Ҳ��㣬�޷�����"<<endl;
                }
                else
                {
                    backs.amounts[0]-=number*backs.itemlist[choice11]->price;
                    backs.amounts[choice11]+=number;
                    cout<<"����ɹ�"<<endl;
                    continue;
                }
                }
                else
                {
                    return;
                }
                }
            }
        }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:return;
    }
}

void readdata(Account& accounts, back& backs)
{
    string filename=to_string(accounts.account)+".txt";
    ifstream opf(filename,ios::in|ios::binary);

    size_t len;

    opf.read((char*)&len,sizeof(size_t));
    accounts.password.resize(len);
    opf.read(&accounts.password[0],len);
    
    opf.read((char*)&len,sizeof(size_t));
    accounts.name.resize(len);
    opf.read(&accounts.name[0],len);

    for(int i=0;i<10;i++)
    {
        opf.read((char*) &backs.amounts[i],sizeof(int));
    }
}

void game_begin(Account& tempaccount,back& backs)
{
    while(true)
    {
        int choice1;
        cout<<"1:�򿪱���"<<endl;
        cout<<"2:�鿴����"<<endl;
        cout<<"3:�򿪵�ͼ"<<endl;
        cout<<"0:�˳���¼"<<endl;
        choice1=getmenuchoice();
        switch (choice1)
        {
        case 1: backs.showback();
                system("pause");
            break;
        case 2:
            break;
        case 3:place(tempaccount,backs);
            break;
        case 0:
            {
                savedata(tempaccount,backs);
                return;
            }
        default:cout<<"�����������������룺"<<endl;
                system("pause");
                system("cls");
                break;
        }
        
    }
}

// ���ܺ���
string encryption(const string& text) 
{
    string result;
    result.reserve(text.length());
    for (char c:text) 
    {
        if (isalpha(c)) 
        {
            char base=isupper(c)?'A':'a';
            char encrypted=(c-base+5)%26;
            if (encrypted<0)encrypted+=26; 
            encrypted+=base;
            result+=encrypted;
        } 
        else 
        {
            result+=c; 
        }
    }
    return result;
}

void registeraccount()
{
    Account temp;
    back backs;
    ifstream opf;
    string temp_password;

    cout<<"1:�޸�����"<<endl;
    cout<<"0:�������˵�"<<endl;
    int loginChoice = getmenuchoice();
    if(loginChoice==0) 
    {
        return;
    }
    shuru: cout<<"�������˺�(�������֣�����7λ):"<<endl;
    cin>>temp.account;
    clearInputBuffer();
    string temp_account=to_string(temp.account)+".txt";
    opf.open(temp_account,ios::in|ios::binary);
    bool isopen=opf.is_open();
    opf.close();
    if(isopen)
    {
        cout<<"���˺��ѱ�ע�ᣬ���������룺"<<endl;
        goto shuru;
    }
    cout<<"���������룺"<<endl;
    cin>>temp_password;
    clearInputBuffer();
    temp.password=encryption(temp_password);
    cout<<"�������ǳƣ�"<<endl;
    cin>>temp.name;
    clearInputBuffer();
    savedata(temp,backs);
}

void exitgame()
{
    cout<<"��ӭ�´�ʹ�ã�"<<endl;
    system("pause");
    exit(0);
}

void login()
{
    Account templog;
    back backs;
    int tempaccount;
    string tempfilename,temppassword;
    ifstream opf;

    cout<<"1:�����˺�"<<endl;
    cout<<"0:�������˵�"<<endl;
    int loginChoice = getmenuchoice();
    if(loginChoice == 0) 
    {
        return;
    }

    shuru1: cout<<"�������˺ţ�"<<endl;
    cin>>templog.account;
    clearInputBuffer();
    tempfilename=to_string(templog.account)+".txt";
    opf.open(tempfilename,ios::in|ios::binary);
    bool islog=opf.is_open();
    opf.close();
    if(!islog)
    {
        cout<<"���˺�δע�ᣡ"<<endl;
        goto shuru1;
    }
    readdata(templog,backs);

    shurumima:cout<<"���������룺"<<endl;
    cin>>temppassword;
    clearInputBuffer();

    if(templog.password==encryption(temppassword))
    cout<<"��¼�ɹ�,��ӭ���汾��Ϸ��"<<endl;
    else 
    {
        cout<<"�������"<<endl;
        system("pause");
        goto shurumima;
    }
    game_begin(templog,backs);
}



void changepassword()
{
    size_t len=0;
    ifstream test;
    ofstream opf;
    Account x;
    back backs;
    string oldpassword,newpassword,filename;

    cout<<"1:�޸�����"<<endl;
    cout<<"0:�������˵�"<<endl;
    int loginChoice = getmenuchoice();
    if(loginChoice == 0) 
    {
        return;
    }
    shuru2: cout<<"�������˺�"<<endl;
    cin>>x.account;
    clearInputBuffer();
    filename=to_string(x.account)+".txt";
    test.open(filename,ios::in|ios::binary);
    bool isopen=test.is_open();
    test.close();
    if(!isopen)
    {
        cout<<"���˺Ų�����,����������"<<endl;
        goto shuru2;
    }
    readdata(x,backs);

    shuruyuanmima:cout<<"������ԭ����:"<<endl;
    cin>>oldpassword;
    clearInputBuffer();

    cout<<"������������:"<<endl;
    cin>>newpassword;
    clearInputBuffer();

    if(encryption(oldpassword)==x.password)
    {
        x.password=encryption(newpassword);
        savedata(x, backs);
        cout << "�����޸ĳɹ�" << endl;
    }
    else
    {
        cout<<"ԭʼ�����������,���������룺"<<endl;
        goto shuruyuanmima;
    }
}

int main()
{
    int choice=0;
    while(true)
    {
        cout<<"��ӭ���汾��Ϸ"<<endl;
        cout<<"1:��¼�˺�"<<endl;
        cout<<"2:ע���˺�"<<endl;
        cout<<"3:�޸�����"<<endl;
        cout<<"0:�˳���Ϸ"<<endl;
        choice = getmenuchoice();
        switch(choice)
        {
            //��¼�˺�
            case 1: login();
                break;
            //ע���˺�
            case 2: registeraccount();
                break;
            // �޸�����
            case 3: changepassword();
                break;
            // �˳���Ϸ
            case 0:exitgame();
                break;
            default:cout<<"�����������������룺"<<endl;
                    system("pause");
                    system("cls");
                    break;
        }
    }
    return 0;