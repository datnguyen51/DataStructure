#ifndef TREE_H
#define TREE_H
#include "queue.h"
template <class T>
struct TreeNode
{
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;
};
template <class T>
class Tree
{
private:
	TreeNode<T> *root;
    void PrintBefore(TreeNode<T> *root) const
    {
    	if(root != 0)
    	{
    		PrintBefore(root->left);
    		cout<<root->data<<";";
    		PrintBefore(root->right);
    	}
    };
public:
	Tree()
	{
		root = 0;
	};
	void AddChild(T value)
	{
		TreeNode<T> *n = new TreeNode<T>;
		n->data = value;
		n->left = 0;
		n->right = 0;
		if(root == 0)
			root = n;
		else
		{
			Queue<TreeNode<T> *> q;
			TreeNode<T> *p = root;
			q.EnQueue(p);
			while(!q.IsEmpty())
			{
				TreeNode<T> *t = q.DeQueue();
				if(t->left == 0)
				{
					t->left = n;
					break;
				}
				else if(t->right == 0)
				{
					t->right = n;
					break;
				}
				else
				{
					q.EnQueue(t->left);
					q.EnQueue(t->right);
				}
			}
		}
	};
	bool Search(T value)
	{
		Queue<TreeNode<T> *> q;
		TreeNode<T> *p = root;
		q.EnQueue(p);
		while(!q.IsEmpty())
		{
			TreeNode<T> *t = q.DeQueue();
			if(t->data == value)
			{
				return true;
			}
			else if(t->left!=0 && t->right!=0)
			{
				q.EnQueue(t->left);
				q.EnQueue(t->right);
			}
		}
		return false;
	};
	int Max() const
	{
		T amax = 0;
		Queue<TreeNode<T> *> q;
		TreeNode<T> *p = root;
		q.EnQueue(p);
		while(!q.IsEmpty())
		{
			TreeNode<T> *t = q.DeQueue();
			if(t->data > amax)
			{
				amax = t->data;
			}
			if(t->left!=0 && t->right!=0)
			{
				q.EnQueue(t->left);
				q.EnQueue(t->right);
			}
		}
		return amax;
	};
	int Min() const
	{
		Queue<TreeNode<T> *> q;
		TreeNode<T> *p = root;
		q.EnQueue(p);
		T amin = root->data;
		while(!q.IsEmpty())
		{
			TreeNode<T> *t = q.DeQueue();
			if(t->data < amin)
			{
				amin = t->data;
			}
			if(t->left!=0 && t->right!=0)
			{
				q.EnQueue(t->left);
				q.EnQueue(t->right);
			}
		}
		return amin;
	};
	void PreOrder() const
	{
		PrintBefore(root);
	};
};
#endif