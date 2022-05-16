#include<bits\stdc++.h>
//used the same logic just static ke baare me nhi ptabtah
int no_zeros( int n){//recursion me static int jaan bohot zaroori hai
    static int count=0;//ye sirf starting me zero hai baad me ye skip hoga agar dobara count hua to surf ek baar zero hai ye
    if(n>0){
    if(n%10==0){
        
        count++;
        no_zeros(n/10);
       
       
    }
    
    
    }
   

    return count;

}
int main(){
    int num;
    printf("Enter the no\n");
    scanf("%d",&num);
    

    int zeros = no_zeros(num);
    
      printf("No of zeros are %d", zeros);
    
  
    
}