#include"Pokemonclass.h"
#include "Item.h"
#include "Account.h"
#include "Fight.h"
#include<fstream>
#include<vector>
#include<cstring>
#include<cctype>
#include<random>
#include<ctime>
#include<iostream>
#include<algorithm>
#include"teamwork.h"
using namespace std;

int getmenuchoice() 
{
    string input;
    while (true) 
    {
        cout<<"请输入选项：";
        getline(cin,input);
        if (input.length()==1) 
        {
            char c = input[0];
            if (c>='0'&&c<='9') 
            {
                return c-'0';
            }
        }
        cout<<"请输0-9之间的数字"<<endl;
    }
}

int getnumber(int max) 
{
    string input;
    while (true) 
    {
        cout<<"最多可购买数量为"<<max<<endl;
        getline(cin, input);
        if (input.empty()) 
        {
            cout<<"输入不能为空，请重新输入"<<endl;
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
            else cout<<"购买数量过多"<<endl;
        }
        else 
        {
            cout<<"请输入正整数"<<endl;
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
    
    file.write(&accounts.password[0],sizeof(char[30]));
   
    file.write(&accounts.name[0],sizeof(char[30]));

    for(int i:backs.amounts)
    {
        file.write((const char*)&i,sizeof(int));
    }

    file.close();
}

void place(Account& tempaccount,back& backs)
{
    cout<<"1:商店"<<endl;
    cout<<"2:矿脉"<<endl;
    cout<<"3:森林"<<endl;
    cout<<"4:精灵湖"<<endl;
    cout<<"5:火山"<<endl;
    cout<<"6:原始山脉"<<endl;
    cout<<"0:家园"<<endl;
    int choice=getmenuchoice();
    switch(choice)
    {
        case 1:
            {
                cout<<"1:购买物品"<<endl;
                cout<<"0:离开商店"<<endl;
                int choice1=getmenuchoice();
                if(choice1!=1)return;
                else
                {
                    while(true)
                    {
                        cout << "请选择要购买的物品" << endl;
                        cout << "1:小血瓶" << endl;
                        cout << "2:中血瓶" << endl;
                        cout << "3:大血瓶" << endl;
                        cout << "4:小魔力瓶" << endl;
                        cout << "5:中魔力瓶" << endl;
                        cout << "6:大魔力瓶" << endl;
                        cout << "7:基础精灵球" << endl;
                        cout << "8:进阶精灵球" << endl;
                        cout << "9:大师精灵球" << endl;
                        cout << "0:退出商店" << endl;
                        int choice11 = getmenuchoice();
                        if(choice11!=0)
                        {
                            int max=9999-backs.amounts[choice11];
                            int number=getnumber(max);
                            if(backs.amounts[0]<number*backs.itemlist[choice11]->getprice())
                                {
                                    cout<<"金币不足，无法购买"<<endl;
                                    system("pause");
                                    continue;
                                }
                            else
                                {
                                    backs.amounts[0]-=number*backs.itemlist[choice11]->getprice();
                                    backs.amounts[choice11]+=number;
                                    cout<<"购买成功"<<endl;
                                    system("pause");
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
            {

            }
            break;
        case 3:
            {
                
            }
            break;
        case 4:
            {
                
            }
            break;
        case 5:
            {
                
            }
            break;
        case 6:
            {

            }
            break;
        case 0:return;

        default :cout<<"输入有误，请重新输入："<<endl;
                 system("pause");
                 system("cls");
                 break;
    }
}

void readdata(Account& accounts, back& backs)
{
    string filename=to_string(accounts.account)+".txt";
    ifstream opf(filename,ios::in|ios::binary);

    opf.read(&accounts.password[0],sizeof(char[30]));
    
    opf.read(&accounts.name[0],sizeof(char[30]));

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
        cout<<"1:打开背包"<<endl;
        cout<<"2:查看精灵"<<endl;
        cout<<"3:打开地图"<<endl;
        cout<<"0:退出登录"<<endl;
        choice1=getmenuchoice();
        switch (choice1)
        {
        case 1: backs.showback();
                system("pause");
            break;
        case 2:
            {
                string filename=to_string(tempaccount.account)+".txt";
                int a,b,c,num;
                ifstream opf(filename,ios::in|ios::binary);
                opf.seekg(124,ios::beg);
                for(int i=0;i<num;i++)
                {
                    Pokemon* temp;
                    opf.read((char*)&a,sizeof(int));
                    opf.read((char*)&b,sizeof(int));
                    opf.read((char*)&c,sizeof(int));
                    cout<<a;
                    // InfoDisplayer(b,c);
                }
            }
            break;
        case 3:place(tempaccount,backs);
            break;
        case 0:
            {
                savedata(tempaccount,backs);
                return;
            }
        default:cout<<"输入有误，请重新输入："<<endl;
                system("pause");
                system("cls");
                break;
        }
        
    }
}

void exitgame()
{
    cout<<"欢迎下次使用！"<<endl;
    system("pause");
    exit(0);
}

int main()
{
    int choice=0;
    while(true)
    {
        cout<<"欢迎游玩本游戏"<<endl;
        cout<<"1:登录账号"<<endl;
        cout<<"2:注册账号"<<endl;
        cout<<"3:修改密码"<<endl;
        cout<<"0:退出游戏"<<endl;
        choice = getmenuchoice();
        switch(choice)
        {
            //登录账号
            case 1: login();
                break;
            //注册账号
            case 2: registeraccount();
                break;
            // 修改密码
            case 3: changepassword();
                break;
            // 退出游戏
            case 0:exitgame();
                break;
            default:cout<<"输入有误，请重新输入："<<endl;
                    system("pause");
                    system("cls");
                    break;
        }
    }
    return 0;
}
