#include"field.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	field f;

	string filename;
	vector<vector<string>>move_data;
	int a, b;

	cout << "please input the file name:";
	filename = "maze4.txt";

	cout << endl;
	f.readmap(filename);//Ū��
	f.printmap(field::walk_data);//�L�X��l�ɮ�
	system("pause");

	f.move();

	system("pause");
	return 0;
}