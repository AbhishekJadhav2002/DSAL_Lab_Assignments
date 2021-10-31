/*
============================================================================
 Name : Patients_database_circular_queue.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 2
============================================================================
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;
#define size 3

struct patient_name
{
    string firstname;
    string lastname;
};

struct patient
{
    patient_name name;
    int age;
    string disease;
};


class patientQ
{
    private:
        int front, rear;
        struct patient s[size];

    public:
        patientQ()
        {
            front = -1;
            rear = -1;
        };

        bool isQueueFull()
        {
            if ((rear == size-1) || ((front == rear+1)))
            {
                return true;
            }
            // else if (front == (rear + 1))
            // {
            //     return true;
            // }
            else
            {
                return false;
            }
        }
        
        void enqueue(string fname, string lname, string d, int ag)
        {
            // if (rear == front)
            // {
            //     cout<<"\n\n _____ Currently queue is Overflowed ! _____";
            //     return;
            // }
            if (front == -1)
            {
                front = 0;
                rear = 0;  //addition
            }
            int temp = (rear+1)%size;
            s[rear].name.firstname = fname;
            s[rear].name.lastname = lname;
            s[rear].disease = d;
            s[rear].age = ag;
            // rear = temp;
        }

        bool isQueueEmpty()
        {
            if (front == -1)
            {
                return true;
            }
            else if (front == -1 && rear == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        string dequeue()
        {
            {
                struct patient garbage;
                garbage = s[(size - rear)%size];
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1)%size;
                }
                return (garbage.name.firstname);
            }
        }

        void view(int sz)
        {
            cout<<"\n\n Patient        Name              Age        Disease\n   No.                                           \n--------------------------------------------------------------\n";
            for (int i = 0; i < sz; i++)
            {
                cout<<"    "<<(i+1)<<".        "<<s[i].name.firstname<<" "<<s[i].name.lastname;
                cout<<"   ->>-  "<<s[i].age<<"   ->>-  "<<s[i].disease<<"\n\n";
            }
        }
};

int main()
{
    cout<<"-------------------------------------------------------------\n\t----- Standing in the Hospital Queue  -----\n-------------------------------------------------------------\n\n\t\t   /__Garbage Values__/";
    patientQ p;
    p.view(size);
    char stopApp[0];
    stopApp[0] = 'Y';
    int i = 0;
    while(true)
    {
        cout<<"\n\nSelect action from following : \n";
        cout<<" > 1. VIEW RECORDS\t> 2. ENQUEUE RECORDS\t> 3. DEQUEUE RECORD\t> 4. EXIT\n\t\t\tEnter choice (1/2/3/4): ";
        int choice;
        cin>>choice;
        (choice == 2)? i += 1 : 0;
        switch(choice)
        {
            case 1:
                p.view(size);
                break;

            case 2:
                if (p.isQueueFull() == false)
                {
                    string firstname, lastname, disease;
                    int age;
                    cout<<"\nPatient details -\n    "<<i<<".        Enter Patient Name : ";
                    cin>>firstname;
                    cin>>lastname;
                    cout<<"              Enter Age : ";
                    cin>>age;
                    cout<<"              Enter Disease : ";
                    cin>>disease;
                    p.enqueue(firstname, lastname, disease, age);
                    p.view(size);
                    break;
                }
                else
                {
                    cout<<"\n\n ______ Currently queue is Full ! ______\n    Please dequeue to get a empty spot\n";
                    break;
                }

            case 3:
                if (p.isQueueEmpty() == true)
                {
                    cout<<"\n\n _____ Currently queue is Empty ! _____";
                    break;
                }
                else
                {
                    cout<<"\n----------------- Last Patient '"<<p.dequeue()<<"' Discharged ! -----------------\n";
                    i--;
                    break;
                }

            case 4:
                cout<<" >Exited Hospital<\n --| END OF CODE |--";
                break;

            default :
                cout<<"\n Invalid choice !";
                break;
        }
        if (choice == 4)
        {
            break;
        }
        cout<<"\nDo you want to continue (Y/N) ? : ";
        cin>>stopApp[0];
        if (stopApp[0] == 'N' | stopApp[0] == 'n')
        {
            cout<<"\n\t ----------------| END OF CODE |----------------";
        }
    }
}