#include<bits\stdc++.h>
int noofzeros(int n,int c){
    if(n!=1){
        if(n%10==0){
            noofzeros(n/10,c+1);
        }
        else{
            noofzeros(n/10,c);
        }
    }
    return c;
    

}
int main(){
    int num;
    int count=0;
    printf("Enter the no u want to check zeris in\n");
    scanf("%d",&num);
    printf("Now printitng no of zeros\n");
    int value=noofzeros(num,count);
    printf("%d",value);
    return 0;
}