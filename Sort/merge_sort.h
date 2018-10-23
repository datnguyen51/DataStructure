#ifndef MERGER_SORT
#define MERGER_SORT
void Merge(int a[], int left, int right)
{
	int i = left,j = right,mid = (left + right)/2;
	vector<int> v;
	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
			v.push_back(a[i++]);
		else
			v.push_back(a[j++]);
	}
	if(i > mid)
		while (j <= right)
			v.push_back(a[j++]);
	if (j > right)	
		while(i <= mid)
			v.push_back(a[i++]);	
	for (int i = 0 ; i< v.size();i++)
		a[left + i] = v[i];
}
void MergeSort(int a[], int begin, int end)
{
	if(begin < end)
	{
		int mid = (begin+end)/2;
		MergeSort(a, begin, mid);
		MergeSort(a, mid+1, end);
		Merge(a, begin, end);
	}
}
#endif