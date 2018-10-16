#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
template <class T>
class Queue
{
private:
	Node<T> *head, *tail;
	int count;
public:
	Queue()
	{
		head = 0;
		tail = 0;
		count = 0;
	};
	int Empty()
	{
		if(count==0)
			return 1;
		return 0;
	}
	Node<T> *Creat_Node(int value)
	{
		Node<T> *p = new Node<T>;
		p->data = value;
		p->next = 0;
		return p;
	};
	void Push(T value)
	{
		Node<T> *n = Creat_Node(value);
		if(Empty())
			head = tail = n;
		else
		{
			tail->next = n;
			tail = n;
		}
		count++;
	};
	int Data_Head()
	{
		int n = head->data;
		return n;
	}
	T Pop()
	{
		Node<T> *p = head;
		T pop = p->data;
		Node<T> *q = head;
		head = head->next;
		count--;
		return pop;
		delete q;
	};
	void PrintAll() const
	{
		Node<T> *p = head;
		while(p != 0)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
	int Count() const
	{
		return count;
	};
};
#endif