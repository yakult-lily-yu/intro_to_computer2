#include"orcPlayer.h"
#include<iostream>
#include<string>

using namespace std;

OrcPlayer::OrcPlayer()//default constructor
{
	setLevel(1);
	setName("orcplayer");
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(0);
}

OrcPlayer::OrcPlayer(int in_level)//level cnstructor
{
	setLevel(in_level);
	setName("orcplayer");
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(0);
}

OrcPlayer::OrcPlayer(int in_level, string in_name)//ªì©l¤Æ
{
	setLevel(in_level);
	setName(in_name);
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(0);
}

OrcPlayer::~OrcPlayer()
{
}

OrcPlayer::OrcPlayer(const OrcPlayer& input)//copy constructor
{
	int l, a;
	l = input.getLevel();
	a = input.getAttr();
	setLevel(l);
	setAttr(a);
}

void OrcPlayer::levelUp(void)
{
	int level;
	level = this->level + 1;
	setLevel(level);
}

void OrcPlayer::setLevel(int in_level)
{
	this->level = in_level;
	setAttr(in_level);
	setDef(in_level);
	setMaxMP(in_level);
	setMaxHP(in_level);
	setLVupExp(in_level);
}

int OrcPlayer::getLevel(void) const
{
	return level;
}

void OrcPlayer::setAttr(int in_level)
{
	this->attack = 50 + 12 * in_level;
}

int OrcPlayer::getAttr(void) const
{
	return attack;
}

void OrcPlayer::setDef(int in_level)
{
	this->defense = 30 + 10 * in_level;
}

int OrcPlayer::getDef(void) const
{
	return defense;
}

void OrcPlayer::setMaxHP(int in_level)
{
	this->max_hp = 200 + 20 * in_level;
}

int OrcPlayer::getMaxHP(void) const
{
	return max_hp;
}

void OrcPlayer::setMaxMP(int in_level)
{
	this->max_mp = 50 + 5 * in_level;
}

int OrcPlayer::getMaxMP(void) const
{
	return max_mp;
}

void OrcPlayer::setLVupExp(int in_level)
{
	this->lvup_exp = ceil(pow(10, log2(in_level + 1)));
}

int  OrcPlayer::getLVupExp(void) const
{
	return lvup_exp;
}