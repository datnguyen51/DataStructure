#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include <cstring>

int ChucNang()
{
	int n;
	cout<<"1. Sinh du lieu ngau nhien.\n";
	cout<<"2. Nhap du lieu.\n";
	cout<<"3. Them du lieu.\n";
	cout<<"4. Them n du lieu.\n";
	cout<<"5. Tim du lieu.\n";
	cout<<"6. So lan du lieu xuat hien.\n";
	cout<<"Moi ban chon chuc nang: ";
	cin>>n;
	return n;
}

void SinhSoNgauNhien()
{
	int n, i, dau, cuoi;
	cout<<"Moi nhap so du can sinh ra: ";
	cin>>n;
	cout<<"Khoang du lieu ban muon random: ";
	cin>>dau>>cuoi;
	char fileName[100];
	cout<<"Moi ban nhap ten file: ";
	cin.ignore();
	cin.getline(fileName, 100);
	ofstream fout(fileName);
	srand(time(0));
	for(i=0; i<n; i++)
	{
		int r = dau + rand() % (cuoi - dau + 1);
		fout<<r<<" ";
	}
	fout.close();
}
void NhapDuLieu(int a[],int &N)
{
	int i;
	char fileName[100];
	cout<<"Moi ban nhap ten file: ";
	cin.ignore();
	cin.getline(fileName, 100);
	ofstream fout(fileName, ios::app);
	for(i=0; i<N; i++)
	{
		fout<<a[i]<<" ";
	}
	fout.close();
}

void ADD(int a[], int &N)
{
	int add;
	cout<<"Du lieu muon them: ";
	cin>>add;
	a[N] = add;
	N++;
}

void ADD_n(int a[], int &N)
{
	int add, n;
	cout<<"So du lieu muon them: ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"Du lieu muon them: ";
		cin>>add;
		a[N] = add;
		N++;
	}
}

int BinarySearch(int a[], int find, int begin, int end)
{
	int mid = (begin + end)/2;
	if(begin>end)
		return -1;
	if(find > a[mid])
		return BinarySearch(a, find, mid+1, end);
	if(find < a[mid])
		return BinarySearch(a, find, begin, mid-1);
	if(find == a[mid])
		return mid;
}
void Find(int a[],int n)
{
	int key;
	cout<<"Nhap so ban muon tim: ";
	cin>>key;
	sort(a,a+n);
	if (a[BinarySearch(a,key,0,n)] == key)
		cout<<"Yes"<<endl;
	else 
		cout<<"No"<<endl;
}
void XuatHien(int a[], int b[], int n)
{
	
}

//====================================================================================================================================
int Function()
{
	int n;
	cout<<"1. Add Subject.\n";
	cout<<"2. Add Point.\n";
	cout<<"3. Print Point.\n";
	cout<<"4. Average.\n";
	cout<<"5. Save.\n";
	cout<<"6. Open File.\n";
	cout<<"0. Exit.\n";
	cout<<"Choice: ";
	cin>>n;
	return n;
}
void ADD_Subject(string s[],string c[], int &S)
{
	string subject;
	string subject_code;
	int n;
	cout<<"Number of Subject: ";
	cin>>n;
	cin.ignore();
	for(int i=0; i<n; i++)
	{	
		cout<<"Subject Name: ";
		getline(cin,subject);
		s[S] = subject;
		cout<<"Subject Code: ";
		getline(cin,subject_code);
		c[S] = subject_code;
		S++;
	}
}
void ADD_Point(string s[], string c[], float p[],int &P, int &S)
{
	float point;
	while(P<S)
	{
		cout<<s[P]<<"("<<c[P]<<")"<<" Point: ";
		cin>>point;
		p[P] = point;
		P++;
	}
}
void PrintPoint(string s[], string c[], float p[], int &S)
{
	for(int i=0; i<S; i++)
	{
		cout<<s[i]<<"("<<c[i]<<")"<<": "<<p[i]<<endl;
	}
}
void Average(float p[], int &S)
{
	float Sum=0;
	for(int i=0; i<S; i++)
	{
		Sum += p[i];
	}
	cout<<"Average Point: "<<Sum/S<<endl;
}
void Save(string s[], string c[], float p[], int &S)
{
	int i;
	char fileName[100];
	cout<<"File Name: ";
	cin.ignore();
	cin.getline(fileName, 100);
	ofstream fout(fileName);
	for(i=0; i<S; i++)
	{
		fout<<"Subject Name: "<<s[i]<<endl;
		fout<<"Subject Code: "<<c[i]<<endl;
		fout<<"Point       : "<<p[i]<<endl;
	}
	fout.close();
}
void OpenFile()
{
	char cmd[100] = "gedit ";
	char fileName[100];
	cout<<"Open File: ";
	cin.ignore();
	cin.getline(fileName,100);
	strcat(cmd, fileName);
	system(cmd);
}