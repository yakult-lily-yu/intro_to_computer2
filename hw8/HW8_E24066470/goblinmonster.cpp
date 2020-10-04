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

GoblinMonster::GoblinMonster(string name, int exp, int max_hp, int max_mp, int attack, int defense)
	:AbstractMonster::AbstractMonster(name,exp,max_hp,max_mp,attack,defense)
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
	int harm_up = (this->attack - in->getDef()) + (this->attack - in->getDef())*0.1;//�Ǫ�������H�����m
	int harm_down = (this->attack - in->getDef()) - (this->attack - in->getDef())*0.1;
	//cout << harm_up << " " << harm_down << endl;

	srand(time(NULL));
	int demage = rand() % (harm_up - harm_down + 1) + harm_down;//�ϳ̲׶ˮ`���ˮ`�Ƚd���H����

	int g_hp = in->getHP() - demage;
	in->setHP(g_hp);//�]�wgeneralplayer�ѤU��hp
}
