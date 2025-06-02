#ifndef POKEMONCLASS_H
#define POKEMONCLASS_H

#include <string>
using namespace std;

// 技能结构体声明
struct Skill {
    int level;
    double ATK;
    double DEF;
    double HP;
    int MP;
    double DOD;
    int num;
    string name;
};

// 宝可梦基类声明
class Pokemon {
protected:
    int level;
    int EXP;
    int ATK;
    int DEF;
    int HP;
    int MP;
    int HPmax;
    int MPmax;
    double DOD;
    Skill skill[6];

    void AttributeMaker(int EXP);
    void AttributeRestorer();
    virtual void Skillmaker() = 0;  // 纯虚函数，需子类实现

public:
    void DAGmaker(int DAG);
    void HPadder(int HPadd);
    void InfoDisplayer();
    void SkillDisplayer();
};

// 元素类型子类声明
class ElementPokemon_Metal : public Pokemon {
protected:
    string elementname = "Metal";
    int elementnum = 1;
};

class ElementPokemon_Mood : public Pokemon {
protected:
    string elementname = "Mood";
    int elementnum = 2;
};

class ElementPokemon_Water : public Pokemon {
protected:
    string elementname = "Water";
    int elementnum = 3;
};

class ElementPokemon_Fire : public Pokemon {
protected:
    string elementname = "Fire";
    int elementnum = 4;
};

class ElementPokemon_Terra : public Pokemon {
protected:
    string elementname = "Terra";
    int elementnum = 5;
};

// 具体宝可梦类声明
class Scizor : public ElementPokemon_Metal {
protected:
    void Skillmaker() override;  // 隐式实现纯虚函数

public:
    Scizor(int EXP);
};

class Metang : public ElementPokemon_Metal {
protected:
    void Skillmaker() override;

public:
    Metang(int EXP);
};

class Sceptile : public ElementPokemon_Mood {
protected:
    void Skillmaker() override;

public:
    Sceptile(int EXP);
};

class Venusaur : public ElementPokemon_Mood {
protected:
    void Skillmaker() override;

public:
    Venusaur(int EXP);
};

class Gyarados : public ElementPokemon_Water {
protected:
    void Skillmaker() override;

public:
    Gyarados(int EXP);
};

class Kingdra : public ElementPokemon_Water {
protected:
    void Skillmaker() override;

public:
    Kingdra(int EXP);
};

class Arcanine : public ElementPokemon_Fire {
protected:
    void Skillmaker() override;

public:
    Arcanine(int EXP);
};

class Magmortar : public ElementPokemon_Fire {
protected:
    void Skillmaker() override;

public:
    Magmortar(int EXP);
};

class Donphan : public ElementPokemon_Terra {
protected:
    void Skillmaker() override;

public:
    Donphan(int EXP);
};

class Marshtomp : public ElementPokemon_Terra {
protected:
    void Skillmaker() override;

public:
    Marshtomp(int EXP);
};

#endif // POKEMONCLASS_H