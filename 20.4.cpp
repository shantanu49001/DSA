#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
// save as array visualise as tree
using namespace std;
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
        // initialise pq
    }
    bool isEmpty()
    {
        return pq.size() == 0; // vector ka inbuilt size
    }
    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {
        // min element of priority queue
        // min prority at index 0
        if (isEmpty())
        {
            return 0;
        }

        return pq[0];
    }
    void Insert(int element)
    {
        pq.push_back(element); // cbt satisfied but hepify false
        // parent tak jane k liye (child index-1)/2
        int childIndex = pq.size() - 1;
        // int parentIndex = (childIndex - 1) / 2;
        while (childIndex > 0)                      // root tak na chala jaye
        {                                           // agar hoga to hi swap karega
            int parentIndex = (childIndex - 1) / 2; // zyada bada to lready hau pehle 2 choice nhi hai
            if (pq[childIndex] < pq[parentIndex])
            { // swap
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
            //
            //  parentIndex = (childIndex - 1) / 2;
        }
    }
    

    //deleting
    int removeMin(){
        int answer=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        //dono child me se min wale se swap insertion me parent only child-1/2
        //deleion me out of 2 child ek me se 
        //coz child 2 hai parent ek hi hai
      int parentIndex=0;
      int leftChildIndex=2*parentIndex  +1;
      int rightChildIndex=2*parentIndex +2;
      int minIndex=parentIndex;//to keep index of kisse swap hua
      while (leftChildIndex<pq.size())
      {
        int minIndex=parentIndex;
        if (pq[minIndex]>pq[leftChildIndex])
        {
            minIndex=leftChildIndex;
        }
        if (pq[minIndex]<pq[rightChildIndex]&&rightChildIndex<pq.size())
        {
            minIndex=rightChildIndex;
        }
        if (minIndex==parentIndex)
        {
            break;
        }
        
        int temp=pq[minIndex];
        pq[minIndex]=pq[parentIndex];
        pq[parentIndex]=temp;
        

        //for second swapping
        parentIndex=minIndex;
        leftChildIndex=2*parentIndex +1;
        rightChildIndex=2*parentIndex+2;
        
      }
     return answer; 
    }
    void PrintTree(int i){
      //  int allowed=(2*i)+2;
        while ((2*i+2)!=this->pq.size())
        {
            printf("%d:", this->pq[i]);
            printf("L:%d ", this->pq[(2 * i) + 1]);
            printf("R:%d\n", this->pq[(2 * i) + 2]);
            i++;
          //  PrintTree(i);
            
        }
        
      


    }
};
int main()
{  //this is only the heap sort algorithm
     PriorityQueue p;
     int choice=1;
     while (choice!=0)
     {
        printf("===================================ENTER UR CHOICE======================================================================\n");
        printf("1.Get Size of Heap\n");
        printf("2.Get Min of Heap\n");
        printf("3.Insert element to Heap\n");
        printf("4.Delete element from Heap\n");
        printf("5.Get Heap\n");
        printf("0.Exit\n");
        scanf("%d",&choice);
        if (choice==1)
        {
            printf("Size of heap is %d\n",p.getSize());
        }
        if (choice==2)
        {
            printf("Minimum element in the heap is %d\n",p.getMin());
        }
        if (choice==3)
        {
            int element;
            printf("Enter the element to add\n");
            scanf("%d",&element);
            p.Insert(element);
        }
        if (choice==4)
        {
            printf("Deleted %d\n",p.removeMin());
        }
        if (choice==5)
        {int i=0;
        p.PrintTree(i);    
        }
        if (choice==0)
        {
            printf("Thanks for Using\n");
        }
        
        
     }
     
//design main menu 
//print the heap

    return 0;
}