/*
============================================================================
 Name : Stack.h
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 3
============================================================================
*/

#ifndef _STACK_H_
#define _STACK_H_
using namespace std;

template<class S>
struct Node
{
    S data;
    struct Node* link;
};

template<class S>
class Stack
{
    private:
        int size;
        char stack_array[100];

    public :
        struct Node<S>* t = NULL;
        bool isEmpty();
        S top();
        void push(S a);
        void pop();
        int peek();
        Stack(int i)
        {
            size = i;
        }
};
#endif