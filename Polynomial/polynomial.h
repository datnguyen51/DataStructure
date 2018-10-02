#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <algorithm>
#include <math.h>
template <class T>
struct Node
{
	T coefficient; //hệ số
	T degree; //bậc
	Node<T> *next;
	Node()
	{
		coefficient = 0;
		degree = 0;
		next = 0;
	};
	Node(T coe, T deg)
	{
		coefficient = coe;
		degree = deg;
		next = 0;
	};
};
template <class T>
class Polynomial
{
private:
	int size;
	Node<T> *head;
	Node<T> *tail;
public:
	Polynomial()
	{
		size = 0;
		head = tail = 0;
	};
	Polynomial(int deg) // khởi tạo đa thức bâc deg
	{
		Node<T> *p = Creat_Polynomial(deg);
		head = p;
		for(int i=deg-1; i>=0; i--)
		{
			Node<T> *n = Creat_Polynomial(i);
			p->next = n;
			p = n;
		}
		size = deg + 1;
	};
	Node<T> *Creat_Polynomial(T coef, T deg) // tạo thành phần với hệ số coef và bậc deg
	{
		Node<T> *n = new Node<T>;
		n->degree = deg;
		n->coefficient = coef;
		n->next = 0;
		return n;
	}
	Node<T> *Creat_Polynomial(T deg) // tạo thành phần với bậc deg
	{
		Node<T> *n = new Node<T>;
		n->degree = deg;
		n->coefficient = 1;
		n->next = 0;
		return n;
	}
	void Set_Coef(T coef, T deg) // set hệ số coef cho phân tử bậc deg
	{
		Node<T> *p = head;
		while(p!=0)
		{
			if(p->degree == deg)
				p->coefficient = coef;
			p=p->next;
		}
	};
	T Calculator(T value) // tính đa thức
	{
		Node<T> *p = head;
		T sum=0;
		T i = p->degree;
		while(p!=0)
		{
			sum = sum + (p->coefficient)*pow(value, i);
			p = p->next;
			i--;
		}
		return sum;
	};
	friend Polynomial<T> operator * (Polynomial<T> &a, T value)
	{
		Polynomial<T> c;
		Node<T> *pa = a.head;
		T coef = pa->coefficient*value;
		T deg = pa->degree;
		Node<T> *pc = new Node<T>;
		pc->coefficient = coef;
		pc->degree = deg;
		pc->next = 0;
		c.head = pc;
		pa = pa->next;
		while(pa != 0)
		{
			coef = pa->coefficient*value;
			deg = pa->degree;
			Node<T> *n = new Node<T>;
			n->coefficient = coef;
			n->degree = deg;
			n->next = 0;
			pc->next = n;
			pc=n;
			pa = pa->next;
		}
		return c;
	};
	friend Polynomial<T> operator + (Polynomial<T> &a, Polynomial<T> &b)
	{
		Polynomial<T> c;
		Node<T> *pa = a.head;
		Node<T> *pb = b.head;
		Node<T> *pc = new Node<T>;
		T coef, deg;
		if(a.size == b.size)
		{
			coef = pa->coefficient+pb->coefficient;
			deg = pa->degree;
			pc->coefficient = coef;
			pc->degree = deg;
			pc->next = 0;
			pa = pa->next;
			pb = pb->next;
			c.head = pc;
		}
		else if(a.size > b.size)
		{
			coef = pa->coefficient;
			deg = pa->degree;
			pc->coefficient = coef;
			pc->degree = deg;
			pc->next = 0;
			pa = pa->next;
			c.head = pc;
			for(int i=b.size; i<a.size-1; i++)
			{
				coef = pa->coefficient;
				deg = pa->degree;
				Node<T> *n = new Node<T>;
				n->coefficient = coef;
				n->degree = deg;
				n->next = 0;
				pc->next = n;
				pc=n;
				pa = pa->next;
			}
		}
		else if(a.size < b.size)
		{
			coef =pb->coefficient;
			deg = pb->degree;
			pc->coefficient = coef;
			pc->degree = deg;
			pc->next = 0;
			pb = pb->next;
			c.head = pc;
			for(int i=a.size; i<b.size-1; i++)
			{
				coef = pb->coefficient;
				deg = pb->degree;
				Node<T> *n = new Node<T>;
				n->coefficient = coef;
				n->degree = deg;
				n->next = 0;
				pc->next = n;
				pc=n;
				pb = pb->next;
			}
		}
		while(pa != 0 || pb != 0)
		{
			coef = pa->coefficient+pb->coefficient;
			deg = pa->degree;
			Node<T> *n = new Node<T>;
			n->coefficient = coef;
			n->degree = deg;
			n->next = 0;
			pc->next = n;
			pc=n;
			pa = pa->next;
			pb = pb->next;
		}
		return c;
	};
	void Print() // hiện thị đa thức
	{
		Node<T> *p = head;
		while(p != 0)
		{
			// phần tử đầu tiên có bậc cao nhất
			if(p->degree == head->degree)
			{
				if(p->coefficient >= 0)
				{
					if(p->coefficient == 0)
						p=p->next;
					else if(p->coefficient == 1)
					{
						cout<<"x^"<<p->degree;
						p=p->next;
					}
					else
					{
						cout<<p->coefficient<<"x^"<<p->degree;
						p=p->next;
					}
				}
				else if(p->coefficient < 0)
				{
					if(p->coefficient == -1)
					{
						cout<<"-x^"<<p->degree;
						p=p->next;
					}
					else if(p->coefficient < -1)
					{
						cout<<p->coefficient<<"x^"<<p->degree;
						p=p->next;
					}
				}
			}
			// phần tử có bậc = 0
			else if(p->degree == 0)
			{
				if(p->coefficient > 1)
				{
					cout<<"+"<<p->coefficient<<endl;
					p = p->next;
				}
				else if(p->coefficient < 0)
				{
					cout<<p->coefficient<<endl;
					p = p->next;
				}
				else if(p->coefficient == 0)
				{
					cout<<endl;
					p = p->next;
				}
				else
				{
					cout<<"+1"<<endl;
					p = p->next;
				}
			}
			// phần tử có bậc = 1
			else if(p->degree == 1)
			{
				if(p->coefficient >= 0)
				{
					if(p->coefficient == 1)
					{
						cout<<"+x";
						p = p->next;
					}
					else if(p->coefficient == 0)
						p = p->next;
					else
					{
						cout<<"+"<<p->coefficient<<"x";
						p = p->next;
					}
				}
				else if(p->coefficient < 0)
				{
					if(p->coefficient == -1)
						cout<<"-x";
					else
						cout<<p->coefficient<<"x";
					p = p->next;
				}
			}
			// phần tử có bậc nhỏ hơn bậc lớn nhất và lớn hơn bậc 1
			else if(p->degree > 1)
			{
				if(p->coefficient >= 0)
				{
					if(p->coefficient == 1)
					{
						cout<<"+x^"<<p->degree;
						p=p->next;
					}
					else if(p->coefficient == 0)
						p=p->next;
					else
					{
						cout<<"+"<<p->coefficient<<"x^"<<p->degree;
						p = p->next;
					}
				}
				else if(p->coefficient < 0)
				{
					if(p->coefficient == -1)
						cout<<"-x^"<<p->degree;
					else
						cout<<p->coefficient<<"x^"<<p->degree;
					p = p->next;
				}
			}
		}
	}
};
#endif