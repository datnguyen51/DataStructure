template <class T>
class List
{
private:
	T a[100];
	int N;
public:
	List()
	{
		N=0;
	};
	void Add(T v)
	{
		a[N] = v;
		N++;
	};
	void PrintAll() const
	{
		for(int i=0; i<N; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	};
	void Change(int pos, T value)
	{
		a[pos-1] = value;
	};
	int Count() const
	{
		return N;
	};
	void Insert(int pos, T value)
	{
		N++;
		for(int i=N-1; i>=0; i--)
		{
			a[i] = a[i-1];
			if(i == pos-1)
			{
				break;
			}
		}
		a[pos-1] = value;
	};
	void Delete(int begin, int end)
	{
		int t=0;
		for(int i=begin-1; i<end; i++)
		{
			a[i] = 0;
			t++;
		}
		for(int i=0; i<N; i++)
		{
			if(a[i] != 0 && (i-t)>=0)
				a[i-t] = a[i];
		}
		N -= t;
	};
	void Delete(int pos)
	{
		a[pos-1]=0;
		for(int i=0; i<N; i++)
		{
			if(i>=pos && (i-1)>=0)
				a[i-1] = a[i];
		}
		N--;
	}
	int Count(T value)
	{
		int count=0;
		for(int i=0; i<N; i++)
		{
			if(a[i]==value)
				count++;
		}
		return count;
	};
};
