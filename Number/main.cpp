#include <iostream>
using namespace std;
#include "list.h"
// #include "queue.h"
// #include "stack.h"
int main()
{
	List<int> li;
	li.Add(0);
	li.Add(4);
	li.Add(10);
	li.Add(11);
	li.Add(100);
	List<int> li1 = li;
	li.Insert_to_head(22);
	li.Insert_to_head(27);
	li.Insert_to_tail(32);
	// li.PrintAll();
	li.Insert_to_possition(5, 55);
	// li.Reverse();
	// li.Insert_to_head(1);
	// li.Insert_to_head(99);
	// li.Insert_to_tail(70);
	// cout<<li.Check(99)<<endl;
	// li.PrintAll();
	// li.PrintAll();
	// li.Swap(2,5);
	// li.PrintAll();
	// cout<<li.Get_Item(5)<<endl;
	// li.PrintAll();
	// cout<<li.Find_pos_of_Item(4)<<endl;
	// li.PrintAll();
	// cout<<li.Max()<<endl;
	// cout<<li.Min()<<endl;

	// li.Insert_to_possition(5, 5);
	// li.PrintAll();
	// li.Change(4,10);
	// li.PrintAll();
	// li.Change(5,80);
	// li.PrintAll();
	// li.Delete_Tail();
	// li.Delete_Tail();
	// li.Delete_Tail();
	// li.Delete_Tail();
	// li.PrintAll();

	// li.Delete_Data_in_Pos(8);
	// li.PrintAll();

	// li.Delete_Data(li.Max());
	// li.PrintAll();
	// li.Reverse();
	// li.PrintAll();
	// li.Sort_Min_to_Max();
	// li.PrintAll();
	// li.Sort_Max_to_Min();
	li.PrintAll();
	li1.PrintAll();
	// li.Count(10);
	// cout<<"So phan tu la: "<<li.Count()<<endl;
	return 0;
}