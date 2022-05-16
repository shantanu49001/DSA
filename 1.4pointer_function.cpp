//SENDING POINTER INTO A FUNCTION
#include<iostream>
using namespace std;
void print(int *p){//pointer as argument
    cout<<*p<<" ";
}
void incrementPointer(int *p){
    p=p+1;
    cout<<p<<"\t";
}
void increment(int *p){
    (*p)++;
    cout<<*p<<"\t";
}
void incr(int i){
 i++;
 cout<<i<<"\t";
}
int main()
{   int i=10;
   int *p=&i;
   print(p);//chit me address likhe isko de diya---->pass by val
   cout<<p<<" \t";
   incrementPointer(p);//chit me address likh kar ise bhi de diya;ab ye apni chit me address change kr rhe hai---->pass by value
   cout<<p<<" \t";//iske paas apni chit ka address hai main function ke paas
   cout<<*p<<"\t";
   increment(p); //isne kya kiya us p ke adrres pr jake uski value change kr di to ab p ki value overall change ho chuki hai
   cout<<*p<<"\t";//--->pass by ref
   cout<<i<<"\t";//badha hua i print
   incr(i);//--------->pass by val//i aur badhega
   cout<<i<<"\t";//firse ek kam i coz ye pass by val hai
    return 0;
}