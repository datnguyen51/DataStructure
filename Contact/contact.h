#ifndef CONTACT_H
#define CONTACT_H
#include "phone.h"
#include "list.h"
int Menu()
{
	int func;
	cout<<"1. Add contact."<<endl;
	cout<<"2. Delete contact."<<endl;
	cout<<"3. Show contact."<<endl;
	cout<<"4. Find contact."<<endl;
	cout<<"5. Save file."<<endl;
	cout<<"6. Read file."<<endl;
	cout<<"7. Fix contact."<<endl;
	cout<<"8. HTML."<<endl;
	cout<<"0. Exit."<<endl;
	cout<<"Choose the function: ";
	cin>>func;
	return func;
};
void Add_Contact(List<Phone> &p)
{
	Phone a;
	cin>>a;
	p.Add(Phone(a));
};
void Delete_Contact(List<Phone> &p)
{
	string na;
	int pos;
	cout<<"Delete Contact name: ";
	cin.ignore();
	getline(cin, na);
	for(int i=1; i<=p.Count(); i++)
	{
		Phone a = p.Get_Item(i); 
		if(a.GetName() == na)
		{
			p.Delete_Data_in_Pos(i);
			break;
		}
	}
};
void Show_Contact(List<Phone> &p)
{
	p.PrintAll();
};
void Find_Contact(List<Phone> &p)
{
	string na;
	cout<<"Find Contact name: ";
	cin.ignore();
	getline(cin, na);
	cout<<"================="<<endl;
	for(int i=1; i<=p.Count(); i++)
	{
		Phone a = p.Get_Item(i); 
		if(a.GetName() == na)
		{
			cout<<"Name: "<<a.GetName()<<endl;
			cout<<"Number Type: "<<a.GetType()<<endl;
			cout<<"Number: "<<a.GetNumber()<<endl;
			cout<<"================="<<endl;
			break;
		}
	}
};
void Save_File(List<Phone> &p)
{
	char fileName[1000];
	cout<<"Name file: ";
	cin.ignore();
	cin.getline(fileName,1000);
	ofstream fout(fileName);
	fout<<p.Count()<<endl;
	for(int i=1; i<=p.Count(); i++)
	{
		Phone a = p.Get_Item(i); 
		fout<<a.GetName()<<endl;
		fout<<a.GetType()<<endl;
		fout<<a.GetNumber()<<endl;
	}
};
void Read_File(List<Phone> &p)
{
	int stt;
	char fileName[1000];
	cout<<"Name file: ";
	cin.ignore();
	cin.getline(fileName,1000);
	ifstream fin(fileName);
	fin>>stt;
	fin.ignore();
	for(int i=1; i<=stt; i++)
	{
		string name;
		string type;
		string number;	
		getline(fin,name);
		getline(fin,type);
		getline(fin,number);
		Phone a(name, type, number);
		p.Add(Phone(a));
	}
};
void Fix_Contact(List<Phone> &p)
{
	string name;
	string type;
	string number;
	int pos;
	cout<<"Nhap vi tri sach muon sua: ";
	cin>>pos;
	Phone a = p.Get_Item(pos);
	cin>>a;
	p.Change(pos,Phone(a));
};
void HTML(List<Phone> &p)
{
	char fileName[1000];
	cout<<"Name file: ";
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
				fout<<"<th>Name</th>"<<endl;
				fout<<"<th>Type Number</th>"<<endl;
				fout<<"<th>Number</th>"<<endl;
			fout<<"<tr>"<<endl;
			for(int i=1; i<=p.Count(); i++)
			{
				Phone a = p.Get_Item(i);
				fout<<"<tr>"<<endl;
					fout<<"<td>"<<a.GetName()<<"</td>"<<endl;
					fout<<"<td>"<<a.GetType()<<"</td>"<<endl;
					fout<<"<td>"<<a.GetNumber()<<"</td>"<<endl;
				fout<<"<tr>"<<endl;
			}
		fout<<"</table>"<<endl;
		fout<<"</div>"<<endl;
	fout<<"</body>"<<endl;
	fout<<"</html>"<<endl;
};
#endif