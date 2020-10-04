#pragma once
#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

/*
* ²�檺�x�}�ۥ[�M�ۭ�
*/

class Matrix
{
	friend ostream &operator<<(ostream &, const Matrix &);//output
	friend istream &operator>>(istream &, Matrix &);//input

public:
	Matrix();			// default constructor, ���򳣤���, �Ndata�s�J2*2���O0����
	Matrix(int, int);		// constructor, �u�]�w�j�p, ��ƹw�]��0
	Matrix(int, int, double[], int);// constructor, �N�ǤJ���@���}�C��s���G���}�C��Jdata��
	Matrix(const Matrix &);		// copy constructor
	~Matrix();			// destructor, �M�zdata

	void setData(int, int, double);	// �]�w��(r,c)��mdata����

	int getRow() const;		// �^��private member: row
	int getCol() const;		// �^��private member: col
	double getData(int, int) const;	// ����x�}(r,c)��m����

	const Matrix &operator=(const Matrix&);//assignment

	Matrix operator+(const Matrix&);//matrix+matrix
	Matrix operator + (double);//all values plus the double value
	Matrix operator++(int);//all values plus 1.0
	Matrix operator*(const Matrix&);//Matrix*Matrix
	Matrix operator()();//transpose and return the transpose itself
	const Matrix &operator+=(const Matrix&);//m1=m1+m2
	bool operator == (const Matrix &) const;//test if two matrix is same

	static int getCount();

	void displayData() {	// �N�o�ӯx�}����ƦL�X�� (�����ק�)
		for (int i = 0; i<row; i++) {
			for (int j = 0; j<col; j++) {
				cout << data[i][j] << "\t";
			}
			cout << "" << endl;
		}
	}

private:
	double ** data;			// �@�ӤG����double�x�}
	int row;			// �x�sdata�@���X��row
	int col;			// �x�sdata�@���X��col
	static int count;   //�p�⦳�X��matrix
	void setUp(int, int);		// utility function, �]�wrow�Mcol����
};

#endif
