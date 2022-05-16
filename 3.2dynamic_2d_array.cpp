#include<bits/stdc++.h>
int main(){
    //we req pointer aarys and a double pointer to store these poiner arrays
   /*
                                .  /////////
  array having pointer arrays <-. /////////--->array 
                                . ////////
                                . ///////
                                .////////
   */ 
    int m,n;
    printf("Enter the no of rows\n");
    scanf("%d",&m);
    printf("Enter no of columns\n");
    scanf("%d",&n);
    int **p=new int *[m];//pointer pointing to array of pointers
    for (int i = 0; i < m; i++)
    {
        p[i]=new int[n];//pointer points to new array column defined byt his
     for (int j = 0; i < n; i++)
     {
         scanf("%d",p[i][j]);
     }
     
    }
    for (int i = 0; i < m; i++)
    {
        delete [] p[i];//-->sabse pehle rows ko delete karo
    }
    delete []p;//  []--->apne aap se deref-->uske ___ ko point karo
    //-->udke baad pointer to pointer aarys kopooint kr rha tha usnko dlete karo
    
    return 0;
}
//jagged arrays