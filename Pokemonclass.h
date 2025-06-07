#ifndef POKEMONCLASS_H
#define POKEMONCLASS_H

#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

struct Skill {
    int level;      
    double ATK;      
    double DEF;      
    double HP;       
    int MP;          
    double DOD;      
    int num;         
    std::string name;
};
class Pokemon {
protected:
    // ��������
    int level;              // �ȼ�
    int EXP;                // ����ֵ
    int ATK;                // ������
    int DEF;                // ������
    int HP;                 // ��ǰ����ֵ
    int MP;                 // ��ǰħ��ֵ
    int HPmax;              // �������ֵ
    int MPmax;              // ���ħ��ֵ
    double DOD = 0.1;       // ����������
    int num;                // �����α��
    std::string name;       // ����������
    Skill skill[6];         // ��������

    // �����㷨
    void AttributeMaker(int EXP) {
        level = static_cast<int>(std::pow(EXP, 0.5));
        ATK = 10 + 5 * level;
        DEF = 5 + 4 * level;
        HPmax = 20 * level + 100;
        MPmax = 200 + 8 * level;
    }
    void AttributeRestorer() {
        HP = HPmax;
        MP = MPmax;
    }

public:
    // ����������ȷ����ȷ�ͷ���Դ
    virtual ~Pokemon() = default;

    // ս���ӿ�
    void DAGmaker(int damage) {
        HP -= damage;
        if (HP < 0) HP = 0;
    }
    void HPadder(int heal) {
        HP += heal;
        if (HP > HPmax) HP = HPmax;
    }
    Skill SkillSelector(int num) const {
        return skill[num - 1];
    }

    // ��Ϣչʾ
    void InfoDisplayer();
    void SkillDisplayer();
    void InfoDisplayer_Liter();
    void SkillDisplayer_Lite(int i);

    // ���麯������������ʵ�֣�
    virtual int GetPokemonType() const = 0;
    virtual void Skillmaker() = 0;
    std::vector<Pokemon*> CreatePokemonArray(const std::vector<int>& nums, const std::vector<int>& exps);
    Pokemon* CreatePokemon(int num, int EXP);
};

// Ԫ�����ͻ��ࣨ��/ľ/ˮ/��/����
class ElementPokemon_Metal : public Pokemon {
protected:
    const std::string elementname = "Metal";
    const int elementnum = 1;
};
class ElementPokemon_Mood : public Pokemon {
protected:
    const std::string elementname = "Mood";
    const int elementnum = 2;
};
class ElementPokemon_Water : public Pokemon {
protected:
    const std::string elementname = "Water";
    const int elementnum = 3;
};
class ElementPokemon_Fire : public Pokemon {
protected:
    const std::string elementname = "Fire";
    const int elementnum = 4;
};
class ElementPokemon_Terra : public Pokemon {
protected:
    const std::string elementname = "Terra";
    const int elementnum = 5;
};

// ���屦����ʵ�֣�ʾ������ǯ��룩
class Scizor : public ElementPokemon_Metal {
    void Skillmaker() override;
public:
    explicit Scizor(int EXP);
};

// ������������������ʡ�Ծ���ʵ�֣�����ͷ�ļ���ࣩ
class Metang : public ElementPokemon_Metal { void Skillmaker() override; public: explicit Metang(int); };
class Sceptile : public ElementPokemon_Mood { void Skillmaker() override; public: explicit Sceptile(int); };
class Venusaur : public ElementPokemon_Mood { void Skillmaker() override; public: explicit Venusaur(int); };
class Gyarados : public ElementPokemon_Water { void Skillmaker() override; public: explicit Gyarados(int); };
class Kingdra : public ElementPokemon_Water { void Skillmaker() override; public: explicit Kingdra(int); };
class Arcanine : public ElementPokemon_Fire { void Skillmaker() override; public: explicit Arcanine(int); };
class Magmortar : public ElementPokemon_Fire { void Skillmaker() override; public: explicit Magmortar(int); };
class Donphan : public ElementPokemon_Terra { void Skillmaker() override; public: explicit Donphan(int); };
class Marshtomp : public ElementPokemon_Terra { void Skillmaker() override; public: explicit Marshtomp(int); };

// ������������������numѡ�������ಢ����Pokemonָ��


// ������������������ĺ�������

#endif POKEMONCLASS_H