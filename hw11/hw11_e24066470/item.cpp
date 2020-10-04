#include"item.h"

using namespace std;

item::item()
	:name("item"),weight(2),effect("initial"),description("just innitual"),level_required(2),type('i')
{
}

item::item(string name,int weight,string effect,string description,int level_required,char type)
	:name(name), weight(weight), effect(effect), description(description), level_required(level_required), type(type)
{
}

item::~item()
{
}

int item::getWeight()
{
	return weight;
}

int item::use(int k)
{
	return 0;
}

void item::display()
{
	cout << "  " << name << "  " << endl;
	cout << "weight:" << weight;
	cout << "   effect:" << effect << endl;
	cout << description;
}
