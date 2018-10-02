#ifndef PHONE_H
#define PHONE_H
#include <string>
class Phone
{
private:
	string name;
	string type;
	string number;
public:
	Phone(){};
	Phone(string na, string ty, string nu)
	{
		name = na;
		type = ty;
		number = nu;
	};
	void SetName(string a)
	{
		name = a;
	};
	void SetType(string a)
	{
		type = a;
	};
	void SetNumber(string a)
	{
		number = a;
	};
	string GetName()
	{
		return name;
	};
	string GetType()
	{
		return type;
	};
	string GetNumber()
	{
		return number;
	};
	friend istream &operator >> (istream &in, Phone &a)
	{
		cin.ignore();
		cout<<"Name: ";
		getline(cin, a.name);
		cout<<"Number type: ";
		getline(cin, a.type);
		cout<<"Number: ";
		getline(cin, a.number);
		return in;
	};
	friend ostream &operator << (ostream &out, Phone a)
	{
		out<<a.name<<"\t\t\t"<<a.type<<"\t"<<a.number<<endl;
		return out;
	};
};
#endif
/*type:
+mobile: điện thoại cá nhân
+work: điện thoại cơ quan
+home: điện thoại nhà*/