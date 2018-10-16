#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#include "mylib.h"
int main()
{
	int a[10000], N=0;
	do{
		system("clear");
		int n = ChucNang();
		switch(n)
		{
			case 1:
				SinhSoNgauNhien();
				break;
			case 2:
				NhapDuLieu(a, N);
				break;
			case 3:
				ADD(a,N);
				break;
			case 4:
				ADD_n(a,N);
				break;
			case 5:
				Find(a,N);
				break;
			case 6:
				break;
			case 0:
				break;
		}
		if(n==0)
		{
			break;
		}
		cout<<"Moi nhap phim bat ky de tiep tuc: ";
		cin.get();
		cin.get();
	}while(1);
	return 0;
}