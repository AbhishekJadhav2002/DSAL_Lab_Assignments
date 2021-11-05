/*
============================================================================
 Name : Binary_Tree.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 5
============================================================================
*/

#include <bits/stdc++.h>
#include "Binary_Tree_Header.h"
#include <vector>
#include <exception>
using namespace std;

int main()
{
    Binary_Tree<int> BT;
    cout<<"\t\t\t\t\t\t\t\t---------- Binary Seach Tree ----------";
    Functions_after_switch :
    {
        cout<<"\n\nFuntions -\n\t1. Insert Array \t2. Delete Element\t3. Search\t4. Display Tree \t5. Mirror Convert\t6. Copy Tree\t7. Leaf Nodes\t8. LevelWise Traversal\n\t\t\t\t\t\t\t\t\tEnter Choice : ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int input;
                vector<int> v;
                cout<<"\nEnter -1 to stop entering elements...\nEnter Elements : ";
                bool app = true;
                while(app)
                {
                    cin>>input;
                    if(input == -1){app = false;}
                    else{v.push_back(input);}
                }
                BT.InsertArray(&v.front(), v.size());
                cout<<"\nBinary Tree built is : ";
                BT.InorderRec(BT.GetRoot());
                goto Functions_after_switch;
            }      
            case 2:
            {
                cout<<"\nTree : ";BT.InorderRec(BT.GetRoot());
                int dlt_element;
                cout<<"\nEnter element to be deleted from above tree : ";
                cin>>dlt_element;
                BT.DeleteNode(BT.GetRoot(), dlt_element);
                cout<<"\n[ "<<dlt_element<<" deleted from tree ]";
                goto Functions_after_switch;
            }
            case 3:
            {
                int search_key;
                cout<<"\nEnter key to be searches in tree : ";
                cin>>search_key;
                BT.isPresent(search_key);
                goto Functions_after_switch;
            }
            case 4:
            {
                cout<<"\nDisplay Tree -\n\t1.Inorder\t2.Preorder\t3.Postorder\n\t\tSelect View : ";
                int view;
                cin>>view;
                switch(view)
                {
                    case 1:
                    {
                        cout<<"\nInorder Traversal(ascending) : "; BT.InorderRec(BT.GetRoot());
                        goto Functions_after_switch;
                    }
                    case 2:
                    {
                        cout<<"\nPreorder Traversal : "; BT.PreorderRec(BT.GetRoot());
                        goto Functions_after_switch;
                    }
                    case 3:
                    {
                        cout<<"\nPostorder Traversal : "; BT.PostorderRec(BT.GetRoot());
                        goto Functions_after_switch;
                    }
                }
            }
            case 5:
            {
                cout<<"\nBinary Tree before mirroring : ";BT.InorderRec(BT.GetRoot());
                cout<<"\nBinary Tree after mirroring : ";BT.MirrorImage(BT.GetRoot());BT.InorderRec(BT.GetRoot());
                cout<<"\n[ Don't forget to select Mirroring Tree option again ]";
                goto Functions_after_switch;
            }
            case 6:
            {
                cout<<"\nCoping Tree1 to Tree2 -> Tree1 : ";BT.InorderRec(BT.GetRoot());
                Node<int>* tree2;
                cout<<"\n                           Tree2 : ";BT.copyTree(tree2, BT.GetRoot());
                goto Functions_after_switch;
            }
            case 7:
            {
                cout<<"\nDisplying Leaf Nodes : ";
                BT.DisplayLeafNodes(BT.GetRoot());
                goto Functions_after_switch;
            }
            case 8:
            {
                cout<<"\nLevel Wise Traversal : ";BT.DisplayLevelWise(BT.GetRoot());
                goto Functions_after_switch;
            }
            default :
            {
                cout<<"\n\n\t\t----Program Terminated----\n";
                return 0;
            }
        }
    }
}