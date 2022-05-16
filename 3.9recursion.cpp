//base case->jisko change karna hai uspe limit lga deni ai
//recursive call
//profd to two nos by rec
#include<bits\stdc++.h>
int prod(int a,int b){
    while(b>=1){
        return a+prod(a,b-1);
        /*
              4+prod(4,3)
              4+4+prod(3)
              4+4+4+prod(2)
              4+4+4+4+prod(1)
              exit;//while 
        */
    }

}
int main(){
    int m,n;
    printf("Enter the nos to find the product\n");
    scanf("%d",&m);
    scanf("%d",&n);
  int val=  prod(m,n);
  printf("%d",val);
}