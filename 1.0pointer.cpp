#include<bits\stdc++.h>
int main(){
    int i=9;
    int *p=&i;//this is pointer so it can only store address
    //int *p=7 not allowed
    cout<<&i<<" ";//&i and p do same task
    //i and *p do same task
    cout<<*p<<" ";//--->dereferencing that 
    i++;
    cout<<*p<<" ";
    cout<<i<<" ";//--->dono same hi address ko point kr rhe hai to value dono ki change hogi
    *p=23;//alag se p ko memory deke usme arr[i ] ka address dal deta hai
    cout<<*p<<" ";//-->dono same hi hai p ke through bhi value change kr skte hai
    cout<<i<<" ";
    int *q=p;//-->allowed hai pointer bhi pointer ke equal ho sakta hai but ab both q,p i ko point kr rhe hai
    int *r=0;//jab humare paas ku ch nhi ho point krne ko initially use zero null pointr ko point kr rhe hai
    *p+=1;//adress me one add matlb 1 ko hexa decimal m convert karke usi hexa d me add 
    //this is only ointer arithematic.
    //this is used in array traversal *p+=sizeof(i);
    cout<<p<<" ";
    cout<<sizeof(p);//ye 8 retuen karga
    //arr[i]
   // cout<<sizeof(i);//ye 40 dega
//int *p=0;
//*p=a;
//cout<<*p--->rreturns error as it is pointing to null pointter
}