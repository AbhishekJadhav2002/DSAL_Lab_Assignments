#include<bits/stdc++.h>
#include "Stack_using_array.cpp"
#include <string>
#include <algorithm>
// #include <stack> 
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
            else if (c == '*' || c =='/')
            {
                return 2;
            }
            else if (c == '+' || c =='-')
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
        Stack s(expression_length);
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
        while (s.peek() != -1)
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