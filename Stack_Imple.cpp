/*
============================================================================
 Name : Stack_Imple.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 4
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;
#include "Stack.h" //importing stack.h file's functions and defining implementation here in this file with .cpp extension

template<class S>
bool Stk<S> :: isEmpty()
{
    return t == NULL;
}

template<class S>
S Stk<S> :: top()
{
    return t->data;
}

template<class S>
void Stk<S> :: push(S n)
{
    struct N<S>* temp;
    temp = new N<S>();
    temp->data = n;
    temp->link = t;
    t = temp;
}

template<class S>
void Stk<S> :: pop()
{
    struct N<S>* temp;
    temp = new N<S>();
    temp = t;
    t = t->link;
    temp->link = NULL;
    free(temp);
}