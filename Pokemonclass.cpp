<<<<<<< HEAD
#include "Pokemonclass.h"
#include<string>
#include<cmath>
#include<iostream>
using namespace std;

struct Skill{
	int level;	//技能释放所要求的最低等级
	double ATK;	//技能攻击力倍率
	double DEF;	//技能防御力倍率
	double HP;	//技能生命回复倍率
	int MP;		//技能释放消耗的能量值
	double DOD;	//技能带来的闪避概率影响
	int num;	//技能编号
	string name;//技能名称
};

class Pokemon {
protected:
	int level;	//等级
	int EXP;	//经验值
	int ATK;	//攻击力
	int DEF;	//防御力
	int HP;		//生命值
	int MP;		//能量值
	int HPmax;	//当前状态下的最大生命值
	int MPmax;	//当前状态下的最大能量值
	double DOD = 0.1;	//闪避概率
	int num;	//宝可梦种类编号
	Skill skill[6];//技能，实际构造技能由子类进行。目前为每种宝可梦设定有六个技能。

	void AttributeMaker(int EXP) {
		level = int(pow(EXP, 0.5));	//使用经验值构造等级
		ATK = 10 + (5 * level);//使用等级构造攻击力，下同。
		DEF = 5 + (4 * level);
		HPmax = (20 * level) + 100;
		MPmax = 200 + (8 * level);
	}
	void AttributeRestorer() {
		HP = HPmax;
		MP = MPmax;
	}
	virtual void Skillmaker() = 0;	//不同种类的宝可梦有不同的技能，所以此技能构造函数由子类实现。
public:
	void DAGmaker(int DAG) { HP -= DAG; if (HP < 0)HP = 0; }	//伤害施加函数
	void HPadder(int HPadd) { HP += HPadd; if (HP > HPmax)HP = HPmax; }	//生命值回复函数
	void InfoDisplayer() {	//宝可梦基本信息查看函数
		cout << "等级：" << level << endl;
		cout << "经验值：" << EXP << endl;
		cout << "生命值：" << HP << " / " << HPmax << endl;
		cout << "能量值：" << MP << " / " << MPmax << endl;
		cout << "攻击力：" << ATK << endl;
		cout << "防御力：" << DEF << endl;
		cout << "闪避概率：" << DOD * 100 << "%" << endl;
		cout << endl;
	}
	void SkillDisplayer() {
		int i = 0;
		for (i = 0; i < 6; i++) {
			cout << "技能名称：" << skill[i].name << endl;
			cout << "攻击倍率：" << skill[i].ATK * 100 << "%" << endl;
			cout << "防御倍率：" << skill[i].DEF * 100 << "%" << endl;
			cout << "生命回复倍率：" << skill[i].HP * 100 << "%" << endl;
			cout << "闪避概率提升：" << skill[i].DOD * 100 << "%" << endl;
			cout << "能量值消耗：" << skill[i].MP << endl;
			cout << "技能释放所需最低等级：" << skill[i].level << "级" << endl;
			cout << endl;
		}
	}
};
//此为宝可梦基类的内容（未完全完成），在设定上所有宝可梦都使用相同的“经验值-等级”转换和“等级-其他属性”转换，
//而实际在战斗过程中产生差别的是技能倍率，因此在此处实现这两类数值的转换函数。
//宝可梦有五种元素类型,在战斗中元素之间有克制关系，会影响伤害的数值。
//目前设定每种元素有两种宝可梦，因此需构建5个宝可梦元素子类，再以此构建10种宝可梦类。
class ElementPokemon_Metal :public Pokemon {//金元素
protected:
	string elementname = "Metal";//元素名
	int elementnum = 1;//元素编号
};
class ElementPokemon_Mood :public Pokemon {//木元素
protected:
	string elementname = "Mood";
	int elementnum = 2;
};
class ElementPokemon_Water :public Pokemon {//水元素
protected:
	string elementname = "Water";
	int elementnum = 3;
};
class ElementPokemon_Fire :public Pokemon {//火元素
protected:
	string elementname = "Fire";
	int elementnum = 4;
};
class ElementPokemon_Terra :public Pokemon {//土元素
protected:
	string elementname = "Terra";
	int elementnum = 5;
}; 

class Scizor :public ElementPokemon_Metal {	//巨钳螳螂
protected:
	void Skillmaker(){	//目前每个宝可梦都最多拥有3个攻击类技能，2个防御或回复类技能，1个闪避类技能，根据宝可梦的等级先后解锁。
						//使用技能时通过技能编号进行调用。技能的主要属性靠倍率生效，部分属性靠数值生效。
		skill[0].ATK = 1.8; skill[0].DEF = 0.5; skill[0].DOD = -0.1; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 10; skill[0].name = "Iron Charge"; skill[0].num = 1;//攻击技能“钢铁冲锋”
		//此为第一个技能的构建，此后的技能构建方式相同。
		skill[1].ATK = 2.2; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Alloy Cut"; skill[1].num = 2;//攻击技能“合金切割”
		skill[2].ATK = 3.0; skill[2].DEF = 0.3; skill[2].DOD = 0.1; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 40; skill[2].name = "Atomic Blast"; skill[2].num = 3;//攻击技能“原子冲击波”
		skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = -0.1; skill[3].HP = 0.15; skill[3].level = 0; skill[3].MP = 20; skill[3].name = "Bronze Wall"; skill[3].num = 4;//防御技能“铜墙铁壁”
		skill[4].ATK = 0.4; skill[4].DEF = 3.0; skill[4].DOD = 0; skill[4].HP = 0.15; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Energy Shield"; skill[4].num = 5;//防御技能“能量护盾”
		skill[5].ATK = 0.5; skill[5].DEF = 0.5; skill[5].DOD = 0.7; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Quickstep"; skill[5].num = 6;//闪避技能“疾风步”
	}
public:
	Scizor(int);
};
Scizor::Scizor(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 1;
}

class Metang :public ElementPokemon_Metal {	//合金十字
protected:
	void Skillmaker() {	
		skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 28; skill[0].name = "Ion Impact"; skill[0].num = 1; // 攻击技能"离子冲击"
		skill[1].ATK = 2.0; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 32; skill[1].name = "Magnet Storm"; skill[1].num = 2; // 攻击技能"磁力风暴"
		skill[2].ATK = 2.7; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 48; skill[2].name = "Superconduct"; skill[2].num = 3; // 攻击技能"超导光束"
		skill[3].ATK = 0.2; skill[3].DEF = 1.8; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 22; skill[3].name = "Magnetic Shield"; skill[3].num = 4; // 防御技能"磁力护盾"
		skill[4].ATK = 0.3; skill[4].DEF = 0.3; skill[4].DOD = 0; skill[4].HP = 0.25; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Energy Regen"; skill[4].num = 5; // 恢复技能"能量再生"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.2; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 35; skill[5].name = "Electro Drift"; skill[5].num = 6; // 闪避技能"电磁飘移"
	}
public:
	Metang(int);
};
Metang::Metang(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 2;
}

class Sceptile :public ElementPokemon_Mood {	//蜥蜴王
protected:
	void Skillmaker() {
		skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 20; skill[0].name = "Leaf Blade"; skill[0].num = 1; // 攻击技能"叶刃斩击"
		skill[1].ATK = 1.9; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Seed Bomb"; skill[1].num = 2; // 攻击技能"种子机关枪"
		skill[2].ATK = 2.5; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 55; skill[2].name = "Forest Storm"; skill[2].num = 3; // 攻击技能"森林风暴"
		skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 15; skill[3].name = "Nature's Shelter"; skill[3].num = 4; // 防御技能"自然庇护"
		skill[4].ATK = 0.3; skill[4].DEF = 1.6; skill[4].DOD = 0; skill[4].HP = 0.05; skill[4].level = 25; skill[4].MP = 35; skill[4].name = "Root Bind"; skill[4].num = 5; // 防御技能"根须缠绕"
		skill[5].ATK = 0.5; skill[5].DEF = 0.5; skill[5].DOD = 0.2; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 25; skill[5].name = "Shade Stealth"; skill[5].num = 6; // 闪避技能"树影遁形"
	}
public:
	Sceptile(int);
};
Sceptile::Sceptile(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 3;
}

class Venusaur :public ElementPokemon_Mood {	//妙蛙花
protected:
	void Skillmaker() {
		skill[0].ATK = 1.6; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 18; skill[0].name = "Vine Whip"; skill[0].num = 1; // 攻击技能"藤鞭猛击"
		skill[1].ATK = 2.1; skill[1].DEF = 0.8; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 38; skill[1].name = "Petal Blizzard"; skill[1].num = 2; // 攻击技能"花瓣风暴"
		skill[2].ATK = 2.6; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Ancient Power"; skill[2].num = 3; // 攻击技能"原始之力"
		skill[3].ATK = 0.1; skill[3].DEF = 0.1; skill[3].DOD = 0; skill[3].HP = 0.35; skill[3].level = 0; skill[3].MP = 10; skill[3].name = "Photosynthesis"; skill[3].num = 4; // 恢复技能"光合作用"
		skill[4].ATK = 0.4; skill[4].DEF = 2.2; skill[4].DOD = 0; skill[4].HP = 0; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Petal Shield"; skill[4].num = 5; // 防御技能"花瓣护盾"
		skill[5].ATK = 0.3; skill[5].DEF = 0.3; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Grass Camouflage"; skill[5].num = 6; // 闪避技能"草丛匿踪"
	}
public:
	Venusaur(int);
};
Venusaur::Venusaur(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 4;
}

class Gyarados :public ElementPokemon_Water {	//暴鲤龙
protected:
	void Skillmaker() {
		skill[0].ATK = 1.9; skill[0].DEF = 0.4; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 35; skill[0].name = "Hydro Pump"; skill[0].num = 1; // 攻击技能"水炮轰击"
		skill[1].ATK = 1.5; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Twister"; skill[1].num = 2; // 攻击技能"龙卷风"
		skill[2].ATK = 2.8; skill[2].DEF = 0.2; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 60; skill[2].name = "Hyper Beam"; skill[2].num = 3; // 攻击技能"破坏光线"
		skill[3].ATK = 0.2; skill[3].DEF = 1.9; skill[3].DOD = 0; skill[3].HP = 0.12; skill[3].level = 0; skill[3].MP = 30; skill[3].name = "Tidal Shield"; skill[3].num = 4; // 防御技能"潮汐护盾"
		skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 15; skill[4].name = "Rain Dish"; skill[4].num = 5; // 恢复技能"雨水滋润"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Wave Jump"; skill[5].num = 6; // 闪避技能"波浪跳跃"
	}
public:
	Gyarados(int);
};
Gyarados::Gyarados(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 5;
}

class Kingdra :public ElementPokemon_Water {	//刺龙王
protected:
	void Skillmaker() {
		skill[0].ATK = 1.7; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 22; skill[0].name = "Dragon Breath"; skill[0].num = 1; // 攻击技能"龙息冲击"
		skill[1].ATK = 2.0; skill[1].DEF = 0.6; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 32; skill[1].name = "Ocean Blade"; skill[1].num = 2; // 攻击技能"海浪刃"
		skill[2].ATK = 2.4; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 45; skill[2].name = "Abyss Roar"; skill[2].num = 3; // 攻击技能"深渊咆哮"
		skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 28; skill[3].name = "Aqua Barrier"; skill[3].num = 4; // 防御技能"水幕屏障"
		skill[4].ATK = 0.2; skill[4].DEF = 0.2; skill[4].DOD = 0; skill[4].HP = 0.25; skill[4].level = 25; skill[4].MP = 38; skill[4].name = "Tide Recovery"; skill[4].num = 5; // 恢复技能"潮汐恢复"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 25; skill[5].name = "Bubble Escape"; skill[5].num = 6; // 闪避技能"泡沫遁形"
	}
public:
	Kingdra(int);
};
Kingdra::Kingdra(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 5;
}

class Arcanine :public ElementPokemon_Fire {	//风速狗
protected:
	void Skillmaker() {
		skill[0].ATK = 1.8; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 25; skill[0].name = "Flame Rush"; skill[0].num = 1; // 攻击技能"火焰冲刺"
		skill[1].ATK = 2.2; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 35; skill[1].name = "Inferno Storm"; skill[1].num = 2; // 攻击技能"烈焰风暴"
		skill[2].ATK = 2.9; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Explosion Rush"; skill[2].num = 3; // 攻击技能"爆炎冲击"
		skill[3].ATK = 0.3; skill[3].DEF = 1.8; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 20; skill[3].name = "Flame Shield"; skill[3].num = 4; // 防御技能"火焰护盾"
		skill[4].ATK = 0.2; skill[4].DEF = 0.2; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 30; skill[4].name = "Scorch Recovery"; skill[4].num = 5; // 恢复技能"灼热恢复"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Smoke Screen"; skill[5].num = 6; // 闪避技能"烟幕遁形"
	}
public:
	Arcanine(int);
};
Arcanine::Arcanine(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 7;
}

class Magmortar :public ElementPokemon_Fire {	//鸭嘴炎兽
protected:
	void Skillmaker() {
		skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 28; skill[0].name = "Lava Burst"; skill[0].num = 1; // 攻击技能"熔岩冲击"
		skill[1].ATK = 1.9; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Fire Punch"; skill[1].num = 2; // 攻击技能"火焰拳"
		skill[2].ATK = 2.6; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 48; skill[2].name = "Fire Blast"; skill[2].num = 3; // 攻击技能"烈焰风暴"
		skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 22; skill[3].name = "Flame Armor"; skill[3].num = 4; // 防御技能"火焰护甲"
		skill[4].ATK = 0.3; skill[4].DEF = 2.0; skill[4].DOD = 0; skill[4].HP = 0; skill[4].level = 25; skill[4].MP = 35; skill[4].name = "Scorching Shield"; skill[4].num = 5; // 防御技能"灼热护盾"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Smog Escape"; skill[5].num = 6; // 闪避技能"烟雾遁形"
	}
public:
	Magmortar(int);
};
Magmortar::Magmortar(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 8;
}

class Donphan :public ElementPokemon_Terra {	//顿甲
protected:
	void Skillmaker() {
		skill[0].ATK = 1.9; skill[0].DEF = 0.4; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 35; skill[0].name = "Earthquake"; skill[0].num = 1; // 攻击技能"地震冲击"
		skill[1].ATK = 1.6; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Rock Blast"; skill[1].num = 2; // 攻击技能"岩石炮"
		skill[2].ATK = 2.4; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Land Crush"; skill[2].num = 3; // 攻击技能"大地粉碎"
		skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 30; skill[3].name = "Rock Shield"; skill[3].num = 4; // 防御技能"岩石护盾"
		skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.15; skill[4].level = 25; skill[4].MP = 20; skill[4].name = "Sand Recovery"; skill[4].num = 5; // 恢复技能"沙尘恢复"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Sand Escape"; skill[5].num = 6; // 闪避技能"沙暴遁形"
	}
public:
	Donphan(int);
};
Donphan::Donphan(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 9;
}

class Marshtomp :public ElementPokemon_Terra {	//沼跃鱼
protected:
	void Skillmaker() {
		skill[0].ATK = 1.6; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 20; skill[0].name = "Mud Bomb"; skill[0].num = 1; // 攻击技能"泥巴炸弹"
		skill[1].ATK = 1.8; skill[1].DEF = 0.6; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Aqua Jet"; skill[1].num = 2; // 攻击技能"水炮冲击"
		skill[2].ATK = 2.3; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 45; skill[2].name = "Earth Rage"; skill[2].num = 3; // 攻击技能"大地之怒"
		skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.08; skill[3].level = 0; skill[3].MP = 25; skill[3].name = "Mud Shield"; skill[3].num = 4; // 防御技能"泥浆护盾"
		skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 15; skill[4].name = "Earth's Blessing"; skill[4].num = 5; // 恢复技能"大地庇护"
		skill[5].ATK = 0.3; skill[5].DEF = 0.3; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Swamp Escape"; skill[5].num = 6; // 闪避技能"沼泽遁形"
	}
public:
	Marshtomp(int);
};
Marshtomp::Marshtomp(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 10;
=======
#include "Pokemonclass.h"
#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

struct Skill{
	int level;	//技能释放所要求的最低等级
	double ATK;	//技能攻击力倍率
	double DEF;	//技能防御力倍率
	double HP;	//技能生命回复倍率
	int MP;		//技能释放消耗的能量值
	double DOD;	//技能带来的闪避概率影响
	int num;	//技能编号
	string name;//技能名称
};

class Pokemon {
protected:
	int level;	//等级
	int EXP;	//经验值
	int ATK;	//攻击力
	int DEF;	//防御力
	int HP;		//生命值
	int MP;		//能量值
	int HPmax;	//当前状态下的最大生命值
	int MPmax;	//当前状态下的最大能量值
	double DOD = 0.1;	//闪避概率
	int num;	//宝可梦种类编号
	Skill skill[6];//技能，实际构造技能由子类进行。目前为每种宝可梦设定有六个技能。

	void AttributeMaker(int EXP) {
		level = int(pow(EXP, 0.5));	//使用经验值构造等级
		ATK = 10 + (5 * level);//使用等级构造攻击力，下同。
		DEF = 5 + (4 * level);
		HPmax = (20 * level) + 100;
		MPmax = 200 + (8 * level);
	}
	void AttributeRestorer() {
		HP = HPmax;
		MP = MPmax;
	}
	virtual void Skillmaker() = 0;	//不同种类的宝可梦有不同的技能，所以此技能构造函数由子类实现。
public:
	void DAGmaker(int DAG) { HP -= DAG; if (HP < 0)HP = 0; }	//伤害施加函数
	void HPadder(int HPadd) { HP += HPadd; if (HP > HPmax)HP = HPmax; }	//生命值回复函数
	Skill SkillSelector(int num) { return skill[num - 1]; }
	void InfoDisplayer() {	//宝可梦基本信息查看函数
		cout << "等级：" << level << endl;
		cout << "经验值：" << EXP << endl;
		cout << "生命值：" << HP << " / " << HPmax << endl;
		cout << "能量值：" << MP << " / " << MPmax << endl;
		cout << "攻击力：" << ATK << endl;
		cout << "防御力：" << DEF << endl;
		cout << "闪避概率：" << DOD * 100 << "%" << endl;
		cout << endl;
	}
	void SkillDisplayer() {
		int i = 0;
		for (i = 0; i < 6; i++) {
			cout << "技能名称：" << skill[i].name << endl;
			cout << "攻击倍率：" << skill[i].ATK * 100 << "%" << endl;
			cout << "防御倍率：" << skill[i].DEF * 100 << "%" << endl;
			cout << "生命回复倍率：" << skill[i].HP * 100 << "%" << endl;
			cout << "闪避概率提升：" << skill[i].DOD * 100 << "%" << endl;
			cout << "能量值消耗：" << skill[i].MP << endl;
			cout << "技能释放所需最低等级：" << skill[i].level << "级" << endl;
			cout << endl;
		}
	}
	void InfoDisplayer_Liter() {	//宝可梦预选界面使用的简要信息呈现
		cout << "等级：" << level << endl;
		cout << "生命值：" << HP << " / " << HPmax << endl;
		cout << "能量值：" << MP << " / " << MPmax << endl;
	}
	void SkillDisplayer_Lite(int i) {	//技能预选界面使用的简要信息呈现
		cout << "技能名称：" << skill[i].name << endl;
		cout << "攻击倍率：" << skill[i].ATK * 100 << "%" << endl;
		cout << "防御倍率：" << skill[i].DEF * 100 << "%" << endl;
		cout << "生命回复倍率：" << skill[i].HP * 100 << "%" << endl;
		cout << "闪避概率提升：" << skill[i].DOD * 100 << "%" << endl;
		cout << "能量值消耗：" << skill[i].MP << endl;
		cout << "技能释放所需最低等级：" << skill[i].level << "级" << endl;
		cout << endl;
	}
};
//此为宝可梦基类的内容（未完全完成），在设定上所有宝可梦都使用相同的“经验值-等级”转换和“等级-其他属性”转换，
//而实际在战斗过程中产生差别的是技能倍率，因此在此处实现这两类数值的转换函数。
//宝可梦有五种元素类型,在战斗中元素之间有克制关系，会影响伤害的数值。
//目前设定每种元素有两种宝可梦，因此需构建5个宝可梦元素子类，再以此构建10种宝可梦类。
class ElementPokemon_Metal :public Pokemon {//金元素
protected:
	string elementname = "Metal";//元素名
	int elementnum = 1;//元素编号
};
class ElementPokemon_Mood :public Pokemon {//木元素
protected:
	string elementname = "Mood";
	int elementnum = 2;
};
class ElementPokemon_Water :public Pokemon {//水元素
protected:
	string elementname = "Water";
	int elementnum = 3;
};
class ElementPokemon_Fire :public Pokemon {//火元素
protected:
	string elementname = "Fire";
	int elementnum = 4;
};
class ElementPokemon_Terra :public Pokemon {//土元素
protected:
	string elementname = "Terra";
	int elementnum = 5;
}; 

class Scizor :public ElementPokemon_Metal {	//巨钳螳螂
protected:
	void Skillmaker(){	//目前每个宝可梦都最多拥有3个攻击类技能，2个防御或回复类技能，1个闪避类技能，根据宝可梦的等级先后解锁。
						//使用技能时通过技能编号进行调用。技能的主要属性靠倍率生效，部分属性靠数值生效。
		skill[0].ATK = 1.8; skill[0].DEF = 0.5; skill[0].DOD = -0.1; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 10; skill[0].name = "Iron Charge"; skill[0].num = 1;//攻击技能“钢铁冲锋”
		//此为第一个技能的构建，此后的技能构建方式相同。
		skill[1].ATK = 2.2; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Alloy Cut"; skill[1].num = 2;//攻击技能“合金切割”
		skill[2].ATK = 3.0; skill[2].DEF = 0.3; skill[2].DOD = 0.1; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 40; skill[2].name = "Atomic Blast"; skill[2].num = 3;//攻击技能“原子冲击波”
		skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = -0.1; skill[3].HP = 0.15; skill[3].level = 0; skill[3].MP = 20; skill[3].name = "Bronze Wall"; skill[3].num = 4;//防御技能“铜墙铁壁”
		skill[4].ATK = 0.4; skill[4].DEF = 3.0; skill[4].DOD = 0; skill[4].HP = 0.15; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Energy Shield"; skill[4].num = 5;//防御技能“能量护盾”
		skill[5].ATK = 0.5; skill[5].DEF = 0.5; skill[5].DOD = 0.7; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Quickstep"; skill[5].num = 6;//闪避技能“疾风步”
	}
public:
	Scizor(int);
};
Scizor::Scizor(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 1;
}

class Metang :public ElementPokemon_Metal {	//合金十字
protected:
	void Skillmaker() {	
		skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 28; skill[0].name = "Ion Impact"; skill[0].num = 1; // 攻击技能"离子冲击"
		skill[1].ATK = 2.0; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 32; skill[1].name = "Magnet Storm"; skill[1].num = 2; // 攻击技能"磁力风暴"
		skill[2].ATK = 2.7; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 48; skill[2].name = "Superconduct"; skill[2].num = 3; // 攻击技能"超导光束"
		skill[3].ATK = 0.2; skill[3].DEF = 1.8; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 22; skill[3].name = "Magnetic Shield"; skill[3].num = 4; // 防御技能"磁力护盾"
		skill[4].ATK = 0.3; skill[4].DEF = 0.3; skill[4].DOD = 0; skill[4].HP = 0.25; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Energy Regen"; skill[4].num = 5; // 恢复技能"能量再生"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.2; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 35; skill[5].name = "Electro Drift"; skill[5].num = 6; // 闪避技能"电磁飘移"
	}
public:
	Metang(int);
};
Metang::Metang(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 2;
}

class Sceptile :public ElementPokemon_Mood {	//蜥蜴王
protected:
	void Skillmaker() {
		skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 20; skill[0].name = "Leaf Blade"; skill[0].num = 1; // 攻击技能"叶刃斩击"
		skill[1].ATK = 1.9; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Seed Bomb"; skill[1].num = 2; // 攻击技能"种子机关枪"
		skill[2].ATK = 2.5; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 55; skill[2].name = "Forest Storm"; skill[2].num = 3; // 攻击技能"森林风暴"
		skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 15; skill[3].name = "Nature's Shelter"; skill[3].num = 4; // 防御技能"自然庇护"
		skill[4].ATK = 0.3; skill[4].DEF = 1.6; skill[4].DOD = 0; skill[4].HP = 0.05; skill[4].level = 25; skill[4].MP = 35; skill[4].name = "Root Bind"; skill[4].num = 5; // 防御技能"根须缠绕"
		skill[5].ATK = 0.5; skill[5].DEF = 0.5; skill[5].DOD = 0.2; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 25; skill[5].name = "Shade Stealth"; skill[5].num = 6; // 闪避技能"树影遁形"
	}
public:
	Sceptile(int);
};
Sceptile::Sceptile(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 3;
}

class Venusaur :public ElementPokemon_Mood {	//妙蛙花
protected:
	void Skillmaker() {
		skill[0].ATK = 1.6; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 18; skill[0].name = "Vine Whip"; skill[0].num = 1; // 攻击技能"藤鞭猛击"
		skill[1].ATK = 2.1; skill[1].DEF = 0.8; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 38; skill[1].name = "Petal Blizzard"; skill[1].num = 2; // 攻击技能"花瓣风暴"
		skill[2].ATK = 2.6; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Ancient Power"; skill[2].num = 3; // 攻击技能"原始之力"
		skill[3].ATK = 0.1; skill[3].DEF = 0.1; skill[3].DOD = 0; skill[3].HP = 0.35; skill[3].level = 0; skill[3].MP = 10; skill[3].name = "Photosynthesis"; skill[3].num = 4; // 恢复技能"光合作用"
		skill[4].ATK = 0.4; skill[4].DEF = 2.2; skill[4].DOD = 0; skill[4].HP = 0; skill[4].level = 25; skill[4].MP = 40; skill[4].name = "Petal Shield"; skill[4].num = 5; // 防御技能"花瓣护盾"
		skill[5].ATK = 0.3; skill[5].DEF = 0.3; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Grass Camouflage"; skill[5].num = 6; // 闪避技能"草丛匿踪"
	}
public:
	Venusaur(int);
};
Venusaur::Venusaur(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 4;
}

class Gyarados :public ElementPokemon_Water {	//暴鲤龙
protected:
	void Skillmaker() {
		skill[0].ATK = 1.9; skill[0].DEF = 0.4; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 35; skill[0].name = "Hydro Pump"; skill[0].num = 1; // 攻击技能"水炮轰击"
		skill[1].ATK = 1.5; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Twister"; skill[1].num = 2; // 攻击技能"龙卷风"
		skill[2].ATK = 2.8; skill[2].DEF = 0.2; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 60; skill[2].name = "Hyper Beam"; skill[2].num = 3; // 攻击技能"破坏光线"
		skill[3].ATK = 0.2; skill[3].DEF = 1.9; skill[3].DOD = 0; skill[3].HP = 0.12; skill[3].level = 0; skill[3].MP = 30; skill[3].name = "Tidal Shield"; skill[3].num = 4; // 防御技能"潮汐护盾"
		skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 15; skill[4].name = "Rain Dish"; skill[4].num = 5; // 恢复技能"雨水滋润"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Wave Jump"; skill[5].num = 6; // 闪避技能"波浪跳跃"
	}
public:
	Gyarados(int);
};
Gyarados::Gyarados(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 5;
}

class Kingdra :public ElementPokemon_Water {	//刺龙王
protected:
	void Skillmaker() {
		skill[0].ATK = 1.7; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 22; skill[0].name = "Dragon Breath"; skill[0].num = 1; // 攻击技能"龙息冲击"
		skill[1].ATK = 2.0; skill[1].DEF = 0.6; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 32; skill[1].name = "Ocean Blade"; skill[1].num = 2; // 攻击技能"海浪刃"
		skill[2].ATK = 2.4; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 45; skill[2].name = "Abyss Roar"; skill[2].num = 3; // 攻击技能"深渊咆哮"
		skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 28; skill[3].name = "Aqua Barrier"; skill[3].num = 4; // 防御技能"水幕屏障"
		skill[4].ATK = 0.2; skill[4].DEF = 0.2; skill[4].DOD = 0; skill[4].HP = 0.25; skill[4].level = 25; skill[4].MP = 38; skill[4].name = "Tide Recovery"; skill[4].num = 5; // 恢复技能"潮汐恢复"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 25; skill[5].name = "Bubble Escape"; skill[5].num = 6; // 闪避技能"泡沫遁形"
	}
public:
	Kingdra(int);
};
Kingdra::Kingdra(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 5;
}

class Arcanine :public ElementPokemon_Fire {	//风速狗
protected:
	void Skillmaker() {
		skill[0].ATK = 1.8; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 25; skill[0].name = "Flame Rush"; skill[0].num = 1; // 攻击技能"火焰冲刺"
		skill[1].ATK = 2.2; skill[1].DEF = 0.7; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 35; skill[1].name = "Inferno Storm"; skill[1].num = 2; // 攻击技能"烈焰风暴"
		skill[2].ATK = 2.9; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Explosion Rush"; skill[2].num = 3; // 攻击技能"爆炎冲击"
		skill[3].ATK = 0.3; skill[3].DEF = 1.8; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 20; skill[3].name = "Flame Shield"; skill[3].num = 4; // 防御技能"火焰护盾"
		skill[4].ATK = 0.2; skill[4].DEF = 0.2; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 30; skill[4].name = "Scorch Recovery"; skill[4].num = 5; // 恢复技能"灼热恢复"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Smoke Screen"; skill[5].num = 6; // 闪避技能"烟幕遁形"
	}
public:
	Arcanine(int);
};
Arcanine::Arcanine(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 7;
}

class Magmortar :public ElementPokemon_Fire {	//鸭嘴炎兽
protected:
	void Skillmaker() {
		skill[0].ATK = 1.7; skill[0].DEF = 0.6; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 28; skill[0].name = "Lava Burst"; skill[0].num = 1; // 攻击技能"熔岩冲击"
		skill[1].ATK = 1.9; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Fire Punch"; skill[1].num = 2; // 攻击技能"火焰拳"
		skill[2].ATK = 2.6; skill[2].DEF = 0.4; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 48; skill[2].name = "Fire Blast"; skill[2].num = 3; // 攻击技能"烈焰风暴"
		skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.1; skill[3].level = 0; skill[3].MP = 22; skill[3].name = "Flame Armor"; skill[3].num = 4; // 防御技能"火焰护甲"
		skill[4].ATK = 0.3; skill[4].DEF = 2.0; skill[4].DOD = 0; skill[4].HP = 0; skill[4].level = 25; skill[4].MP = 35; skill[4].name = "Scorching Shield"; skill[4].num = 5; // 防御技能"灼热护盾"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Smog Escape"; skill[5].num = 6; // 闪避技能"烟雾遁形"
	}
public:
	Magmortar(int);
};
Magmortar::Magmortar(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 8;
}

class Donphan :public ElementPokemon_Terra {	//顿甲
protected:
	void Skillmaker() {
		skill[0].ATK = 1.9; skill[0].DEF = 0.4; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 35; skill[0].name = "Earthquake"; skill[0].num = 1; // 攻击技能"地震冲击"
		skill[1].ATK = 1.6; skill[1].DEF = 0.5; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 25; skill[1].name = "Rock Blast"; skill[1].num = 2; // 攻击技能"岩石炮"
		skill[2].ATK = 2.4; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 50; skill[2].name = "Land Crush"; skill[2].num = 3; // 攻击技能"大地粉碎"
		skill[3].ATK = 0.3; skill[3].DEF = 2.0; skill[3].DOD = 0; skill[3].HP = 0; skill[3].level = 0; skill[3].MP = 30; skill[3].name = "Rock Shield"; skill[3].num = 4; // 防御技能"岩石护盾"
		skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.15; skill[4].level = 25; skill[4].MP = 20; skill[4].name = "Sand Recovery"; skill[4].num = 5; // 恢复技能"沙尘恢复"
		skill[5].ATK = 0.4; skill[5].DEF = 0.4; skill[5].DOD = 0.1; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 15; skill[5].name = "Sand Escape"; skill[5].num = 6; // 闪避技能"沙暴遁形"
	}
public:
	Donphan(int);
};
Donphan::Donphan(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 9;
}

class Marshtomp :public ElementPokemon_Terra {	//沼跃鱼
protected:
	void Skillmaker() {
		skill[0].ATK = 1.6; skill[0].DEF = 0.5; skill[0].DOD = 0; skill[0].HP = 0; skill[0].level = 0; skill[0].MP = 20; skill[0].name = "Mud Bomb"; skill[0].num = 1; // 攻击技能"泥巴炸弹"
		skill[1].ATK = 1.8; skill[1].DEF = 0.6; skill[1].DOD = 0; skill[1].HP = 0; skill[1].level = 25; skill[1].MP = 30; skill[1].name = "Aqua Jet"; skill[1].num = 2; // 攻击技能"水炮冲击"
		skill[2].ATK = 2.3; skill[2].DEF = 0.3; skill[2].DOD = 0; skill[2].HP = 0; skill[2].level = 50; skill[2].MP = 45; skill[2].name = "Earth Rage"; skill[2].num = 3; // 攻击技能"大地之怒"
		skill[3].ATK = 0.2; skill[3].DEF = 1.7; skill[3].DOD = 0; skill[3].HP = 0.08; skill[3].level = 0; skill[3].MP = 25; skill[3].name = "Mud Shield"; skill[3].num = 4; // 防御技能"泥浆护盾"
		skill[4].ATK = 0.1; skill[4].DEF = 0.1; skill[4].DOD = 0; skill[4].HP = 0.2; skill[4].level = 25; skill[4].MP = 15; skill[4].name = "Earth's Blessing"; skill[4].num = 5; // 恢复技能"大地庇护"
		skill[5].ATK = 0.3; skill[5].DEF = 0.3; skill[5].DOD = 0.15; skill[5].HP = 0; skill[5].level = 0; skill[5].MP = 20; skill[5].name = "Swamp Escape"; skill[5].num = 6; // 闪避技能"沼泽遁形"
	}
public:
	Marshtomp(int);
};
Marshtomp::Marshtomp(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 10;
>>>>>>> 鏂板鏂囦欢娣诲姞椤圭洰鏂囦欢銆?}