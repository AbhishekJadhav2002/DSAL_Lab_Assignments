/*
============================================================================
 Name : Student_Database_using_class_n_sorting.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 1
============================================================================
*/

#include<bits/stdc++.h>
using namespace std;
struct name
{
    char firstname[10];
    char lastname[12];
};


struct profile
{
    name student_name;
    float SGPA;
    int Roll_no;
};


class student_data
{
    private :
        
        struct profile std_db[15]={"Abhishek", "Jadhav", 9.89, 23232, "Abhijeet", "Ingle", 9.8, 23231, "Ronal", "Dhodia", 9.54, 23222, "Pratik", "Gabhale", 9.12, 23224, "Ayush", "Gala", 9.65, 23228, "Kunal", "Kachare", 9.5, 23235, "Mihir", "Inamdar", 9.01, 23230, "Sanika", "Joshi", 9.2, 23234, "Atharva", "Kinikar", 9.8, 23241, "Mrunal", "Kashid", 9.45, 23238, "Kalyani", "Nilpankar", 8.97, 23237, "Tanmay", "Goregaonkar", 8.85, 23227, "Shruti", "Jagdale", 9.74, 23233, "Sandesh", "Dholas", 8.86, 23223, "Akshay", "K", 8.98, 23242};
        int n = 15;
    
    public :
        
        void view(int n)
        {
            cout<<"\n\n Student        Name                 SGPA        Roll\n   No.                                           No.\n--------------------------------------------------------------\n";
            for (int i = 0; i <= n-1; i++)
            {
                cout<<"    "<<i+1<<".        "<<std_db[i].student_name.firstname<<" "<<std_db[i].student_name.lastname;
                cout<<"   ->>-  "<<std_db[i].SGPA<<"   ->>-  "<<std_db[i].Roll_no<<"\n\n";
            }
        }

        void add()
        {
                cout<<"\n Enter no. of Student details to be added (max 15) : ";
                int n;
                cin>>n;
                cout<<"\n ------------ No. of Students to added : "<<n<<" -----------\n      Filling data such as Name, SGPA, Roll no.\n ------------------------------------------------------";
                for ( int i = 2; i < 2+n; i++)
                {
                    cout<<"\n\n# Details of Student no. "<<i+1<<" - \n\n                             FirstName Surname\n  > Enter Name of Student : ";
                    cin>>std_db[i].student_name.firstname>>std_db[i].student_name.lastname;
                    cout<<"\n  > Enter Student SGPA : ";
                    cin>>std_db[i].SGPA;
                    cout<<"\n  > Enter Student Roll no. : ";
                    cin>>std_db[i].Roll_no;
                    cout<<" --------------------------------------------------------------";
                }
                cout<<"---------------- Addition Done Successfully ! ----------------";
                student_data :: view(15);
        }

        void search_sgpa(float r)  //linear search on SGPA
        {
            cout<<"\n\n< Searching in SGPA using Linear Search...>\n-----------------------------------------------";
            int t = 1;
            for (int i = 0; i < n; i++)
            {
                if(std_db[i].SGPA == r)
                {
                    cout<<"\n\n#"<<t<<" Details of Student with SGPA "<<std_db[i].SGPA<<" -";
                    cout<<"\n\n Student        Name                 SGPA        Roll\n    No.                                          No.\n--------------------------------------------------------------\n";
                    cout<<"    "<<i+1<<".        "<<std_db[i].student_name.firstname<<" "<<std_db[i].student_name.lastname;
                    cout<<"   ->>-  "<<std_db[i].SGPA<<"   ->>-  "<<std_db[i].Roll_no;
                    cout<<"\n--------------------------------------------------------------";
                    t++;
                    continue;
                }
            }
            if(t == 0)
            {
                cout<<"\n Student '"<<r<<"' not found or Input correct SGPA";
            }
        }

        void modify()
        {
            cout<<"\n Enter Student no. which is to be modified : ";
            int m;
            cin>>m;
            int m_i = m - 1;
            for (int i = 0; i < 15; i++)
            {
                if ( i == m_i)
                {
                    char stopModify = 'Y';
                    while (stopModify == 'Y')
                    {
                        cout<<"\n# Modify - \t1. Name\t\t2. SGPA\t\t3. Student Roll no.\n  Choice (1/2/3): ";
                        int choice;
                        cin>>choice;
                        switch(choice)
                        {
                            case 1:
                                cout<<"                             FirstName Surname\n  > Enter Name of Student : ";
                                cin>>std_db[i].student_name.firstname>>std_db[i].student_name.lastname;
                                cout<<" -------- Changes Done Successfully ! --------";
                                student_data :: view(15);
                                break;
                            case 2:
                                cout<<"\n  > Enter Student SGPA : ";
                                cin>>std_db[i].SGPA;
                                cout<<" -------- Changes Done Successfully ! --------";
                                student_data :: view(15);
                                break;
                            case 3:
                                cout<<"\n  > Enter Student Roll_no : ";
                                cin>>std_db[i].Roll_no;
                                cout<<" -------- Changes Done Successfully ! --------";
                                student_data :: view(15);
                                break;
                            default:
                                cout<<" Invalid choice !\n -------------------------------------------";
                        }
                        cout<<"\nDo you want to continue modification (Y/N) ? : ";
                        cin>>stopModify;
                        cout<<" -------------------------------------------\n";
                    }
                    break;
                }
                else
                {
                    cout<<"\n Student no. is out of range or Invalid input";
                }
            }
        }

        void sort_names(int n)  //insertion sort for sorting names
        {
            for (int k=n-1; k>0; k--)
            {  
                struct profile temp = std_db[k];
                int j = k-1;
                while (j >= 0 && strcmp(temp.student_name.firstname, std_db[j].student_name.firstname) < 0)  //compares both the strings character by character
                {
                    std_db[j+1] = std_db[j];
                    j = j-1;
                }
                std_db[j+1] = temp;
            }
        }

        void sort_SGPA(int l, int k)  //sorting SGPA using quick sorting
        {
            int r = k-1;
            if (l>=r) return;
            int i=l;
            int j=r+1;
            struct profile prec;
            int p = std_db[l].SGPA; //Select pivot element
            prec = std_db[l]; //temporarily storing pivot record prec
            while(1)
            {
                do{ i++; } while (std_db[i].SGPA < p && i <= r);
                do{ j--; } while (std_db[j].SGPA > p && j >= l);
                if(i >= j) break;
                struct profile temp;
                temp = std_db[j];
                std_db[j] = std_db[i];
                std_db[i] = temp;
            }
            std_db[l] = std_db[j];
            std_db[j] = prec;
            sort_SGPA(l,j); //left list
            sort_SGPA(j+1,r); //right list
            student_data :: view(10);
        }

        void sort_RollNo()  //sorting roll no. in ascending order using bubble sort
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n-1; j++)
                {
                    if((std_db[j].Roll_no) < (std_db[j+1].Roll_no)) //Swapping
                    {
                        struct profile temp;
                        temp = std_db[j];
                        std_db[j] = std_db[j+1];
                        std_db[j+1] = temp;
                    }
                }
            }
            student_data :: view(n);
        }

        void search_name()
        {
            cout<<"\n Enter student name to be searched : ";
            char search[10];
            cin>>search;
            cout<<"\n< Searching name using Binary Search...>";
            int lower = 0, upper, mid;
            upper = n - 1;
            mid = (lower + upper)/2;
            student_data :: sort_names(n);
            while (lower <= upper)
            {
                if(strcmp(std_db[mid].student_name.firstname, search)<0)
                {
                    lower = mid + 1;
                }
                else if(strcmp(std_db[mid].student_name.firstname, search)==0)
                {
                    cout<<"\n\n# Details of Student with name "<<std_db[mid].student_name.firstname<<" -";
                    cout<<"\n\n Student        Name                 SGPA        Roll\n    No.                                           No.\n--------------------------------------------------------------\n";
                    cout<<"    1.        "<<std_db[mid].student_name.firstname<<" "<<std_db[mid].student_name.lastname;
                    cout<<"   ->>-  "<<std_db[mid].SGPA<<"   ->>-  "<<std_db[mid].Roll_no;
                    cout<<"\n--------------------------------------------------------------";
                    break;
                }
                else
                {
                    upper = mid - 1;
                    mid = (lower + upper)/2;
                }
            }
            if(lower > upper)
            {
                cout<<"\n Student '"<<search<<"' details not found or Input correct name";
            }
        }
};


int main()
{
    struct profile std_db[15]={"Abhishek", "Jadhav", 9.89, 23232, "Abhijeet", "Ingle", 9.8, 23231, "Ronal", "Dhodia", 9.54, 23222, "Pratik", "Gabhale", 9.12, 23224, "Ayush", "Gala", 9.65, 23228, "Kunal", "Kachare", 9.5, 23235, "Mihir", "Inamdar", 9.01, 23230, "Sanika", "Joshi", 9.2, 23234, "Atharva", "Kinikar", 9.8, 23241, "Mrunal", "Kashid", 9.45, 23238, "Kalyani", "Nilpankar", 8.97, 23237, "Tanmay", "Goregaonkar", 8.85, 23227, "Shruti", "Jagdale", 9.74, 23233, "Sandesh", "Dholas", 8.86, 23223, "Akshay", "K", 8.98, 23242};
    student_data std;
    cout<<"--------------------------------------------------------------------\n\t\t----- SE IT Student Database -----\n--------------------------------------------------------------------\n";
    std.view(15);
    char stopApp;
    stopApp = 'Y';
    while(stopApp == 'Y')
    {
        cout<<"\n\nSelect action from following : \n";
        cout<<"> 1. VIEW RECORDS\t> 2. ADD RECORDS\t> 3. MODIFY RECORD\t> 4. SEARCH SGPA\t> 5. SORT NAME\t\t> 6. SORT SGPA(Toppers)\t\t> 7. SORT ROLL NO.\t\t> 8. SEARCH NAME\t> 9. EXIT\n\t\t\t\t\t\t\t\t\tEnter choice (1/2/3/4/5/6/7/8/9): ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                std.view(15);
                break;
            case 2:
                std.add();
                break;
            case 3:
                std.modify();
                break;
            case 4:
                cout<<"\n Enter Student SGPA to be searched : ";
                float r;
                cin>>r;
                std.search_sgpa(r);
                break;
            case 5:
                cout<<"\n< Sorting name alphabetically using Insertion Sort...>";
                std.sort_names(15);
                std.view(15);
                break;
            case 6:
                cout<<"\n< Sorting top 10 SGPA using Quick Sort...>";
                std.sort_SGPA(0, 10);
                break;
            case 7:
                cout<<"\n< Sorting Roll No. wise using Bubble Sort...>";
                std.sort_RollNo();
                break;
            case 8:
                std.search_name();
                break;
            case 9:
                cout<<" >Exited successful<\n --| END OF CODE |--";
                return 0;
            default :
                cout<<"\n Invalid choice !";
        }
        cout<<"\n\nDo you want to continue (Y/N) ? : ";
        cin>>stopApp;
        if (stopApp == 'N' | 'n')
        {
            cout<<" ----------------| END OF CODE |----------------\n";
        }
    }
    return 0;
}
