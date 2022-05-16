//ponter bhi ek var hai so usa bhi dd kisi pointer pe store hoga
//box bana k sab solve kara karo
void increment1(int **p){
    p+=1;//ye double pointer apna address change kr rhe poore ka nhi
}
void increment2(int **p){
    *p+=1;//ye double pointer apna  origin al ka value change kr rha hai
}
void increment3(int **p){
    **p+=1;//apna address change kr rhe hai poore ka nhi
}
#include<iostream>
using namespace std;
int main(){
int i=10;
int *p1=&i;
int **p2=&p1;
cout<<p2<<"\t";
cout<<&p1;//both return same vale odf address
cout<<p1<<"\t";
cout<<*p2<<"\t";//all return same value .box banake siolve akro
cout<<&i<<"\t";
cout<<i<<"\t";
cout<<*p1<<"\t";
cout<<**p2<<"\t";
return 0;}
//11 wala .txt refer both
//pointer assignmt bhi
//double pointer sirf apne pointing tak dakhal krta hai