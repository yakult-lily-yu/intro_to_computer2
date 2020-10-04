#include"Matrix.h"
#include<iostream>
#include<vector>

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
}

Matrix::matrix(int row, int col)//設定大小，並使初始為零
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
	//data[0][0] = 1;
}

Matrix::matrix(int row, int col, double input[], int valume)
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
}

Matrix::Matrix(const Matrix &input)//copy constructor
{
	Matrix copy;
	int r, c;
	r = input.row;
	c = input.col;

	setUp(r,c);

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
}

Matrix Matrix::add(const Matrix &input)//add
{
	Matrix add_m(row, col);

	if (input.row == row && input.col == col)
	{	
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				add_m.data[i][j] = input.data[i][j] + data[i][j];
				//cout << "add[" << i << "][" << j << "]=" << data[i][j] << "+" << input.data[i][j]<<endl;
			}
			//cout << endl;
		}
	}
	else//防呆
	{
		cout << "error !!!" << endl;
	}

	return add_m;
}

Matrix Matrix::multiply(const Matrix &input)//multiply
{
	Matrix mul_m(row, input.col);
	vector<double> a;
	double last=0;

	if (col == input.row)
	{
		for (int j = 0; j < input.col; j++)
		{
			for (int i = 0; i < row; i++)
			{
				for (int m = 0; m < col; m++)
				{
					//cout << data[i][m] << "*" << input.data[m][j] << "=" << data[i][m] * input.data[m][j]<<endl;
					a.push_back(data[i][m] * input.data[m][j]);
				}
				for (int n = 0; n < a.size(); n++)
				{
					//cout << "a"<<n<<":"<< a[i] << " ";
					last = last + a[n];
				}
				mul_m.data[i][j] = last;
				a.clear();
				last = 0;
			}
		}
	}
	else
	{
		cout << "error !!!" << endl;
	}

	return mul_m;
}

Matrix Matrix::transpose()//transpose
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

void matrix::setup(int col, int row)//設定row和col
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

Matrix::~Matrix()//destructor
{
	cout << "destructor called" << endl;
	for (int i = 0; i < row; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}




