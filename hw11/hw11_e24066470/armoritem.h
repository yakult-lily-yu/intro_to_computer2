#ifndef ARMORITEM_H
#define ARMORITEM_H
#include"item.h"
#include<iostream>
#include<string>

using namespace std;

class armoritem :public item
{
public:
	armoritem();
	armoritem(string name = "背心", int weight = 3, string effect = "正面效果:[1]防禦增加 10%\n負面效果:無", string description = "當今僅存於庫斯山中的庫斯熊皮所製成，能增加防禦力，此外一向被獵人視為幸運象徵。", int level_required = 1, char type = 'a');
	~armoritem();

	void setdef_plus(int def);
	int getdef_plus();

	int def_plus;
};

#endif // !ARMORITEM_H

