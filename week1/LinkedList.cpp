#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node *next;
};

class LinkedList
{
	private:
		Node *head;
		Node *tail;
	public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void AddNode(int a)
	{
		Node *temp = new Node();
		temp -> value = a;
		temp -> next = NULL;
		if (head== NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail -> next = temp;
			tail = tail ->next;
		}
	}

	void AddFront(int a)
	{
		Node *temp = new Node();
		temp ->value = a;
		temp -> next = head;
		head = temp;
	}

	void AddPosition(int position,int a)
	{
		Node *temp1 = new Node();
		Node *temp2 = new Node();
		Node *temp = new Node();
		temp2 = head;
		for(int i = 0;i<position;i++)
		{
			temp1 = temp2;
			temp2 = temp2 -> next;
		}
		temp -> value = a;
		temp1 -> next = temp;
		temp -> next = temp2;
	}

	void DeleteEnd()
	{
		Node *temp = new Node();
		Node *current = new Node();
		temp = head;
		while(temp->next != NULL )
		{
			current = temp;
			temp = temp -> next;
		}
		current -> next = NULL;
		tail = current;
	}

	void DeleteFirst()
	{
		Node *temp = new Node();
		temp = head;
		head = temp -> next;
		temp = NULL;
	}
	
	void DeletePosition(int position)
	{
		Node *temp1 = new Node();
		Node *temp2 = new Node();
		temp1 = head;
		for (int i = 0;i<position;i++)
		{
			temp2 = temp1;
			temp1 = temp1 -> next;
		}
		temp2 -> next = temp1 ->next;
	}

	void Output()
	{
		Node *temp = new Node();
		temp = head;
		while( temp != NULL)
		{
			cout<<temp ->value<<endl;
			temp = temp -> next;
		}
	}		
	
};

int main()
{
	LinkedList a;
	a.AddNode(5);
	a.AddNode(3);
	a.AddNode(2);
	a.AddFront(10);
	a.AddPosition(2,15);
	a.DeletePosition(3);
	a.Output();
	return 0;
}