#ifndef STACK_H
#define STACK_H
#include "node.h"
template <class T>
class Stack
{
private:
	Node<T> *head, *tail;
	int count;
public:
	Stack()
	{
		head = 0;
		tail = 0;
		count = 0;
	};
	int Empty()
	{
		return head == 0;
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
			n->next = head;
			head = n;
		}
		count++;
	};
	T Pop()
	{
		T pop = head->data;
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