#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "book.h"
#include "list.h"
#include "library.h"
int main()
{
	int n, stt=0;
	List<Book> s;
	do{
		system("clear");
		n = Menu();
		if(n==1)
		{
			Add_Book(s);
		}
		if(n==2)
		{
			Delete_Book(s);
		}
		if(n==3)
		{
			cout<<"STT\t";
			cout<<"Ten sach\t";
			cout<<"Ten tac gia\t";
			cout<<"Nam san xuat\t";
			cout<<"So trang\t"<<endl;
			Print_Data_of_Book(s);
		}
		if(n==4)
		{
			Save_File(s);
		}
		if(n==5)
		{
			Read_File(s);
		}
		if(n==6)
		{
			Fix_Data_of_Book(s);
		}
		if(n==7)
		{
			HTML(s);
		}	
		if(n==0)
			break;
		cout<<"Nhap phim bat ky de tiep tuc: ";
		cin.get();
		cin.ignore();
	}while(n!=0);
	return 0;
}