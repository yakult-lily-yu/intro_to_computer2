#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string filename;
	cout << "please input the filename:";//��J�ɦW
	cin >> filename;
	//filename = "input.txt";

	fstream datafile;
	datafile.open(filename, ios::in);//�}��
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
	if (datafile.is_open())//Ū��
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

	/*for (int i = 0; i < mydata.size(); i++)//�L�X�ɮ�
	{
		for (int j = 0; j < mydata[i].size(); j++)
		{
			cout << mydata[i][j] << " ";
		}
		cout << endl;
	}*/

	int answer_num;//�����çR�����׼ƥ�
	answer_num = mydata[0][0];
	mydata.erase(mydata.begin());
	cout << "there are " << answer_num << " answers :" << endl;

	while (mydata.size()>0)
	{
		int element_num;//�֦����Ʀr�ƥ�
		int quantity;//�C���`�@�ռ�
		vector<vector<int>> deal;
		element_num = mydata[0][0];
		quantity = mydata[0][1];
		mydata.erase(mydata.begin());
		for (int i = 0; i < quantity; i++)//�N�j��Ʀs�J�p��Ƥ�
		{
			deal.push_back(mydata[i]);
		}
		mydata.erase(mydata.begin(), mydata.begin() + quantity);//�h��mydata���w�x�s��deal���զX

		int**save = new int*[element_num + 1];//�ť��ʺA�}�C����������
		for (int i = 0; i < element_num; i++)
		{
			save[i] = new int[element_num];
		}

		for (int i = 0; i < element_num; i++)//��l��save
		{
			for (int j = 0; j < element_num; j++)
			{
				save[i][j] = 0;
			}
		}

		for (int i = 0; i < deal.size(); i++)//��������
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

		int*num_counter = new int[element_num];//�ŧi�p��̤j�s���@���ʺA�}�C
		for (int i = 0; i < element_num; i++)//��l��num_counter
		{
			num_counter[i] = 0;
		}

		for (int i = 0; i < element_num; i++)//�p������s�餤�̤j���s
		{
			for (int j = 0; j < element_num; j++)
			{
				if (save[i][j] == -1)
					num_counter[i]++;
			}
		}

		int max;
		max = num_counter[0];
		for (int i = 0; i < element_num; i++)//��X�̤j�s�馳�X�ӤH
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