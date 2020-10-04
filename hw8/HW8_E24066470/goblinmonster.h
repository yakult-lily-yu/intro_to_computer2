#ifndef GOBLINMONSTER_H
#define GOBLINMONSTER_H

#include"abstractMonster.h"
#include<iostream>
#include<string>

using namespace std;

class GoblinMonster:public AbstractMonster
{
public:
	GoblinMonster();
	GoblinMonster(string name="Goblin", int exp=12, int max_hp=100, int max_mp=50, int attack=60, int defense = 40);//normal contructor
	~GoblinMonster();//destructor
	/*
	void setHP(int);
	int getHP() const;
	void setMP(int);
	int getMP() const;
	*/
	/*
	const string name;
	const int attack;
	const int defense;
	const int exp;
	const int max_hp;
	const int max_mp;
	*/

	virtual void attackTo(GeneralPlayer*);//pure virtual function
};

#endif
