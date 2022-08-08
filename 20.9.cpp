//practise of Pq algo

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
using namespace std;
class PQ{
vector<int> pq;
PQ(){

}
bool IsEmpty(){
    return pq.size()==0;
}
int getSize(){
    return pq.size();
}
int getMin(){
    if (pq.size()==0)
    {
        return 0;
    }
    
    return pq[0];
}
void Insert(int element){//up heapify  peehe se aage
    pq.push_back(element);
    int childIndex=pq.size()-1;
    while (childIndex>0)//remember
    {
        int parentIndex=(childIndex-1)/2;//we have only one parent
        if (pq[childIndex]<pq[parentIndex])
        {
            int temp=pq[childIndex];
            pq[childIndex]=pq[parentIndex];
            pq[parentIndex]=temp;
        }
        else{
            break;//already at same position as soon as we get any one correct position
        }
        childIndex=parentIndex;//for next parent iNdx will be obtained from new child Index
    }
    

}
void Remove(){//down heapify aage se peeche-->two choices of swap
    int answer=pq[0];
pq[0]=pq[pq.size()-1];
pq.pop_back();
//
int parentIndex=0;
int leftChildIndex=2*parentIndex+1;
int rightChildIndex=2*parentIndex+2;
int minIndex=parentIndex;//to keep track kisse replace hua hai
while (leftChildIndex<pq.size())//remember
{
    int minIndex=parentIndex;
    //three if to get index jisse swap hu or to exit if no swap requires here we have to swp choices and two exit 
    if (pq[minIndex]>pq[leftChildIndex])
    {
        minIndex=leftChildIndex;
    }
    if (pq[minIndex]>pq[rightChildIndex])
    {
        minIndex=rightChildIndex;
    }
    if (minIndex==parentIndex)
    {
        break;
    }
    
    //swap->minIndex and parentIndex
   int temp=pq[minIndex];
   pq[minIndex]=pq[parentIndex];
   pq[parentIndex]=temp;


    //next iter
    parentIndex=minIndex;
    leftChildIndex=2*parentIndex+1;
    rightChildIndex=2*parentIndex+2;
}
//search for print function or implemet it 
}
};
int main()
{      
    return 0;
}