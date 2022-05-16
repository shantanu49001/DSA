//using array as pointer 
#include<stdio.h>
#include<stdlib.h>
int sum(int *a,int size){//address passed
int ans=0;
for(int i=0;i<size;i++){
    ans+=a[i];
}
printf("%d",ans);
}
int main(){
int a[10];
printf("%d\t",sizeof(a));
//a=address of first element;int type hai  +3 karenge to 3rd elemt kop oint karega
sum(a+3,7);//passing a part of array

return 0;}