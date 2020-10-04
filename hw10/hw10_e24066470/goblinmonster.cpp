#include"goblinmonster.h"
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

GoblinMonster::GoblinMonster()
	:AbstractMonster::AbstractMonster()
{
	count++;
}

GoblinMonster::GoblinMonster(string name, int exp, int max_hp, int max_mp, int attack, int defense, int money)
	: AbstractMonster::AbstractMonster(name, exp, max_hp, max_mp, attack, defense, money)
{
	count++;
}

GoblinMonster::~GoblinMonster()
{
	cout << "destructor" << endl;
	count--;
}

void GoblinMonster::attackTo(GeneralPlayer* in)//attack to
{
	int ghp, demage;
	if (this->attack<in->getDef())
		ghp = in->getHP();
	else
	{
		int harm_up = (this->attack - in->getDef()) + (this->attack - in->getDef())*0.1;//¤H§ðÀ»´î©Çª«ªº¨¾¿m
		int harm_down = (this->attack - in->getDef()) - (this->attack - in->getDef())*0.1;
		//cout << harm_up << " " << harm_down << endl;

		srand(time(NULL));
		demage = rand() % (harm_up - harm_down + 1) + harm_down;//¨Ï³Ì²×¶Ë®`¬°¶Ë®`­È½d³ò¤¤ÀH¾÷­È

		ghp = in->getHP() - demage;
	}
}
