#include <iostream>
using namespace std;
#include "polynomial.h"
int main()
{
	Polynomial<int> pa(4);
	Polynomial<int> pb(1);
	Polynomial<int> pc;
	pa.Print();
	pb.Print();
	// pa.Set_Coef(3,4);
	// pa.Print();
	// pa.Set_Coef(-1,3);
	// pa.Print();
	// pa.Set_Coef(-5,2);
	// pa.Print();
	// pa.Set_Coef(-1,1);
	// pa.Print();
	// pa.Set_Coef(-8,0);
	// pa.Print();
	pc = pa+pb;
	pc.Print();
	cout<<pc.Calculator(2)<<endl;
	return 0;
}