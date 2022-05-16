#include<bits\stdc++.h>
int GP_Sum(int num,int term){
    
    while(term>=1){//restriction on changing var.
     return    pow(num, term) + GP_Sum(num, term - 1);//return statement me hi add karo--->main lie is important in recursion
        
    }

}
int main(){
    int num,term;
    printf("Enter the base of the gp\n");
    scanf("%d",&num);
    printf("Enter no of terms\n");
    scanf("%d",&term);
    int val=GP_Sum(num,term);
    printf("SUm is %d\n",val);
    return 0;
}
/*
 * recusion is used whenever we want  that solution of one problem depends on ceain smaller prob
 * 
 * 
 * 
 * 
 */