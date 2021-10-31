#include<bits/stdc++.h>
using namespace std;
#include "Stack.h"  //importing stack.h file's functions and defining implementation here in this file with .cpp extension

// template<class s>
// bool Stack<s> :: isFull()
// {
//     if (t == size - 1)
//     {
//         return true;
//     }
//     return false;
// }

template<class S>
bool Stack<S> :: isEmpty()
{
    if (t < 0)
    {
        return true;
    }
    return false;
}

template<class S>
S Stack<S> :: top()
{
    string str;
    // str += stack_array[t];
    return stack_array[t];
}

template<class S>
void Stack<S> :: push(char n)
{
    t += 1;
    stack_array[t] = n;
}

template<class S>
void Stack<S> :: pop()
{
    char popped = stack_array[t];
    t--;
    // return popped;
}

template<class s>
int Stack<s> :: peek()
{
    return t;
}