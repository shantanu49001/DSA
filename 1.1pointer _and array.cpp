#include<iostream>
using namespace std;
int main(){
    int a[10];
    cout<<a<<"\n";
    cout<<&a<<"\n";//both have same value
    cout<<&a[0]<<"\n";
    cout<< &a[1]<<"\n";//ye first bockka address 
    cout<<a+1<<"\n";//ye bhi first block ka address
    //a=a+3 not allowed ek baar array assignho gya use change nhi kr sakte usko point krne wala pointer o kar sakte hai
    //i[a]->*(i+a)
    //value of a initially is the same value at start of array 

return 0;
}