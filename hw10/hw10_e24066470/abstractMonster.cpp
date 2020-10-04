#include"abstractMonster.h"
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<time.h>

using namespace std;

int AbstractMonster::count = 0;

AbstractMonster::AbstractMonster()
	:name("AbstractMonster"), max_hp(20), max_mp(20), attack(20), defense(20), exp(20), money(20)
{
	setHP(max_hp);
	setMP(max_mp);
	//cout << "count01 called" << endl;
	//count++;
}

AbstractMonster::AbstractMonster(string name, int exp, int max_hp, int max_mp, int defense, int attack, int money)//default constructor
	:name(name), max_hp(max_hp), max_mp(max_mp), attack(attack), defense(defense), exp(exp), money(money)
{
	setHP(max_hp);
	setMP(max_mp);
	//cout << "count01 called" << endl;
	//count++;
}

AbstractMonster::~AbstractMonster()//destructor
{
	//count--;
	//cout << "destructor" << endl;
}

void AbstractMonster::attackTo(GeneralPlayer* in)//attack to
{
	int harm_up = (this->attack - in->getDef()) + (this->attack - in->getDef())*0.1;//怪物攻擊減人的防禦
	int harm_down = (this->attack - in->getDef()) - (this->attack - in->getDef())*0.1;
	//cout << harm_up << " " << harm_down << endl;

	srand(time(NULL));
	int demage = rand() % (harm_up - harm_down + 1) + harm_down;//使最終傷害為傷害值範圍中隨機值

	int g_hp = in->getHP() - demage;
	in->setHP(g_hp);//設定generalplayer剩下的hp
}

void AbstractMonster::display(void)
{
	cout << "name:" << name << endl;
	cout << "hp:" << hp << endl;
	cout << "mp:" << mp << endl;
	//cout << "exp:" << exp << endl;
	cout << "attack:" << attack << endl;
	cout << "defense:" << defense << endl;
	//cout << "max_hp:" << max_hp << endl;
	//cout << "max_mp:" << max_mp << endl;
	cout << endl;
}

void AbstractMonster::setHP(int hp_in)
{
	this->hp = hp_in;
}

int AbstractMonster::getHP(void) const
{
	return hp;
}

void AbstractMonster::setMP(int mp_in)
{
	this->mp = mp_in;
}

int AbstractMonster::getMP(void) const
{
	return mp;
}

string AbstractMonster::serialize()
{
	string str = "$";
	string hp = to_string(getHP());
	string mp = to_string(getMP());
	str += hp;
	str += "$";
	str += mp;
	return str;
}

void AbstractMonster::unserialize(string in)
{
	string word;
	istringstream a(in);
	vector<int> data_member;
	while (getline(a, word, '$'))
	{
		data_member.push_back(atoi((word).c_str()));
	}
	this->hp = data_member[1];
	this->mp = data_member[2];
}