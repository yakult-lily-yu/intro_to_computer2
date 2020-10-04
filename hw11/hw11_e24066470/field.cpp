#include"field.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>
#include<time.h>

using namespace std;

vector<vector<string>> field::mydata;//mydata
int field::treasure_count = 0;//treasure num
int field::end_x;
int field::end_y;
int field::now_x = 1;
int field::now_y = 1;
int meet_monster_count = 0;
vector<vector<string>> field::walk_data;

int monster_num = 0;
string passed_true = "X";
vector<vector<int>>contain_treasure;
vector<int>in_contain_treasure;

void field::readmap(string filename)//open file
{
	fstream datafile;
	datafile.open(filename, ios::in);
	vector<string> in_mydata;

	while (!datafile.good())
	{
		cout << "read file error !!!" << endl;
		cout << "please input the filename again:";
		cin >> filename;
		cout << endl;
		datafile.open(filename, ios::in);
	}
	if (datafile.is_open())//read file
	{
		string line, word;
		while (getline(datafile, line))
		{
			istringstream a(line);
			while (getline(a, word, ','))
			{
				in_mydata.push_back((word).c_str());
			}
			mydata.push_back(in_mydata);
			in_mydata.clear();
		}
	}
	mydata.erase(mydata.begin());//erase the first row
	walk_data = mydata;
	/*
	for (int i = 0; i < mydata.size(); i++)
	{
	for (int j = 0; j < mydata[i].size(); j++)
	{
	cout << mydata[i][j];
	}
	cout << endl;
	}
	*/
}

void field::find_start(vector<vector<string>> data)//找出终點位置
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			if (data[i][j] == "201")
			{
				end_x = j;
				end_y = i;
				//cout << i << j << endl;
			}
		}
	}
}

void field::monster_state()
{
	srand(time(NULL));
	monster_num = ((mydata[0].size() / 3));
	cout << "mon" << monster_num;
	int* monster_x = new int[(mydata[0].size() / 3)];
	int* monster_y = new int[(mydata[0].size() / 3)];
	int m, n;

	for (int i = 0; i < (mydata[0].size() / 3); i++)
	{
		monster_x[i] = rand() % (mydata[0].size());
		monster_y[i] = rand() % (mydata.size());

		while (walk_data[monster_y[i]][monster_x[i]] == "1" || walk_data[monster_y[i]][monster_x[i]] == "200" || walk_data[monster_y[i]][monster_x[i]] == "201")
		{
			monster_x[i] = rand() % (mydata[0].size());
			monster_y[i] = rand() % (mydata.size());
		}
		walk_data[monster_y[i]][monster_x[i]] = "-1";
	}
	for (int i = 0; i < (mydata[0].size() / 3); i++)
	{
		cout << monster_x[i] << " " << monster_y[i] << endl;
	}
}
/*
void field::set_battle_list()
{
	for (int i = 0; i < monster_num; i++)
	{
		GeneralPlayer GP;
		KnightPlayer KP;
		MagicianPlayer MP;
		OrcPlayer OP;
		GoblinMonster* GM = new GoblinMonster;
		ZombieMonster *ZM=new ZombieMonster;
		JWMonster *JW=new JWMonster;
		//battle B =new battle k(&GP, &KP, &MP, &OP, zm[meet_monster_count], gm[meet_monster_count], jw[meet_monster_count], 3, 3);

		gm.push_back(GM);
		zm.push_back(ZM);
		jw.push_back(JW);
		b.push_back(*B);
	}
}
*/
void field::move(void)
{
	srand(time(NULL));
	bool done = false;
	char way;
	int x, y;
	x = 1;
	y = 1;

	monster_state();//generate monster

	cout << "向上移動請輸入 \'w\',向右移動請輸入\'d\'t,向下移動請輸入\'s\',向左移動請輸入\'a\'" << endl;

	while (done == false)
	{
		GeneralPlayer GP;
		KnightPlayer KP;
		MagicianPlayer MP;
		OrcPlayer OP;

		if (valid(x, y) == true)
		{
			if (walk_data[y][x] == "-1")
			{
				cout << "危險危險 !!! 遇到敵人了 !!!" << endl;
				cout << "準備戰鬥 !!!" << endl;
				system("pause");

				GoblinMonster GM;
				ZombieMonster ZM;
				JWMonster JW;
				battle b(&GP, &KP, &MP, &OP, &ZM, &GM, &JW,3,3);

				b.fight();

				system("pause");
				system("cls");

				now_x = x;
				now_y = y;
				walk_data[now_y][now_x] = "X";
				system("cls");
				cout << "you are on (" << now_x << "," << now_y << ") now" << endl;
				printmap(walk_data);
				//cout << "若您想裝備武器或防護，請輸入\"E\"開啟背包" << endl;

				for (int i = 0; i < walk_data.size(); i++)//let previous x disappear
				{
					for (int j = 0; j < walk_data[i].size(); j++)
					{
						if (walk_data[i][j] == "X")
						{
							walk_data[i][j] = "0";
						}
					}
				}
				meet_monster_count++;
			}
			/*else if (walk_data[y][x] == "202")
			{
				
			}*/
			else
			{
				now_x = x;
				now_y = y;
				walk_data[now_y][now_x] = "X";

				system("cls");
				cout << "you are on (" << now_x << "," << now_y << ") now" << endl;
				printmap(walk_data);
				//cout << "若您想裝備武器或防護，請輸入\"E\"開啟背包" << endl;

				for (int i = 0; i < walk_data.size(); i++)//let previous x disappear
				{
					for (int j = 0; j < walk_data[i].size(); j++)
					{
						if (walk_data[i][j] == "X")
						{
							walk_data[i][j] = "0";
						}
					}
				}
			}
		}
		else if (valid(x, y) == false)
		{
			x = now_x;
			y = now_y;
			walk_data[now_y][now_x] = "X";

			system("cls");
			cout << "you are on (" << now_x << "," << now_y << ") now" << endl;
			printmap(walk_data);
			//cout << "若您想裝備武器或防護，請輸入\"E\"開啟背包" << endl;

			for (int i = 0; i < walk_data.size(); i++)
			{
				for (int j = 0; j < walk_data[i].size(); j++)
				{
					if (walk_data[i][j] == "X")
					{
						walk_data[i][j] = "0";
					}
				}
			}
		}
		

		if (mydata[y][x] == "201")
			done = true;

		if (done == true)
		{
			//cout << "break" << endl;
			break;
		}

		cin >> way;
		if (way == 'w' || way == 'W')
			y = now_y - 1;
		else if (way == 'd' || way == 'D')
			x = now_x + 1;
		else if (way == 's' || way == 'S')
			y = now_y + 1;
		else if (way == 'a' || way == 'A')
			x = now_x - 1;
		/*
		else if (way == 'e' || way == 'E')
		{
			int e_player;
			char e_item;

			/*
			battle.getplayers();
			for (int j = 0; j < battle.getPNum(); j++)
			{
				cout << "[" << j + 1 << "]" << battle.getplayers().size()->getName() << " ";
			}

			cout << "請選擇想要裝備的角色" << endl;
			cin >> e_player;

			GP.bag_display();
			cout << "輸入想要裝備的物品編號，若無，則輸入\"Q\"跳出" << endl;
			cin >> e_item;
			if (GP.getItembag()[e_item - 1]->type == 'w' || GP.getItembag()[e_item - 1]->type == 'a')//若型態非立即吸收的物品，放到裝備區
			{
				GP.set_equipt(GP.getItembag()[e_item - 1]);//物品裝備
				GP.itembag.erase(GP.itembag.begin() + (e_item - 1));//將物品從背包中消除
			}
			else if (GP.getItembag()[e_item - 1]->type == 'c')
			{
				GP.getItembag()[e_item - 1]->use(GP.getHP());
			}
		}
		*/
	}
}

bool field::valid(int x, int y)
{
	bool result = false;
	if (y >= 0 && y < mydata.size() && x >= 0 && x < mydata[y].size())
		if (mydata[y][x] != "1")
			result = true;
	//cout << "valid" << endl;
	return result;
}

void field::printmap(vector<vector<string>> data)
{
	int x_large, y_large, x_small, y_small;
	x_large = now_x + 3;
	y_large = now_y + 3;
	x_small = now_x - 2;
	y_small = now_y - 2;

	if (x_small < 0)
		x_small = 0;
	if (y_small < 0)
		y_small = 0;
	if (x_large > mydata[0].size())
		x_large = mydata[0].size();
	if (y_large > mydata.size())
		y_large = mydata.size();

	cout << " ========================\n" << endl;
	for (int i = y_small; i < y_large; i++)
	{
		cout << "|       ";
		for (int j = x_small; j < x_large; j++)
		{
			if (data[i][j] == "0")
				cout << "  ";
			else if (data[i][j] == "1")
				cout << "▉";
			else if (data[i][j] == "200")
				cout << " S";
			else if (data[i][j] == "201")
				cout << " E";
			else if (data[i][j] == "X")
				cout << " X";
			else if (data[i][j] >= "202")
				cout << " *";
			else if (data[i][j] == "-1")
				cout << " M";
		}
		cout << "       |";
		cout << endl;
	}
	cout << "\n ========================";
	cout << endl;
}

