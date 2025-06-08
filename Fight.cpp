#include "teamwork.h"
#include "Pokemonclass.h"
#include "Fight.h"
#include "Item.h"
#include <cstdlib>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

void Fight_Start(string accounts) {

	cout << "��ѡ��Ҫ��ս�ı����Σ�" << endl;

}

int Fight_During(Pokemon& Mine, Pokemon& Enemy) {
	int selection = 0;
	Skill skill_mine = { 0 }, skill_enemy = { 0 };
	system("cls");
FightDuring_Start:
	cout << "�ҷ������Σ�" << endl;
	Mine.InfoDisplayer_Liter();
	cout << "�з������Σ�" << endl;
	Enemy.InfoDisplayer_Liter();
	cout << "����ѡ��" << endl;
	cout << "1. ��������" << endl;
	cout << "2. ��������" << endl;
	cout << "3. ���ܼ���" << endl;
	cout << "4. ҩƷ" << endl;
	cout << "5. ������" << endl;
	cout << "6. ����" << endl;
	cout << "�������Ӧ���֣�";
	clearInputBuffer();
	selection = getmenuchoice(6);
	switch (selection)
	{
	case 1: {
		if (ATKselect(Mine, skill_mine)) { Fight_Action(Mine, Enemy, skill_mine, skill_enemy); system("cls"); goto FightDuring_Start; }
		else goto FightDuring_Start;
	} break;
	case 2:; break;
	case 3:; break;
	case 4:; break;
	case 5:; break;
	case 6: { if (Fight_Escape())return 0; else { Escape_Fail(Mine, Enemy, skill_enemy); cout << "����ʧ��" << endl; goto FightDuring_Start; } };
	default: goto FightDuring_Start;
	}
	return 0;
}

bool Fight_Escape() {
	int num = 70;
	int Ran = RandomNumber(100);
	if (Ran <= num)return true;
	else return false;
}

void Fight_Action(Pokemon& Mine, Pokemon& Enemy, Skill skill_mine, Skill skill_enemy) {
	int damage;
	double DEFrate;	//�˺������ʣ�
	DEFrate =Enemy.DEFgetter() * skill_enemy.DEF / (45 + Enemy.DEFgetter() * skill_enemy.DEF);	//�˺�������=������ֵ/������+������ֵ��
	damage = Mine.ATKgetter() * skill_mine.ATK * (1 - DEFrate);
	Enemy.DAGmaker(damage); if (!Enemy.HPgetter())return;
	DEFrate = Mine.DEFgetter() * skill_mine.DEF / (45 + Mine.DEFgetter() * skill_mine.DEF);
	damage = Enemy.ATKgetter() * skill_enemy.ATK * (1 - DEFrate);
	Mine.DAGmaker(damage); return;
}

void Escape_Fail(Pokemon& Mine, Pokemon& Enemy, Skill skill_enemy) {
	int damage;
	double DEFrate;
	DEFrate = Mine.DEFgetter()/ (45 + Mine.DEFgetter());
	damage = Enemy.ATKgetter() * skill_enemy.ATK * (1 - DEFrate);
	Mine.DAGmaker(damage); return;
}

bool SkillCertify(Pokemon& Mine, Skill skill_mine) {	//���ܿ����Լ춨
	if (Mine.levelgetter() < skill_mine.level) {
		cout << "�ȼ����㣬������ѡ��" << endl; return false;
	}
	else if (Mine.MPgetter() >= skill_mine.MP)return true; else {
		cout << "�������㣬������ѡ��" << endl; return false;
	}
}

int ATKselect(Pokemon& Mine, Skill& skill_mine) {
	int selection;
	system("cls");
	Mine.InfoDisplayer_Liter();
	cout << "1. �������� 1��" << endl;
	Mine.SkillDisplayer_Lite(1);
	cout << "2. �������� 2��" << endl;
	Mine.SkillDisplayer_Lite(2);
	cout << "3. �������� 3��" << endl;
	Mine.SkillDisplayer_Lite(3);
	cout << "0. ����" << endl;
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