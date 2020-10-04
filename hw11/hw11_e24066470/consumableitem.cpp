#include"consumableitem.h"

consumableitem::consumableitem()
	:item::item()
{
}

consumableitem::consumableitem(string name, int weight, string effect, string description, int level_required, char type)
	: item::item(name, weight, effect, description, level_required, type)
{
}

consumableitem::~consumableitem()
{
}

void consumableitem::sethp_plus(int hp)
{
	if (hp < 20)
	{
		hp_plus = 20 - hp;
	}
	else
	{
		hp_plus = hp * 0.2;
	}
}

int consumableitem::gethp_plus()
{
	return hp_plus;
}

int consumableitem::use(int hp)
{
	sethp_plus(hp);

	return hp + gethp_plus();
}