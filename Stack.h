/*
============================================================================
 Name : Stack.h
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 4
============================================================================
*/

#ifndef _STACK_H_
#define _STACK_H_
using namespace std;

template<class S>
struct N
{
    S data;
    struct N* link;
};

template<class S>
class Stk
{
    public :
        int size;
        struct N<S>* t = NULL;
        bool isEmpty();
        S top();
        void push(S a);
        void pop();
        Stk(int i)
        {
            size = i;
        }
};

#endif