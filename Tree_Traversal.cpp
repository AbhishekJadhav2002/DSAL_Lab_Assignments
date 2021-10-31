/*
============================================================================
 Name : Tree_Traversal.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 4
============================================================================
*/
#include<bits/stdc++.h>
#include "Expression_conversion_Imple.h"
#include "Tree_Traversal_Imple.h"
using namespace std;

int main()
{
    After_Invalid_Operators :
    string infix;
    cout<<"\nEnter Infix Expression : ";
    cin>>infix;
    if (BracketCheck(infix) == false)
    {
        cout<<"\n!!! Invalid pair of brackets entered! Please enter the correct expression !!!\n";
        goto After_Invalid_Operators;
    }
    else
    {
        switch(OperatorValidity(infix))
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

            case -1:
                break;
        }
    }
    cout<<"\nPostfix Expression is : "<<InfixToPostFix(infix);
    Expression<char> e(InfixToPostFix(infix));
    while(true)
    {
        cout<<"\n\nSelect Tree Traversal ->\t1.Inorder(Infix)\t2.Preorder(Prefix)\t3.Postorder(Postfix)\n\t\t\t\t\t\tEnter Choice : ";
        int t;
        cin>>t;
        switch(t)
        {
            case 1:
                cout<<"\nInorder Traversal Algorithm ->\t1.Recursive\t2.Without Recursive\n\t\t\t\tEnter Choice : ";
                int I;
                cin>>I;
                switch(I)
                {
                    case 1:
                        cout<<"\n\nExpression "<<infix<<" in Inorder Traversal using Recursion : ";
                        e.InorderRec(e.create_Post());
                        continue;

                    case 2:
                        cout<<"\n\nExpression "<<infix<<" in Inorder Traversal without Recursion : ";
                        e.InorderWithoutRec(e.create_Post());
                        continue;
                }
                continue;

            case 2:
                cout<<"\nPreorder Traversal Algorithm ->\t1.Recursive\t2.Without Recursive\n\t\t\t\tEnter Choice : ";
                int Pre;
                cin>>Pre;
                switch(Pre)
                {
                    case 1:
                        cout<<"\n\nExpression "<<infix<<" in Preorder Traversal using Recursion : ";
                        e.PreorderRec(e.create_Post());
                        continue;

                    case 2:
                        cout<<"\n\nExpression "<<infix<<" in Preorder Traversal without Recursion : ";
                        e.PreorderWithoutRec(e.create_Post());
                        continue;
                }
                continue;

            case 3:
                cout<<"\nPostorder Traversal Algorithm ->\t\t1.Recursive\t2.Without Recursive\n\t\t\t\t\tEnter Choice : ";
                int P;
                cin>>P;
                switch(P)
                {
                    case 1:
                        cout<<"\n\nExpression "<<infix<<" in Postorder Traversal using Recursion : ";
                        e.PostorderRec(e.create_Post());
                        continue;

                    case 2:
                        cout<<"\n\nExpression "<<infix<<" in Postorder Traversal without Recursion : ";
                        e.PostorderWithoutRec(e.create_Post());
                        continue;
                }
                continue;

            default:
                cout<<"\n\n\t---Program Terminated---";
                break;
        }
    }
}