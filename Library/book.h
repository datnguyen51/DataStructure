#ifndef BOOK_H
#define BOOK_H
using namespace std;
#include "list.h"
class Book
{
private:
	string TenS;
	string TenTG;
	int NamSX;
	int SoTrang;
public:
	Book(){};
	Book(string sach, string tg, int namsx, int sotrang)
	{
		TenS = sach;
		TenTG = tg;
		NamSX = namsx;
		SoTrang = sotrang;
	};
	
	void SetTenS(string a)
	{
		TenS = a;
	};
	void SetTenTG(string a)
	{
		TenTG = a;
	};
	void SetNamSX(int a)
	{
		NamSX = a;
	};
	void SetSoTrang(int a)
	{
		SoTrang = a;
	};
	string GetTenS()
	{
		return TenS;
	};
	string GetTenTG()
	{
		return TenTG;	
	};
	int GetNamSX()
	{
		return NamSX;
	};
	int GetSoTrang()
	{
		return SoTrang;
	};
	friend istream &operator >> (istream &in, Book &a)
	{
		in.ignore();
		cout<<"Nhap ten sach: ";
		getline(in, a.TenS);
		cout<<"Nhap ten tac gia: ";
		getline(in, a.TenTG);
		cout<<"Nhap nam san xuat: ";
		in>>a.NamSX;
		cout<<"Nhap so trang: ";
		in>>a.SoTrang;
		return in;
	}
	friend ostream &operator <<(ostream &out, Book a)
	{
		out<<"\t"<<a.TenS<<"\t"<<a.TenTG<<"\t"<<a.NamSX<<"\t"<<a.SoTrang<<endl;
		return out;
	}
};
#endif