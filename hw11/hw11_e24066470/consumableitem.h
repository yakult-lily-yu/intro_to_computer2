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
	consumableitem(string name = "��h��", int weight = 1, string effect = "�����ĪG:[1]�W�[��q 20% �Y��q�p��20�h�ɥR��20 \n�t���ĪG:�L", string description = "�h���ɭԨ�����h�ħa!", int level_required = 1, char type = 'c');
	~consumableitem();

	void sethp_plus(int hp);
	int gethp_plus();
	int use(int);

	int hp_plus;
};
#endif
