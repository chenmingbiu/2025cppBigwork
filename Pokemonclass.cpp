<<<<<<< HEAD
#include "Pokemonclass.h"
#include<string>
#include<cmath>
#include<iostream>
using namespace std;

struct Skill{
	int level;	//�����ͷ���Ҫ�����͵ȼ�
	double ATK;	//���ܹ���������
	double DEF;	//���ܷ���������
	double HP;	//���������ظ�����
	int MP;		//�����ͷ����ĵ�����ֵ
	double DOD;	//���ܴ��������ܸ���Ӱ��
	int num;	//���ܱ��
	string name;//��������
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
	Skill skill[6];//���ܣ�ʵ�ʹ��켼����������С�ĿǰΪÿ�ֱ������趨���������ܡ�

	void AttributeMaker(int EXP) {
		level = int(pow(EXP, 0.5));	//ʹ�þ���ֵ����ȼ�
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
	void InfoDisplayer() {	//�����λ�����Ϣ�鿴����
		cout << "�ȼ���" << level << endl;
		cout << "����ֵ��" << EXP << endl;
		cout << "����ֵ��" << HP << " / " << HPmax << endl;
		cout << "����ֵ��" << MP << " / " << MPmax << endl;
		cout << "��������" << ATK << endl;
		cout << "��������" << DEF << endl;
		cout << "���ܸ��ʣ�" << DOD * 100 << "%" << endl;
		cout << endl;
	}
	void SkillDisplayer() {
		int i = 0;
		for (i = 0; i < 6; i++) {
			cout << "�������ƣ�" << skill[i].name << endl;
			cout << "�������ʣ�" << skill[i].ATK * 100 << "%" << endl;
			cout << "�������ʣ�" << skill[i].DEF * 100 << "%" << endl;
			cout << "�����ظ����ʣ�" << skill[i].HP * 100 << "%" << endl;
			cout << "���ܸ���������" << skill[i].DOD * 100 << "%" << endl;
			cout << "����ֵ���ģ�" << skill[i].MP << endl;
			cout << "�����ͷ�������͵ȼ���" << skill[i].level << "��" << endl;
			cout << endl;
		}
	}
};
//��Ϊ�����λ�������ݣ�δ��ȫ��ɣ������趨�����б����ζ�ʹ����ͬ�ġ�����ֵ-�ȼ���ת���͡��ȼ�-�������ԡ�ת����
//��ʵ����ս�������в��������Ǽ��ܱ��ʣ�����ڴ˴�ʵ����������ֵ��ת��������
//������������Ԫ������,��ս����Ԫ��֮���п��ƹ�ϵ����Ӱ���˺�����ֵ��
//Ŀǰ�趨ÿ��Ԫ�������ֱ����Σ�����蹹��5��������Ԫ�����࣬���Դ˹���10�ֱ������ࡣ
class ElementPokemon_Metal :public Pokemon {//��Ԫ��
protected:
	string elementname = "Metal";//Ԫ����
	int elementnum = 1;//Ԫ�ر��
};
class ElementPokemon_Mood :public Pokemon {//ľԪ��
protected:
	string elementname = "Mood";
	int elementnum = 2;
};
class ElementPokemon_Water :public Pokemon {//ˮԪ��
protected:
	string elementname = "Water";
	int elementnum = 3;
};
class ElementPokemon_Fire :public Pokemon {//��Ԫ��
protected:
	string elementname = "Fire";
	int elementnum = 4;
};
class ElementPokemon_Terra :public Pokemon {//��Ԫ��
protected:
	string elementname = "Terra";
	int elementnum = 5;
}; 

class Scizor :public ElementPokemon_Metal {	//��ǯ���
protected:
	void Skillmaker(){	//Ŀǰÿ�������ζ����ӵ��3�������༼�ܣ�2��������ظ��༼�ܣ�1�������༼�ܣ����ݱ����εĵȼ��Ⱥ������
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
Scizor::Scizor(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 1;
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
Metang::Metang(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 2;
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
Sceptile::Sceptile(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 3;
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
Venusaur::Venusaur(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 4;
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
Gyarados::Gyarados(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 5;
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
Kingdra::Kingdra(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 5;
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
Arcanine::Arcanine(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 7;
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
Magmortar::Magmortar(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 8;
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
Donphan::Donphan(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 9;
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
	int level;	//�����ͷ���Ҫ�����͵ȼ�
	double ATK;	//���ܹ���������
	double DEF;	//���ܷ���������
	double HP;	//���������ظ�����
	int MP;		//�����ͷ����ĵ�����ֵ
	double DOD;	//���ܴ��������ܸ���Ӱ��
	int num;	//���ܱ��
	string name;//��������
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
	Skill skill[6];//���ܣ�ʵ�ʹ��켼����������С�ĿǰΪÿ�ֱ������趨���������ܡ�

	void AttributeMaker(int EXP) {
		level = int(pow(EXP, 0.5));	//ʹ�þ���ֵ����ȼ�
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
	Skill SkillSelector(int num) { return skill[num - 1]; }
	void InfoDisplayer() {	//�����λ�����Ϣ�鿴����
		cout << "�ȼ���" << level << endl;
		cout << "����ֵ��" << EXP << endl;
		cout << "����ֵ��" << HP << " / " << HPmax << endl;
		cout << "����ֵ��" << MP << " / " << MPmax << endl;
		cout << "��������" << ATK << endl;
		cout << "��������" << DEF << endl;
		cout << "���ܸ��ʣ�" << DOD * 100 << "%" << endl;
		cout << endl;
	}
	void SkillDisplayer() {
		int i = 0;
		for (i = 0; i < 6; i++) {
			cout << "�������ƣ�" << skill[i].name << endl;
			cout << "�������ʣ�" << skill[i].ATK * 100 << "%" << endl;
			cout << "�������ʣ�" << skill[i].DEF * 100 << "%" << endl;
			cout << "�����ظ����ʣ�" << skill[i].HP * 100 << "%" << endl;
			cout << "���ܸ���������" << skill[i].DOD * 100 << "%" << endl;
			cout << "����ֵ���ģ�" << skill[i].MP << endl;
			cout << "�����ͷ�������͵ȼ���" << skill[i].level << "��" << endl;
			cout << endl;
		}
	}
	void InfoDisplayer_Liter() {	//������Ԥѡ����ʹ�õļ�Ҫ��Ϣ����
		cout << "�ȼ���" << level << endl;
		cout << "����ֵ��" << HP << " / " << HPmax << endl;
		cout << "����ֵ��" << MP << " / " << MPmax << endl;
	}
	void SkillDisplayer_Lite(int i) {	//����Ԥѡ����ʹ�õļ�Ҫ��Ϣ����
		cout << "�������ƣ�" << skill[i].name << endl;
		cout << "�������ʣ�" << skill[i].ATK * 100 << "%" << endl;
		cout << "�������ʣ�" << skill[i].DEF * 100 << "%" << endl;
		cout << "�����ظ����ʣ�" << skill[i].HP * 100 << "%" << endl;
		cout << "���ܸ���������" << skill[i].DOD * 100 << "%" << endl;
		cout << "����ֵ���ģ�" << skill[i].MP << endl;
		cout << "�����ͷ�������͵ȼ���" << skill[i].level << "��" << endl;
		cout << endl;
	}
};
//��Ϊ�����λ�������ݣ�δ��ȫ��ɣ������趨�����б����ζ�ʹ����ͬ�ġ�����ֵ-�ȼ���ת���͡��ȼ�-�������ԡ�ת����
//��ʵ����ս�������в��������Ǽ��ܱ��ʣ�����ڴ˴�ʵ����������ֵ��ת��������
//������������Ԫ������,��ս����Ԫ��֮���п��ƹ�ϵ����Ӱ���˺�����ֵ��
//Ŀǰ�趨ÿ��Ԫ�������ֱ����Σ�����蹹��5��������Ԫ�����࣬���Դ˹���10�ֱ������ࡣ
class ElementPokemon_Metal :public Pokemon {//��Ԫ��
protected:
	string elementname = "Metal";//Ԫ����
	int elementnum = 1;//Ԫ�ر��
};
class ElementPokemon_Mood :public Pokemon {//ľԪ��
protected:
	string elementname = "Mood";
	int elementnum = 2;
};
class ElementPokemon_Water :public Pokemon {//ˮԪ��
protected:
	string elementname = "Water";
	int elementnum = 3;
};
class ElementPokemon_Fire :public Pokemon {//��Ԫ��
protected:
	string elementname = "Fire";
	int elementnum = 4;
};
class ElementPokemon_Terra :public Pokemon {//��Ԫ��
protected:
	string elementname = "Terra";
	int elementnum = 5;
}; 

class Scizor :public ElementPokemon_Metal {	//��ǯ���
protected:
	void Skillmaker(){	//Ŀǰÿ�������ζ����ӵ��3�������༼�ܣ�2��������ظ��༼�ܣ�1�������༼�ܣ����ݱ����εĵȼ��Ⱥ������
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
Scizor::Scizor(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 1;
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
Metang::Metang(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 2;
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
Sceptile::Sceptile(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 3;
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
Venusaur::Venusaur(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 4;
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
Gyarados::Gyarados(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 5;
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
Kingdra::Kingdra(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 5;
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
Arcanine::Arcanine(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 7;
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
Magmortar::Magmortar(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 8;
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
Donphan::Donphan(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 9;
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
Marshtomp::Marshtomp(int EXP) {
	AttributeMaker(EXP);
	AttributeRestorer();
	Skillmaker();
	num = 10;
>>>>>>> 新增文件添加项目文件�?}