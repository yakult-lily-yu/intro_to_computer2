#pragma once
#ifndef FIELD_H
#define FIELD_H

#include<iostream>
#include<string>
#include<vector>

#include"abstractMonster.h"
#include"goblinmonster.h"
#include"knightPlayer.h"
#include"JWMonster.h"
#include"magicianPlayer.h"
#include"orcPlayer.h"
#include"zombieMonster.h"
#include"battle.h"
#include"item.h"
#include"consumableitem.h"
#include"armoritem.h"
#include"weaponitem.h"

using namespace std;

typedef struct
{
	char type;
	bool used;//判斷是否使用
	void *instence;
}item_information;

class field
{
public:
	static vector<vector<string>> mydata;
	static vector<vector<string>> walk_data;
	static int treasure_count;
	static int end_x;
	static int end_y;

	void readmap(string filename);
	void move(void);
	void find_start(vector<vector<string>> data);
	void printmap(vector<vector<string>> data);
	void monster_state(void);

	//void set_battle_list();//每次遇到敵人的constructer
	//void use_battle_list();

private:
	bool valid(int x, int y);
	static int now_x;
	static int now_y;
	int meet_monster_count;

	vector<GoblinMonster*>gm;
	vector<ZombieMonster*>zm;
	vector<JWMonster*>jw;
	vector<battle*>b;
};

#endif // !FIELD_H


