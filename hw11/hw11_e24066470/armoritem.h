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
	armoritem(string name = "�I��", int weight = 3, string effect = "�����ĪG:[1]���m�W�[ 10%\n�t���ĪG:�L", string description = "���Ȧs��w���s�����w�����֩һs���A��W�[���m�O�A���~�@�V�Q�y�H�������B�H�x�C", int level_required = 1, char type = 'a');
	~armoritem();

	void setdef_plus(int def);
	int getdef_plus();

	int def_plus;
};

#endif // !ARMORITEM_H

