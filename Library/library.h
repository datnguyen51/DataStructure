#ifndef LIBRARY_H
#define LIBRARY_H
#include "book.h"
#include "list.h"
int Menu()
{
	int cn;
	cout<<"LIBRARY"<<endl;
	cout<<"1. Add book."<<endl;
	cout<<"2. Delete book."<<endl;
	cout<<"3. Show book."<<endl;
	cout<<"4. Save file."<<endl;
	cout<<"5. Read file."<<endl;
	cout<<"6. Fix book."<<endl;
	cout<<"7. HTML."<<endl;
	cout<<"0. Exit."<<endl;
	cout<<"Choose the function: ";
	cin>>cn;
	return cn;
};
void Add_Book(List<Book> &l)
{
	Book a;
	cin>>a;
	l.Add(Book(a));
};
void Delete_Book(List<Book> &l)
{
	int pos;
	cout<<"Vi tri sach ban muon xoa: ";
	cin>>pos;
	l.Delete_Data_in_Pos(pos);
};
void Print_Data_of_Book(List<Book> &l)
{
 	l.PrintAll();
};
void Save_File(List<Book> &l)
{
	char fileName[1000];
	cout<<"Ten file: ";
	cin.ignore();
	cin.getline(fileName,1000);
	ofstream fout(fileName);
	fout<<l.Count()<<endl;
	for(int i=1; i<=l.Count(); i++)
	{
		Book a = l.Get_Item(i); 
		fout<<a.GetTenS()<<endl;
		fout<<a.GetTenTG()<<endl;
		fout<<a.GetNamSX()<<endl;
		fout<<a.GetSoTrang()<<endl;
	}
};
void Read_File(List<Book> &l)
{
	int stt;
	char fileName[1000];
	cout<<"Ten file: ";
	cin.ignore();
	cin.getline(fileName,1000);
	ifstream fin(fileName);
	fin>>stt;
	for(int i=1; i<=stt; i++)
	{
		string tensach;
		string tentacgia;
		int namsx;
		int sotrang;	
		fin.ignore();
		getline(fin,tensach);
		getline(fin,tentacgia);
		fin>>namsx;
		fin>>sotrang;
		Book a(tensach,tentacgia,namsx,sotrang);
		l.Add(Book(a));
	}
};
void Fix_Data_of_Book(List<Book> &l)
{
	string tensach;
	string tentacgia;
	int namsx;
	int sotrang;
	int pos;
	cout<<"Nhap vi tri sach muon sua: ";
	cin>>pos;
	Book a = l.Get_Item(pos);
	cin>>a;
	l.Change(pos,Book(a));
};
void HTML(List<Book> &l)
{
	char fileName[1000];
	cout<<"Ten file: ";
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
			fout<<"<tr>"<<endl;
				fout<<"<th>STT</th>"<<endl;
				fout<<"<th>Ten sach</th>"<<endl;
				fout<<"<th>Ten Tac gia</th>"<<endl;
				fout<<"<th>Nam san xuat</th>"<<endl;
				fout<<"<th>So trang</th>"<<endl;
			fout<<"<tr>"<<endl;
			for(int i=1; i<=l.Count(); i++)
			{
				Book a = l.Get_Item(i);
				fout<<"<tr>"<<endl;
					fout<<"<td>"<<i<<"</td>"<<endl;
					fout<<"<td>"<<a.GetTenS()<<"</td>"<<endl;
					fout<<"<td>"<<a.GetTenTG()<<"</td>"<<endl;
					fout<<"<td>"<<a.GetNamSX()<<"</td>"<<endl;
					fout<<"<td>"<<a.GetSoTrang()<<"</td>"<<endl;
				fout<<"<tr>"<<endl;
			}
		fout<<"</table>"<<endl;
		fout<<"</div>"<<endl;
	fout<<"</body>"<<endl;
	fout<<"</html>"<<endl;
};
#endif