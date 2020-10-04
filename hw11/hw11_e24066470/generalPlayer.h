#pragma once
#ifndef GENERALPLAYER_H
#define GENERALPLAYER_H
#include"abstractMonster.h"
#include"item.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;
class AbstractMonster;
class GeneralPlayer
{
public:
	GeneralPlayer(); // default constructor, with level = 1, name = ¡§anonymous¡¨
	GeneralPlayer(int); // normal constructor, initializes level of the player, name = ¡§anonymous¡¨
	GeneralPlayer(int, string); // normal constructor, initializes level  and name of the player
	GeneralPlayer(const GeneralPlayer&); //Copy constructor. Call setAttr() in setLevel() to set attributes
	~GeneralPlayer();

	void setName(string);
	string getName(void) const;
	void setLevel(int); // need to call setAttr() inside
	int getLevel(void) const;
	int getHP();
	void setHP(int);
	int getMP();
	void setMP(int);
	int getExp();
	void setExp(int);
	virtual void setAttr(int);
	int getAttr(void) const;
	void setDef(int);
	int getDef(void) const;

	void setMaxHP(int);
	int getMaxHP(void) const;
	void setMaxMP(int);
	int getMaxMP(void) const;
	void setLVupExp(int);
	int getLVupExp(void) const;
	void setMoney(int);
	int getMoney();

	void levelUp(void);
	void increaseHP(int);
	void increaseMP(int);
	void increaseExp(int);
	void recoverHP(void); // hp = max_hp;
	void recoverMP(void); // mp = max_mp;

	void attackTo(AbstractMonster*);

	virtual void specialSkill();
	string serialize();
	void unserialize(string);

	void setItembag(item*);
	vector<item*>getItembag();
	void setBag_weight();
	int getBag_weight();
	void setMax_weight(int);
	int getMax_weight();
	void set_equipt(item*);
	vector<item*>get_equipt();
	vector<item*>itembag;
	vector<item*>equipt;

	void bag_display();
	void equipt_display();

	void display();

private:
	string name; // Stores the name of the player
	int hp; // Stores the HP of the player, >= 0
	int mp;// Stores the MP of the player, >= 0
	int exp; // Stores the experience of the player, >= 0. Will not reset to zero after level-up
	int bag_weight;//bag weight
	int max_weight;

protected:
	int level; // Stores the level of the player, >= 1
	int attack; // stores attack of the player
	int defense; // stores defense of the player
	int max_hp; // stores max. HP of the player
	int max_mp; // stores max. MP of the player
	int lvup_exp; // stores needed exp. to level-up
	int money;//represents the number of money,>=0
};


#endif


