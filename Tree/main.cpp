#include <bits/stdc++.h>
using namespace std;
#include "tree.h"
int main()
{
	Tree<int> t;
	t.AddChild(7);
	t.AddChild(6);
	t.AddChild(15);
	t.AddChild(5);
	t.AddChild(4);
	t.AddChild(10);
	t.AddChild(20);
	t.PreOrder();
	cout<<endl;
	cout<<t.Search(7)<<endl;
	cout<<"Max: "<<t.Max()<<endl;
	cout<<"Min: "<<t.Min()<<endl;
	return 0;
}