#pragma once
#ifndef ZOMBIEMONSTER_H
#define ZOMBIEMONSTER_H

#include"abstractMonster.h"
#include<iostream>
#include<string>

using namespace std;

class ZombieMonster :public AbstractMonster
{
public:
	ZombieMonster();
	ZombieMonster(string name = "Zombie", int exp = 17, int max_hp = 150, int max_mp = 30, int defense = 65, int attack = 50, int money = 35);//normal contructor
	~ZombieMonster();//destructor
					 /*
					 void setHP(int);
					 int getHP() const;
					 void setMP(int);
					 int getMP() const;
					 */

	virtual void attackTo(GeneralPlayer*);//pure virtual function
};

#endif


