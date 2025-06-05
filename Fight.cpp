#include "teamwork.h"
#include "Pokemonclass.h"
#include "Fight.h"
#include "Item.h"
#include "Account.h"
#include <cstdlib>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

extern Account User;
extern back Userback;

void Fight_Start(string accounts) {

	cout << "请选择要出战的宝可梦：" << endl;

}

int Fight_During(Pokemon& Mine, Pokemon& Enemy) {
	int selection = 0;
	Skill skill_mine = { 0 }, skill_enemy = { 0 };
	system("cls");
FightDuring_Start:
	if (Win_During(Mine, Enemy)) { return 0; }
	cout << "我方宝可梦：" << endl;
	Mine.InfoDisplayer_Liter();
	cout << "敌方宝可梦：" << endl;
	Enemy.InfoDisplayer_Liter();
	cout << "操作选择：" << endl;
	cout << "1. 攻击技能" << endl;
	cout << "2. 防御技能" << endl;
	cout << "3. 闪避技能" << endl;
	cout << "4. 药品" << endl;
	cout << "5. 精灵球" << endl;
	cout << "6. 逃跑" << endl;
	cout << "请输入对应数字：";
	clearInputBuffer();
	selection = getmenuchoice(6);
	switch (selection)
	{
	case 1: {
		if (ATKselect(Mine, skill_mine)) { Fight_Action(Mine, Enemy, skill_mine, skill_enemy); system("cls"); goto FightDuring_Start; }
		else goto FightDuring_Start;
	} break;
	case 2: {
		if (DEFselect(Mine, skill_mine)) { Fight_Action(Mine, Enemy, skill_mine, skill_enemy); system("cls"); goto FightDuring_Start; }
		else goto FightDuring_Start;
	} break;
	case 3: {
		if (DODselect(Mine, skill_mine)) { Fight_Action(Mine, Enemy, skill_mine, skill_enemy); system("cls"); goto FightDuring_Start; }
		else goto FightDuring_Start;
	} break;
	case 4:; break;
	case 5:; break;
	case 6: { if (Fight_Escape())return 0; else { Escape_Fail(Mine, Enemy, skill_enemy);goto FightDuring_Start; } };
	default: goto FightDuring_Start;
	}
	return 0;
}

bool Fight_Escape() {	//逃跑判定
	int num = 70;
	int Ran = RandomNumber(100);
	if (Ran <= num)return true;
	else return false;
}

void Fight_Action(Pokemon& Mine, Pokemon& Enemy, Skill skill_mine, Skill skill_enemy) {	//战斗模组，默认由玩家先手发起攻击
	int damage;
	double DEFrate;	//伤害减免率；
	cout << "你使用了技能：" << skill_mine.name << endl;
	cout << "敌人使用了技能：" << skill_enemy.name << endl;
	DEFrate =Enemy.DEFgetter() * skill_enemy.DEF / (45 + Enemy.DEFgetter() * skill_enemy.DEF);	//伤害减免率=防御数值/（常数+防御数值）
	damage = Mine.ATKgetter() * skill_mine.ATK * (1 - DEFrate);
	Enemy.DAGmaker(damage); 
	cout << "你对敌人造成了" << damage << "点伤害" << endl;
	if (!Enemy.HPgetter()) { cout << "敌人生命值耗尽" << endl; Nextstep(); return; }
	DEFrate = Mine.DEFgetter() * skill_mine.DEF / (45 + Mine.DEFgetter() * skill_mine.DEF);
	damage = Enemy.ATKgetter() * skill_enemy.ATK * (1 - DEFrate);
	Mine.DAGmaker(damage); 
	cout << "敌人对你造成了" << damage << "点伤害" << endl;
	cout << Mine.Namegetter() << "（你）使用了技能：" << skill_mine.name << endl;
	cout << Enemy.Namegetter() << "（敌人）使用了技能：" << skill_enemy.name << endl;
	if (DODCertify(Enemy, skill_enemy)) { cout << "敌人闪避成功" << endl; }
	else {
		DEFrate = Enemy.DEFgetter() * skill_enemy.DEF / (45 + Enemy.DEFgetter() * skill_enemy.DEF);	//伤害减免率=防御数值/（常数+防御数值）
		damage = Mine.ATKgetter() * skill_mine.ATK * (1 - DEFrate);
		Enemy.DAGmaker(damage);
		cout << "你对敌人造成了" << damage << "点伤害" << endl;
	}
	HPadder_Skill(Mine, skill_mine);
	if (!Enemy.HPgetter()) { cout << "敌人生命值耗尽" << endl; Nextstep(); return; }
	if (DODCertify(Mine, skill_mine)) { cout << "你闪避成功" << endl; }
	else {
		DEFrate = Mine.DEFgetter() * skill_mine.DEF / (45 + Mine.DEFgetter() * skill_mine.DEF);
		damage = Enemy.ATKgetter() * skill_enemy.ATK * (1 - DEFrate);
		Mine.DAGmaker(damage);
		cout << "敌人对你造成了" << damage << "点伤害" << endl;
	}
	HPadder_Skill(Enemy, skill_enemy);
	Nextstep();
	return;
}

void Escape_Fail(Pokemon& Mine, Pokemon& Enemy, Skill skill_enemy) {	//逃跑失败
	int damage;
	double DEFrate;
	cout << "逃跑失败" << endl;
	DEFrate = Mine.DEFgetter()/ (45 + Mine.DEFgetter());
	damage = Enemy.ATKgetter() * skill_enemy.ATK * (1 - DEFrate);
	Mine.DAGmaker(damage);
	cout << "敌人对你造成了" << damage << "点伤害" << endl;
	Nextstep();
	return;
}

bool SkillCertify(Pokemon& Mine, Skill skill_mine) {	//技能可用性检定
	if (Mine.levelgetter() < skill_mine.level) {
		cout << "等级不足，请重新选择" << endl; return false;
	}
	else if (Mine.MPgetter() >= skill_mine.MP)return true; else {
		cout << "能量不足，请重新选择" << endl; return false;
	}
}

int ATKselect(Pokemon& Mine, Skill& skill_mine) {	//攻击技能选择
	int selection;
	system("cls");
	Mine.InfoDisplayer_Liter();
	cout << "1. 攻击技能 1：" << endl;
	Mine.SkillDisplayer_Lite(1);
	cout << "2. 攻击技能 2：" << endl;
	Mine.SkillDisplayer_Lite(2);
	cout << "3. 攻击技能 3：" << endl;
	Mine.SkillDisplayer_Lite(3);
	cout << "0. 返回" << endl;
ATKselect_Start:
	clearInputBuffer();
	selection = getmenuchoice(3);
	switch (selection)
	{
	case 1: { if (SkillCertify(Mine, Mine.SkillSelector(1))) { skill_mine = Mine.SkillSelector(1); return 1; } else goto ATKselect_Start; }
	case 2: { if (SkillCertify(Mine, Mine.SkillSelector(2))) { skill_mine = Mine.SkillSelector(2); return 1; } else goto ATKselect_Start; }
	case 3: { if (SkillCertify(Mine, Mine.SkillSelector(3))) { skill_mine = Mine.SkillSelector(3); return 1; } else goto ATKselect_Start; }
	case 0:   return 0;
	default:goto ATKselect_Start;
		break;
	}
}

int DEFselect(Pokemon& Mine, Skill& skill_mine) {	//防御技能选择
	int selection;
	system("cls");
	Mine.InfoDisplayer_Liter();
	cout << "1. 防御技能 1：" << endl;
	Mine.SkillDisplayer_Lite(4);
	cout << "2. 防御技能 2：" << endl;
	Mine.SkillDisplayer_Lite(5);
	cout << "0. 返回" << endl;
DEFselect_Start:
	clearInputBuffer();
	selection = getmenuchoice(2);
	switch (selection)
	{
	case 1: { if (SkillCertify(Mine, Mine.SkillSelector(4))) { skill_mine = Mine.SkillSelector(4); return 1; } else goto DEFselect_Start; }
	case 2: { if (SkillCertify(Mine, Mine.SkillSelector(5))) { skill_mine = Mine.SkillSelector(5); return 1; } else goto DEFselect_Start; }
	case 0:   return 0;
	default:goto DEFselect_Start;
		break;
	}
}

bool Win_During(Pokemon& Mine, Pokemon& Enemy) {
	if (Mine.HPgetter() && Enemy.HPgetter())return true; else return false;
}

int DODselect(Pokemon& Mine, Skill& skill_mine) {	//闪避技能选择
	int selection;
	system("cls");
	Mine.InfoDisplayer_Liter();
	cout << "1. 闪避技能 1：" << endl;
	Mine.SkillDisplayer_Lite(6);
	cout << "0. 返回" << endl;
DODselect_Start:
	clearInputBuffer();
	selection = getmenuchoice(1);
	switch (selection)
	{
	case 1: { if (SkillCertify(Mine, Mine.SkillSelector(6))) { skill_mine = Mine.SkillSelector(6); return 1; } else goto DODselect_Start; } 
	case 0:   return 0;
	default:goto DODselect_Start;
		break;
	}
}

bool Win_During(Pokemon& Mine, Pokemon& Enemy) {	//战斗中胜负判定
	if (Mine.HPgetter() && Enemy.HPgetter())return true; else return false;
}

bool DODCertify(Pokemon& Mine, Skill skill_mine) {
	int num;
	num = Mine.DODgetter() * 100 + skill_mine.DOD * 100;
	if (num >= RandomNumber(100))return true;
	else return false;
}

void HPadder_Skill(Pokemon& Mine, Skill skill_mine) {
	Mine.HPadder(skill_mine.HP);
}
