#include"knightPlayer.h"
#include<iostream>
#include<string>

using namespace std;

KnightPlayer::KnightPlayer()//default constructor
{
	setLevel(1);
	setName("knightplayer");
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(0);
}

KnightPlayer::KnightPlayer(int in_level)//level cnstructor
{
	setLevel(in_level);
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(0);
	setName("knightplayer");
}

KnightPlayer::KnightPlayer(int in_level, string in_name)//初始化
{
	setLevel(in_level);
	setName(in_name);
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(0);
}

KnightPlayer::KnightPlayer(const KnightPlayer& input)//copy constructor
{
	int l, a;
	l = input.getLevel();
	a = input.getAttr();
	setLevel(l);
	setAttr(a);
}

void KnightPlayer::levelUp(void)
{
	int level;
	level = this->level + 1;
	setLevel(level);
}

void KnightPlayer::setLevel(int in_level)
{
	this->level = in_level;
	setAttr(in_level);
	setDef(in_level);
	setMaxMP(in_level);
	setMaxHP(in_level);
	setLVupExp(in_level);
}

int KnightPlayer::getLevel(void) const
{
	return level;
}

void KnightPlayer::setAttr(int in_level)
{
	this->attack = 40 + 10 * in_level;
}

int KnightPlayer::getAttr(void) const
{
	return attack;
}

void KnightPlayer::setDef(int in_level)
{
	this->defense = 20 + 12 * in_level;
}

int KnightPlayer::getDef(void) const
{
	return defense;
}

void KnightPlayer::setMaxHP(int in_level)
{
	this->max_hp = 150 + 25 * in_level;
}

int KnightPlayer::getMaxHP(void) const
{
	return max_hp;
}

void KnightPlayer::setMaxMP(int in_level)
{
	this->max_mp = 70 + 10 * in_level;
}

int KnightPlayer::getMaxMP(void) const
{
	return max_mp;
}

void KnightPlayer::setLVupExp(int in_level)
{
	this->lvup_exp = ceil(pow(10, log2(in_level + 1)));
}

int  KnightPlayer::getLVupExp(void) const
{
	return lvup_exp;
}

void KnightPlayer::heal(void)//減少mp,增加hp
{
	int hp, mp;
	hp = getHP() + level * 10;
	mp = getMP() - level * 5;

	setHP(hp);
	setMP(mp);
}

void KnightPlayer::specialSkill()
{
	heal();
}

