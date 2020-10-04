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

using namespace std;

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

private:
	bool valid(int x, int y);
	static int now_x;
	static int now_y;
};

#endif // !FIELD_H

