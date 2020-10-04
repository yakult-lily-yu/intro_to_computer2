#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<string>

using namespace std;

class item
{
public:
	item();
	item(string, int, string, string, int, char);
	~item();

	int getWeight();
	void display();
	virtual int use(int);

	const int level_required;
	const int weight;
	const string name;
	const string effect;
	const string description;
	const char type;
};

#endif
