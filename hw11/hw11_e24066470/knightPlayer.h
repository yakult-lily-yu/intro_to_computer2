#pragma once
#ifndef KNIGHTPLAYER_H
#define KNIGHTPLAYER_H

#include"generalPlayer.h"
#include<iostream>
#include<string>

using namespace std;

class KnightPlayer :public GeneralPlayer
{
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	~KnightPlayer();

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

	void display();
	void specialSkill();
	void heal(void);
	//void holy_attack(void);//¯«¸t¤@À»
};
#endif

