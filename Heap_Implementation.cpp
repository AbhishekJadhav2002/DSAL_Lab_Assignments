/*
============================================================================
 Name : Heap_Implementation.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 9
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

//Heapify function to maintain heap property.
void Heapify(int A[], int n, int i)
{
    int large = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && A[large] < A[left])
        large = left;
    if (right < n && A[large] < A[right])
        large = right;
    // large contains the index of largest value from all three
    if (large == i)
        return;
    swap(A[large], A[i]);
    Heapify(A, n, large);
}

//Function to build a Heap from array.
void buildHeap(int A[], int n)
{
    // internal nodes are from n/2-1 to 0
    for (int i = n / 2 - 1; i >= 0; --i)
        Heapify(A, n, i);
}

//Function to sort an array using Heap Sort.
void heapSort(int A[], int n)
{
    buildHeap(A, n);
    for (int i = n - 1; i > 0; --i)
    {
        swap(A[0], A[i]);
        Heapify(A, i, 0);
    }
}

int main()
{
    cout<<"\nEnter size of array (>7): ";
    int size;
    againSize :
    {
        cin>>size;
        if(size < 8)
        {
            cout<<"\nSize of array is smaller, input size should be greater than '7'";
            goto againSize;
        }
    }
    cout<<"\nEnter "<<size<<" no. of elements of array : ";
    int array[size];
    for(int i = 0; i < size; i++)
    {
        cin>>array[i];
    }
    cout<<"\nArray befor Heap Sort :";
    for(int i = 0; i < size; i++)
    {
        cout<<" "<<array[i];
    }
    cout<<"\nArray after Heap Sort :";
    heapSort(&array[0], size);
    for(int i = 0; i < size; i++)
    {
        cout<<" "<<array[i];
    }
}