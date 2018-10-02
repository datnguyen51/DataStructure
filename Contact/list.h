#ifndef LIST_H
#define LIST_H
#include <algorithm>
#include "phone.h"
template <class T>
struct Node
{
	T data;
	Node<T> *next;
};
template <class T>
class List
{
private:
	Node<T> *head;
	Node<T> *tail;
	int count;
public:
	List()
	{
		head = 0;
		tail = 0;
		count = 0;
	};
	void Add(T value)
	{
		Node<T> *n= Creat_Node(value);
		if(IsEmpty())
			head = tail = n;
		else
		{
			tail->next = n;
			tail = n;
		}
		count++;
	};
	void PrintAll() const
	{
		Node<T> *p = head;
		while (p != 0)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	};
	Node<T> *Creat_Node(T value)
	{
		Node<T> *p = new Node<T>;
		p->data = value;
		p->next = 0;
		return p;
	};
	int Check(T value)
	{
		Node<T> *p = head;
		while(p!=0)
		{
			if(p->data==value)
			{
				return 1;
				break;
			}
			return 0;
		}
	};
	void Insert_to_head(T value)
	{
		Node<T> *p = Creat_Node(value);
		p->next = head;
		head = p;
		count++;
	};
	void Insert_to_tail(T value)
	{
		Node<T> *p = Creat_Node(value);
		tail->next = p;
		tail = p;
		count++;
	};
	void Insert_to_possition(int pos, T value)
	{
		int i=1;
		Node<T> *p = Creat_Node(value);
		Node<T> *q = head;
		if(pos == 1)
			Insert_to_head(value);
		else
		{
			for(i=1; i<pos-1; i++)
			{
				// i++;
				q = q->next;
			}
			p->next = q->next;
			q->next = p;
		}
		count++;
	};
	void Change(int pos, T value)
	{
		if(pos == 1)
		{
			Node<T> *q = head;
			q->data = value;
		}
		else
		{
			Node<T> *p = head;
			for(int i=1; i<pos-1; i++)
				p = p->next;
			p->next->data = value;
		}
	};
	void Delete_Data_in_Pos(int pos)
	{
		if(pos == 1)
		{
			Node<T> *q = head;
			head = head -> next;
			delete q;
		}
		else
		{
			Node<T> *p = head;
			for(int i=1; i<pos-1; i++)
				p = p->next;
			Node<T> *q = p->next;
			p->next = p->next->next;
			delete q;
		}
		count--;
	};
	int Count() const
	{
		return count;
	};
	void Count(T value)
	{
		int count = 0;
		Node<T> *p = head;
		while (p != 0)
		{
			// cout<<p->data<<" ";
			if(p->data == value)
				count++;
			p = p->next;
		}
		cout<<"So phan tu "<<value<<" xuat hien: "<<count<<endl;
	};
	void Delete_Data(T value)
	{
		Node<T> *p = head;
		int pos = 1;
		while(!IsEmpty())
		{
			if(p->data == value)
			{
				Delete_Data_in_Pos(pos);
				break;
			}
			p = p->next;
			pos++;
		}
	};
	void Delete_Tail()
	{
		Node<T> *p = head;
		for(int i=1; i<count-1; i++)
			p=p->next;
		Node<T> *q = p->next;
		p->next = p->next->next;
		delete q;
		count--;
	};
	void Swap(int pos1, int pos2)
	{
		Node<T> *p = head;
		Node<T> *q = head;
		T swap1, swap2;
		for(int i=1; i<=count; i++)
		{
			if(i == pos1)
				swap1 = p->data;
			if(i == pos2)
				swap2 = p->data;
			p = p->next;
		}
		for(int i=1; i<=count; i++)
		{
			if(i == pos1)
				q->data = swap2;
			if(i == pos2)
				q->data = swap1;
			q = q->next;
		}
		cout<<swap1<<" "<<swap2<<endl;
	};
	void Reverse()
	{
		Node<T> *p = head;
		Node<T> *cur = 0;
		Node<T> *pre = 0;
		while(p!=0)
		{
			cur = p;
			p = p->next;
			cur->next = pre;
			pre = cur;
		}
		head = cur;
	};
	T Get_Item(int pos)
	{
		T x;
		if(pos == 1)
		{
			x =  head->data;
		}
		else
		{
			if(pos == count)
			{
				x = tail->data;
			}
			else
			{
				Node<T> *p = head;
				for(int i=1; i<pos-1; i++)
					p=p->next;
				x = p->next->data;
			}
		}
		return x;
	};
	T Find_pos_of_Item(T value)
	{
		int pos=1;
		Node<T> *p = head;
		while(!IsEmpty())
		{
			if(p->data == value)
			{
				return pos;
				break;
			}
			p = p->next;
			pos++;
		}
	};
	int IsEmpty()
	{
		return head == 0;
	};
	T Max()
	{
		Node<T> *p = head;
		T max = head->data;
		for(int i=1; i<=count; i++)
		{
			if(p->data > max)
				max = p->data;
			p = p->next;
		}
		return max;
	};
	T Min()
	{
		Node<T> *p = head;
		T min = head->data;
		for(int i=1; i<=count; i++)
		{
			if(p->data < min)
				min = p->data;
			p = p->next;
		}
		return min;
	};
	// void Array_Reverse()
	// {
	// 	int i=1;
	// 	Node<T> *p = head;
	// 	while(p!=0)
	// 	{
	// 		a[i] = p->data;
	// 		p = p->next;
	// 		i++;
	// 	}
	// 	reverse(a, a+count+2);
	// };
	// void Array_Sort()
	// {
	// 	int i=1;
	// 	Node<T> *p = head;
	// 	while(p!=0)
	// 	{
	// 		a[i] = p->data;
	// 		p = p->next;
	// 		i++;
	// 	}
	// 	sort(a, a+count+1);
	// };
	// void Sort_Min_to_Max()
	// {
	// 	Array_Sort();
	// 	for(int i=1; i<=count; i++)
	// 	{
	// 		T x = a[i];
	// 		Change(i,x);
	// 	}
	// };
	// void Sort_Max_to_Min()
	// {
	// 	Array_Sort();
	// 	reverse(a, a+count+2);
	// 	for(int i=1; i<=count; i++)
	// 	{
	// 		T x = a[i];
	// 		Change(i,x);
	// 	}
	// };
};
#endif