/*
============================================================================
 Name : Stack.h
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 4
============================================================================
*/
#ifndef _ExpConv_H_
#define _ExpConv_H_

#include <bits/stdc++.h>
#include "Stack.h"  //importing templated header Stack of type class
#include "Stack_Imple.cpp"  //importing Stack method definition(required to be imported)
#include <string>
#include <algorithm>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool IsOperand(char c)  
{
    if (c >= 'A' && c <= 'Z'){return true;}
    if (c >= 'a' && c <= 'z'){return true;}
    if (c >= '0' && c <= '9'){return true;}
    return false;
}

bool IsOperator(char c)  
{  
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    return false;
}

int OperatorValidity(string e)
{
    int operators = 0;
    int operands = 0;
    for (int i = 1; i < e.length(); i++)
    {
        if (IsOperator(e[0]) == true)
        {
            return 0;
        }
        else if (IsOperator(e[i]) == true)
        {
            operators += 1;
        }
        else
        {
            if ((IsOperand(e[i-1]) == true) && (IsOperand(e[i]) == true))
            {
                return 2;
            }
            operands += 1;
        }
    }
    if (operators > (operands-1))
    {
        return 1;
    }
    return -1;
}

bool BracketCheck(string e)
{
    int noOfBrackets = 0;
    for (int i = 0; i < e.length(); i++)
    {
        if (e[i] == '(' | e[i] == ')')
        {
            noOfBrackets += 1;
        }
    }
    Stk<char> b(noOfBrackets);
    for (int i = 0; i < e.length(); i++)
    {
        if (e[i] == '(')
        {
            b.push(e[i]);
        }
        if (e[i] == ')')
        {
            if (b.isEmpty())
            {
                return false;
            }
            b.pop();
        }
    }
    return(b.isEmpty());
}

string InfixToPostFix(string expression)
{
    Stk<char> s(expression.length());
    char token;
    string postfix = "";
    for (int i = 0; i < expression.length(); i++)
    {
        token = expression[i];
        if (token == ' ')
        {
            continue;
        }
        else if (IsOperand(token) == true)
        {
            postfix += token;
        }
        else if (token == '(')
        {
            s.push(token);
        }
        else if (token == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (IsOperator(token) == true)
        {
            while (!s.isEmpty() && (precedence(s.top()) >= precedence(token)))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(token);
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.top();
        s.pop();
    }
    // cout<< postfix;
    return postfix;
}

#endif