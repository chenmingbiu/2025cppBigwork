#pragma once
#include <string>
#include "Pokemonclass.h"  // 假设Pokemon类在此头文件中定义

// 战斗系统功能声明
void Fight_Start(std::string accounts);
int Fight_During(Pokemon& Mine, Pokemon& Enemy);
