
#include "Pokemonclass.h"
#include "Fight.h"
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
FightDuring_Start:
	system("cls");
	cout << "1. ��������" << endl;
	cout << "2. ��������" << endl;
	cout << "3. ���ܼ���" << endl;
	cout << "4. ҩƷ" << endl;
	cout << "5. ������" << endl;
	cout << "6. ����" << endl;
	cout << "�������Ӧ���֣�";
	cin >> selection;
	switch (selection)
	{
	case 1:; break;
	case 2:; break;
	case 3:; break;
	case 4:; break;
	case 5:; break;
	case 6:; break;
	default:cout << "��������ȷ�Ĳ������֣�" << endl; goto FightDuring_Start;
	}
	return int(0);
}