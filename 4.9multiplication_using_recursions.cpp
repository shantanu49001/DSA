#include<bits\stdc++.h>
int product(int c,int t,int d){
while(t<=d){
    return c+product(c,d,t+1);//2*3=2 added 3 times
}

}
int main(){
    int a,b;
    printf("Enter first nos\n");
    scanf("%d",&a);
    printf("Enter second no\n");
    scanf("%d",&b);
    int times=0;
  int prod=  product(a,times,b);
   printf("product is %d",prod);
    return 0;
}