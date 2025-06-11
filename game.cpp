#include <fstream>
#include <vector>
#include <cstring>
#include <cctype>
#include <random>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cmath>
#include <memory>

using namespace std;

struct Skill {
    int level;	//�����ͷ���Ҫ�����͵ȼ�
    double ATK;	//���ܹ���������
    double DEF;	//���ܷ���������
    double HP;	//���������ظ�����
    int MP;		//�����ͷ����ĵ�����ֵ
    double DOD;	//���ܴ��������ܸ���Ӱ��
    int num;	//���ܱ��
    string name;//��������
    Skill(int level, double ATK, double DEF, double HP, int MP, double DOD, int num, string name) : level(level), ATK(ATK), DEF(DEF), HP(HP), MP(MP), DOD(DOD), num(num), name(name) {}
    Skill() {
        level = 0; ATK = 0; DEF = 0; HP = 0; MP = 0; DOD = 0; num = 0; name = "0";
    }
};
struct Pokemonteam {
    int num;    //��׽�ɹ�ʱ�ı����α��
    int type;   //����������
    int EXP;    //�����ξ���ֵ
    Pokemonteam(int num, int type, int EXP): num(num), type(type), EXP(EXP) {}
    Pokemonteam() {
        num = 0; type = 0; EXP = 0;
    }
};
class Pokemon;
class item;
class restore_item;
class non_restore_item;
class back;
class Account;
class ElementPokemon_Metal;
class ElementPokemon_Mood;
class ElementPokemon_Water;
class ElementPokemon_Terra;
class Scizor;
class Metang;
class Sceptile;
class Venusaur;
class Gyarados;
class Kingdra;
class Kingdra;
class Arcanine;
class Magmortar;
class Donphan;
class Marshtomp;

int getmenuchoice(int);
int getnumber(int);
void clearInputBuffer();
string encryption(const string&);
int RandomNumber(int);
void readdata();
void savedata();
void place();
void game_begin();
void login();
void registeraccount();
void changepassword();
void exitgame();
double ElementRestraint(Pokemon*, Pokemon*);
bool Win_During(Pokemon*, Pokemon*);
bool Fight_Escape();
void Escape_Fail(Pokemon*, Pokemon*, Skill);
bool SkillCertify(Pokemon*, Skill);
int ATKselect(Pokemon*, Skill&);
int DEFselect(Pokemon*, Skill&);
int DODselect(Pokemon*, Skill&);
bool DODCertify(Pokemon*, Skill);
void HPadder_Skill(Pokemon*, Skill);
void Fight_Action(Pokemon*, Pokemon*, Skill, Skill);
int Fight_During(Pokemon*, Pokemon*);
void Fight_Start(Pokemon*);
void PokemonteamSelector();
void NewPokemonSave(Pokemon*);
void PokemonSave(Pokemon*, int);
void PokemonSearch(int);
bool ItemAmountCertify(int);
int PokemonCapture(Pokemon*);
bool Fight_Capture(int, Pokemon*);
void RestoreItemUsing(Pokemon*);
Skill RandomSkill(Pokemon*);

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
        strcpy_s(name, 29, b);
        name[29] = '\0';
        strcpy_s(describe, 999, d);
        describe[999] = '\0';
    }
    void showitem()
    {
        std::cout << name << "��" << describe << "��";
    }
    int getprice() {
        return price;
    }

    virtual int geteffect() = 0;

    item() = default;
};
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

    int effect;

public:

    non_restore_item(int a, char* b, int c, char* d, int e) :item(a, b, c, d), effect(e) {}

    int geteffect()
    {
        return effect;
    }
};
class Account
{
    friend void registeraccount();
public:
    char name[30] = { 0 };
    int account;
    char password[30] = { 0 };
    Account();
};
Account::Account() {
    account = 0;
}
class back
{
public:
    vector<int> amounts = { 1000,3,2,1,3,2,1,3,2,1 };
    item* itemlist[10] =
    {
    new restore_item(1000,const_cast <char*>("���"),0,const_cast <char*>("��Ϸʹ�õĻ���"),0),
    new restore_item(1001,const_cast <char*>("СѪƿ"),50,const_cast <char*>("С�͵�Ѫ���ظ�ҩ�����Իָ�200��Ѫ��"),200),
    new restore_item(1002,const_cast <char*>("��Ѫƿ"),100,const_cast <char*>("���͵�Ѫ���ظ�ҩ�����Իָ�500��Ѫ��"),500),
    new restore_item(1003,const_cast <char*>("��Ѫƿ"),250,const_cast <char*>("���͵�Ѫ���ظ�ҩ�����Իָ�1000��Ѫ��"),1000),
    new restore_item(1004,const_cast <char*>("С��ƿ"),50,const_cast <char*>("С�͵������ظ�ҩ�����Իָ�100������"),100),
    new restore_item(1005,const_cast <char*>("����ƿ"),100,const_cast <char*>("���͵������ظ�ҩ�����Իָ�200������"),200),
    new restore_item(1006,const_cast <char*>("����ƿ"),250,const_cast <char*>("���͵������ظ�ҩ�����Իָ�500������"),500),
    new non_restore_item(1007, const_cast<char*>("��ͨ��"), 200, const_cast<char*>("��ͼ��ľ�����С���ʲ�׽��������"), 20),
    new non_restore_item(1008, const_cast<char*>("�߼���"),500,const_cast<char*>("���׵ľ����򣬴���ʲ�׽��������"),50),
    new non_restore_item(1009,const_cast<char*>("��ʦ��"),1000,const_cast<char*>("��߼��ľ����򣬱ض���׽��������"),100)
    };

    void showback()
    {
        for (int i = 0; i < 10; i++)
        {
            if (amounts[i] != 0)
            {
                itemlist[i]->showitem();
                std::cout <<"ӵ��������" << amounts[i] << std::endl;
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
class Pokemon {
protected:
    int level;	//�ȼ�
    int EXP;	//����ֵ
    int ATK;	//������
    int DEF;	//������
    int HP;		//����ֵ
    int MP;		//����ֵ
    int HPmax;	//��ǰ״̬�µ��������ֵ
    int MPmax;	//��ǰ״̬�µ��������ֵ
    double DOD = 0.1;	//���ܸ���
    int num;	//������������
    string name;
    string elementname;//Ԫ����
    int elementnum;//Ԫ�ر��

    Skill skill[6];//���ܣ�ʵ�ʹ��켼����������С�ĿǰΪÿ�ֱ������趨���������ܡ�

    void AttributeMaker(int EXP) {
        level = int(pow(EXP, 0.5));	//ʹ�þ���ֵ����ȼ�
        if (level > 100)level = 100;	//��ߵȼ�Ϊ100��
        ATK = 10 + (5 * level);//ʹ�õȼ����칥��������ͬ��
        DEF = 5 + (4 * level);
        HPmax = (20 * level) + 100;
        MPmax = 200 + (8 * level);
    }
    void AttributeRestorer() {
        HP = HPmax;
        MP = MPmax;
    }
    virtual void Skillmaker() = 0;	//��ͬ����ı������в�ͬ�ļ��ܣ����Դ˼��ܹ��캯��������ʵ�֡�
public:
    void DAGmaker(int DAG) { HP -= DAG; if (HP < 0)HP = 0; }	//�˺�ʩ�Ӻ���
    void HPadder(int HPadd) { HP += HPadd; if (HP > HPmax)HP = HPmax; }	//����ֵ�ظ�����
    void MPadder(int MPadd) { MP += MPadd; if (MP > MPmax)MP = MPmax; }
    void EXPadder(int EXPadd) { EXP += EXPadd; }
    void MPreducer(int MPred) { MP -= MPred; }
    string Namegetter() { return name; }
    int elementgetter() { return elementnum; }
    int EXPgetter() { return EXP; }
    int levelgetter() { return level; }
    int HPmaxgetter() { return HPmax; }
    int MPmaxgetter() { return MPmax; }
    int HPgetter() { return HP; }
    int MPgetter() { return MP; }
    int ATKgetter() { return ATK; }
    int DEFgetter() { return DEF; }
    double DODgetter() { return DOD; }
    Skill SkillSelector(int num) { return skill[num - 1]; }
    int GetPokemonType() { return num; }	//��ȡ�����ε�������
    void InfoDisplayer() {	//�����λ�����Ϣ�鿴����
        std::cout << "���������ƣ�" << name << std::endl;
        std::cout << "������Ԫ�أ�" << elementname << std::endl;
        std::cout << "�ȼ���" << level << std::endl;
        std::cout << "����ֵ��" << EXP << std::endl;
        std::cout << "����ֵ��" << HP << " / " << HPmax << std::endl;
        std::cout << "����ֵ��" << MP << " / " << MPmax << std::endl;
        std::cout << "��������" << ATK << std::endl;
        std::cout << "��������" << DEF << std::endl;
        std::cout << "���ܸ��ʣ�" << DOD * 100 << "%" << std::endl;
        std::cout << std::endl;
    }
    void InfoDisplayer_Enemy() {
        std::cout << "���������ƣ�" << name << std::endl;
        std::cout << "������Ԫ�أ�" << elementname << std::endl;
        std::cout << "�ȼ���" << level << std::endl;
        std::cout << "����ֵ��" << HPmax << std::endl;
        std::cout << "��������" << ATK << std::endl;
        std::cout << "��������" << DEF << std::endl;
        std::cout << std::endl;
    }
    void SkillDisplayer() {
        int i = 0;
        for (i = 0; i < 6; i++) {
            std::cout << "�������ƣ�" << skill[i].name << std::endl;
            std::cout << "�������ʣ�" << skill[i].ATK * 100 << "%" << std::endl;
            std::cout << "�������ʣ�" << skill[i].DEF * 100 << "%" << std::endl;
            std::cout << "�����ظ����ʣ�" << skill[i].HP * 100 << "%" << std::endl;
            std::cout << "���ܸ���������" << skill[i].DOD * 100 << "%" << std::endl;
            std::cout << "����ֵ���ģ�" << skill[i].MP << std::endl;
            std::cout << "�����ͷ�������͵ȼ���" << skill[i].level << "��" << std::endl;
            std::cout << std::endl;
        }
    }
    void InfoDisplayer_Liter() {	//������Ԥѡ����ʹ�õļ�Ҫ��Ϣ����
        std::cout << "���������ƣ�" << name << std::endl;
        std::cout << "������Ԫ�أ�" << elementname << std::endl;
        std::cout << "�ȼ���" << level << std::endl;
        std::cout << "����ֵ��" << HP << " / " << HPmax << std::endl;
        std::cout << "����ֵ��" << MP << " / " << MPmax << std::endl;
        std::cout << std::endl;
    }
    void InfoDisplayer_Liter_Enemy() {
        std::cout << "���������ƣ�" << name << std::endl;
        std::cout << "������Ԫ�أ�" << elementname << std::endl;
        std::cout << "�ȼ���" << level << std::endl;
        std::cout << "����ֵ��" << HP << " / " << HPmax << std::endl;
        std::cout << std::endl;
    }
    void SkillDisplayer_Lite(int i) {	//����Ԥѡ����ʹ�õļ�Ҫ��Ϣ����
        i--;
        std::cout << "�������ƣ�" << skill[i].name << std::endl;
        std::cout << "�������ʣ�" << skill[i].ATK * 100 << "%" << std::endl;
        std::cout << "�������ʣ�" << skill[i].DEF * 100 << "%" << std::endl;
        std::cout << "�����ظ����ʣ�" << skill[i].HP * 100 << "%" << std::endl;
        std::cout << "���ܸ���������" << skill[i].DOD * 100 << "%" << std::endl;
        std::cout << "����ֵ���ģ�" << skill[i].MP << std::endl;
        std::cout << "�����ͷ�������͵ȼ���" << skill[i].level << "��" << std::endl;
        std::cout << std::endl;
    }
    static int RandomLevel() {
        int l, t;
        t = RandomNumber(100);
        if (t <= 40) { l = RandomNumber(30); }
        else if (t < 70) { l = RandomNumber(30) + 30; }
        else if (t < 90) { l = RandomNumber(30) + 60; }
        else { l = RandomNumber(10) + 90; }
        return l;
    }
    static Pokemon* CreatePokemon(int num, int EXP);
    static Pokemon* RandomPokemon(int);
    Pokemon() {
        level = 0; EXP = 0; ATK = 0; DEF = 0; HP = 0; MP = 0; HPmax = 0; MPmax = 0; DOD = 0.1; num = 0; name = "0"; elementname = "0"; elementnum = 0;
        for (int i = 0; i < 6; i++) {
            skill[i] = Skill();
        }
    }
};
class ElementPokemon_Metal :public Pokemon {//��Ԫ��
public:
    ElementPokemon_Metal() {
        elementname = "Metal";
        elementnum = 1;
    }
};
class ElementPokemon_Mood :public Pokemon {//ľԪ��
public:
    ElementPokemon_Mood() {
        elementname = "Mood";
        elementnum = 2;
    }
};
class ElementPokemon_Water :public Pokemon {//ˮԪ��
public:
    ElementPokemon_Water() {
        elementname = "Water";
        elementnum = 3;
    }
};
class ElementPokemon_Fire :public Pokemon {//��Ԫ��
public:
    ElementPokemon_Fire() {
        elementname = "Fire";
        elementnum = 4;
    }
};
class ElementPokemon_Terra :public Pokemon {//��Ԫ��
public:
    ElementPokemon_Terra() {
        elementname = "Terra";
        elementnum = 5;
    }
};
class Scizor :public ElementPokemon_Metal {	//��ǯ���
protected:
    void Skillmaker() {	//Ŀǰÿ�������ζ����ӵ��3�������༼�ܣ�2��������ظ��༼�ܣ�1�������༼�ܣ����ݱ����εĵȼ��Ⱥ������
        //ʹ�ü���ʱͨ�����ܱ�Ž��е��á����ܵ���Ҫ���Կ�������Ч���������Կ���ֵ��Ч��
        skill[0].ATK = 1.8; skill[0].DEF = 0.5; skill[0].DOD = -0.1; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 10; skill[0].name = "Iron Charge"; skill[0].num = 1;//�������ܡ�������桱
        //��Ϊ��һ�����ܵĹ������˺�ļ��ܹ�����ʽ��ͬ��
        skill[1].ATK = 2.2; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Alloy Cut"; skill[1].num = 2;//�������ܡ��Ͻ��и
        skill[2].ATK = 3.0; skill[2].DEF = 0.3; skill[2].DOD = 0.1; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 40; skill[2].name = "Atomic Blast"; skill[2].num = 3;//�������ܡ�ԭ�ӳ������
        skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = -0.1; skill[3].HP = 0.15; skill[3].level = 0; skill[3].MP = 20; skill[3].name = "Bronze Wall"; skill[3].num = 4;//�������ܡ�ͭǽ���ڡ�
        skill[4].ATK = 0.4; skill[4].DEF = 3.0; skill[4].DOD = 0; skill[4].HP = 0.15; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Energy Shield"; skill[4].num = 5;//�������ܡ��������ܡ�
        skill[5].ATK = 0.5; skill[5].DEF = 0.5; skill[5].DOD = 0.7; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Quickstep"; skill[5].num = 6;//���ܼ��ܡ����粽��
    }
public:
    Scizor(int);
};
Scizor::Scizor(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 1;
    name = "Scizor";
}
class Metang :public ElementPokemon_Metal {	//�Ͻ�ʮ��
protected:
    void Skillmaker() {
        skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 28; skill[0].name = "Ion Impact"; skill[0].num = 1; // ��������"���ӳ��"
        skill[1].ATK = 2.0; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 32; skill[1].name = "Magnet Storm"; skill[1].num = 2; // ��������"�����籩"
        skill[2].ATK = 2.7; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 48; skill[2].name = "Superconduct"; skill[2].num = 3; // ��������"��������"
        skill[3].ATK = 0.2; skill[3].DEF = 1.8; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 22; skill[3].name = "Magnetic Shield"; skill[3].num = 4; // ��������"��������"
        skill[4].ATK = 0.3; skill[4].DEF = 0.3; skill[4].DOD = 0; skill[4].HP = 0.25; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Energy Regen"; skill[4].num = 5; // �ָ�����"��������"
        skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.2; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 35; skill[5].name = "Electro Drift"; skill[5].num = 6; // ���ܼ���"���Ʈ��"
    }
public:
    Metang(int);
};
Metang::Metang(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 2;
    name = "Metang";
}
class Sceptile :public ElementPokemon_Mood {	//������
protected:
    void Skillmaker() {
        skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 20; skill[0].name = "Leaf Blade"; skill[0].num = 1; // ��������"Ҷ��ն��"
        skill[1].ATK = 1.9; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Seed Bomb"; skill[1].num = 2; // ��������"���ӻ���ǹ"
        skill[2].ATK = 2.5; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 55; skill[2].name = "Forest Storm"; skill[2].num = 3; // ��������"ɭ�ַ籩"
        skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 15; skill[3].name = "Nature's Shelter"; skill[3].num = 4; // ��������"��Ȼ�ӻ�"
        skill[4].ATK = 0.3; skill[4].DEF = 1.6; skill[4].DOD = 0; skill[4].HP = 0.05; skill[4].level = 25; skill[4].MP = 35; skill[4].name = "Root Bind"; skill[4].num = 5; // ��������"�������"
        skill[5].ATK = 0.5; skill[5].DEF = 0.5; skill[5].DOD = 0.2; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 25; skill[5].name = "Shade Stealth"; skill[5].num = 6; // ���ܼ���"��Ӱ����"
    }
public:
    Sceptile(int);
};
Sceptile::Sceptile(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 3;
    name = "Sceptile";
}
class Venusaur :public ElementPokemon_Mood {	//���ܻ�
protected:
    void Skillmaker() {
        skill[0].ATK = 1.6; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 18; skill[0].name = "Vine Whip"; skill[0].num = 1; // ��������"�ٱ��ͻ�"
        skill[1].ATK = 2.1; skill[1].DEF = 0.8; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 38; skill[1].name = "Petal Blizzard"; skill[1].num = 2; // ��������"����籩"
        skill[2].ATK = 2.6; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Ancient Power"; skill[2].num = 3; // ��������"ԭʼ֮��"
        skill[3].ATK = 0.1; skill[3].DEF = 0.1; skill[3].DOD = 0; skill[3].HP = 0.35; skill[3].level = 0; skill[3].MP = 10; skill[3].name = "Photosynthesis"; skill[3].num = 4; // �ָ�����"�������"
        skill[4].ATK = 0.4; skill[4].DEF = 2.2; skill[4].DOD = 0; skill[4].HP = 0; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Petal Shield"; skill[4].num = 5; // ��������"���껤��"
        skill[5].ATK = 0.3; skill[5].DEF = 0.3; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Grass Camouflage"; skill[5].num = 6; // ���ܼ���"�ݴ�����"
    }
public:
    Venusaur(int);
};
Venusaur::Venusaur(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 4;
    name = "Venusaur";
}
class Gyarados :public ElementPokemon_Water {	//������
protected:
    void Skillmaker() {
        skill[0].ATK = 1.9; skill[0].DEF = 0.4; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 35; skill[0].name = "Hydro Pump"; skill[0].num = 1; // ��������"ˮ�ں��"
        skill[1].ATK = 1.5; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Twister"; skill[1].num = 2; // ��������"�����"
        skill[2].ATK = 2.8; skill[2].DEF = 0.2; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 60; skill[2].name = "Hyper Beam"; skill[2].num = 3; // ��������"�ƻ�����"
        skill[3].ATK = 0.2; skill[3].DEF = 1.9; skill[3].DOD = 0; skill[3].HP = 0.12; skill[3].level = 0; skill[3].MP = 30; skill[3].name = "Tidal Shield"; skill[3].num = 4; // ��������"��ϫ����"
        skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 15; skill[4].name = "Rain Dish"; skill[4].num = 5; // �ָ�����"��ˮ����"
        skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Wave Jump"; skill[5].num = 6; // ���ܼ���"������Ծ"
    }
public:
    Gyarados(int);
};
Gyarados::Gyarados(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 5;
    name = "Gyarados";
}
class Kingdra :public ElementPokemon_Water {	//������
protected:
    void Skillmaker() {
        skill[0].ATK = 1.7; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 22; skill[0].name = "Dragon Breath"; skill[0].num = 1; // ��������"��Ϣ���"
        skill[1].ATK = 2.0; skill[1].DEF = 0.6; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 32; skill[1].name = "Ocean Blade"; skill[1].num = 2; // ��������"������"
        skill[2].ATK = 2.4; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 45; skill[2].name = "Abyss Roar"; skill[2].num = 3; // ��������"��Ԩ����"
        skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 28; skill[3].name = "Aqua Barrier"; skill[3].num = 4; // ��������"ˮĻ����"
        skill[4].ATK = 0.2; skill[4].DEF = 0.2; skill[4].DOD = 0; skill[4].HP = 0.25; skill[4].level = 25; skill[4].MP = 38; skill[4].name = "Tide Recovery"; skill[4].num = 5; // �ָ�����"��ϫ�ָ�"
        skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 25; skill[5].name = "Bubble Escape"; skill[5].num = 6; // ���ܼ���"��ĭ����"
    }
public:
    Kingdra(int);
};
Kingdra::Kingdra(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 5;
    name = "Kingdra";
}
class Arcanine :public ElementPokemon_Fire {	//���ٹ�
protected:
    void Skillmaker() {
        skill[0].ATK = 1.8; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 25; skill[0].name = "Flame Rush"; skill[0].num = 1; // ��������"������"
        skill[1].ATK = 2.2; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 35; skill[1].name = "Inferno Storm"; skill[1].num = 2; // ��������"����籩"
        skill[2].ATK = 2.9; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Explosion Rush"; skill[2].num = 3; // ��������"���׳��"
        skill[3].ATK = 0.3; skill[3].DEF = 1.8; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 20; skill[3].name = "Flame Shield"; skill[3].num = 4; // ��������"���滤��"
        skill[4].ATK = 0.2; skill[4].DEF = 0.2; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 30; skill[4].name = "Scorch Recovery"; skill[4].num = 5; // �ָ�����"���Ȼָ�"
        skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Smoke Screen"; skill[5].num = 6; // ���ܼ���"��Ļ����"
    }
public:
    Arcanine(int);
};
Arcanine::Arcanine(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 7;
    name = "Arcanine";
}
class Magmortar :public ElementPokemon_Fire {	//Ѽ������
protected:
    void Skillmaker() {
        skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 28; skill[0].name = "Lava Burst"; skill[0].num = 1; // ��������"���ҳ��"
        skill[1].ATK = 1.9; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Fire Punch"; skill[1].num = 2; // ��������"����ȭ"
        skill[2].ATK = 2.6; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 48; skill[2].name = "Fire Blast"; skill[2].num = 3; // ��������"����籩"
        skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 22; skill[3].name = "Flame Armor"; skill[3].num = 4; // ��������"���滤��"
        skill[4].ATK = 0.3; skill[4].DEF = 2.0; skill[4].DOD = 0; skill[4].HP = 0; skill[4].level = 25; skill[4].MP = 35; skill[4].name = "Scorching Shield"; skill[4].num = 5; // ��������"���Ȼ���"
        skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Smog Escape"; skill[5].num = 6; // ���ܼ���"�������"
    }
public:
    Magmortar(int);
};
Magmortar::Magmortar(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 8;
    name = "Magmortar";
}
class Donphan :public ElementPokemon_Terra {	//�ټ�
protected:
    void Skillmaker() {
        skill[0].ATK = 1.9; skill[0].DEF = 0.4; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 35; skill[0].name = "Earthquake"; skill[0].num = 1; // ��������"������"
        skill[1].ATK = 1.6; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Rock Blast"; skill[1].num = 2; // ��������"��ʯ��"
        skill[2].ATK = 2.4; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Land Crush"; skill[2].num = 3; // ��������"��ط���"
        skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 30; skill[3].name = "Rock Shield"; skill[3].num = 4; // ��������"��ʯ����"
        skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.15; skill[4].level = 25; skill[4].MP = 20; skill[4].name = "Sand Recovery"; skill[4].num = 5; // �ָ�����"ɳ���ָ�"
        skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Sand Escape"; skill[5].num = 6; // ���ܼ���"ɳ������"
    }
public:
    Donphan(int);
};
Donphan::Donphan(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 9;
    name = "Donphan";
}
class Marshtomp :public ElementPokemon_Terra {	//��Ծ��
protected:
    void Skillmaker() {
        skill[0].ATK = 1.6; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 20; skill[0].name = "Mud Bomb"; skill[0].num = 1; // ��������"���ը��"
        skill[1].ATK = 1.8; skill[1].DEF = 0.6; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Aqua Jet"; skill[1].num = 2; // ��������"ˮ�ڳ��"
        skill[2].ATK = 2.3; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 45; skill[2].name = "Earth Rage"; skill[2].num = 3; // ��������"���֮ŭ"
        skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.08; skill[3].level = 0; skill[3].MP = 25; skill[3].name = "Mud Shield"; skill[3].num = 4; // ��������"�ཬ����"
        skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 15; skill[4].name = "Earth's Blessing"; skill[4].num = 5; // �ָ�����"��رӻ�"
        skill[5].ATK = 0.3; skill[5].DEF = 0.3; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Swamp Escape"; skill[5].num = 6; // ���ܼ���"�������"
    }
public:
    Marshtomp(int);
};
Marshtomp::Marshtomp(int exp) {
    EXP = exp;
    AttributeMaker(EXP);
    AttributeRestorer();
    Skillmaker();
    num = 10;
    name = "Marshtomp";
}
Pokemon* Pokemon::CreatePokemon(int num, int EXP) {
    switch (num) {
    case 1: return new Scizor(EXP);
    case 2: return new Metang(EXP);
    case 3: return new Sceptile(EXP);
    case 4: return new Venusaur(EXP);
    case 5: return new Gyarados(EXP);
    case 6: return new Kingdra(EXP);
    case 7: return new Arcanine(EXP);
    case 8: return new Magmortar(EXP);
    case 9: return new Donphan(EXP);
    case 10: return new Marshtomp(EXP);
    }
}
Pokemon* Pokemon::RandomPokemon(int num) {
    int t, l, exp;
    Pokemon* p;
    l = RandomLevel();
    exp = pow(l, 2);
    switch (num) {
    case 0: {
        t = RandomNumber(10);
        p = Pokemon::CreatePokemon(t, exp); return p;
    }
    case 1: {
        t = RandomNumber(14);
        if (t <= 10) {
            p = Pokemon::CreatePokemon(t, exp); return p;
        }
        else if (t <= 12) {
            p = Pokemon::CreatePokemon(t - 10, exp); return p;
        }
        else {
            p = Pokemon::CreatePokemon(t - 12, exp); return p;
        }
    }
    case 2: {
        t = RandomNumber(14);
        if (t <= 10) {
            p = Pokemon::CreatePokemon(t, exp); return p;
        }
        else if (t <= 12) {
            p = Pokemon::CreatePokemon(t - 8, exp); return p;
        }
        else {
            p = Pokemon::CreatePokemon(t - 10, exp); return p;
        }
    }
    case 3: {
        t = RandomNumber(14);
        if (t <= 10) {
            p = Pokemon::CreatePokemon(t, exp); return p;
        }
        else if (t <= 12) {
            p = Pokemon::CreatePokemon(t - 6, exp); return p;
        }
        else {
            p = Pokemon::CreatePokemon(t - 8, exp); return p;
        }
    }
    case 4: {
        t = RandomNumber(14);
        if (t <= 10) {
            p = Pokemon::CreatePokemon(t, exp); return p;
        }
        else if (t <= 12) {
            p = Pokemon::CreatePokemon(t - 4, exp); return p;
        }
        else {
            p = Pokemon::CreatePokemon(t - 6, exp); return p;
        }
    }
    case 5: {
        t = RandomNumber(14);
        if (t <= 10) {
            p = Pokemon::CreatePokemon(t, exp); return p;
        }
        else if (t <= 12) {
            p = Pokemon::CreatePokemon(t - 2, exp); return p;
        }
        else {
            p = Pokemon::CreatePokemon(t - 4, exp); return p;
        }
    }
    }
}


Account User;
back Userback;
Pokemonteam pokemonteam[6];

int getmenuchoice(int num)
{
    string input;
    int t;
    while (true)
    {
        std::cout << "������ѡ�";
        getline(std::cin, input);
        if (input.length() == 1)
        {
            char c = input[0];
            t = int(c - '0');
            if (t >= 0 && t <= num)
            {
                return t;
            }
        }
        std::cout << "������0-" << num << "֮�������" << std::endl;
    }
}   
int getnumber(int max)
{
    string input;
    while (true)
    {
        std::cout << "��������Ҫ�����������    �����ɹ�������Ϊ" << max << "��" << std::endl;
        getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "���벻��Ϊ�գ�����������" << std::endl;
            continue;
        }
        bool isnumber = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                isnumber = false;
                break;
            }
        }

        if (isnumber)
        {
            int i = stoi(input);
            if (i <= max)return i;
            else std::cout << "������������" << std::endl;
        }
        else
        {
            std::cout << "������������" << std::endl;
        }
    }
}
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(1024, '\n');
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
int RandomNumber(int num) { //���ɴ�1��num���������
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> dist(1, num);
    int random_num = dist(rng);
    return random_num;
}
void readdata()
{
    int i = 0;
    string filename = to_string(User.account) + ".dat";
    ifstream opf(filename, ios::in | ios::binary);

    opf.read(&User.password[0], sizeof(char[30]));

    opf.read(&User.name[0], sizeof(char[30]));

    for (i = 0; i < 10; i++)
    {
        opf.read((char*)&Userback.amounts[i], sizeof(int));
    }
    for (i = 0; i < 6; i++) {
        opf.read((char*)&pokemonteam[i].num, sizeof(int));
    }
}
void savedata()
{
    string filename = to_string(User.account) + ".dat";
    ofstream file_1(filename, ios::out | ios::binary | ios::in);
    ifstream file_2(filename, ios::in | ios::binary);
    file_1.seekp(0, ios::beg);
    file_1.write(&User.password[0], sizeof(char[30]));

    file_1.write(&User.name[0], sizeof(char[30]));

    for (int i : Userback.amounts)
    {
        file_1.write((const char*)&i, sizeof(int));
    }
    file_2.seekg(0, ios::end);
    streamsize size = file_2.tellg();
    if (size <= 110) {
        int teamstart = 0;
        for (int i = 0; i < 6; i++) {
            file_1.write((const char*)&teamstart, sizeof(int));
        }
    }
    file_1.close();
    file_2.close();
}
void place()
{
Place_Start:
    system("cls");
    std::cout << "1. �̵�" << std::endl;
    std::cout << "2. ����" << std::endl;
    std::cout << "3. ɭ��" << std::endl;
    std::cout << "4. ����" << std::endl;
    std::cout << "5. ��ɽ" << std::endl;
    std::cout << "6. ԭʼɽ��" << std::endl;
    std::cout << "0. ��԰" << std::endl;
    int choice = getmenuchoice(6);
    switch (choice)
    {
    case 1:
    {
        system("cls");
        std::cout << "1:������Ʒ" << std::endl;
        std::cout << "0:�뿪�̵�" << std::endl;
        int choice1 = getmenuchoice(1);
        if (choice1 != 1)return;
        else
        {
            while (true)
            {
                system("cls");
                std::cout << "��ӵ�еĽ��������" << Userback.amounts[0] << std::endl;
                std::cout << "��ѡ��Ҫ�������Ʒ" << std::endl;
                std::cout << "1. СѪƿ ��HP�ظ�����200�� �۸�" << Userback.itemlist[1]->getprice() << "���  ������������" << Userback.amounts[1] << "��" << std::endl;
                std::cout << "2. ��Ѫƿ ��HP�ظ�����500�� �۸�" << Userback.itemlist[2]->getprice() << "���  ������������" << Userback.amounts[2] << "��" << std::endl;
                std::cout << "3. ��Ѫƿ ��HP�ظ�����1000�� �۸�" << Userback.itemlist[3]->getprice() << "���  ������������" << Userback.amounts[3] << "��" << std::endl;
                std::cout << "4. С��ƿ ��MP�ظ�����100�� �۸�" << Userback.itemlist[4]->getprice() << "���  ������������" << Userback.amounts[4] << "��" << std::endl;
                std::cout << "5. ����ƿ ��MP�ظ�����200�� �۸�" << Userback.itemlist[5]->getprice() << "���  ������������" << Userback.amounts[5] << "��" << std::endl;
                std::cout << "6. ����ƿ ��MP�ظ�����500�� �۸�" << Userback.itemlist[6]->getprice() << "���  ������������" << Userback.amounts[6] << "��" << std::endl;
                std::cout << "7. ��ͨ��  �۸�" << Userback.itemlist[7]->getprice() << "���  ������������" << Userback.amounts[7] << "��" << std::endl;
                std::cout << "8. �߼���  �۸�" << Userback.itemlist[8]->getprice() << "���  ������������" << Userback.amounts[8] << "��" << std::endl;
                std::cout << "9. ��ʦ��  �۸�" << Userback.itemlist[9]->getprice() << "���  ������������" << Userback.amounts[9] << "��" << std::endl;
                std::cout << "0. �˳��̵�" << std::endl;
                int choice11 = getmenuchoice(9);
                if (choice11 != 0)
                {
                    int max = 9999 - Userback.amounts[choice11];
                    int number = getnumber(max);
                    if (Userback.amounts[0] < number * Userback.itemlist[choice11]->getprice())
                    {
                        std::cout << "��Ҳ��㣬�޷�����" << std::endl;
                        system("pause");
                        continue;
                    }
                    else
                    {
                        Userback.amounts[0] -= number * Userback.itemlist[choice11]->getprice();
                        Userback.amounts[choice11] += number;
                        std::cout << "����ɹ�" << std::endl;
                        savedata();
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
        system("cls");
        int choice;
        std::cout << "�������� ���� " << std::endl;
        std::cout << "�������У������� Scizor����ǯ��룩��Metang���Ͻ�ʮ�֣����ֵĸ�������" << endl;
        std::cout << "1. Ѱ�ұ�����" << std::endl;
        std::cout << "0. �򿪵�ͼ" << std::endl;
        choice = getmenuchoice(1);
        if (choice) { PokemonSearch(1); }
        goto Place_Start;
    }
    break;
    case 3:
    {
        system("cls");
        int choice;
        std::cout << "�������� ɭ�� " << std::endl;
        std::cout << "�������У������� Sceptile������������Venusaur�����ܻ������ֵĸ�������" << endl;
        std::cout << "1. Ѱ�ұ�����" << std::endl;
        std::cout << "0. �򿪵�ͼ" << std::endl;
        choice = getmenuchoice(1);
        if (choice) { PokemonSearch(2); }
        goto Place_Start;
    }
    break;
    case 4:
    {
        system("cls");
        int choice;
        std::cout << "�������� ���� " << std::endl;
        std::cout << "�������У������� Gyarados������������Kingdra�������������ֵĸ�������" << endl;
        std::cout << "1. Ѱ�ұ�����" << std::endl;
        std::cout << "0. �򿪵�ͼ" << std::endl;
        choice = getmenuchoice(1);
        if (choice) { PokemonSearch(3); }
        goto Place_Start;
    }
    break;
    case 5:
    {
        system("cls");
        int choice;
        std::cout << "�������� ��ɽ " << std::endl;
        std::cout << "�������У������� Arcanine�����ٹ�����Magmortar��Ѽ�����ޣ����ֵĸ�������" << endl;
        std::cout << "1. Ѱ�ұ�����" << std::endl;
        std::cout << "0. �򿪵�ͼ" << std::endl;
        choice = getmenuchoice(1);
        if (choice) { PokemonSearch(4); }
        goto Place_Start;
    }
    break;
    case 6:
    {
        system("cls");
        int choice;
        std::cout << "�������� ԭʼɽ�� " << std::endl;
        std::cout << "�������У������� Donphan���ټף���Marshtomp����Ծ�㣩���ֵĸ�������" << endl;
        std::cout << "1. Ѱ�ұ�����" << std::endl;
        std::cout << "0. �򿪵�ͼ" << std::endl;
        choice = getmenuchoice(1);
        if (choice) { PokemonSearch(5); }
        goto Place_Start;
    }
    break;
    case 0:return;

    default:std::cout << "�����������������룺" << std::endl;
        system("pause");
        system("cls");
        break;
    }
}
void game_begin()
{
    while (true)
    {
        string filename = to_string(User.account) + ".dat";
        fstream opf(filename, ios::in | ios::out | ios::binary);
        int choice1;
        system("cls");
        std::cout << "��Ŀǰ�� ��԰ �����������鿴�����Σ������ս�ı�������ϣ���ǰ��������ͼ��" << std::endl;
        std::cout << "1. �򿪱���" << std::endl;
        std::cout << "2. �鿴������" << std::endl;
        std::cout << "3. �鿴�����ζ���" << std::endl;
        std::cout << "4. �򿪵�ͼ" << std::endl;
        std::cout << "0. �˳���¼" << std::endl;
        choice1 = getmenuchoice(4);
        switch (choice1)
        {
        case 1: {
            system("cls");
            Userback.showback();
            system("pause");
        }
            break;
        case 2:
        {
            system("cls");
            int a, b, c, num;
            opf.seekg(0, ios::end);
            streamsize size = opf.tellg();
            num = ((size - 124) / 12);
            std::cout << "��ӵ�еı���������Ϊ��" << num << std::endl;
            if (num) {
                opf.seekg(124, ios::beg);
                for (int i = 0; i < num; i++)
                {
                    Pokemon* temp;
                    opf.read((char*)&a, sizeof(int));
                    opf.read((char*)&b, sizeof(int));
                    opf.read((char*)&c, sizeof(int));
                    std::cout << "#" << a << std::endl;
                    temp = Pokemon::CreatePokemon(b, c);
                    temp->InfoDisplayer();
                    delete temp;
                }
            }
            else { std::cout << "���Ѳ�׽�ı�����" << std::endl; }
            std::cout << "�밴����������ϼ�����" << std::endl;
            system("pause");
        }
        break;
        case 3:PokemonteamSelector();
            break;
        case 4:place();
            break;
        case 0:
        {
            savedata();
            return;
        }
        default:std::cout << "�����������������룺" << std::endl;
            system("pause");
            system("cls");
            break;
        }

    }
}
void login()
{
    int tempaccount;
    string tempfilename, temppassword, x;
    ifstream opf;
Login_Begin:
    system("cls");
    std::cout << "1:�����˺�" << std::endl;
    std::cout << "0:�������˵�" << std::endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }
shuru1:  
    system("cls");
    std::cout << "�������˺ţ�" << std::endl;
    std::cin >> x;
    if (x.length() != 7 || !all_of(x.begin(), x.end(), ::isdigit))
    {
        std::cout << "�˺ű���Ϊ7λ���֣�" << std::endl;
        system("pause");
        goto shuru1;
    }
    else User.account = stoi(x);
    clearInputBuffer();
    tempfilename = to_string(User.account) + ".dat";
    opf.open(tempfilename, ios::in | ios::binary);
    bool islog = opf.is_open();
    opf.close();
    if (!islog)
    {
        std::cout << "���˺�δע�ᣡ" << std::endl;
        system("pause");
        system("cls"); goto Login_Begin;
    }

    readdata();

shurumima:
    system("cls");
    std::cout << "���������룺" << std::endl;
    std::cin >> temppassword;
    clearInputBuffer();
    char temp_password[30];
    strcpy_s(temp_password, 29, &encryption(temppassword)[0]);
    temp_password[29] = '\0';

    if (strcmp(User.password, temp_password) == 0) {
        std::cout << "��¼�ɹ�,��ӭ���汾��Ϸ��" << std::endl;
        system("pause");
    }
    else
    {
        std::cout << "�������" << std::endl;
        std::cout << "1. ������������" << std::endl;
        std::cout << "0. ���ص�¼ѡ��" << std::endl;
        loginChoice = getmenuchoice(1);
        if (loginChoice == 1) { goto shurumima; }
        else { goto Login_Begin; }
    }
    game_begin();
}
void registeraccount()
{
    fstream opf;
    string temp_password, temp_name, x;
Register_Begin:
    system("cls");
    std::cout << "1:ע���˺�" << std::endl;
    std::cout << "0:�������˵�" << std::endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }
shuru: 
    system("cls");
    std::cout << "�������˺�(�������֣�����7λ):" << std::endl;
    std::cin >> x;
    clearInputBuffer();
    if (x.length() != 7 || !all_of(x.begin(), x.end(), ::isdigit))
    {
        std::cout << "�˺ű���Ϊ7λ���֣�" << std::endl;
        goto shuru;
    }
    else User.account = stoi(x);
    string temp_account = to_string(User.account) + ".dat";
    opf.open(temp_account, ios::in | ios::binary);
    bool isopen = opf.is_open();
    opf.close();
    if (isopen)
    {
        std::cout << "���˺��ѱ�ע��" << std::endl;
        std::cout << "1. �ٴ������˺�" << std::endl;
        std::cout << "0. ����ע��ѡ�����" << std::endl;
        loginChoice = getmenuchoice(1);
        if (loginChoice) { goto shuru; }
        else { goto Register_Begin; }
    }
shurumima:
    system("cls");
    std::cout << "���������룺" << std::endl;
    std::cin >> temp_password;
    clearInputBuffer();
    if (temp_password.length() > 29)
    {
        std::cout << "���볤�ȳ���29�����������룺" << std::endl;
        goto shurumima;
    }
    strcpy_s(User.password, 29, &encryption(temp_password)[0]);
    User.password[29] = '\0';
shurunicheng:
    system("cls");
    std::cout << "�������ǳƣ�" << std::endl;
    std::cin >> temp_name;
    clearInputBuffer();
    if (temp_name.length() > 29)
    {
        std::cout << "�ǳƳ��ȳ���29�����������룺" << std::endl;
        goto shurunicheng;
    }
    strcpy_s(User.name, 29, &temp_name[0]);
    User.name[29] = '\0';
    opf.open(temp_account, ios::out | ios::binary);
    opf.close();
    savedata();
    std::cout << "ע��ɹ�����ӭʹ�ã���ʹ�õ�¼ѡ����е�¼" << std::endl;
    system("pause");
}
void changepassword()
{
    size_t len = 0;
    ifstream test;
    ofstream opf;
    back backs;
    string oldpassword, newpassword, filename;
shuru2:
    system("cls");
    std::cout << "1:�޸�����" << std::endl;
    std::cout << "0:�������˵�" << std::endl;
    int loginChoice = getmenuchoice(1);
    if (loginChoice == 0)
    {
        return;
    }
    system("cls");
    std::cout << "�������˺�" << std::endl;
    std::cin >> User.account;
    clearInputBuffer();
    filename = to_string(User.account) + ".dat";
    test.open(filename, ios::in | ios::binary);
    bool isopen = test.is_open();
    test.close();
    if (!isopen)
    {
        std::cout << "���˺Ų�����,����������" << std::endl;
        system("pause");
        goto shuru2;
    }
    readdata();

shuruyuanmima:
    system("cls");
    std::cout << "������ԭ����:" << std::endl;
    std::cin >> oldpassword;
    clearInputBuffer();
    char old_password[30];
    strcpy_s(old_password, 29, &encryption(oldpassword)[0]);
    old_password[29] = '\0';

shuruxinmima:
    system("cls");
    std::cout << "������������:" << std::endl;
    std::cin >> newpassword;
    clearInputBuffer();
    if (newpassword.length() > 29)
    {
        std::cout << "�����볤�ȳ���29�����������룺" << std::endl;
        system("pause");
        goto shuruxinmima;
    }
    char new_password[30];
    strcpy_s(new_password, 29, &encryption(newpassword)[0]);
    new_password[29] = '\0';

    if (strcmp(old_password, User.password) == 0)
    {
        strcpy_s(User.password, 30, &encryption(newpassword)[0]);
        savedata();
        std::cout << "�����޸ĳɹ�" << std::endl;
        system("pause");
    }
    else
    {
        std::cout << "ԭʼ�����������,���������룺" << std::endl;
        system("pause");
        goto shuruyuanmima;
    }
}
void exitgame()
{
    system("cls");
    std::cout << "��ӭ�´�ʹ�ã�" << std::endl;
    system("pause");
    exit(0);
}
double ElementRestraint(Pokemon* Mine, Pokemon* Enemy) {
    int a, b;
    a = Mine->elementgetter(); b = Enemy->elementgetter();
    if ((a - b) == 1) { return 0.75; }
    else if ((a - b) == 0) { return 1; }
    else if ((a - b) == -1) { return 1.25; }
    else if ((a - b) == 4) { return 1.25; }
    else if ((a - b) == -4) { return 0.75; }
    else { return 1; }
}
bool Win_During(Pokemon* Mine, Pokemon* Enemy) { // ս����ʤ���ж�
    if (Mine->HPgetter() && Enemy->HPgetter()) {
        return false;
    }
    else {
        return true;
    }
}
bool Fight_Escape() {	//�����ж�
    int num = 70;
    int Ran = RandomNumber(100);
    if (Ran <= num) { return true; }
    else { return false; }
}
void Escape_Fail(Pokemon* Mine, Pokemon* Enemy, Skill skill_enemy) {	//����ʧ��
    int damage;
    double DEFrate;
    DEFrate = Mine->DEFgetter() / (45 + Mine->DEFgetter());
    damage = Enemy->ATKgetter() * skill_enemy.ATK * (1 - DEFrate);
    Mine->DAGmaker(damage);
    std::cout << "���˶��������" << damage << "���˺�" << std::endl;
    system("pause");
    return;
}
bool SkillCertify(Pokemon* Mine, Skill skill_mine) {	//���ܿ����Լ춨
    if (Mine->levelgetter() < skill_mine.level) {
        std::cout << "�ȼ����㣬������ѡ��" << std::endl; return false;
    }
    else if (Mine->MPgetter() >= skill_mine.MP)return true; else {
        std::cout << "�������㣬������ѡ��" << std::endl; return false;
    }
}
int ATKselect(Pokemon* Mine, Skill& skill_mine) {	//��������ѡ��
    int selection;
    system("cls");
    Mine->InfoDisplayer_Liter();
    std::cout << "1. �������� 1��" << std::endl;
    Mine->SkillDisplayer_Lite(1);
    std::cout << "2. �������� 2��" << std::endl;
    Mine->SkillDisplayer_Lite(2);
    std::cout << "3. �������� 3��" << std::endl;
    Mine->SkillDisplayer_Lite(3);
    std::cout << "0. ����" << std::endl;
ATKselect_Start:
    selection = getmenuchoice(3);
    switch (selection)
    {
    case 1: { if (SkillCertify(Mine, Mine->SkillSelector(1))) { skill_mine = Mine->SkillSelector(1); return 1; } else goto ATKselect_Start; }
    case 2: { if (SkillCertify(Mine, Mine->SkillSelector(2))) { skill_mine = Mine->SkillSelector(2); return 1; } else goto ATKselect_Start; }
    case 3: { if (SkillCertify(Mine, Mine->SkillSelector(3))) { skill_mine = Mine->SkillSelector(3); return 1; } else goto ATKselect_Start; }
    case 0:   return 0;
    default:goto ATKselect_Start;
    }
}
int DEFselect(Pokemon* Mine, Skill& skill_mine) {	//��������ѡ��
    int selection;
    system("cls");
    Mine->InfoDisplayer_Liter();
    std::cout << "1. �������� 1��" << std::endl;
    Mine->SkillDisplayer_Lite(4);
    std::cout << "2. �������� 2��" << std::endl;
    Mine->SkillDisplayer_Lite(5);
    std::cout << "0. ����" << std::endl;
DEFselect_Start:
    selection = getmenuchoice(2);
    switch (selection)
    {
    case 1: { if (SkillCertify(Mine, Mine->SkillSelector(4))) { skill_mine = Mine->SkillSelector(4); return 1; } else goto DEFselect_Start; }
    case 2: { if (SkillCertify(Mine, Mine->SkillSelector(5))) { skill_mine = Mine->SkillSelector(5); return 1; } else goto DEFselect_Start; }
    case 0:   return 0;
    default:goto DEFselect_Start;
        break;
    }
}
int DODselect(Pokemon* Mine, Skill& skill_mine) {	//���ܼ���ѡ��
    int selection;
    system("cls");
    Mine->InfoDisplayer_Liter();
    std::cout << "1. ���ܼ��� 1��" << std::endl;
    Mine->SkillDisplayer_Lite(6);
    std::cout << "0. ����" << std::endl;
DODselect_Start:
    selection = getmenuchoice(1);
    switch (selection)
    {
    case 1: { if (SkillCertify(Mine, Mine->SkillSelector(6))) { skill_mine = Mine->SkillSelector(6); return 1; } else goto DODselect_Start; }
    case 0:   return 0;
    default:goto DODselect_Start;
    }
}
bool DODCertify(Pokemon* Mine, Skill skill_mine) {
    int num;
    num = Mine->DODgetter() * 100 + skill_mine.DOD * 100;
    if (num >= RandomNumber(100))return true;
    else return false;
}
void HPadder_Skill(Pokemon* Mine, Skill skill_mine) {
    Mine->HPadder(skill_mine.HP * Mine->HPmaxgetter());
    std::cout << "�ָ���" << skill_mine.HP * Mine->HPmaxgetter() << "��Ѫ��" << std::endl;
}
void Fight_Action(Pokemon* Mine, Pokemon* Enemy, Skill skill_mine, Skill skill_enemy)
{
    int damage;
    double DEFrate;
    system("cls");
    std::cout << Mine->Namegetter() << "���㣩ʹ���˼��ܣ�" << skill_mine.name << std::endl;
    std::cout << Enemy->Namegetter() << "�����ˣ�ʹ���˼��ܣ�" << skill_enemy.name << std::endl;
    Mine->MPadder(-(skill_mine.MP));
    std::cout << std::endl;
    if (DODCertify(Enemy, skill_enemy)) { std::cout << "�������ܳɹ�" << std::endl; }
    else {
        DEFrate = Enemy->DEFgetter() * skill_enemy.DEF / (45 + Enemy->DEFgetter() * skill_enemy.DEF);	//�˺�������=������ֵ/������+������ֵ��
        damage = Mine->ATKgetter() * skill_mine.ATK * (1 - DEFrate) * ElementRestraint(Mine, Enemy); //�˺�=�����λ���������*���ܹ���������*��1-�˺������ʣ�*Ԫ�ؿ��Ʊ���
        Enemy->DAGmaker(damage);
        std::cout << "��Ե��������" << damage << "���˺�" << std::endl;
    }
    std::cout << "��"; HPadder_Skill(Mine, skill_mine);
    if (!Enemy->HPgetter()) { std::cout << "��������ֵ�ľ�" << std::endl; system("pause"); return; }


    if (!Enemy->HPgetter()) {
        std::cout << "��������ֵ�ľ�" << std::endl;
        system("pause");
        return;
    }
    std::cout << std::endl;
    if (DODCertify(Mine, skill_mine)) { std::cout << "�����ܳɹ�" << std::endl; }
    else {
        DEFrate = Mine->DEFgetter() * skill_mine.DEF / (45 + Mine->DEFgetter() * skill_mine.DEF);
        damage = Enemy->ATKgetter() * skill_enemy.ATK * (1 - DEFrate) * ElementRestraint(Enemy, Mine);
        Mine->DAGmaker(damage);
        std::cout << "���˶��������" << damage << "���˺�" << std::endl;
    }
    std::cout << "����"; HPadder_Skill(Enemy, skill_enemy);
    system("pause");
}
int Fight_During(Pokemon* Mine, Pokemon* Enemy) {
    clearInputBuffer();
    int selection = 0, t = 0;
    Skill skill_mine = Skill(), skill_enemy = Skill();
FightDuring_Start:
    system("cls");
    if (Win_During(Mine, Enemy)) { return 1; } 
    skill_enemy = RandomSkill(Enemy);
    std::cout << "�ҷ������Σ�" << std::endl;
    Mine->InfoDisplayer_Liter();
    std::cout << "�з������Σ�" << std::endl;
    Enemy->InfoDisplayer_Liter_Enemy();
    std::cout << "����ѡ��" << std::endl;
    std::cout << "1. ��������" << std::endl;
    std::cout << "2. ��������" << std::endl;
    std::cout << "3. ���ܼ���" << std::endl;
    std::cout << "4. ҩƷ" << std::endl;
    std::cout << "5. ������" << std::endl;
    std::cout << "6. ����" << std::endl;
    selection = getmenuchoice(6);
    switch (selection)
    {
    case 1: {
        if (ATKselect(Mine, skill_mine)) { Fight_Action(Mine, Enemy, skill_mine, skill_enemy); system("cls"); }
        goto FightDuring_Start;
    } break;
    case 2: {
        if (DEFselect(Mine, skill_mine)) { Fight_Action(Mine, Enemy, skill_mine, skill_enemy); system("cls"); }
        goto FightDuring_Start;
    } break;
    case 3: {
        if (DODselect(Mine, skill_mine)) { Fight_Action(Mine, Enemy, skill_mine, skill_enemy); system("cls"); }
        goto FightDuring_Start;
    } break;
    case 4: {
        RestoreItemUsing(Mine); goto FightDuring_Start;
    }
        break;
    case 5: {
        t = PokemonCapture(Enemy);
        switch (t) {
        case 0: {
            goto FightDuring_Start;
        }
        case 1: {
            return -1;
        }
        case -1: {
            Escape_Fail(Mine, Enemy, skill_enemy);
            goto FightDuring_Start;
        }
        }
    }
        ; break;
    case 6: { if (Fight_Escape())return 0; else { std::cout << "����ʧ��" << std::endl; Escape_Fail(Mine, Enemy, skill_enemy); goto FightDuring_Start; } };
    default: goto FightDuring_Start;
    }
    return 1;
}
void Fight_Start(Pokemon* Enemy) {
    system("cls");
    std::cout << "��ѡ��Ҫ��ս�ı����Σ��������Ӧ�Ķ�����λ�ţ�" << std::endl;
    Pokemon* temp;
    int i = 0, choice = 0, t = 0, w = 0;
    bool exam;
    for (i = 0; i < 6; i++) {
        if (pokemonteam[i].num) {
            t++;
        }
    }
    if (!t) {
        std::cout << "�޿ɳ�ս�ı����Σ��������뿪" << std::endl;
        system("pause");
        return;
    }
    for (i = 0; i < 6; i++) {
        if (pokemonteam[i].num) {
            std::cout << "������λ�ţ�" << i + 1 << std::endl;
            temp = Pokemon::CreatePokemon(pokemonteam[i].type, pokemonteam[i].EXP);
            temp->InfoDisplayer();
            delete temp;
        }
    }
    std::cout << "����0��ѡ������" << std::endl;
Start_Choice:
    choice = getmenuchoice(6);
    if (choice) {
        if (!pokemonteam[choice - 1].num) {
            std::cout << "����λΪ�գ�������ѡ��" << std::endl;
            goto Start_Choice;
        }
    }
    else {
        return;
    }
    Pokemon* Mine = Pokemon::CreatePokemon(pokemonteam[choice - 1].type, pokemonteam[choice - 1].EXP);
    std::cout << "��ѡ���ս�ı����Σ�ս��������ʼ" << std::endl;
    system("pause");
    w = Fight_During(Mine, Enemy);
    switch (w) {
    case 0: {
        std::cout << "��ɹ����ܣ�������Ҳ�뿪��" << std::endl;
        system("pause");
        delete Mine;
        return;
    }
    case 1: {
        if (!Enemy->HPgetter()) {
            std::cout << "��ϲ������ʤ����" << std::endl;
            int level_1, level_2;
            level_1 = Mine->levelgetter();
            Mine->EXPadder(Enemy->levelgetter());
            pokemonteam[choice - 1].EXP = Mine->EXPgetter();
            PokemonSave(Mine, pokemonteam[choice - 1].num);
            level_2 = int(pow(Mine->EXPgetter(), 0.5));
            if (level_2 > level_1) {
                std::cout << "��ϲ��ı����εȼ�����������������������Ϣ��" << std::endl;
                temp = Pokemon::CreatePokemon(pokemonteam[choice - 1].type, pokemonteam[choice - 1].EXP);
                temp->InfoDisplayer();
                delete temp;
                system("pause");
            }
            Userback.amounts[0] += 10 * Enemy->levelgetter();
            std::cout << "������" << 10 * Enemy->levelgetter() << "ö��ң���������" << Userback.amounts[0] << "ö���" << std::endl;
            system("pause");
            delete Mine;
            return;
        }
        else {
            std::cout << "���ڶ�ս������ˣ������Ѿ��뿪" << std::endl;
            system("pause");
            delete Mine;
            return;
        }
    }
    case -1: {
        std::cout << "��ɹ���׽�˶Է���������ս��" << std::endl;
        system("pause");
        delete Mine;
        return;
    }
    }
}
void NewPokemonSave(Pokemon* Enemy) {
    int a = 0, b = 0, c = 0, num = 0;
    b = Enemy->GetPokemonType();
    c = Enemy->EXPgetter();
    cout << b << " " << c << endl;
    string filename = to_string(User.account) + ".dat";
    fstream opf(filename, ios::in | ios::out | ios::binary);
    opf.seekg(0, ios::end);
    streamsize size = opf.tellg();
    num = ((size - 124) / 12);
    if (num) {
        opf.seekg(-12, ios::end);
        opf.read((char*)&a, sizeof(int));
        a++;
        opf.seekp(0, ios::end);
        opf.write((char*)&a, sizeof(int));
        opf.write((char*)&b, sizeof(int));
        opf.write((char*)&c, sizeof(int));
        opf.close();
    }
    else {
        a = 1;
        opf.seekp(0, ios::end);
        opf.write((char*)&a, sizeof(int));
        opf.write((char*)&b, sizeof(int));
        opf.write((char*)&c, sizeof(int));
        opf.close();
    }
    
}
void PokemonSave(Pokemon* Mine,int t) {
    int a = t, b = 0, c = 0, num = 0;
    b = Mine->GetPokemonType();
    c = Mine->EXPgetter();
    num = 124 + 12 * (a - 1) + sizeof(int);
    string filename = to_string(User.account) + ".dat";
    fstream opf(filename, ios::in | ios::out | ios::binary);
    opf.seekp(num, ios::beg);
    opf.write((char*)&b, sizeof(int));
    opf.write((char*)&c, sizeof(int));
    opf.close();
}
void PokemonteamSelector() {
    Pokemon* temp;
    string filename = to_string(User.account) + ".dat";
    fstream opf(filename, ios::in | ios::out | ios::binary);
    int i = 0, choice = 0, t = 0;
    bool exam;
    opf.seekg(100, ios::beg);
    for (i = 0; i < 6; i++) {
        opf.seekg(100+sizeof(int)*i, ios::beg);
        opf.read((char*)&pokemonteam[i].num, sizeof(int));
    }
    for (i = 0; i < 6; i++) {
        if (pokemonteam[i].num) {
            opf.seekg(124 + 12 * (pokemonteam[i].num - 1)+sizeof(int), ios::beg);
            opf.read((char*)&pokemonteam[i].type, sizeof(int));
            opf.read((char*)&pokemonteam[i].EXP, sizeof(int));
        }
    }
PokemonteamSelector_Start:
    system("cls");
    std::cout << "������ڴ�ѡ���ս�ı����Σ�ÿֻ��ӵ�еı����ζ�ӵ�и����ڱ���׽ʱ������ı�ţ�����ѡ��ս�ı�����ʱ���������Ž���ѡ��" << std::endl;
    std::cout << "1. �鿴�ѳ�ս�ı�����" << std::endl;
    std::cout << "2. ����ѡ���ս�ı�����" << std::endl;
    std::cout << "0. ����" << endl;
    choice = getmenuchoice(2);
    switch (choice) {
    case 0: { 
        opf.close();
        return;
    }
    case 1: {
        system("cls");
        std::cout << "���������ѳ�ս�ı����Σ�" << std::endl;
        for (i = 0; i < 6; i++) {
            if (pokemonteam[i].num) {
                std::cout << "#" << pokemonteam[i].num << std::endl;
                temp = Pokemon::CreatePokemon(pokemonteam[i].type, pokemonteam[i].EXP);
                temp->InfoDisplayer();
                delete temp;
            }
        }
        system("pause");
        goto PokemonteamSelector_Start;
    }
    case 2: {
        system("cls");
        std::cout << "��������ӵ�е����б����Σ�" << std::endl;
        int a, b, c, num;
        opf.seekg(0, ios::end);
        streamsize size = opf.tellg();
        num = ((size - 124) / 12);
        std::cout << "��ӵ�еı���������Ϊ��" << num << std::endl;
        if (num) {
            opf.seekg(124, ios::beg);
            for (i = 0; i < num; i++)
            {
                opf.read((char*)&a, sizeof(int));
                opf.read((char*)&b, sizeof(int));
                opf.read((char*)&c, sizeof(int));
                std::cout << "#" << a << std::endl;
                temp = Pokemon::CreatePokemon(b, c);
                temp->InfoDisplayer();
                delete temp;
            }
        }
        else {
            std::cout << "���Ѳ�׽�ı�����" << std::endl;
            system("pause");
            goto  PokemonteamSelector_Start;
        }
        std::cout << "������Ҫ��ս�ı����α�ţ�" << std::endl;
        std::cout << "������0��ʾ�ñ����γ�ս��λ��ȱ���籦�����������������ͨ������0�������ó�ս��λ��" << std::endl;
        for (i = 0; i < 6; i++) {
            pokemonteam[i].num = 0;
        }
        for (i = 0; i < 6; i++) {
            t = getmenuchoice(num);
            exam = false;
            for (int k = 0; k < 6; k++) {
                if (t) {
                    if (t == pokemonteam[k].num) { exam = true; }
                }
            }
            if (exam) {
                std::cout << "�����ظ�ѡ��ͬһ��ű����Σ�������ѡ��ó�ս��λ�ı�����" << std::endl;
                i--;
            }
            else {
                pokemonteam[i].num = t;
            }
        }
        std::cout << "ѡ�������" << std::endl;
        for (i = 0; i < 6; i++) {
            if (pokemonteam[i].num) {
                opf.seekg(124 + 12 * (pokemonteam[i].num - 1) + sizeof(int), ios::beg);
                opf.read((char*)&pokemonteam[i].type, sizeof(int));
                opf.read((char*)&pokemonteam[i].EXP, sizeof(int));
            }
        }
        for (i = 0; i < 6; i++) {
            opf.seekp(100 + i * sizeof(int), ios::beg);
            opf.write((char*)&pokemonteam[i].num, sizeof(int));
        }
        goto PokemonteamSelector_Start;
    }
    }
}
void PokemonSearch(int place) {
    Pokemon* temp;
    int choice;
Search_Start:
    temp = Pokemon::RandomPokemon(place);
Search_During:
    system("cls");
    std::cout << "�㷢���ˣ�" << std::endl;
    temp->InfoDisplayer_Enemy();
    std::cout << "��ѡ����Ҫ���е��ж���" << std::endl;
    std::cout << "1. ��ս" << std::endl;
    std::cout << "2. ��׽" << std::endl;
    std::cout << "3. Ѱ����һֻ������" << std::endl;
    std::cout << "0. ����" << std::endl;
    choice = getmenuchoice(3);
    switch (choice) {
    case 0:return;
    case 1: {
        Fight_Start(temp);
        delete temp;
        goto Search_Start;
    }
          break;
    case 2: {
        int t = 0;
        t = PokemonCapture(temp);
        switch (t) {
        case 1: {
            std::cout << "��ѡ����һ���ж���" << std::endl;
            std::cout << "1. �ٴ���Ѱ" << std::endl;
            std::cout << "0. ����" << std::endl;
            choice = getmenuchoice(1);
            if (choice) {
                delete temp;
                goto Search_Start;
            }
            else {
                delete temp;
                return;
            }
        }
        case 0: {
            goto Search_During;
        }
        case -1: {
            std::cout << "������ʼս��" << std::endl;
            system("pause");
            Fight_Start(temp);
            delete temp;
            goto Search_Start;
        }
        }
    }
          break;
    case 3: { delete temp; goto Search_Start; }
    }
}
bool ItemAmountCertify(int i) {
    if (Userback.amounts[i] > 0) {
        return true;
    }
    else {
        return false;
    }
}
int PokemonCapture(Pokemon* Enemy) {
Capture_Start:
    system("cls");
    int choice = 0;
    Enemy->InfoDisplayer_Liter_Enemy();
    std::cout << "��ѡ���ж���" << std::endl;
    std::cout << "1. ʹ����ͨ��" << "��ӵ��������" << Userback.amounts[7] << "��" << std::endl;
    std::cout << "2. ʹ�ø߼���" << "��ӵ��������" << Userback.amounts[8] << "��" << std::endl;
    std::cout << "3. ʹ�ô�ʦ��" << "��ӵ��������" << Userback.amounts[9] << "��" << std::endl;
    std::cout << "0. ȡ����׽" << std::endl;
    choice = getmenuchoice(3);
    if (choice) {
        if (Fight_Capture(6+choice, Enemy)) {
            std::cout << "������" << Enemy->Namegetter() << "��׽�ɹ�" << std::endl;
            NewPokemonSave(Enemy);
            Userback.amounts[6 + choice]--;
            savedata();
            return 1;
        }
        else {
            std::cout << "������" << Enemy->Namegetter() << "��׽ʧ��" << std::endl;
            Userback.amounts[6 + choice]--;
            savedata();
            return -1;
        }
    }
    else {
        return 0;
    }
}
bool Fight_Capture(int i, Pokemon* Enemy) {
    int num, cap;
    int HPcap;
    HPcap = int(double(double(Enemy->HPgetter()) / double(Enemy->HPmaxgetter())) * 30);
    cap = Userback.itemlist[i]->geteffect() + HPcap;
    num = RandomNumber(100);
    if (cap >= num) {
        return true;
    }
    else {
        return false;
    }
}
void RestoreItemUsing(Pokemon* Mine) {
    system("cls");
    int choice, effect;
    std::cout << "��ѡ��Ҫʹ�õ���Ʒ" << std::endl;
    std::cout << "1. СѪƿ ��HP�ظ�����200����ʣ��������" << Userback.amounts[1] << "��" << std::endl;
    std::cout << "2. ��Ѫƿ ��HP�ظ�����500����ʣ��������" << Userback.amounts[2] << "��" << std::endl;
    std::cout << "3. ��Ѫƿ ��HP�ظ�����1000����ʣ��������" << Userback.amounts[3] << "��" << std::endl;
    std::cout << "4. С��ƿ ��MP�ظ�����100����ʣ��������" << Userback.amounts[4] << "��" << std::endl;
    std::cout << "5. ����ƿ ��MP�ظ�����200����ʣ��������" << Userback.amounts[5] << "��" << std::endl;
    std::cout << "6. ����ƿ ��MP�ظ�����500����ʣ��������" << Userback.amounts[6] << "��" << std::endl;
    std::cout << "0. ����" << std::endl;
    choice = getmenuchoice(6);
    effect = Userback.itemlist[choice]->geteffect();
    if (choice) {
        if (choice <= 3) {
            Mine->HPadder(effect); return;
        }
        else {
            Mine->MPadder(effect); return;
        }
    }
    return;
}
Skill RandomSkill(Pokemon* Enemy) {
    int i, t;
    bool w;
    double HPrate;
    HPrate = double(Enemy->HPgetter()) / double(Enemy->HPmaxgetter());
    if (HPrate >= 0.7) {
HPrate_1:
        i = RandomNumber(100);
        Enemy->MPadder(100);
        if (i < 25) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(1));
            if (w)return Enemy->SkillSelector(1);
            else goto HPrate_1;
        }
        else if (i < 50) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(2));
            if (w)return Enemy->SkillSelector(2);
            else goto HPrate_1;
        }
        else if (i < 75) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(3));
            if (w)return Enemy->SkillSelector(3);
            else goto HPrate_1;
        }
        else if (i < 85) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(4));
            if (w)return Enemy->SkillSelector(4);
            else goto HPrate_1;
        }
        else if (i < 25) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(5));
            if (w)return Enemy->SkillSelector(5);
            else goto HPrate_1;
        }
        else {
            w = SkillCertify(Enemy, Enemy->SkillSelector(6));
            if (w)return Enemy->SkillSelector(6);
            else goto HPrate_1;
        }
    }
    else if (HPrate >= 0.3) {
HPrate_2:
        i = RandomNumber(100);
        Enemy->MPadder(100);
        if (i < 18) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(1));
            if (w)return Enemy->SkillSelector(1);
            else goto HPrate_2;
        }
        else if (i < 36) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(2));
            if (w)return Enemy->SkillSelector(2);
            else goto HPrate_2;
        }
        else if (i < 54) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(3));
            if (w)return Enemy->SkillSelector(3);
            else goto HPrate_2;
        }
        else if (i < 72) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(4));
            if (w)return Enemy->SkillSelector(4);
            else goto HPrate_2;
        }
        else if (i < 90) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(5));
            if (w)return Enemy->SkillSelector(5);
            else goto HPrate_2;
        }
        else {
            w = SkillCertify(Enemy, Enemy->SkillSelector(6));
            if (w)return Enemy->SkillSelector(6);
            else goto HPrate_2;
        }
    }
    else {
HPrate_3:
        i = RandomNumber(100);
        Enemy->MPadder(100);
        if (i < 10) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(1));
            if (w)return Enemy->SkillSelector(1);
            else goto HPrate_3;
        }
        else if (i < 20) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(2));
            if (w)return Enemy->SkillSelector(2);
            else goto HPrate_3;
        }
        else if (i < 30) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(3));
            if (w)return Enemy->SkillSelector(3);
            else goto HPrate_3;
        }
        else if (i < 55) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(4));
            if (w)return Enemy->SkillSelector(4);
            else goto HPrate_3;
        }
        else if (i < 80) {
            w = SkillCertify(Enemy, Enemy->SkillSelector(5));
            if (w)return Enemy->SkillSelector(5);
            else goto HPrate_3;
        }
        else {
            w = SkillCertify(Enemy, Enemy->SkillSelector(6));
            if (w)return Enemy->SkillSelector(6);
            else goto HPrate_3;
        }
    }
}

int main() {
    int choice = 0;
    while (true) {
        system("cls");
        std::cout << "��ӭ���汾��Ϸ" << std::endl;
        std::cout << "1. ��¼" << std::endl;
        std::cout << "2. ע��" << std::endl;
        std::cout << "3. �޸�����" << std::endl;
        std::cout << "0. �˳���Ϸ" << std::endl;
        choice = getmenuchoice(3);
        switch (choice) {
        case 1:login(); break;
        case 2:registeraccount(); break;
        case 3:changepassword(); break;
        case 0:exitgame(); break;
        default:; break;
        }
    }
}

