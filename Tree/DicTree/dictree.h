#include <string.h>
#ifndef dictree
#define dictree
struct Node
{
    char data;
    Node *child;
    Node *next;
};
class DicTree
{
private:
    Node *root;    
    Node * AddLetter(char let, Node *p)
    {
        Node *q = p->child;
        if (q == 0)
        {
            Node *con = new Node;
            con->data = let;
            con->child = 0;
            con->next = 0;
            p->child = con;
            return con;
        }
        else
        {
            while (q->data != let && q->next != 0)
                q = q->next;
            if (q->data == let)
                return q;
            else
            {
                Node *em = new Node;
                em->data = let;
                em->child = 0;
                em->next = 0;
                q->next = em;
                return em;
            }   
        }
    };
    Node * SearchLetter(char let, Node *p) const
    {
        Node *q = p->child;
        while (q!= 0)
        {
            if (q->data == let)
                return q;
            q = q->next;
        }
        return 0;
    };
public:
    DicTree()
    {
        root = new Node;
        root->child =0;
        root->next = 0;
    };
    void Add(const char *s)
    {
        int len = strlen(s);
        Node * p = root;
       
        for(int i=0; i<len; i++)
        {
            p = AddLetter(s[i], p);
        }
        Node *pe = new Node;
        pe->data = '#';
        pe->child = 0;
        pe->next = 0;
        
        Node *q = p->child;
        if (q == 0)
        {
            p->child = pe;            
        }
        else
        {
            while (q->data != '#' && q->next != 0)
            {
                q = q->next;
            }
            if (q->next == 0)
                q->next = pe;
        }
    };
    bool Search(const char *tu) const
    {
        int len = strlen(tu);
        Node * p = root;
        for(int i = 0; i<len; i++)
        {
            p = SearchLetter(tu[i], p);
            if (p == 0)
                return false;
        }
        Node *q = p->child;
        while (q!=0)
        {
            if (q->data == '#')
                return true;
            q = q->next;             
        }
        return false;
    };
};
#endif
