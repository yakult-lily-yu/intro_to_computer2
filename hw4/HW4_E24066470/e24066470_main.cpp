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
	m.readmap(filename);//Ū��
	m.printmap(maze::mydata);//�L�X��l�ɮ�
	system("pause");
	system("cls");

	m.find_start(maze::mydata);//��X�_�I�y��
	m.move(maze::start_x, maze::start_y);//���a��
	cout << "======final answer======" << endl;
	m.printmap(maze::mydata);
	cout << "\n"<<"treasure number : " << maze::treasure_count<<endl;

	system("pause");
	return 0;
}