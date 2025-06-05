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
    // 基础属性
    int level;              // 等级
    int EXP;                // 经验值
    int ATK;                // 攻击力
    int DEF;                // 防御力
    int HP;                 // 当前生命值
    int MP;                 // 当前魔法值
    int HPmax;              // 最大生命值
    int MPmax;              // 最大魔法值
    double DOD = 0.1;       // 基础闪避率
    int num;                // 宝可梦编号
    std::string name;       // 宝可梦名称
    Skill skill[6];         // 技能数组

    // 核心算法
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
    // 虚析构函数确保正确释放资源
    virtual ~Pokemon() = default;

    // 战斗接口
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

    // 信息展示
    void InfoDisplayer();
    void SkillDisplayer();
    void InfoDisplayer_Liter();
    void SkillDisplayer_Lite(int i);

    // 纯虚函数（需派生类实现）
    virtual int GetPokemonType() const = 0;
    virtual void Skillmaker() = 0;
    std::vector<Pokemon*> CreatePokemonArray(const std::vector<int>& nums, const std::vector<int>& exps);
    Pokemon* CreatePokemon(int num, int EXP);
};

// 元素类型基类（金/木/水/火/土）
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

// 具体宝可梦实现（示例：巨钳螳螂）
class Scizor : public ElementPokemon_Metal {
    void Skillmaker() override;
public:
    explicit Scizor(int EXP);
};

// 其他宝可梦类声明（省略具体实现，保持头文件简洁）
class Metang : public ElementPokemon_Metal { void Skillmaker() override; public: explicit Metang(int); };
class Sceptile : public ElementPokemon_Mood { void Skillmaker() override; public: explicit Sceptile(int); };
class Venusaur : public ElementPokemon_Mood { void Skillmaker() override; public: explicit Venusaur(int); };
class Gyarados : public ElementPokemon_Water { void Skillmaker() override; public: explicit Gyarados(int); };
class Kingdra : public ElementPokemon_Water { void Skillmaker() override; public: explicit Kingdra(int); };
class Arcanine : public ElementPokemon_Fire { void Skillmaker() override; public: explicit Arcanine(int); };
class Magmortar : public ElementPokemon_Fire { void Skillmaker() override; public: explicit Magmortar(int); };
class Donphan : public ElementPokemon_Terra { void Skillmaker() override; public: explicit Donphan(int); };
class Marshtomp : public ElementPokemon_Terra { void Skillmaker() override; public: explicit Marshtomp(int); };

// 工厂函数声明：根据num选择派生类并返回Pokemon指针


// 批量创建宝可梦数组的函数声明

#endif POKEMONCLASS_H