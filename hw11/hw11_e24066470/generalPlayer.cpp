#include"generalplayer.h"
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<math.h>
#include<time.h>

using namespace std;
int w_count = 0;
int a_count = 0;

GeneralPlayer::GeneralPlayer()//default constructor
{
	setLevel(1);
	setMoney(20);
	setHP(max_hp);
	setMP(max_mp);
	setName("generalplayer");
	setExp(0);
}

GeneralPlayer::GeneralPlayer(int in_level)//初始化等級
{
	setLevel(in_level);
	setMoney(20);
	setHP(max_hp);
	setMP(max_mp);
	setName("generalplayer");
	setExp(0);
}

GeneralPlayer::GeneralPlayer(int in_level, string in_name)//初始化姓名及等級
{
	setLevel(in_level);
	setName(in_name);
	setMoney(20);
	setHP(max_hp);
	setMP(max_mp);
	setExp(0);
}

GeneralPlayer::~GeneralPlayer()
{
}

GeneralPlayer::GeneralPlayer(const GeneralPlayer& input)//copy constructor,copy level and attr(not finish)
{
	int l, a;
	l = input.level;
	a = input.attack;
	setLevel(l);
	setAttr(a);
}

void GeneralPlayer::display(void)
{
	cout << "==" << name << "==\n";
	cout << "level:" << level;
	cout << "   hp:" << hp;
	cout << "   mp:" << mp;
	cout << "   exp:" << exp;
	cout << "   attack:" << attack;
	cout << "   defense:" << defense << endl;
	//cout << "max_hp:  " << max_hp << endl;
	//cout << "max_mp:  " << max_mp << endl;
	//cout << "lvup_exp:" << lvup_exp << endl;
	cout << endl;
}

void GeneralPlayer::setItembag(item *in)
{
	itembag.push_back(in);
	
	setBag_weight();

	int throw_num;
	if (getBag_weight() > max_weight)
	{
		cout << "物品重量超過背包負荷 QAQ 請丟掉一些非必要物品 !!!" << endl;
		bag_display();
		cout << "請選擇所要丟去的東東:" << endl;
		cin >> throw_num;

		for (int i = 0; i < itembag.size(); i++)
		{
			if (throw_num == (i + 1))
				itembag.erase(itembag.begin()+i);
		}
	}
}

void GeneralPlayer::bag_display()
{
	cout << "您現在擁有的物品數:" << itembag.size() << endl;
	cout << "\n您現在所擁有的物品:";
	for (int i = 0; i < itembag.size(); i++)
	{
		cout << "[" << i + 1 << "]" << itembag[i]->name << "   ";
	}
	cout << endl;
}

vector<item*>GeneralPlayer::getItembag()
{
	return itembag;
}

void GeneralPlayer::setMax_weight(int level)
{
	max_weight = level * 5 + 1;
}

int GeneralPlayer::getMax_weight()
{
	return max_weight;
}

void GeneralPlayer::setBag_weight()
{
	int all_weight = 0;

	for (int i = 0; i < itembag.size(); i++)
	{
		all_weight += itembag[i]->weight;
	}
	bag_weight = all_weight;
}

int GeneralPlayer::getBag_weight()
{
	return bag_weight;
}

void GeneralPlayer::set_equipt(item* ii)
{
	equipt.push_back(ii);

	if (ii->type == 'w')
		w_count++;
	else if (ii->type == 'a')
		a_count++;

	int dont_need;
	if (w_count > 1)
	{
		cout << "裝備過多武器 !!! 請將其中一項放入背包 !" << endl;
		equipt_display();
		cout << "請輸入編號:";
		cin >> dont_need;
		setItembag(equipt[(dont_need - 1)]);//將物品放入背包
		equipt.erase(equipt.begin() + (dont_need + 1));//將物品解除裝備
	}
}

vector<item*> GeneralPlayer::get_equipt()
{
	return equipt;
}

void GeneralPlayer::equipt_display()
{
	for (int i = 0; i < equipt.size(); i++)
	{
		cout << "[" << i + 1 << "]" << equipt[i] << "   ";
	}
}

void GeneralPlayer::attackTo(AbstractMonster *in)//attack to
{
	int demage, ghp;

	if (this->attack<in->defense)
		ghp = in->getHP();
	else
	{
		int harm_up = (this->attack - in->defense) + (this->attack - in->defense)*0.1;//人攻擊減怪物的防禦
		int harm_down = (this->attack - in->defense) - (this->attack - in->defense)*0.1;
		//cout << harm_up << " " << harm_down << endl;

		srand(time(NULL));
		demage = rand() % (harm_up - harm_down + 1) + harm_down;//使最終傷害為傷害值範圍中隨機值

		ghp = in->getHP() - demage;
	}

	in->setHP(ghp);//設定abstracmonster剩下的hp

	if (in->getHP() <= 0)//殺死怪物後得到經驗值與錢錢
	{
		int exp_n = this->exp + in->exp;
		setExp(exp_n);
		int money_n = this->money + in->money;
		setMoney(money_n);
	}
}

void  GeneralPlayer::levelUp(void)//level++
{
	int level;
	level = this->level + 1;
	setLevel(level);
	//cout << "level up" << endl;
}

void  GeneralPlayer::increaseHP(int add_hp)//回血
{
	int hp;
	hp = this->hp + add_hp;
	setHP(hp);
}

void GeneralPlayer::increaseMP(int add_mp)//回魔
{
	int mp;
	mp = this->mp + add_mp;
	setMP(mp);
}

void GeneralPlayer::increaseExp(int add_exp)//增加經驗
{
	int exp;
	exp = this->exp + add_exp;
	if (exp > this->lvup_exp)
	{
		levelUp();
	}

	setExp(exp);
	//cout << "increase exp" << endl;
}

void GeneralPlayer::recoverHP(void)//使hp恢復最大
{
	int hp;
	hp = this->max_hp;
	setHP(hp);
}

void GeneralPlayer::recoverMP(void)//使mp恢復最大
{
	int mp;
	mp = this->max_mp;
	setMP(mp);
}

void GeneralPlayer::setHP(int in_hp)
{
	if (in_hp > max_hp)//當輸入的hp>max_hp時，hp=max_hp
		this->hp = max_hp;
	else
		this->hp = in_hp;
}

int GeneralPlayer::getHP()
{
	return hp;
}

void GeneralPlayer::setMP(int in_mp)
{
	if (in_mp > max_mp)//當輸入的mp>max_mp時，mp=max_mp
		this->mp = max_mp;
	else
		this->mp = in_mp;
}

int GeneralPlayer::getMP()
{
	return mp;
}

void GeneralPlayer::setExp(int in_exp)
{
	this->exp = in_exp;
}

int GeneralPlayer::getExp()
{
	return exp;
}

void GeneralPlayer::setAttr(int in_level)
{
	this->attack = 20 + 5 * in_level;
}

int GeneralPlayer::getAttr(void) const
{
	return attack;
}

void GeneralPlayer::setDef(int in_level)
{
	this->defense = 20 + 5 * in_level;
}

int GeneralPlayer::getDef(void) const
{
	return defense;
}

void  GeneralPlayer::setMaxHP(int in_level)
{
	this->max_hp = 100 + in_level * 10;
}

int  GeneralPlayer::getMaxHP(void) const
{
	return max_hp;
}

void  GeneralPlayer::setMaxMP(int in_level)
{
	this->max_mp = 40 + 5 * in_level;
}

int  GeneralPlayer::getMaxMP(void) const
{
	return max_mp;
}

void  GeneralPlayer::setLVupExp(int in_level)
{
	this->lvup_exp = ceil(pow(10, log2(in_level + 1)));
}

int  GeneralPlayer::getLVupExp(void) const
{
	return lvup_exp;
}

void GeneralPlayer::setName(string in_name)//setname
{
	this->name = in_name;
}

string GeneralPlayer::getName(void) const//getname
{
	return name;
}

void GeneralPlayer::setLevel(int in_level)//setlevel
{
	this->level = in_level;
	setDef(in_level);
	setAttr(in_level);
	setMaxMP(in_level);
	setMaxHP(in_level);
	setLVupExp(in_level);
}

int GeneralPlayer::getLevel(void) const//getlevel
{
	return level;
}

void GeneralPlayer::setMoney(int money_in)
{
	this->money = money_in;
}

int GeneralPlayer::getMoney()
{
	return money;
}

void GeneralPlayer::specialSkill()
{
}

string GeneralPlayer::serialize()
{
	string str = "$";
	string lv = to_string(getLevel());
	string hp = to_string(getHP());
	string mp = to_string(getMP());
	string exp = to_string(getExp());
	str += lv;
	str += "$";
	str += hp;
	str += "$";
	str += mp;
	str += "$";
	str += exp;
	return str;
}

void GeneralPlayer::unserialize(string in)
{
	string word;
	istringstream a(in);
	vector<int> data_member;
	while (getline(a, word, '$'))
	{
		data_member.push_back(atoi((word).c_str()));
	}
	this->level = data_member[0];
	this->hp = data_member[1];
	this->mp = data_member[2];
	this->exp = data_member[3];
}

