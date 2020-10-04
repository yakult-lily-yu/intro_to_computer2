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
	weaponitem(string name = "���b", int weight = 4, string effect = "�����ĪG:[1]�����W�[ 25%   [2]�h��o10%�g���\n�t���ĪG:[1]���m���C15%", string description = "�ѯ��ȤΫC�ɻs�@�A�����A�G�Ӻ��¦p���A�]�]�A�G�Ϫ��a�b�W�[�����O���P�ɤ]�|���C���m�O�C", int level_required = 4, char type = 'w');
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
