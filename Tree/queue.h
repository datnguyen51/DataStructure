#ifndef QUEUE_H
#define QUEUE_H
template <class T>
struct QNode
{
	T data;
	QNode<T> *next;
};
template <class T>
class Queue
{
private:
	QNode<T> *head;
public:
	Queue()
	{
		head=0;
	};
	void EnQueue(T value)
	{
		QNode<T> *n = new QNode<T>;
		n->data = value;
		n->next = 0;
		if(head==0)
			head = n;
		else
		{
			QNode<T> *p = head;
			while(p->next!=0)
				p=p->next;
			p->next = n;
		}
	};
	T DeQueue()
	{
		T n = head->data;
		QNode<T> *p = head;
		head = head->next;
		delete p;
		return n;
	}
	int IsEmpty()
	{
		return head == 0;
	}
};
#endif