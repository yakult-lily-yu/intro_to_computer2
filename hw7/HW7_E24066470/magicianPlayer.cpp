#include"magicianPlayer.h"
#include<iostream>
#include<string>

using namespace std;

MagicianPlayer::MagicianPlayer()//default constructor
{
	setLevel(1);
	setName("orcplayer");
}

MagicianPlayer::MagicianPlayer(int in_level)//level cnstructor
{
	setLevel(in_level);
	setName("orcplayer");
}

MagicianPlayer::MagicianPlayer(int in_level, string in_name)//初始化
{
	setLevel(in_level);
	setName(in_name);
}

MagicianPlayer::MagicianPlayer(const MagicianPlayer& input)//copy constructor
{
	int l, a;
	l = input.getLevel();
	a = input.getAttr();
	setLevel(l);
	setAttr(a);
}

void MagicianPlayer::levelUp(void)
{
	int level;
	level = this->level + 1;
	setLevel(level);
}

void MagicianPlayer::setLevel(int in_level)
{
	this->level = in_level;
	setAttr(in_level);
	setDef(in_level);
	setMaxMP(in_level);
	setMaxHP(in_level);
	setLVupExp(in_level);
}

int MagicianPlayer::getLevel(void) const
{
	return level;
}

void MagicianPlayer::setAttr(int in_level)
{
	this->attack = 30 + 8 * in_level;
}

int MagicianPlayer::getAttr(void) const
{
	return attack;
}

void MagicianPlayer::setDef(int in_level)
{
	this->defense = 20 + 7 * in_level;
}

int MagicianPlayer::getDef(void) const
{
	return defense;
}

void MagicianPlayer::setMaxHP(int in_level)
{
	this->max_hp = 120 + 15 * in_level;
}

int MagicianPlayer::getMaxHP(void) const
{
	return max_hp;
}

void MagicianPlayer::setMaxMP(int in_level)
{
	this->max_mp = 100 + 15 * in_level;
}

int MagicianPlayer::getMaxMP(void) const
{
	return max_mp;
}

void MagicianPlayer::setLVupExp(int in_level)
{
	this->lvup_exp = ceil(pow(10, log2(in_level + 1)));
}

int  MagicianPlayer::getLVupExp(void) const
{
	return lvup_exp;
}

void MagicianPlayer::pray(void)//減少hp，增加mp
{
	int hp, mp;
	hp = getHP() - level * 5;
	mp = getMP() + level * 10;

	setHP(hp);
	setMP(mp);
}