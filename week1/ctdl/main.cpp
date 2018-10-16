#include <iostream>
using namespace std;
#include "list.h"
int main()
{
	List<int> ds;
	ds.Add(0);
	ds.Add(4);
	ds.Add(10);
	ds.Add(10);
	ds.Add(100);
	ds.Insert(4, 50);
	ds.Insert(2, 500);
	ds.Change(1,10);
	ds.Delete(3);
	ds.PrintAll();
	cout<<"So phan tu "<<"xuat hien: "<<ds.Count(10)<<endl;
	cout<<"So phan tu la: "<<ds.Count()<<endl;
	return 0;
}