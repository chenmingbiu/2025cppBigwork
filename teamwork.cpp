#include"Pokemonclass.h"
#include<fstream>
#include<vector>
#include<cstring>
#include<cctype>
#include<random>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;

class item
{
public:
    int id;
    int price;
    char name[30]={0};
    char describe[1000]={0};
    item(int a,char* b,int c,char* d):id(a),price(c)
    {
        strncpy(name,b,29);
        name[29]='\0';
        strncpy(describe,d,999);
        describe[999]='\0';
    }
    virtual void showitem(){};
};

class restore_item:public item
{
    friend class back;

public:
    int effect;
    
    restore_item(int a,char* b,int c,char* d,int e):item(a,b,c,d),effect(e){}

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

    non_restore_item(int a,char* b,int c,char* d,int e):item(a,b,c,d),success(e){}
    
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
    new restore_item(1000,"金币",0,"各个大陆的流通货币",0),
    new restore_item(1001,"小血瓶",30,"小型的血量回复药，可以恢复50点血量",50),
    new restore_item(1002,"中血瓶",50,"中型的血量回复药，可以恢复50点血量",100),
    new restore_item(1003,"中血瓶",70,"大型的血量回复药，可以恢复150点血量",150),
    new restore_item(1004,"小蓝瓶",30,"小型的魔力回复药，可以恢复50点魔力",50),
    new restore_item(1005,"中蓝瓶",50,"中型的魔力回复药，可以恢复50点魔力",100),
    new restore_item(1006,"大蓝瓶",70,"大型的魔力回复药，可以恢复150点魔力",150),
    new non_restore_item(1007,"基础精灵球",100,"最低级的精灵球，小概率捕捉到精灵",20),
    new non_restore_item(1008,"进阶精灵球",200,"进阶的精灵球，大概率捕捉到精灵",50),
    new non_restore_item(1009,"大师精灵球",300,"最高级的精灵球，必定捕捉到精灵",100)
    };
    
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

    ~back() 
    {
        for (item* ptr:itemlist) 
        {
            delete ptr;
        }
    }
};

class Account
{
    friend void registeraccount();
    friend void accountread(ifstream& opf,Account& temp);
public:
    char name[30]={0};
    int account;
    char password[30]={0};
};

int getmenuchoice() 
{
    string input;
    while (true) 
    {
        cout << "请输入选项：";
        getline(cin, input);
        if (input.length() == 1) 
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
                        cout<<"请选择要购买的物品"<<endl;
                        cout<<"1:小血瓶"<<endl;
                        cout<<"2:中血瓶"<<endl;
                        cout<<"3:大血瓶"<<endl;
                        cout<<"4:小魔力瓶"<<endl;
                        cout<<"5:中魔力瓶"<<endl;
                        cout<<"6:大魔力瓶"<<endl;
                        cout<<"7:基础精灵球"<<endl;
                        cout<<"8:进阶精灵球"<<endl;
                        cout<<"9:大师精灵球"<<endl;
                        cout<<"0:退出商店"<<endl;
                        int choice11=getmenuchoice();
                        if(choice11!=0)
                        {
                            int max=9999-backs.amounts[choice11];
                            int number=getnumber(max);
                            if(backs.amounts[0]<number*backs.itemlist[choice11]->price)
                                cout<<"金币不足，无法购买"<<endl;
                            else
                                {
                                    backs.amounts[0]-=number*backs.itemlist[choice11]->price;
                                    backs.amounts[choice11]+=number;
                                    cout<<"购买成功"<<endl;
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
                    cout<<a<<' '<<b<<' '<<c<<' '<<endl;
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

// 加密函数
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
    string temp_password,temp_name,x;

    cout<<"1:注册账号"<<endl;
    cout<<"0:返回主菜单"<<endl;
    int loginChoice = getmenuchoice();
    if(loginChoice==0) 
    {
        return;
    }
    shuru: cout<<"请输入账号(仅限数字，长度7位):"<<endl;
    cin>>x;
    clearInputBuffer();
    if(x.length()!=7||!all_of(x.begin(),x.end(),::isdigit)) 
        {
            cout << "账号必须为7位数字！" << endl;
            goto shuru;
        }
    else temp.account=stoi(x);
    string temp_account=to_string(temp.account)+".txt";
    opf.open(temp_account,ios::in|ios::binary);
    bool isopen=opf.is_open();
    opf.close();
    if(isopen)
    {
        cout<<"该账号已被注册，请重新输入："<<endl;
        goto shuru;
    }
    shurumima:cout<<"请输入密码："<<endl;
    cin>>temp_password;
    clearInputBuffer();
    if(temp_password.length()>29)
    {
        cout<<"密码长度超过29，请重新输入："<<endl;
        goto shurumima;
    }
    strncpy(temp.password,&encryption(temp_password)[0],29);
    temp.password[29]='\0';
    shurunicheng:cout<<"请输入昵称："<<endl;
    cin>>temp_name;
    clearInputBuffer();
    if(temp_name.length()>29)
    {
        cout<<"昵称长度超过29，请重新输入："<<endl;
        goto shurunicheng;
    }
    strncpy(temp.name,&temp_name[0],29);
    temp.name[29]='\0';
    savedata(temp,backs);
    cout<<"注册成功，欢迎使用"<<endl;
}

void exitgame()
{
    cout<<"欢迎下次使用！"<<endl;
    system("pause");
    exit(0);
}

void login()
{
    Account templog;
    back backs;
    int tempaccount;
    string tempfilename,temppassword,x;
    ifstream opf;

    cout<<"1:输入账号"<<endl;
    cout<<"0:返回主菜单"<<endl;
    int loginChoice = getmenuchoice();
    if(loginChoice == 0) 
    {
        return;
    }

    shuru1: cout<<"请输入账号："<<endl;
    cin>>x;
    if(x.length()!=7||!all_of(x.begin(),x.end(),::isdigit)) 
        {
            cout<<"账号必须为7位数字！"<<endl;
            goto shuru1;
        }
    else templog.account=stoi(x);
    clearInputBuffer();
    tempfilename=to_string(templog.account)+".txt";
    opf.open(tempfilename,ios::in|ios::binary);
    bool islog=opf.is_open();
    opf.close();
    if(!islog)
    {
        cout<<"该账号未注册！"<<endl;
        goto shuru1;
    }
    readdata(templog,backs);

    shurumima:cout<<"请输入密码："<<endl;
    cin>>temppassword;
    clearInputBuffer();
    char temp_password[30];
    strncpy(temp_password,&encryption(temppassword)[0],29);
    temp_password[29]='\0';

    if(strcmp(templog.password,temp_password)==0)
    cout<<"登录成功,欢迎游玩本游戏！"<<endl;
    else 
    {
        cout<<"密码错误"<<endl;
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

    cout<<"1:修改密码"<<endl;
    cout<<"0:返回主菜单"<<endl;
    int loginChoice = getmenuchoice();
    if(loginChoice == 0) 
    {
        return;
    }

    shuru2: cout<<"请输入账号"<<endl;
    cin>>x.account;
    clearInputBuffer();
    filename=to_string(x.account)+".txt";
    test.open(filename,ios::in|ios::binary);
    bool isopen=test.is_open();
    test.close();
    if(!isopen)
    {
        cout<<"该账号不存在,请重新输入"<<endl;
        goto shuru2;
    }
    readdata(x,backs);

    shuruyuanmima:cout<<"请输入原密码:"<<endl;
    cin>>oldpassword;
    clearInputBuffer();
    char old_password[30];
    strncpy(old_password,&encryption(oldpassword)[0],29);
    old_password[29]='\0';

    shuruxinmima:cout<<"请输入新密码:"<<endl;
    cin>>newpassword;
    clearInputBuffer();
    if(newpassword.length()>29)
    {
        cout<<"新密码长度超过29，请重新输入："<<endl;
        goto shuruxinmima;
    }
    char new_password[30];
    strncpy(new_password,&encryption(newpassword)[0],29);
    new_password[29]='\0';

    if(strcmp(old_password,x.password)==0)
    {
        strncpy(x.password,&encryption(newpassword)[0],30);
        savedata(x, backs);
        cout << "密码修改成功" << endl;
    }
    else
    {
        cout<<"原始密码输入错误,请重新输入："<<endl;
        goto shuruyuanmima;
    }
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
