#include"zombieMonster.h"
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

ZombieMonster::ZombieMonster()
	:AbstractMonster::AbstractMonster("Zombie", 17, 150, 30, 65, 50, 35)
{
	count++;
}
/*
ZombieMonster::ZombieMonster(string name, int exp, int max_hp, int max_mp, int attack, int defense, int money)
	: AbstractMonster::AbstractMonster(name, exp, max_hp, max_mp, attack, defense, money)
{
	count++;
}
*/
ZombieMonster::~ZombieMonster()
{
	count--;
	cout << "destructor" << endl;
}

void ZombieMonster::attackTo(GeneralPlayer* in)//attack to
{
	int demage;
	bool superattack = 0;

	srand(time(NULL));

	superattack = rand() % 2;

	if (superattack == 0)
	{
		int harm_up = (this->attack - in->getDef()) + (this->attack - in->getDef())*0.1;//�Ǫ�������H�����m
		int harm_down = (this->attack - in->getDef()) - (this->attack - in->getDef())*0.1;
		//cout << harm_up << " " << harm_down << endl;

		demage = rand() % (harm_up - harm_down + 1) + harm_down;//�ϳ̲׶ˮ`���ˮ`�Ƚd���H����
	}
	else if (superattack == 1)//superattack
	{
		int harm_up = (this->attack * 2 - in->getDef()) + (this->attack * 2 - in->getDef())*0.1;//�Ǫ�������H�����m
		int harm_down = (this->attack * 2 - in->getDef()) - (this->attack * 2 - in->getDef())*0.1;

		demage = rand() % (harm_up - harm_down + 1) + harm_down;//�ϳ̲׶ˮ`���ˮ`�Ƚd���H����

		int s_mp = this->getMP() - 10;//���mp
		setMP(s_mp);
	}

	int g_hp = in->getHP() - demage;
	in->setHP(g_hp);//�]�wgeneralplayer�ѤU��hp
}
