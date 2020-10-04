#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include"generalPlayer.h"
#include"knightPlayer.h"
#include"magicianPlayer.h"
#include"orcPlayer.h"

#include"abstractMonster.h"
#include"goblinmonster.h"
#include"JWMonster.h"
#include"zombieMonster.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct
{
	char type;//monster 'm' or player 'p'
	bool alive;//判斷是否還活著
	void *instance;//pointer to instance
}character;

class battle
{
public:
	battle();//constructor
	battle(int, int);//constructor,input player number and monster number
	battle(GeneralPlayer*, KnightPlayer*, MagicianPlayer*, OrcPlayer*, ZombieMonster*, GoblinMonster*, JWMonster*, int, int);//construster

	void fight();
	void setPlayers(GeneralPlayer*, KnightPlayer*, MagicianPlayer*, OrcPlayer*);
	vector<GeneralPlayer*> getPlayers() const;
	void setMonsters(ZombieMonster*, GoblinMonster*, JWMonster*);
	vector<AbstractMonster*> getMonsters();
	void setAction_list(int);//人和怪物的攻擊順序
	character* getPlayer_condition();
	character* getMonster_condition();
	void display_end();

	void setPNum(int);
	int getPNum();
	void setMNum(int);
	int getMNum();
	void setTurnLimit();
	int getTurnLimit();

	vector<GeneralPlayer*> players;
	vector<AbstractMonster*> monsters;
	character* action_list;
	character* player_condition;
	character* monster_condition;

	static int dead_p_count;
	static int dead_m_count;

private:
	static int n_turn;
	int turn_limit;
	int monsterNum;
	int playerNum;

};



#endif // !BATTLE_H

