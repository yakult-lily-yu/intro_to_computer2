#include<iostream>
#include<vector>
#include<string>
#include"e24066470.h"

using namespace std;

int main()
{
	maze m;

	string filename;
	vector<vector<string>>move_data;
	//int *start;
	int a, b;
	cout << "please input the file name:";
	cin >> filename;
	//filename = "maze4.txt";

	cout << endl;
	m.readmap(filename);//讀檔
	m.printmap(maze::mydata);//印出初始檔案
	system("pause");
	system("cls");

	m.find_start(maze::mydata);//找出起點座標
	m.move(maze::start_x, maze::start_y);//走地圖
	cout << "======final answer======" << endl;
	m.printmap(maze::mydata);
	cout << "\n"<<"treasure number : " << maze::treasure_count<<endl;

	system("pause");
	return 0;
}