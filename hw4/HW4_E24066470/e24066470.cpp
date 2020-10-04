#include"e24066470.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>

using namespace std;
vector<vector<string>> maze::mydata;//全域變數mydata
int maze::treasure_count=0;//紀錄寶石數量
int maze::start_x;
int maze::start_y;

string passed_true = "X";//確定正確的路
string tried = " ";//嘗試過的路
vector<vector<int>>contain_treasure;
vector<int>in_contain_treasure;

void maze::readmap(string filename)//開檔，讀檔
{
	fstream datafile;
	datafile.open(filename,ios::in);//開檔
	vector<string> in_mydata;

	while (!datafile.good())//防輸入錯誤檔名
	{
		cout << "read file error !!!" << endl;
		cout << "please input the filename again:";
		cin >> filename;
		cout << endl;
		datafile.open(filename, ios::in);
	}
	if (datafile.is_open())//讀檔
	{
		string line,word;
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
	mydata.erase(mydata.begin());//清除標示大小的第一行
}

void maze::find_start(vector<vector<string>> data)//找出终點位置
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			if (data[i][j] == "201")
			{
				start_x = j;
				start_y = i;
				//cout << i << j << endl;
			}
		}
	}
	/*
	int*start = new int[2] ;
	start[0] = start_x;
	start[1] = start_y;
	return start;
	*/
}
/*
void maze::start( int start_x, int start_y)//使起點為X
{
	mydata[start_y][start_x] = "X";
}*/

bool maze::move(int x, int y)//走地圖
{
	bool done = false;
	if (valid(x, y)==true)
	{
		if (mydata[y][x] == "200")//走到則bool=true
		{
			done = true;
			//cout << "done true" << endl;
		}
		else if (done == false)
		{
			if (mydata[y][x] >="202")//計算走過的寶物
			{
				in_contain_treasure.push_back(y);
				in_contain_treasure.push_back(x);
				contain_treasure.push_back(in_contain_treasure);
				in_contain_treasure.clear();
;				treasure_count++;
			}
			mydata[y][x] = tried;
			if (mydata[y][x] >= "202")
			{
				mydata[y][x] = "*";
			}
			//cout << "tried" << endl;
			//cout << "moving down" << endl;
			done = move(x+1 , y);
			if (!done)
			{
				//cout << "moving right" << endl;
				done = move(x, y+1);
			}
			if (!done)
			{
				//cout << "mving up" << endl;
				done = move(x, y - 1);
			}
			if (!done)
			{
				//cout << "moving lift" << endl;
				done = move(x - 1, y);
			}
		}
		
		if (done)//如果確定是對的，改變值
		{
			//cout << "done3" << endl;
			mydata[y][x] = passed_true;
			printmap(mydata);
			system("pause");
			system("cls");
		}
	}
	return done;
}

bool maze::valid(int x, int y)//判斷是否為牆壁與是否為走過的
{
	bool result = false;
	if (y >= 0 && y < mydata.size() && x >= 0 && x < mydata[y].size())
		if (mydata[y][x] != "1" && mydata[y][x]!=tried )
			result = true;
	//cout << "valid" << endl;
	return result;
}

void maze::printmap(vector<vector<string>> data)//印出檔案
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			if (data[i][j] == "0")
			{
				data[i][j] = " ";
			}
			else if (data[i][j] == "200")
			{
				data[i][j] = "S";
			}
			else if (data[i][j] == "201")
			{
				data[i][j] = "E";
			}
			else if (data[i][j] >= "202" && data[i][j] != passed_true)
			{
				data[i][j] = "*";
			}

			for (int k = 0; k < contain_treasure.size(); k++)//在未走到寶物前都顯現出寶物
			{
				if (i == contain_treasure[k][0] && j == contain_treasure[k][1] && data[i][j] != passed_true)
				{
					data[i][j] = "*";
				}
			}
			if (i == start_y && j == start_x && data[i][j] != passed_true && i!=0 && j!=0)
			{
				data[i][j] = "E";
			}
			cout << data[i][j]<<" ";
		}
		cout << endl;
	}
	//system("pause");
	//system("cls");
}