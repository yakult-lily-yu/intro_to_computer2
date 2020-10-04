#ifndef WEAPONITEM_H
#define WEAPONITEM_H
#include"item.h"
#include<iostream>
#include<string>

using namespace std;

class weaponitem:public item
{
public:
	weaponitem();
	weaponitem(string name = "墨刃", int weight = 4, string effect = "正面效果:[1]攻擊增加 25%   [2]多獲得10%經驗值\n負面效果:[1]防禦降低15%", string description = "由秘銀及青銅製作，曾受詛咒而漆黑如墨，也因詛咒使玩家在增加攻擊力的同時也會降低防禦力。", int level_required = 4, char type = 'w');
	~weaponitem();

	void setattack_plus(int attack);
	int getattack_plus();
	void setexp_plus(int exp);
	int getexp_plus();
	void setdef_reduce(int def);
	int getdef_reduce();

	int attack_increment;
	int exp_increment;
	int def_decrease;
};

#endif
