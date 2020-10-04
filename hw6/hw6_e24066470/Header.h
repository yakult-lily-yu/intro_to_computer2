#pragma once
#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

/*
* 簡單的矩陣相加和相乘
*/

class Matrix
{
	friend ostream &operator<<(ostream &, const Matrix &);//output
	friend istream &operator>>(istream &, Matrix &);//input

public:
	Matrix();			// default constructor, 什麼都不傳, 將data存入2*2都是0的值
	Matrix(int, int);		// constructor, 只設定大小, 資料預設為0
	Matrix(int, int, double[], int);// constructor, 將傳入的一維陣列轉存為二維陣列放入data中
	Matrix(const Matrix &);		// copy constructor
	~Matrix();			// destructor, 清理data

	void setData(int, int, double);	// 設定第(r,c)位置data的值

	int getRow() const;		// 回傳private member: row
	int getCol() const;		// 回傳private member: col
	double getData(int, int) const;	// 拿到矩陣(r,c)位置的值

	const Matrix &operator=(const Matrix&);//assignment

	Matrix operator+(const Matrix&);//matrix+matrix
	Matrix operator + (double);//all values plus the double value
	Matrix operator++(int);//all values plus 1.0
	Matrix operator*(const Matrix&);//Matrix*Matrix
	Matrix operator()();//transpose and return the transpose itself
	const Matrix &operator+=(const Matrix&);//m1=m1+m2
	bool operator == (const Matrix &) const;//test if two matrix is same

	static int getCount();

	void displayData() {	// 將這個矩陣的資料印出來 (不必修改)
		for (int i = 0; i<row; i++) {
			for (int j = 0; j<col; j++) {
				cout << data[i][j] << "\t";
			}
			cout << "" << endl;
		}
	}

private:
	double ** data;			// 一個二維的double矩陣
	int row;			// 儲存data共有幾個row
	int col;			// 儲存data共有幾個col
	static int count;   //計算有幾個matrix
	void setUp(int, int);		// utility function, 設定row和col的值
};

#endif
