#include <bits/stdc++.h>
using namespace std;
#include "merge_sort.h"
int main()
{
	int a[1000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	MergeSort(a,0,n-1);
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}