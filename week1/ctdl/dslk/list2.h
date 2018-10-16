#ifndef LIST2_H
#define LIST2_H
#include "node.h"
template <class T>
class List2
{
private:
	Node<T> *head;
	Node<T> *tail;
public:
	List2()
	{
		head = 0;
		tail = 0;
	};
	int IsEmpty()
	{
		return head == 0;	
	};
	Node<T> *Creat_Node(T value)
	{
		Node<T> *p = new Node<T>;
		p->data = value;
		p->next = 0;
		return p;
	};
	void Push(T value)
	{
		Node<T> *p = Creat_Node(value);
		if(head == 0)
			head = tail = p;
		else
		{
			tail->next = p;
			tail = p;
		}
	};
	void Push_Head(T value)
	{
		Node<T> *p = Creat_Node(value);
		p->next = head;
		head = p;
	};
	void Push_Tail(T value)
	{
		Node<T> *p = Creat_Node(value);
		tail->next = p;
		tail = p;
	};
	void PrintAll() const
	{
		Node<T> *p = head;
		while(p != 0)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	};
	void Reverse()
	{
		Node<T> *p = head;
		Node<T> *n = 0;
		Node<T> *m = 0;
		while(p!=0)
		{
			n=p;
			p = p->next;
			n->next = m;
			m = n;
		}
		head = n;
	}
	void Insert(int pos,T value)
	{
		Node<T> *p = Creat_Node(value);
		if(pos == 1)
		{
			p->next = head;
			head = p;
		}
		else
		{
			Node<T> *q = head;
			for(int i=1; i<pos-1; i++)
				q=q->next;
			p->next = q->next;
			q->next = p;
		}
	};
	List2(int pos1, int pos2)
	{
		Node<T> *p = head;
		List2<int> a;
		for(int i=1; i<pos1; i++)
			p=p->next;
		for(int i=pos1; i<=pos2; i++)
		{
			a.Push(p->data);
			p=p->next;
		}
		return a;
	};
};
#endif