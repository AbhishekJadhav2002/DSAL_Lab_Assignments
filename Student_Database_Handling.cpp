/*
============================================================================
 Name : Student_Database_Handling.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 10
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

struct DoB
{
    int day, month, year;
};

struct StudentForm
{
    int roll_no;
    string stud_name, stud_address;
    DoB stud_DoB;
    float stud_percent;
};

class DatabaseFile
{
    StudentForm stud_rec;  //single declaration for simplified usage of struct StudentForm
    public :
        void CreateAFile();
        void AddNewRecord();
        void DisplayFileContent();
        void SearchRecord();
        void ModifyRecord();
        void DeleteRecord();
};

void DatabaseFile :: CreateAFile()
{
    ifstream file_exist("StudentData.dat");
    if(file_exist)  //validity to check if file needs to be created again or exist already
    {
        cout<<"\nFile 'StudentData.dat' already exist in this directory !\nFile contents are...";
        DatabaseFile :: DisplayFileContent();
        return;
    }
    fstream file("StudentData.dat", ios::out | ios::binary);  //open file in write mode to create new database
    cout<<"\nNew file StudentData.dat created..\n";
    AddNewRecord();  //add initial record
    file.close();
}

void DatabaseFile :: AddNewRecord()
{
    cout<<"\nFill student details :\nRoll No. : ";
    cin>>stud_rec.roll_no;
    cin.ignore();
    fstream write_file("StudentData.dat", ios::app | ios::binary); //open file in append mode
    fstream read_file("StudentData.dat", ios::in | ios::binary); //open file in read with different pointer
    StudentForm s1;
    read_file.read((char*)&s1, sizeof(s1));
    int flag_interating_through_file = 1;
    while(!read_file.eof())  //read file till end for roll no. validity check
    {
        if(s1.roll_no == stud_rec.roll_no)
        {
            cout<<"\nStudent with roll no. "<<stud_rec.roll_no<<" already exist !\n";
            flag_interating_through_file = 0;
            break;
        }
        else
        {
            read_file.read((char*)&s1, sizeof(s1));  //read next record
        }
    }
    if(flag_interating_through_file == 1)  //if roll no. is unique then only write to the file
    {
        cout<<"\nName : ";
        getline(cin, stud_rec.stud_name);
        cout<<"\nAddress : ";
        getline(cin, stud_rec.stud_address);
        cout<<"\nDate of birth(DD/MM/YYYY) : ";
        string date;
        getline(cin, date);
        stud_rec.stud_DoB.day = stoi(date.substr(0, 2));
        stud_rec.stud_DoB.month = stoi(date.substr(3, 2));
        stud_rec.stud_DoB.year = stoi(date.substr(6, 4));
        cout<<"\nPercentage marks : ";
        cin>>stud_rec.stud_percent;
        write_file.write((char*)&stud_rec, sizeof(stud_rec));  //write to the file
        cout<<"\nRecord added successfully to the file !\n";
    }
    read_file.close();
    return;
}

void DatabaseFile :: DisplayFileContent()
{
    fstream read_file;
    read_file.open("StudentData.dat", ios::in | ios::binary);
    if(!read_file)  //file not found
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        read_file.read((char*)&stud_rec, sizeof(stud_rec));  //read first record
        cout<<"\nRoll No.\tName\t\tDoB\t\tPercentage\tAddress\n---------------------------------------------------------------------------";
        while(!read_file.eof())  //read file till  end of file
        {
            cout<<"\n"<<stud_rec.roll_no<<"\t\t"<<stud_rec.stud_name<<"\t"<<stud_rec.stud_DoB.day<<"/"<<stud_rec.stud_DoB.month<<"/"<<stud_rec.stud_DoB.year<<"\t"<<stud_rec.stud_percent<<"\t\t"<<stud_rec.stud_address;
            read_file.read((char*)&stud_rec, sizeof(stud_rec));  //read next record
        }
    }
    read_file.close();
}

void DatabaseFile :: SearchRecord()
{
    fstream read_file("StudentData.dat", ios::in | ios::binary);  //open file in reading mode
    if(!read_file)
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        bool flag = false;
        cout<<"\nEnter roll no. to be searched : ";
        int key;
        cin>>key;
        read_file.read((char*)&stud_rec, sizeof(stud_rec)); //read first record
        while(!read_file.eof())  //search till end of file
        {
            if(stud_rec.roll_no == key)  //if key is equal to correct roll number
            {
                cout<<"\nRecord found !\n";
                flag = true;  //set flag
                cout<<"\nRoll No.\tName\t\tDoB\t\tPercentage\tAddress\n---------------------------------------------------------------------------";
                cout<<"\n"<<stud_rec.roll_no<<"\t\t"<<stud_rec.stud_name<<"\t"<<stud_rec.stud_DoB.day<<"/"<<stud_rec.stud_DoB.month<<"/"<<stud_rec.stud_DoB.year<<"\t"<<stud_rec.stud_percent<<"\t\t"<<stud_rec.stud_address;  //display student details
                break;
            }
            else
            {
                read_file.read((char*)&stud_rec, sizeof(stud_rec)); //read next record
            }
        }
        if(!flag)  //if roll no. is not found
            cout<<"\nRecord not found !\n";
    }
    read_file.close();
}

void DatabaseFile :: ModifyRecord()
{
    cout<<"\nEnter roll no. of the student : ";
    int rno, flag = 0;
    cin>>rno;
    fstream read_file("StudentData.dat", ios::in | ios::binary);  //open file in read mode
    fstream newFile("temp.dat", ios::out | ios::binary);  //create new temp file for temporary data storage
    if(!read_file)
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        read_file.read((char*)&stud_rec, sizeof(stud_rec));
        while(!read_file.eof())
        {
            if(stud_rec.roll_no != rno)  //if current record is not that to be updated
            {
                newFile.write((char*)&stud_rec, sizeof(stud_rec));  //write to the temp file
            }
            else  //if current record is that ts to be updated
            {
                cout<<"\nRecord Found !\n";
                flag = 1;
                cout<<"\nFill student details :\nRoll No. : "<<rno;
                stud_rec.roll_no = rno;
                cin.ignore();
                cout<<"\nName : ";
                getline(cin, stud_rec.stud_name);
                cout<<"\nAddress : ";
                getline(cin, stud_rec.stud_address);
                cout<<"\nDate of birth(DD/MM/YYYY) : ";
                string date;
                getline(cin, date);
                stud_rec.stud_DoB.day = stoi(date.substr(0, 2));
                stud_rec.stud_DoB.month = stoi(date.substr(3, 2));
                stud_rec.stud_DoB.year = stoi(date.substr(6, 4));
                cout<<"\nPercentage marks : ";
                cin>>stud_rec.stud_percent;
                newFile.write((char*)&stud_rec, sizeof(stud_rec));  //write to the file
                cout<<"\nRecord updated successfully to the file !\n";  //write updated record to the temp file
            }
            read_file.read((char*)&stud_rec, sizeof(stud_rec));  //read next record from the
        }
        read_file.close();
        newFile.close();
        remove("StudentData.dat");
        rename("temp.dat", "StudentData.dat");
        if(flag == 0)  //flag remained same then
        {
            cout<<"\nRecord with roll no. "<<rno<<" is not found in the file 'StudentData.dat'\n";
        }
    }
}

void DatabaseFile :: DeleteRecord()
{
    cout<<"\nEnter roll no. of the student : ";
    int rno, flag = 0;
    cin>>rno;
    fstream read_file("StudentData.dat", ios::in | ios::binary);  //open file in read mode
    fstream newFile("temp.dat", ios::out | ios::binary);  //create new temp file for temporary data storage
    if(!read_file)
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        read_file.read((char*)&stud_rec, sizeof(stud_rec));
        while(!read_file.eof())
        {
            if(stud_rec.roll_no != rno)  //if current record is not that to be updated
            {
                newFile.write((char*)&stud_rec, sizeof(stud_rec));  //write to the temp file
            }
            else  //if current record is that ts to be updated
            {
                cout<<"\nRecord Found and Deleted!\n";
                flag = 1;
            }
            read_file.read((char*)&stud_rec, sizeof(stud_rec));  //read next record from the
        }
        read_file.close();
        newFile.close();
        remove("StudentData.dat");
        rename("temp.dat", "StudentData.dat");
        if(flag == 0)  //flag remained same then
        {
            cout<<"\nRecord with roll no. "<<rno<<" is not found in the file 'StudentData.dat'\n";
        }
    }
}

int main()
{
    DatabaseFile fileOp;
    int ch;
    do
    {
        cout<<"\n================================================================MENUS================================================================\n\nChoose Operation -\n1.Create File \t2.Add Record\t3.View Records  \t4.Search Record \t5.Modify Record \t6.Delete Record \t7.Exit\n\t\t\t\t\t \t Choose Operation : ";
        cin>>ch;
        cout<<"\n====================================================================================================================================="<<endl;
        switch(ch)
        {
            case 1:
                fileOp.CreateAFile();
                break;
            case 2:
                fileOp.AddNewRecord();
                break;
            case 3:
                fileOp.DisplayFileContent();
                break;
            case 4:
                fileOp.SearchRecord();
                break;
            case 5:
                fileOp.ModifyRecord();
                break;
            case 6:
                fileOp.DeleteRecord();
                break;
            case 7:
                cout<<"\n--- Program Terminated ---\n";
                return 0;
            default:
                cout<<"\nEnter Valid Operation\n";
                break;
        }
    }while(true);
    return 0;
}