#ifndef TEAMWORK_H
#define TEAMWORK_H

#include "Pokemonclass.h"
#include "Item.h"
#include "Account.h"
#include "Fight.h"
#include <vector>
#include <string>

int getmenuchoice();
int getnumber(int max);
int RandomNumber(int);
void clearInputBuffer();
void savedata(Account& accounts, back& backs);
void readdata(Account& accounts, back& backs);
void place(Account& tempaccount, back& backs);
void game_begin(Account& tempaccount, back& backs);
void exitgame();

#endif