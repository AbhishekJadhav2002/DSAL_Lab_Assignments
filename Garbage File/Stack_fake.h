#ifndef _STACK_H_
#define _STACK_H_

template<class S>
class Stack
{
    private :
        int size;
        char stack_array[100];
        int t;

    public:
        bool isEmpty();
        char top();
        void push(char a);
        void pop();
        int peek();
        Stack(int i)
        {
            t = -1;
            size = i;
        }
};
#endif