/*
============================================================================
 Name : Expression_conversion.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 3
============================================================================
*/

#include<bits/stdc++.h>
#include "Stack.h"  //importing templated header Stack of type class
#include "Stack_Imple.cpp"  //importing Stack method definition(required to be imported)
#include <string>
#include <algorithm>
using namespace std;

// struct tabular
// {
//     char symbols;
//     char tab_stack;
//     char expression;
// };

class Expression_Conversion
{
    public :
        // struct tabular represent[20];
        string expression;
        int expression_length;
        // string symbols[20];  //done with this
        // string STACK[15];
        // int STACK_SIZE = 0;
        Expression_Conversion(string s)
        {
            expression = s;
            expression_length = expression.length();
            // for (int i = 0; i < expression_length; i++)
            // {
            //     if ((IsOperator(expression[i]) == true) | (expression[i] == '(') | (expression[i] == ')'))
            //     {
            //         STACK_SIZE++;
            //     }
            // }
            // string STACK[STACK_SIZE] = "";
        };
        string postfix = "";
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
            if (c >= 'A' && c <= 'Z')
                return true;
            if (c >= 'a' && c <= 'z')
                return true;
            if (c >= '0' && c <= '9')
                return true;
            return false;
        }

        bool IsOperator(char c)  
        {  
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
                return true;
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
                    operators++;
                }
                else
                {
                    if ((IsOperand(e[i-1]) == true) && (IsOperand(e[i]) == true))
                    {
                        return 2;
                    }
                    operands++;
                }
            }
            if (operators < (operands-1))
            {
                return 1;
            }
            return -1;
        }

        bool BracketCheck(string e)
        {
            stack<char> b;
            for (int i = 0; i < e.length(); i++)
            {
                if (e[i] == '(')
                {
                    b.push(e[i]);
                }
                // if (b.isEmpty())
                // {
                //     return false;
                // }
                if (e[i] == ')')
                {
                    b.pop();
                }
            }
            return(b.empty());
        }

        string InfixToPostFix()
        {
            // int NoOfOperants = 0;
            Stack<char> s(expression_length);
            char token;
            for (int i = 0; i < expression_length; i++)
            {
                token = expression[i];
                // symbols[i] += token;
                // represent[i].symbols += token;
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
                    // STACK[NoOfOperants] = token;
                    // NoOfOperands++;
                    // represent[NoOfOperants].tab_stack += token;
                    // NoOfOperants++;
                }
                else if (token == ')')
                {
                    // STACK[NoOfOperants] = token;
                    // NoOfOperants++;
                    while (s.top() != '(')
                    {
                        postfix += s.top();
                        // represent[NoOfOperants].tab_stack += s.top();
                        // NoOfOperants++;
                        s.pop();
                    }
                    s.pop();
                }
                else if (IsOperator(token) == true)
                {
                    // STACK[NoOfOperants] = token;
                    // NoOfOperants++;
                    while (!s.isEmpty() && (precedence(s.top()) >= precedence(token)))
                    {
                        postfix += s.top();
                        // represent[NoOfOperants].tab_stack += s.top();
                        // NoOfOperants++;
                        s.pop();
                    }
                    s.push(token);
                }
            }
            while (!s.isEmpty())
            {
                postfix += s.top();
                // represent[NoOfOperants].tab_stack += s.top();
                // NoOfOperants++;
                s.pop();
            }
            // cout<< postfix;
            return postfix;
        }
};

int main()
{
    After_Invalid_Operators :
    string infix;
    cout<<"\nEnter infix Expression : ";
    cin>>infix;
    Expression_Conversion exp(infix);
    if (exp.BracketCheck(infix) == false)
    {
        cout<<"\n!!! Invalid pair of brackets entered! Please enter the correct expression !!!\n";
        goto After_Invalid_Operators;
    }
    else
    {
        switch(exp.OperatorValidity(infix))
        {
            case 0:
                cout<<"\n!!! Invalid Infix Expression entered! Operator ['"<<infix[0]<<"'] at beginning !!!\n";
                goto After_Invalid_Operators;

            case 1:
                cout<<"\n!!! Invalid no. of operators entered! Please enter the correct expression !!!\n";
                goto After_Invalid_Operators;

            case 2:
                cout<<"\n!!! Invalid! Some operands are entered one after another; Please enter the correct expression !!!\n";
                goto After_Invalid_Operators;
        }
    }
    // cout<<"------------------------------------------------------------\n\tSYMBOL\t|\tSTACK\t  |\tEXPRESSION\n------------------------------------------------------------\n";
    // for (int i = 0; i < infix.length(); i++)
    // {
    //     cout<<"\t\t"<<exp.represent[i].symbols<<"\t\t\t"<<exp.represent[i].tab_stack<<"\n";
    // }
    int tc = 2;
    while (tc != 0)
    {
        cout<<"Select Conversion Method >\n\t1. Prefix Conversion\t2. Postfix Conversion\n\t\tEnter Choice (1/2) : ";
        int choice;
        cin>>choice;
        if (choice == 2)
        {
            cout<<"\nPostfix Expression is : "<<exp.InfixToPostFix()<<"\n\n";
            tc--;
            continue;
        }
        else if (choice == 1)
        {
            cout<<"\nPrefix Expression is : ";
            string answer = exp.InfixToPostFix();
            reverse(answer.begin(), answer.end());
            cout<<answer<<"\n\n";
            tc--;
            continue;
        }
        else
        {
            cout<<"\n\tInvalid Choice! Exiting from code...";
            return 0;
        }
    }
};