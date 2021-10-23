/*
============================================================================
 Name : Stack_Imple.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 3
============================================================================
*/

#include<bits/stdc++.h>
using namespace std;
#include "Stack.h" //importing stack.h file's functions and defining implementation here in this file with .cpp extension

template<class S>
bool Stack<S> :: isEmpty()
{
    return t == NULL;
}

template<class S>
S Stack<S> :: top()
{
    return t->data;
}

template<class S>
void Stack<S> :: push(S n)
{
    struct Node<S>* temp;
    temp = new Node<S>();
    temp->data = n;
    temp->link = t;
    t = temp;
}

template<class S>
void Stack<S> :: pop()
{
    struct Node<S>* temp;
    temp = new Node<S>();
    temp = t;
    t = t->link;
    temp->link = NULL;
    free(temp);
}