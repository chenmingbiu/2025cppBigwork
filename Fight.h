#ifndef FIGHT_H
#define FIGHT_H

#include <string>
#include "Pokemonclass.h"

extern Account User;
extern back Userback;

void Fight_Start(std::string accounts);

int Fight_During(Pokemon& Mine, Pokemon& Enemy);

#endif 
