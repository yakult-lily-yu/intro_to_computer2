#ifndef MAGICIANPLAYER_H
#define MAGICIANPLAYER_H

#include"generalPlayer.h"
#include<iostream>
#include<string>

using namespace std;

class MagicianPlayer :public GeneralPlayer
{
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	void setLevel(int);
	int getLevel(void) const;
	void setAttr(int);
	int getAttr(void) const;
	void levelUp(void);
	void setDef(int);
	int getDef(void) const;

	void setMaxHP(int);
	int getMaxHP(void) const;
	void setMaxMP(int);
	int getMaxMP(void) const;
	void setLVupExp(int);
	int getLVupExp(void) const;

	void specialSkill();
	void pray(void);
};
#endif

