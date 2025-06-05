
#include "Pokemonclass.h"
#include "Fight.h"
#include <cstdlib>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

void Fight_Start(string accounts) {

	cout << "请选择要出战的宝可梦：" << endl;

}

int Fight_During(Pokemon& Mine, Pokemon& Enemy) {
	int selection = 0;
	Skill skill_mine = { 0 }, skill_enemy = { 0 };
FightDuring_Start:
	system("cls");
	cout << "1. 攻击技能" << endl;
	cout << "2. 防御技能" << endl;
	cout << "3. 闪避技能" << endl;
	cout << "4. 药品" << endl;
	cout << "5. 精灵球" << endl;
	cout << "6. 逃跑" << endl;
	cout << "请输入对应数字：";
	cin >> selection;
	switch (selection)
	{
	case 1:; break;
	case 2:; break;
	case 3:; break;
	case 4:; break;
	case 5:; break;
	case 6:; break;
	default:cout << "请输入正确的操作数字！" << endl; goto FightDuring_Start;
	}
	return int(0);
}