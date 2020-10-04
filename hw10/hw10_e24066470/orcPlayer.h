#pragma once
#ifndef ORCPLAYER_H
#define ORCPLAYER_H

#include"generalPlayer.h"
#include<iostream>
#include<string>

using namespace std;

class OrcPlayer :public GeneralPlayer
{
public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	~OrcPlayer();

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
};
#endif

