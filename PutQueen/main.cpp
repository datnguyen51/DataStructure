#include <iostream>
#include <fstream>
using namespace std;
#include "qeen.h"
int main()
{
	int n;
	char a[100][100];
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a[i-1][j-1] = '-';
	SetQueen(n,a,1);
	// HTML(a,n,1);
	return 0;
}