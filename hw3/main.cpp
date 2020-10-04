#include "Complex.h"
#include <cstdlib>

using namespace std;

int main()
{
	Complex a(3.4, 8.7);
	Complex b(3, 5);
	Complex tmp;
	a.print();
	a.add(b).print();
	a.multiply(b).print();
	a.divide(b).print();
	a.conjugate().print();
	system("PAUSE");
	return 0;
}