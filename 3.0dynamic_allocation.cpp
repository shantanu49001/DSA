#include<iostream>
using namespace std;
int main(){
    int arr[10];//--->compile time allocation
    int n;      //arr[10],int i etc are in stack memory
    cin>>n;
    int a[n];//run time allocation
return 0;
}//stck mem<heap mem
//as son as we wrte code compiler holds enough memory to acc all var in stack 
//but what if we r making run time array then cmpiler doesn't know how much stackit should make to acc all vr

//if n is very large it might return false results
//therefore user defined arays are formaed in heap not in stack,it is done in dyanic mem allocation
//int *ptr=new int--->heap me dynamic int memory jiko p oint karega jo run time me change kr sakte hai