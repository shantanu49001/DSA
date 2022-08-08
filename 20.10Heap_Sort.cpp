#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void Swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void Heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if (l<=n&&a[l]>a[largest])
    {
        largest=l;
    }
    if (r<=n&&a[r]>a[largest])
    {
        largest=r;
    }
    if (largest!=i)//largest is changed
    {
        Swap(&a[largest],&a[i]);
        Heapify(a,n,largest);
    }
    
    
}
void BuildHeap(int a[],int n){
    for (int i = n/2; i >0; i--)
    {
        Heapify(a,n,i);//coz n/2 ke baad leaf hai wp apne sahi place me hoti hi hai
    }
    
}
int main()
{
    return 0;
}