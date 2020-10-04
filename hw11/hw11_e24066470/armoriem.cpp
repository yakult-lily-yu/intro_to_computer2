#include"armoritem.h"

armoritem::armoritem()
	:item::item()
{
}

armoritem::armoritem(string name, int weight, string effect, string description, int level_required, char type)
	:item::item (name, weight, effect, description, level_required, type)
{
}

armoritem::~armoritem()
{
}

void armoritem::setdef_plus(int def)
{
	def_plus = def * 0.1;
}

int armoritem::getdef_plus()
{
	return def_plus;
}