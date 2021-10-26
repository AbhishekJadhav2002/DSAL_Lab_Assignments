// C++ program to Implement a stack
//using singly linked list
#include <bits/stdc++.h>
using namespace std;
 
// Declare linked list node
 
struct Node
{
    char data;
    struct Node* link;
};

class Stack
{
    // Utility function to add an element
    // data in the stack insert at the beginning
    public :
        struct Node* top;
        Stack()
        {
            top = NULL;
        }

        void push(char data)
        {
            // Create new node temp and allocate memory
            struct Node* temp;
            temp = new Node();

            // Check if stack (heap) is full.
            // Then inserting an element would
            // lead to stack overflow
            // if (!temp)
            // {
            //     cout << "\nHeap Overflow";
            //     exit(1);
            // }

            // Initialize data into temp data field
            temp->data = data;

            // Put top pointer reference into temp link
            temp->link = top;

            // Make temp as top of Stack
            top = temp;
        }

        // Utility function to check if
        // the stack is empty or not
        bool isEmpty()
        {
            return (top == NULL);
        }

        // Utility function to return top element in a stack
        int peek()
        {
            return top->data;
            // Check for empty stack
            // if (!isEmpty())
            //     return top->data;
            // else
            //     top = NULL;
        }

        // Utility function to pop top
        // element from the stack
        int pop()
        {
            struct Node* temp;

            // Check for stack underflow
            // if (top == NULL)
            // {
            //     // cout << "\nStack Underflow" << endl;
            //     exit(1);
            // }
            // else
            {
                // Top assign into temp
                temp = top;
                int removed;
                removed = top -> data;

                // Assign second node to top
                top = top->link;

                // Destroy connection between
                // first and second
                temp->link = NULL;

                // Release memory of top node
                free(temp);
                return removed;
            }
        }

        // Function to print all the
        // elements of the stack
        void display()
        {
            struct Node* temp;

            // Check for stack underflow
            if (top == NULL)
            {
                cout << "\nStack Underflow";
                exit(1);
            }
            else
            {
                temp = top;
                while (temp != NULL)
                {

                    // Print node data
                    cout <<" "<<temp->data;

                    // Assign temp link to temp
                    temp = temp->link;
                }
            }
        }
};
 
// Driver Code
// int main()
// {
//     Stack s;
//     int choice;
//     while (choice != 4)
//     {
//         cout<<"\nChoose Stack Operation -\n\t1. Push element\t\t2. Pop element\t\t3. Display elements\t4. Exit\n\t\t\t\tEnter choice (1/2/3/4) : ";
//         cin>>choice;
//         switch(choice)
//         {
//             case 1:
//                 int k;
//                 cout<<"\nEnter elements to be pushed  : ";
//                 cin>>k;
//                 s.push(k);
//                 continue;
            
//             case 2:
//                 if (s.isEmpty() == true)
//                 {
//                     cout<<"Stack is Empty, no element to be popped";
//                     continue;
//                 }
//                 else
//                 {
//                     cout<<"\nTop most element '"<<s.pop()<<"' popped\n";
//                     continue;
//                 }

//             case 3:
//                 if (s.isEmpty() == true)
//                 {
//                     cout<<"Stack is Empty ! no element to display, please choose push operation.\n";
//                     continue;
//                 }
//                 else
//                 {
//                     cout<<"\nStack elements from top to bottom are : [";
//                     s.display();
//                     cout<<" ]";
//                     continue;
//                 }

//             case 4:
//                 cout<<"\n\t\t\t----Program terminated----";
//                 return 0;
            
//             default :
//                 cout<<"\nInvalid Choice : "<<choice;
//         }
//     }  
//     return 0;
// }