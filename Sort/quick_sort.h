#ifndef QUICK_SORT
#define QUICK_SORT
void QuickSort(vector<int> &a, int begin, int last)
{
	int mid = (begin+last)/2;
	int x = a[mid];
	int i=begin, j=last;
	while(i<=j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			if(i<j)
				swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(begin<j)
		QuickSort(a,begin,j);
	if(i<last)
		QuickSort(a,i,last);
}
#endif