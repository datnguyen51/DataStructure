#include <iostream>
using namespace std;
#include "fibo.h"
int main()
{
	int n;
	cout<<"Fibo: ";
	cin>>n;
	cout<<"Fibo "<<n<<": "<<Fibo(n)<<endl;
	return 0;
}