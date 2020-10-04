#include"Header.h"
#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int Matrix::count = 0;//初始化count

Matrix::Matrix()//將data存入2*2皆為零
{
	data = new double*[2];
	for (int i = 0; i < 2; i++)
	{
		data[i] = new double[2];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			data[i][j] = 0;
		}
	}
	count++;
}

Matrix::Matrix(int row, int col)//設定大小，並使初始為零
{
	setUp(row, col);

	data = new double*[row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new double[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = 0;
		}
	}
	count++;
}

Matrix::Matrix(int row, int col, double input[], int valume)
{
	setUp(row, col);

	data = new double*[row];//new data
	for (int i = 0; i < row; i++)
	{
		data[i] = new double[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = 0;
		}
	}

	double *copy_input = new double[valume];
	for (int i = 0; i < valume; i++)
	{
		copy_input[i] = input[i];
	}

	double in;
	bool stop = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			in = copy_input[0];
			//cout << "data[" << i << "][" << j << "] = "<<in<<endl;

			setData(i, j, in);//將值放入data
			getData(i, j);

			for (int k = 0; k < valume - 1; k++)//每放入一個值，就將傳入的一維矩陣縮小
			{ 
				if (valume == 1)//當縮減到一時bool=1
				{
					stop = 1;
					break;
				}

				copy_input[k] = copy_input[k + 1];//將原先後一個的值放入前一個
				if (k == valume - 2)//當讀取到最後一格，下一格是null時，表示已經到底，使一維矩陣縮小
				{
					copy_input[valume - 1] = NULL;
					valume = valume - 1;
				}
			}
		}
		//cout << endl;
		if (stop == 1)
			break;
	}
	count++;
}

istream &operator>>(istream &input, Matrix &m4)//input data
{
	int r, c,size;
	r = m4.row;
	c = m4.col;
	size = r * c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			input >> m4.data[i][j];
		}
	}
	return input;
}

ostream &operator<<(ostream &output,const Matrix&in_m)//output data
{
	int r, c;
	r = in_m.row;
	c = in_m.col;

	cout << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << in_m.data[i][j]<<" ";
		}
		cout << endl;
	}
	return output;
}

Matrix Matrix::operator+(const Matrix& in_m)//+ operator
{
	Matrix add_m(row, col);

	if (in_m.row == row && in_m.col == col)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				add_m.data[i][j] = in_m.data[i][j] + data[i][j];
		}
	}
	else//防呆
		cout << "error !!!" << endl;

	return add_m;
}

Matrix Matrix::operator+(double in_d)//+ operator,plus a double
{
	Matrix add_m(row, col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			add_m.data[i][j] = in_d + data[i][j];
		}
	}

	return add_m;
}

Matrix Matrix::operator*(const Matrix&in_m)//multiply * operator
{
	Matrix mul_m(row, in_m.col);
	vector<double> a;
	double last = 0;

	if (col == in_m.row)
	{
		for (int j = 0; j < in_m.col; j++)
		{
			for (int i = 0; i < row; i++)
			{
				for (int m = 0; m < col; m++)
					a.push_back(data[i][m] * in_m.data[m][j]);
				for (int n = 0; n < a.size(); n++)
					last = last + a[n];
				mul_m.data[i][j] = last;
				a.clear();
				last = 0;
			}
		}
	}
	else
		cout << "error !!!" << endl;

	return mul_m;
}

Matrix Matrix::operator()()//transpose () operator
{
	Matrix trans_m(row, col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			trans_m.data[i][j] = data[j][i];
		}
	}

	return trans_m;
}

Matrix Matrix::operator++(int)//operator ++,all plus 1
{
	int add = 1;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//cout << "initial"<<data[i][j]<<" ";
			data[i][j] = add + data[i][j];
			//cout << "after"<<data[i][j] << " ";
		}
		cout << endl;
	}

	return *this;
}

const Matrix &Matrix::operator+=(const Matrix&in_m)
{
	*this = *this + in_m;
	return *this;
}

bool Matrix::operator==(const Matrix&in_m) const
{
	if (row != in_m.row || col != in_m.col)
		return false;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (data[i][j] != in_m.data[i][j])
				return false;
		}
	}

	return true;
}

const Matrix &Matrix::operator=(const Matrix&in_m)//= operator
{
	if (&in_m != this)//檢查記憶體位置是否相同
	{
		if (row != in_m.row || col != in_m.col)
		{
			for (int i = 0; i < row; i++)
			{
				delete[] data[i];
			}
			delete[] data;
			row = in_m.row;
			col = in_m.row;

			data = new double*[row];//new data
			for (int i = 0; i < row; i++)
			{
				data[i] = new double[col];
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				data[i][j] = in_m.data[i][j];
			}
		}
	}
	return *this;
}

Matrix::Matrix(const Matrix &input)//copy constructor
{
	Matrix copy;
	int r, c;
	r = input.row;
	c = input.col;

	setUp(r, c);

	data = new double*[r];
	for (int i = 0; i < r; i++)
	{
		data[i] = new double[c];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data[i][j] = input.data[i][j];
		}
	}
	count++;
	//cout << "\ncount" << count << endl;
}

void Matrix::setUp(int col, int row)//設定row和col
{
	this->col = col;
	this->row = row;
}

int Matrix::getRow() const
{
	return row;
}

int Matrix::getCol() const
{
	return col;
}

void Matrix::setData(int row, int col, double num)//設定data內的值
{
	data[row][col] = num;
}

double Matrix::getData(int row, int col) const
{
	return data[row][col];
}
int Matrix::getCount()
{
	return count;
}

Matrix::~Matrix()//destructor
{
	cout << "destructor called" << endl;
	//cout << "\ncount" << count << endl;
	for (int i = 0; i < row; i++)
	{
		delete[] this->data[i];
	}
	delete[] data;
	count--;
}