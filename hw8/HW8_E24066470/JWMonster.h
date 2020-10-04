#ifndef JWMONSTER_H
#define JWMONSTER_H

#include"abstractMonster.h"
#include<iostream>
#include<string>

using namespace std;

class JWMonster :public AbstractMonster
{
public:
	JWMonster();
	JWMonster(string name = "JWHuang", int exp = 42, int max_hp = 250, int max_mp = 100, int defense = 100, int attack = 120);//normal contructor
	~JWMonster();//destructor
					 /*
					 void setHP(int);
					 int getHP() const;
					 void setMP(int);
					 int getMP() const;
					 */

	virtual void attackTo(GeneralPlayer*);//pure virtual function
};

#endif


