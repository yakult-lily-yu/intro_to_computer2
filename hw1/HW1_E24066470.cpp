#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string filename;
	cout << "please input the filename:";//輸入檔名
	cin >> filename;
	//filename = "input.txt";

	fstream datafile;
	datafile.open(filename, ios::in);//開檔
	vector<vector<int>> mydata;
	vector<int> in_mydata;

	while (!datafile.good())
	{
		cout << "read file error !!!" << endl;
		cout << "please input the filename again:";
		cin >> filename;
		cout << endl;
		datafile.open(filename, ios::in);
	}
	if (datafile.is_open())//讀檔
	{
		string line, word;
		while (getline(datafile, line))
		{
			istringstream a(line);
			while (getline(a, word, ' '))
			{
				in_mydata.push_back(atoi((word).c_str()));
			}
			mydata.push_back(in_mydata);
			in_mydata.clear();
		}
	}

	/*for (int i = 0; i < mydata.size(); i++)//印出檔案
	{
		for (int j = 0; j < mydata[i].size(); j++)
		{
			cout << mydata[i][j] << " ";
		}
		cout << endl;
	}*/

	int answer_num;//紀錄並刪除答案數目
	answer_num = mydata[0][0];
	mydata.erase(mydata.begin());
	cout << "there are " << answer_num << " answers :" << endl;

	while (mydata.size()>0)
	{
		int element_num;//擁有的數字數目
		int quantity;//每次總共組數
		vector<vector<int>> deal;
		element_num = mydata[0][0];
		quantity = mydata[0][1];
		mydata.erase(mydata.begin());
		for (int i = 0; i < quantity; i++)//將大資料存入小資料中
		{
			deal.push_back(mydata[i]);
		}
		mydata.erase(mydata.begin(), mydata.begin() + quantity);//去掉mydata中已儲存於deal的組合

		int**save = new int*[element_num + 1];//宣布動態陣列紀錄相關數
		for (int i = 0; i < element_num; i++)
		{
			save[i] = new int[element_num];
		}

		for (int i = 0; i < element_num; i++)//初始化save
		{
			for (int j = 0; j < element_num; j++)
			{
				save[i][j] = 0;
			}
		}

		for (int i = 0; i < deal.size(); i++)//紀錄相關
		{
			int m, n;
			n = deal[i][0] - 1;
			m = deal[i][1] - 1;

			save[n][n] = -1;
			save[n][m] = -1;
			save[m][m] = -1;
			save[m][n] = -1;

			for (int j = 0; j < element_num; j++)
			{
				if (save[j][n] == -1)
					save[j][m] = -1;
				else if (save[j][m] == -1)
					save[j][n] = -1;
			}
		}

		int*num_counter = new int[element_num];//宣告計算最大群的一維動態陣列
		for (int i = 0; i < element_num; i++)//初始化num_counter
		{
			num_counter[i] = 0;
		}

		for (int i = 0; i < element_num; i++)//計算相關群體中最大的群
		{
			for (int j = 0; j < element_num; j++)
			{
				if (save[i][j] == -1)
					num_counter[i]++;
			}
		}

		int max;
		max = num_counter[0];
		for (int i = 0; i < element_num; i++)//找出最大群體有幾個人
		{
			if (num_counter[i] < num_counter[i + 1])
				max = num_counter[i + 1];
			else
				num_counter[i + 1] = max;
		}

		cout << max << endl;
		deal.clear();
	}
	
	system("pause");
	return 0;
}