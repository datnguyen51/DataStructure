#ifndef MATRIX_H
#define MATRIX_H
template <class T>
struct Node
{
	T data;
	Node<T> *next;	
};
template <class T>
class Matrix
{
private:
	int row, col;
	Node<T> *head;
public:
	Matrix()
	{
		head=0;
	};
	Matrix(int r, int c)
	{
		row = r;
		col = c;
	};
	int GetRow()
	{
		return row;
	};
	int GetCol()
	{
		return col;
	};
	Node<T> *Creat_Node(T value)
	{
		Node<T> *p = new Node<T>;
		p->data = value;
		p->next = 0;
		return p;
	};
	void Creat_Matrix()
	{
		T value;
		cin>>value;
		Node<T> *p = Creat_Node(value);
		head = p;
		for(int i=1; i<row*col; i++)
		{
			cin>>value;
			Node<T> *n = Creat_Node(value);
			p->next = n;
			p=n;
		}
	};
	void Print() const
	{
		Node<T> * p = head;
		for(int i=0; i<row; i++)
		{
			cout<<"[ ";
			for (int j=0; j<col; j++)
			{
				cout<<p->data<<" ";
				p = p->next;
			}
			cout<<"]"<<endl;
		}
		cout<<endl;
	};
	friend Matrix<T> operator + (Matrix<T> &a, Matrix<T> &b)
	{
		Matrix<T> c;
		c.head = 0;
		Node<T> *pa = a.head;
		Node<T> *pb = b.head;
		Node<T> *pc = new Node<T>;
		pc->data = pa->data + pb->data;
		pc->next = 0;
		c.head = pc;
		pa = pa->next;
		pb = pb->next;
		if(a.row == b.row && a.col == b.col)
		{
			c.row = a.row;
			c.col = a.col;
			while(pa != 0 && pb != 0)
			{
				Node<T> *n = new Node<T>;
				n->data = pa->data + pb->data;
				n->next = 0;
				pc->next = n;
				pc = n;
				pa = pa->next;
				pb = pb->next;
			}
		}
		return c;
	};
	friend Matrix<T> operator - (Matrix<T> &a, Matrix<T> &b)
	{
		Matrix<T> c;
		c.head = 0;
		Node<T> *pa = a.head;
		Node<T> *pb = b.head;
		Node<T> *pc = new Node<T>;
		pc->data = pa->data - pb->data;
		pc->next = 0;
		c.head = pc;
		pa = pa->next;
		pb = pb->next;
		if(a.row == b.row && a.col == b.col)
		{
			c.row = a.row;
			c.col = a.col;
			while(pa != 0 && pb != 0)
			{
				Node<T> *n = new Node<T>;
				n->data = pa->data - pb->data;
				n->next = 0;
				pc->next = n;
				pc = n;
				pa = pa->next;
				pb = pb->next;
			}
		}
		return c;
	};
	friend Matrix<T> operator * (Matrix<T> &a, Matrix<T> &b)
	{
		Matrix<T> c;
		c.head = 0;
		Node<T> *pa = a.head;
		Node<T> *pb = b.head;
		Node<T> *qb = b.head;
		Node<T> *nb = b.head;
		for(int i=1; i<b.row; i++)
		{
			for(int j=1; j<b.col; j++)
			{
				for(int k=0; k<b.col; k++)
					qb = qb->next;
				pb->next = qb;
				pb = qb;
			}
			nb = nb->next;
			qb = nb;
		}
		Node<T> *pc = new Node<T>;
		pc->data = pa->data * pb->data;
		pc->next = 0;
		c.head = pc;
		pa = pa->next;
		pb = pb->next;
		if(a.row == b.row && a.col == b.col && a.row == b.col)
		{
			c.row = a.row;
			c.col = a.col;
			while(pa != 0 && pb != 0)
			{
				Node<T> *n = new Node<T>;
				n->data = pa->data - pb->data;
				n->next = 0;
				pc->next = n;
				pc = n;
				pa = pa->next;
				pb = pb->next;
			}
		}
		return c;
	};
};
#endif