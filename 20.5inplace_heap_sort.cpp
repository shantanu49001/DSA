// heap sort ko improve krn ahi
// reducing thr spave complexity
// array partition krna hai at each strp
// sorted ka size increase hota jayga and unsorted ka size decrea at each step sorted ka size incr new element to parent se comapre

// insertion kke liye same process

// but deletion me swap karenge then ....swap.......

// earlier we were taking a vector ->n space complexity

// inplace->algos taking no extra space other tahnk the input

// we are given a array we need to sort it using the heap sort

// firs twe need to create a heap
// prtition oth index arry heap rest not heapified

// now comapre the next index value with the sorted array part child parent ine=dex se

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void inplaceHeapSort(int pq[], int n)
{
    for (int i = 1; i < n; i++)
    {

        int childIndex = i; // jahan pr new add hua
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    // remove
    int size = n;
    while (size > 1)
    {
        /* code */

        int temp = pq[0];
        pq[0] = pq[n - 1]; // swap donw
        pq[n - 1] = temp;
        // now size of array is reduced
        size--;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && pq[rightChildIndex] < pq[minIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}
//follow the previous class code
int main()
{   int input[]={5,1,2,0,8};
    inplaceHeapSort(input,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<input[i]<<endl;
    }
    
    return 0;
}