#include"weaponitem.h"

weaponitem::weaponitem()
	:item::item()
{
}

weaponitem::weaponitem(string name, int weight, string effect, string description, int level_required, char type)
	: item::item(name,weight,effect, description,level_required, type)
{
}

weaponitem::~weaponitem()
{
}

void weaponitem::setattack_plus(int attack)
{
	attack_increment = attack * 0.2;
}

int weaponitem::getattack_plus()
{
	return attack_increment;
}

void weaponitem::setexp_plus(int exp)
{
	exp_increment = exp * 0.1;
}

int weaponitem::getexp_plus()
{
	return exp_increment;
}

void weaponitem::setdef_reduce(int def)
{
	def_decrease = def * 0.15;
}

int weaponitem::getdef_reduce()
{
	return def_decrease;
}