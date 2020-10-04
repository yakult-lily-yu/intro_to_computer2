#pragma once
#ifndef complex_h
#define complex_h

using namespace std;

class complex
{
public:
	complex();
	complex(double real, double imag);
	complex add(complex input);
	complex multiple(complex input);
	complex divide(complex input);
	complex conjugate();
	void print();

private:
	double real;
	double imag;
};
#endif // !complex_h
