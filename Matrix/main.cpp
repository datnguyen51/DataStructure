#include <iostream>
using namespace std;
#include "matrix.h"
int main()
{
	Matrix<int> m(2,2);
	Matrix<int> n(2,2);
	m.Creat_Matrix();
	m.Print();
	n.Creat_Matrix();
	n.Print();
	Matrix<int> t(m);
	// t = New(m);
	t.Print();
	return 0;
}