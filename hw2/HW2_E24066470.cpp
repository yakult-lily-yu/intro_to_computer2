#include<iostream>
#include<time.h>
#include<vector>

using namespace std;

vector<int> x_remem;
vector<int> y_remem;
vector<vector<int>> save_input;//防呆設置
vector<int> in_save_input;

void open_surrounding(char**save_array, int in_x, int in_y, int input_length);

int main()
{
	int input_length, bombs_num;
	vector<vector<char>> initial;
	vector<char>in_initial;

	cout << "please input the length(10,20 or 30) you want:" << endl;//使用者輸入初始資料設定
	cin >> input_length;																 
	while (input_length != 10 && input_length != 20 && input_length != 30)
	{
		cout << "please input 10,20 or 30 !!!" << endl;
		cin >> input_length;
	}
	cout << "please input the number of bombs you want:" << endl;
	cin >> bmbs_num;
	while (bombs_num>(input_length*input_length))
	{
		cout << "please input the reasonable number !!!";
		cin >> bombs_num;
	}

	for (int i = 0; i < input_length; i++)//初始化vector
	{
		for (int j = 0; j < input_length; j++)
		{
			in_initial.push_back('?');
		}
		initial.push_back(in_initial);
	}

	for (int i = 0; i < input_length; i++)//印出初始表格
	{
		if (i + 1 >= 10)
		{
			cout << i + 1 << "   ";
		}
		else
			cout << i + 1 << "    ";
		for (int j = 0; j < input_length; j++)
		{
			cout << initial[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	char**save_array = new char*[input_length + 2];//宣告動態陣列儲存資料
	for (int i = 0; i <= (input_length + 1); i++)
	{
		save_array[i] = new char[input_length + 2];
	}
	for (int i = 0; i <= (input_length + 1); i++)
	{
		for (int j = 0; j <= (input_length + 1); j++)
		{
			if ((i == 0) || (i == input_length + 1)) {
				save_array[i][j] = 'w';
			}
			else if ((j == 0) || (j == input_length + 1)) {
				save_array[i][j] = 'w';
			}
			else {
				save_array[i][j] = '0';
			}
		}
	}

	/*print save array
	cout << "PRINT SAVE ARRAY\n";
	for(int i=0; i<input_length+2; i++){
	for(int j=0; j<input_length+2; j++){
	cout << save_array[i][j];
	}
	cout << "\n";
	}
	*/

	srand(time(NULL));//隨機放置炸彈位置
	int n, m;
	int bomb_count, around_count;
	bomb_count = 0;
	around_count = 1;
	while (bomb_count < bombs_num)
	{
		n = (rand() % (input_length)) + 1;
		m = (rand() % (input_length)) + 1;
		while (n == 0 || m == 0)
		{
			n = (rand() % (input_length)) + 1;
			m = (rand() % (input_length)) + 1;
		}
		while (save_array[n][m] == '*')
		{
			n = (rand() % (input_length)) + 1;
			m = (rand() % (input_length)) + 1;
		}
		save_array[n][m] = '*';
		bomb_count++;
	}

	for (int i = 1; i <= input_length; i++)//計算周圍炸彈數量
	{
		for (int j = 1; j <= input_length; j++)
		{
			if (save_array[i][j] == '*')
			{
				int a, b, a1, b1;
				a = i - 1;
				b = j - 1;
				a1 = i + 1;
				b1 = j + 1;
				for (int k = a; k <= a1; k++)
				{
					for (int g = b; g <= b1; g++)
					{
						if (save_array[k][g] != '0' && save_array[k][g] != '*' && save_array[k][g] != '1' && save_array[k][g] != '2' && save_array[k][g] != '3' && save_array[k][g] != '4' && save_array[k][g] != '5')
							continue;
						else if (save_array[k][g] != '0' && save_array[k][g] == '*')
							continue;
						else if (save_array[k][g] == '0')
							save_array[k][g] = '1';
						else if (save_array[k][g] == '1')
							save_array[k][g] = '2';
						else if (save_array[k][g] == '2')
							save_array[k][g] = '3';
						else if (save_array[k][g] == '3')
							save_array[k][g] = '4';
						else if (save_array[k][g] == '4')
							save_array[k][g] = '5';
						else if (save_array[k][g] == '5')
							save_array[k][g] = '5';
					}
				}
			}
		}
	}
	/*
	for (int i = 1; i <= input_length; i++)//印出測試
	{
		if (i >= 10)
		{
			cout << i << "   ";
		}
		else
			cout << i << "    ";
		for (int j = 1; j <= input_length; j++)
		{
			cout << save_array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/

	int in_x, in_y;//使用者輸入選擇的座標位置
	cout << "please input the place you want to open" << endl;
	cout << "x =";
	cin >> in_x;
	cout << "y =";
	cin >> in_y;
	
	bool had_walked = true;//判斷是否是已經開過的
	while (in_x<1 || in_x>(input_length + 1) || in_y<1 || in_y>(input_length + 1) || (had_walked == false))
	{
		cout << "please input the reasonable number !!!" << endl;
		cout << "x =";
		cin >> in_x;
		cout << "y =";
		cin >> in_y;

		for (int i = 0; i < save_input.size(); i++)
		{
			if (in_x == save_input[i][0] && in_y == save_input[i][1])
			{
				had_walked = false;
				break;
			}
			else
				had_walked = true;
		}
	}

	while (save_array[in_y][in_x] != '*')
	{
		int nuknow_count = 0;
		if (save_array[in_y][in_x] == '0')//若輸入位置為空白處
		{
			x_remem.clear();
			y_remem.clear();
			x_remem.push_back(in_x);
			y_remem.push_back(in_y);

			in_save_input.push_back(in_x);
			in_save_input.push_back(in_y);
			save_input.push_back(in_save_input);

			open_surrounding(save_array, in_x, in_y, input_length);
			/*
			cout << "PRINT save_array\n";
			for(int i=0; i<y_remem.size(); i++){
			cout << y_remem[i]<<","<<x_remem[i]<<endl;
			}*/
			for (int i = 0; i < x_remem.size(); i++)
			{
				initial[y_remem[i] - 1][x_remem[i] - 1] = save_array[y_remem[i]][x_remem[i]];
			}
		}
		else//若輸入位置為數字
		{
			in_save_input.push_back(in_x);
			in_save_input.push_back(in_y);
			save_input.push_back(in_save_input);
			in_save_input.clear();

			initial[in_y - 1][in_x - 1] = save_array[in_y][in_x];
		}

		for (int i = 0; i < input_length; i++)//若問號數量等於炸彈數，則表示成功跳出迴圈
		{
			for (int j = 0; j < input_length; j++)
			{
				if (initial[i][j] == '?')
					nuknow_count++;
			}
		}
		if (nuknow_count == bombs_num)
			break;

		for (int i = 0; i < input_length; i++)//印出initial
		{
			if (i + 1 >= 10)
			{
				cout << i + 1 << "   ";
			}
			else
				cout << i + 1 << "    ";
			for (int j = 0; j < input_length; j++)
			{
				cout << initial[i][j] << " ";
			}
			cout << endl;
		}
		cout << "please input the place you want to open" << endl;
		cout << "x =";
		cin >> in_x;
		cout << "y =";
		cin >> in_y;

		for (int i = 0; i < save_input.size(); i++)
		{
			if ((in_x == save_input[i][0]) && (in_y == save_input[i][1]))
			{
				had_walked = false;
				break;
			}
			else
				had_walked = true;
		}

		while (in_x<1 || in_x>(input_length + 1) || in_y<1 || in_y>(input_length + 1) || (had_walked==false))
		{
			cout << "please input the reasonable number !!!" << endl;
			cout << "x =";
			cin >> in_x;
			cout << "y =";
			cin >> in_y;
			for (int i = 0; i < save_input.size(); i++)
			{
				if (in_x == save_input[i][0] && in_y == save_input[i][1])
				{
					had_walked = false;
					break;
				}
				else
					had_walked = true;
			}
		}
	}

	if (save_array[in_y][in_x] == '*')//輸
	{
		cout << "\n     * * * * * *" << endl;
		cout << "       BOMB !!!" << endl;
		cout << "     * * * * * *" << endl;
		cout << "     you lose @@\n" << endl;

		for (int i = 1; i <= input_length; i++)//印出測試
		{
			if (i >= 10)
			{
				cout << i << "   ";
			}
			else
				cout << i << "    ";
			for (int j = 1; j <= input_length; j++)
			{
				cout << save_array[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else//贏
	{
		cout << "you find all of the bombs > <" << endl;
		cout << "congratulations !!!" << endl;
	}

	system("pause");
	return 0;
}

void open_surrounding(char**save_array, int in_x, int in_y, int input_length) //打開附近的區域
{
	//cout << "CHECK:"<<in_y<<","<<in_x<<endl;
	for (int i = in_y - 1; i <= in_y + 1; i++)
	{
		for (int j = in_x - 1; j <= in_x + 1; j++)
		{
			//看有沒有超出範圍
			if ((i>input_length + 1) || (j>input_length + 1)) {
				//cout << i<<','<<j<<" out of bound\n";
				continue;
			}
			//看之前有沒有找過
			bool explored = false;
			for (int k = 0; k<y_remem.size() - 1; k++)
			{
				if ((y_remem[k] == i) && (x_remem[k] == j))
				{
					//cout << "=>explored\n";
					explored = true;
				}
			}
			//cout << "check:"<<i<<","<<j<<"="<<save_array[i][j];
			//確定沒找過
			if (explored == false) {
				if (save_array[i][j] != '0' && save_array[i][j] != '*' && save_array[i][j] != '1' && save_array[i][j] != '2' && save_array[i][j] != '3' && save_array[i][j] != '4' && save_array[i][j] != '5') {
					//cout << " is wall\n";
					continue;
				}
				else if (((i != in_y) || (j != in_x)) && (save_array[i][j] == '1' || save_array[i][j] == '2' || save_array[i][j] == '3' || save_array[i][j] == '4' || save_array[i][j] == '5'))
				{
					y_remem.push_back(i);
					x_remem.push_back(j);

					in_save_input.push_back(j);
					in_save_input.push_back(i);
					save_input.push_back(in_save_input);
					in_save_input.clear();

					//cout<<" not 0;save y:"<<y_remem[y_remem.size()-1]<<",x:"<<x_remem[x_remem.size()-1]<<endl;
				}
				else if (((i != in_y) || (j != in_x)) && (save_array[i][j] == '0'))
				{
					y_remem.push_back(i);
					x_remem.push_back(j);

					in_save_input.push_back(j);
					in_save_input.push_back(i);
					save_input.push_back(in_save_input);
					in_save_input.clear();

					//cout<<" is 0;save y:"<<y_remem[y_remem.size()-1]<<",x:"<<x_remem[x_remem.size()-1]<<endl;
					//cout << "find next:"<<i<<','<<j<<endl;
					open_surrounding(save_array, j, i, input_length);
				}
			}
		}
	}
}
