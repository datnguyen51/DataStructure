#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "phone.h"
#include "list.h"
#include "contact.h"
int main()
{
	int n;
	List<Phone> p;
	do{
		system("clear");
		n = Menu();
		if(n==1)
		{
			Add_Contact(p);
		}
		if(n==2)
		{
			Delete_Contact(p);
		}
		if(n==3)
		{
			cout<<"Name\t\t\t";
			cout<<"Number Type\t";
			cout<<"Number\t"<<endl;
			Show_Contact(p);
		}
		if(n==4)
		{
			Find_Contact(p);
		}
		if(n==5)
		{
			Save_File(p);
		}
		if(n==6)
		{
			Read_File(p);
		}
		if(n==7)
		{
			Fix_Contact(p);
		}
		if(n==8)
		{
			HTML(p);
		}
		if(n==0)
			break;
		cout<<"Nhap phim bat ky de tiep tuc: ";
		cin.get();
		cin.ignore();
	}while(n!=0);
}