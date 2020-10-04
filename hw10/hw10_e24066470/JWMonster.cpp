#include"JWMonster.h"
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

JWMonster::JWMonster()
	:AbstractMonster::AbstractMonster()
{
	count++;
}

JWMonster::JWMonster(string name, int exp, int max_hp, int max_mp, int attack, int defense, int money)
	: AbstractMonster::AbstractMonster(name, exp, max_hp, max_mp, attack, defense, money)
{
	count++;
}

JWMonster::~JWMonster()
{
	count--;
	cout << "destructor" << endl;
}

void JWMonster::attackTo(GeneralPlayer*in)//attack to
{
	int n_hp = in->getHP()*1.1;//輪到殭屍時，自動增加hp和mp
	int n_mp = in->getMP()*1.05;
	if (n_hp > in->getMaxHP())//若大於最大HP則不變
	{
		n_hp = in->getMaxHP();
	}
	in->setHP(n_hp);
	if (n_mp > in->getMaxMP())//若大於最大MP則不變
	{
		n_mp = in->getMaxMP();
	}
	in->setMP(n_mp);

	int demage;
	bool superattack = 0;

	srand(time(NULL));

	superattack = rand() % 2;

	if (superattack == 0)
	{
		int harm_up = (this->attack - in->getDef()) + (this->attack - in->getDef())*0.1;//怪物攻擊減人的防禦
		int harm_down = (this->attack - in->getDef()) - (this->attack - in->getDef())*0.1;
		//cout << harm_up << " " << harm_down << endl;

		demage = rand() % (harm_up - harm_down + 1) + harm_down;//使最終傷害為傷害值範圍中隨機值
	}
	else if (superattack == 1)//superattack
	{
		int harm_up = (this->attack * 2 - in->getDef()) + (this->attack * 2 - in->getDef())*0.1;//怪物攻擊減人的防禦
		int harm_down = (this->attack * 2 - in->getDef()) - (this->attack * 2 - in->getDef())*0.1;

		demage = rand() % (harm_up - harm_down + 1) + harm_down;//使最終傷害為傷害值範圍中隨機值

		int s_mp = this->getMP() - 10;//減少mp
		setMP(s_mp);
	}

	int g_hp = in->getHP() - demage;
	in->setHP(g_hp);//設定generalplayer剩下的hp
}