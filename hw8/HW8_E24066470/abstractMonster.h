#ifndef ABSTRACTMONSTER_H
#define ABSTRACTMONSTER_H
#include"generalPlayer.h"

#include<iostream>
#include<string>

using namespace std;
class GeneralPlayer;
class AbstractMonster
{
public:
	AbstractMonster();
	AbstractMonster(string, int, int, int, int, int);//normal contructor
	~AbstractMonster();//destructor

	void setHP(int);
	int getHP() const;
	void setMP(int);
	int getMP() const;

	virtual void attackTo(GeneralPlayer*) = 0;//pure virtual function
	void display(void);

	const string name;
	const int attack;
	const int defense;
	const int exp;
	const int max_hp;
	const int max_mp;

	static int count;

private:
	int hp;
	int mp;
};

#endif