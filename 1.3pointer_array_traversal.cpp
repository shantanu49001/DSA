#include<iostream>
#include<stdio.h>
#include<stdlib.h>

int main(){
    int val[]={1,2,3};
    int *p=&val[0];//int i=3 tha to i++ karne pr i ka size add hot hai but *p pointer hai jo ki int pointer hai to use add karne pr next address int ka add hota hai
   //int *p=&val--->don't use this else usme poora arra ka add size store hoga
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t",*p);
        p++;//ISKO EK AGALS SE MEMORY BLOCK MILTA HAI KISME ADDRESS STORE HTA HAI AUR YE ADDRESS KE ACC HI ADD HOTA HAI.
    }       //here pis pointing outside the array eaddress
    printf("%d\t",*p);//radom memory allot
   p--;//here it comes to last
   printf("%d\t",*p);
   p--;//here it comes to secnd last;
   //coz memory to poore computer me hoti hai stored.
   printf("%d\t",*p);
   

return 0;
}


