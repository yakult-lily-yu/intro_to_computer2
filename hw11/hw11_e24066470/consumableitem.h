#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H

#include"item.h"
#include<iostream>
#include<string>

using namespace std;

class consumableitem :public item
{
public:
	consumableitem();
	consumableitem(string name = "止痛藥", int weight = 1, string effect = "正面效果:[1]增加血量 20% 若血量小於20則補充至20 \n負面效果:無", string description = "痛的時候來顆止痛藥吧!", int level_required = 1, char type = 'c');
	~consumableitem();

	void sethp_plus(int hp);
	int gethp_plus();
	int use(int);

	int hp_plus;
};
#endif
