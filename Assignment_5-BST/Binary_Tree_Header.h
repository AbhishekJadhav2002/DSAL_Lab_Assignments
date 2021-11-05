/*
============================================================================
 Name : Binary_Tree_Header.h
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 5
============================================================================
*/
#ifndef _Binary_Tree_H_
#define _Binary_Tree_H_
#include <bits/stdc++.h>
#include <queue>
#define max(a, b) (((a) > (b)) ? (a) : (b))  //defining user defined macro preprocessor function
using namespace std;

template<typename B>
struct Node
{
    B data;
    Node<B>* left;
    Node<B>* right;
};

template<typename B>
class Binary_Tree
{
    private :
        struct Node<B>* root;
    public :
        Binary_Tree()
        {
            root = NULL;
        }
        Node<B>* Makenode(B x);
        Node<B>* GetRoot();
        void Insert(B x);
        void InsertArray(B *arr, int size);
        bool isPresent(B k);
        // Node<B>* Search(B k);
        Node<B>* GetNodeOf(B k);
        Node<B>* DeleteNode(Node<B>* root, B k);
        Node<B>* findMin(Node<B>* root);
        void InorderRec(Node<B>*);
		void PreorderRec(Node<B>*);
		void PostorderRec(Node<B>*);
        int Height(Node<B>*);
        void MirrorImage(Node<B>*);
        void copyTree(Node<B>* tree1, Node<B>* tree2);
        void DisplayLeafNodes(Node<B>*);
        void DisplayLevelWise(Node<B>*);
};

template<typename B>
Node<B>* Binary_Tree<B> :: Makenode(B x)  //creates one node with data as parameter passed
{
    Node<B>* newNode = new struct Node<B>();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

template<typename B>
Node<B>* Binary_Tree<B> :: GetRoot()
{
    return root;
}

template<typename B>
void Binary_Tree<B> :: Insert(B x)
{
    if(root == NULL)
    {
        root = Makenode(x);
        return;
    }
    else
    {
        Node<B>* P = root;
        Node<B>* Q = root;
        while(Q != NULL && x != P->data)
        {
            P = Q;
            if(x < P->data)
            {
                Q = P->left;
            }
            else if(x > P->data)
            {
                Q = P->right;
            }
        }
        if(x == P->data)
        {
            cout<<"\n"<<x<<" is already present, Duplicates are not allowed";
            return;
        }
        if(x < P->data)
        {
            P->left = Makenode(x);
            return;
        }
        else
        {
            P->right = Makenode(x);
            return;
        }
    }
}

template<typename B>
void Binary_Tree<B> :: InsertArray(B *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        Binary_Tree :: Insert(*(arr + i));
    }
}

template<typename B>
bool Binary_Tree<B> :: isPresent(B k)
{
    if(root == NULL)
    {
        cout<<"\n[ Empty Tree ]";
        return false;
    }
    else
    {
        if(Binary_Tree :: GetNodeOf(k) != NULL)
        {
            cout<<"\n"<<k<<" is present in the tree";
            return true;
        }
        else
        {
            // cout<<"\nElement "<<k<<" not present in the tree";
            return false;
        }
    }
}

template<typename B>
Node<B>* Binary_Tree<B> :: GetNodeOf(B k)
{
    if(root == NULL)
    {
        root = Makenode(k);
        cout<<"\n[ Tree is empty, creating root node ]";
        return root;
    }
    else
    {
        Node<B>* p = root;
        while(p)
        {
            if(k == p->data)
            {
                return p;
            }
            else if(k < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        cout<<"\n[ Element "<<k<<" is not present in the tree returning NULL ]";
        return NULL;
    }
}

template<typename B>
Node<B>* Binary_Tree<B> :: DeleteNode(Node<B>* root, B k)
{
    if(root == NULL) {return NULL;}
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == k) {return NULL;}
        else {return root;}
    }
    Node<B>* key_node = NULL;
    Node<B>* temp;
    Node<B>* last;
    queue<Node<B>*> q;
    q.push(root);
    // Do level order traversal to find deepest
    // node(temp), node to be deleted (key_node)
      // and parent of deepest node(last)
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->data == k) {key_node = temp;}
        if(temp->left)
        {
            last = temp;//storing the parent node
            q.push(temp->left);
        }
        if(temp->right)
        {
            last = temp;// storing the parent node
            q.push(temp->right);
        }
    }
    if(key_node != NULL)
    {
        key_node->data = temp->data;//replacing key_node's data to deepest node's data
        if(last->right == temp) {last->right = NULL;}
        else {last->left = NULL;}
        delete(temp);
    }
    return root;
}

template<typename B>
Node<B>* Binary_Tree<B> :: findMin(Node<B>* root)
{
	Node<B>* c = root;
	while(c && c->left != NULL){c = c->left;}
	return c;
}

template<typename B>
void Binary_Tree<B> :: InorderRec(Node<B>* t)
{
    if(t != NULL)
    {
        InorderRec(t->left);
        cout<<t->data<<" ";
        InorderRec(t->right);
    }
}

template<typename B>
void Binary_Tree<B> :: PreorderRec(Node<B>* t)
{
    if(t != NULL)
    {
        cout<<t->data<<" ";
        PreorderRec(t->left);
        PreorderRec(t->right);
    }
}

template<typename B>
void Binary_Tree<B> :: PostorderRec(Node<B>* t)
{
    if(t != NULL)
    {
        PostorderRec(t->left);
        PostorderRec(t->right);
        cout<<t->data<<" ";
    }
}

template<typename B>
int Binary_Tree<B> :: Height(Node<B>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(Height(root->left), Height(root->right));
    }
}

template<typename B>
void Binary_Tree<B> :: MirrorImage(Node<B>* root)
{
    if(root != NULL)
    {
        struct Node<B>* temp;
        MirrorImage(root->left);
        MirrorImage(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

template<typename B>
void Binary_Tree<B> :: copyTree(Node<B>* tree2, Node<B>* tree)
{
    if(tree == NULL)
    {
        tree2 = NULL;
    }
    else
    {
        tree2 = new Node<B>;
        tree2->data = tree->data;
        copyTree(tree2->left, tree->left);
        cout<<tree2->data<<" ";
        copyTree(tree2->right, tree->right);
    }
}

template<typename B>
void Binary_Tree<B> :: DisplayLeafNodes(Node<B>* root)
{
    if(!root)
    {
        cout<<"\nTree is Empty";
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    if(root->left)
       DisplayLeafNodes(root->left);
    if(root->right)
       DisplayLeafNodes(root->right);
}

template<typename B>
void Binary_Tree<B> :: DisplayLevelWise(Node<B>* root)
{
    queue<Node<B>*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node<B>* temp = Q.front();
        Q.pop();
        cout<<"\n\t\t\t"<<temp->data<<endl;
        if(temp->left) {Q.push(temp->left);}
        if(temp->right) {Q.push(temp->right);}
    }
}
#endif