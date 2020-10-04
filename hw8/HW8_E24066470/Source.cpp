#include"abstractMonster.h"
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

int AbstractMonster::count = 0;

AbstractMonster::AbstractMonster()
	:name("AbstractMonster"), max_hp(10), max_mp(10), attack(10), defense(10), exp(10)
{
	//cout << "count01 called" << endl;
	//count++;
}

AbstractMonster::AbstractMonster(string name, int exp, int max_hp, int max_mp,int defense, int attack)//default constructor
	:name(name),max_hp(max_hp),max_mp(max_mp),attack(attack),defense(defense),exp(exp)
{
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
	int harm_up = (this->attack - in->getDef())+ (this->attack - in->getDef())*0.1;//�Ǫ�������H�����m
	int harm_down= (this->attack - in->getDef()) - (this->attack - in->getDef())*0.1;
	//cout << harm_up << " " << harm_down << endl;
	
	srand(time(NULL));
	int demage = rand() % (harm_up - harm_down + 1) + harm_down;//�ϳ̲׶ˮ`���ˮ`�Ƚd���H����

	int g_hp = in->getHP() - demage;
	in->setHP(g_hp);//�]�wgeneralplayer�ѤU��hp
}

void AbstractMonster::display(void)
{
	cout << "name:" << name << endl;
	cout << "hp:" << hp << endl;
	cout << "mp:" << mp << endl;
	cout << "exp:" << exp << endl;
	cout << "attack:" << attack << endl;
	cout << "defense:" << defense << endl;
	cout << "max_hp:" << max_hp << endl;
	cout << "max_mp:" << max_mp << endl;
	cout << "\n" << endl;
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