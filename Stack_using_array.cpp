#include<bits/stdc++.h>
using namespace std;

class Stack
{
    private :
        int size;
        int stack_array[5];
        int top = -1;

    public :
        Stack(int s)
        {
            size = s;
        };

        bool isFull()
        {
            if (top == size - 1)
            {
                return true;
            }
            return false;
        }

        bool isEmpty()
        {
            if (top < 0)
            {
                return true;
            }
            return false;
        }

        void push(int n)
        {
            top += 1;
            stack_array[top] = n;
        }

        int pop()
        {
            top--;
            return stack_array[top];
        }

        void display()
        {
            for (int i = top; i >= 0; i--)
            {
                cout<<stack_array[i]<<" ";
            }
        }
};

int main()
{
    cout<<"Enter size of the stack you want : ";
    int size;
    cin>>size;
    Stack s(size);
    int choice;
    while (choice != 4)
    {
        cout<<"\nChoose Stack Operation -\n\t1. Push element\t\t2. Pop element\t\t3. Display elements\t4. Exit\n\t\t\t\tEnter choice (1/2/3/4) : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                if (s.isFull() == true)
                {
                    cout<<"Stack is full ! Please pop an element\n";
                    continue;
                }
                else
                {
                    int k;
                    cout<<"\nNo. of elements to be pushed (<"<<size<<") : ";
                    cin>>k;
                    cout<<"\n    Enter "<<k<<" elements to pushed : ";
                    for (int i = 0; i < k; i++)
                    {
                        int n;
                        cin>>n;
                        s.push(n);
                    }
                    continue;
                }
            
            case 2:
                if (s.isEmpty() == true)
                {
                    cout<<"Stack is Empty, no element to be popped";
                    continue;
                }
                else
                {
                    cout<<"\nTop most element '"<<s.pop()<<"' popped\n";
                    continue;
                }

            case 3:
                if (s.isEmpty() == true)
                {
                    cout<<"Stack is Empty, no element to display, please choose push operation";
                    continue;
                }
                else
                {
                    cout<<"\nStack elements from top to bottom are : [";
                    s.display();
                    cout<<" ]";
                    continue;
                }

            case 4:
                cout<<"\n\t\t\t----Program terminated----";
                return 0;
            
            default :
                cout<<"\nInvalid Choice : "<<choice;
        }
    }
}