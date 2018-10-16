#include <iostream>
#include <string>
using namespace std;
#include "mylib.h"
int main()
{
	string s[1000];
	string c[1000];
	float p[1000];
	int S=0, P=0;
	do{
		int n = Function();
		switch(n)
		{
			case 1:
				ADD_Subject(s,c,S);
				break;
			case 2:
				ADD_Point(s,c,p,P,S);
				break;
			case 3:
				PrintPoint(s,c,p,S);
				break;
			case 4:
				Average(p,S);
				break;
			case 5:
				Save(s,c,p,S);
				break;
			case 6:
				OpenFile();
				break;
			case 0:
				break;
		}
		if(n==0)
			break;
		char ch;
		cout<<"Continue(y/n): ";
		cin>>ch;
		if(ch == 'n')
			break;
		else
			system("clear");
	}while(1);
	return 0;
}