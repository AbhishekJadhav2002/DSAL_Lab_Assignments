/*
============================================================================
 Name : Tree_Traversal_Imple.h
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 4
============================================================================
*/
#ifndef _Tree_H_
#define _Tree_H_
#include <stack>
using namespace std;

template<typename N>
struct Node
{
    char data;
    Node<N> *left, *right;
};

template<typename N>
class Expression
{
	char prefix[50], infix[50];
    string postfix;
	Node<N>* root;
	int top;

	public:
        Expression(string p)  //parameterised constructor to take postfix input
        {
            postfix = p;
        };

		Node<N>* getroot()
		{
			return root;
		};
		Node<N>* create_Post();         //creates tree using stack and postfix, and returns root(last) element
		void InorderRec(Node<N>*);      //prints postfix to [Left-Node-Right] order i.e. Infix format
		void PreorderRec(Node<N>*);     //prints postfix to [Node-Left-Right] order i.e. Prefix format
		void PostorderRec(Node<N>*);    //prints postfix to [Left-Right-Node] order i.e. Postfix format
		void InorderWithoutRec(Node<N>*);  
		void PreorderWithoutRec(Node<N>*);
		void PostorderWithoutRec(Node<N>*);
};

template<typename N>
Node<N>* Expression<N> :: create_Post()
{
    Node<N>* temp, *t1, *t2;
    stack<Node<N>*> s;
    for(int i=0; i < postfix.length(); i++)
    {
        if(isalnum(postfix[i]))
        {
            temp = new Node<N>;
            temp->data = postfix[i];
            temp->left = temp->right = NULL;
            s.push(temp);
        }
        else
        {
            t2 = s.top();
            s.pop();
            t1 = s.top();
            s.pop();
            temp = new Node<N>;
            temp->data = postfix[i];
            temp->left = t1;
            temp->right = t2;
            s.push(temp);
        }
    }
    temp = s.top();
    s.pop();
    return temp;
}

template<typename N>
void Expression<N> :: InorderRec(Node<N>* t)
{
    if(t!=NULL)
    {
        InorderRec(t->left);
        cout<<t->data;
        InorderRec(t->right);
    }
}

template<typename N>
void Expression<N> :: PreorderRec(Node<N>* t)
{
    if(t!=NULL)
    {
        cout<<t->data;
        PreorderRec(t->left);
        PreorderRec(t->right);
    }
}

template<typename N>
void Expression<N> :: PostorderRec(Node<N>* t)
{
    if(t!=NULL)
    {
        PostorderRec(t->left);
        PostorderRec(t->right);
        cout<<t->data;
    }
}

template<typename N>
void Expression<N> :: InorderWithoutRec(Node<N>* t)
{
    Node<N>* temp = t;
    stack<Node<N>*> s;

    while(temp!=NULL)
    {
        s.push(temp);
        temp = temp->left;
    }

    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        cout<<temp->data;
        temp = temp->right;
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}

template<typename N>
void Expression<N> :: PreorderWithoutRec(Node<N>* t)
{
    Node<N>* temp = t;
    stack<Node<N>*> s;
    while(temp != NULL)
    {
        cout<<temp->data;
        s.push(temp);
        temp = temp->left;
    }

    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        temp = temp->right;
        while(temp != NULL)
        {
            cout<<temp->data;
            s.push(temp);
            temp = temp->left;
        }
    }
}

template<typename N>
void Expression<N> :: PostorderWithoutRec(Node<N>* t)
{
	Node<N>* P , *previous;
	stack<Node<N>*> S;
	if(t == NULL)
	{
		cout<<"Tree Is Empty\n";
	}
	S.push(t);
	while(!S.empty())
	{
		P = S.top();
		S.pop();
		if(P->right == NULL && P->left == NULL)
		{
			previous = P;
			cout<<P->data;
		}
		else
		{
			if(P->right==previous||P->left==previous)
			{
				previous = P;
				cout<<P->data;
			}
			else
			{
				S.push(P);
				if(P->right)
					S.push(P->right);
	            if(P->left)
	            	S.push(P->left);
	        }
		}
	}
}
#endif