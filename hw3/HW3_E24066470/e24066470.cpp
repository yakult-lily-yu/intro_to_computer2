#include<iostream>
#include"complex.h"

using namespace std;

complex::complex()
{
	real = 0;
	imag = 0;
}

complex::complex(double real_in , double imag_in )
{
	real = real_in;
	imag = imag_in;
}

complex complex::add(complex input)
{
	complex output_add(real + input.real, imag + input.imag);
	return output_add;
}

complex complex::multiple(complex input)
{
	complex output_mul(real * input.real - imag * input.imag , real * input.imag + imag * input.real);
	return output_mul;
}

complex complex::divide(complex input)
{
	complex output_div((real*input.real + imag * input.imag) / (input.real*input.real + input.imag*input.imag),
		(-real * input.imag + imag * input.real) / (input.real*input.real + input.imag*input.imag));
	return output_div;
}

complex complex::conjugate()
{
	complex output_conj(real,-imag);
	return output_conj;
}

void complex::print()
{
	cout << real << (imag >= 0 ? " + " : " ") << imag << "i" << endl;
}