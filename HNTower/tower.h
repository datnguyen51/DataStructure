void Tower(int n, char c1, char c2, char c3)
{
	if(n==1)
		cout<<c1<<"---->"<<c3<<endl;
	else
	{
		Tower(n-1, c1, c3, c2);
		Tower(1, c1, c2, c3);
		Tower(n-1, c2, c1, c3);
	}

}