void Chessboard(int n, char a[][100])
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			cout<<a[i-1][j-1]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
bool Safe(int n, char a[][100], int x, int y)
{
	for(int i=1; i<y; i++)
	{
			if(a[x-1][i-1]=='H')
				return false;
	}
	for(int i=x-1, j=y-1; i>=1,j>=1; i--, j--)
	{
			if(a[i-1][j-1]=='H')
				return false;
	}
	for(int i=x+1 ,j=y-1; i<=n, j>=1; i++, j--)
		if(a[i-1][j-1]=='H')
			return false;
	return true;
}
void HTML(char a[][100], int n)
{
	// SetQueen(n,a,r);
	char fileName[1000];
	cin.ignore();
	cin.getline(fileName,1000);
	ofstream fout(fileName);
	fout<<"<!DOCTYPE html>"<<endl;
	fout<<"<html>"<<endl;
	fout<<"<head>"<<endl;
	fout<<"<meta http-equiv="<<"Content-Type"<<" content="<<"text/html; charset=utf-8"<<">"<<endl;
	fout<<"<title>Danh sách các sách</title>"<<endl;
	fout<<"</head>"<<endl;
	fout<<"<body>"<<endl;
		fout<<"<div align=center>"<<endl;
		fout<<"<table border=1>"<<endl;
			for(int i=1; i<=n; i++)
			{
				fout<<"<tr>"<<endl;
				for(int j=1; j<=n; j++)
				{
						fout<<"<td>"<<a[i-1][j-1]<<"</td>"<<endl;
				}
				fout<<"<tr>"<<endl;
			}
		fout<<"</table>"<<endl;
		fout<<"</div>"<<endl;
	fout<<"</body>"<<endl;
	fout<<"</html>"<<endl;
}
void SetQueen(int n, char a[][100],int r)
{
	if(r>n)
		Chessboard(n,a);
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(Safe(n,a,i,r))
			{
				a[i-1][r-1] = 'H';
				SetQueen(n,a,r+1);
				a[i-1][r-1] = '-';
			}
		}
	}
}
