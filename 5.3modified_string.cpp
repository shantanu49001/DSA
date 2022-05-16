#include<bits\stdc++.h>
int seperateChar(char c[],int index,int length){
    while (c[index]!='\0')
    {
        if(c[index]==c[index+1]){
            printf("%s*",c[index]);
            seperateChar(c,index+2,length);//uske baad wale  index ko skip karna hai
        }
        else{
            printf("%s",c[index]);
            seperateChar(c,index+1,length);
        }
    }
  
    

}
int main(){
    char str[50];
    printf("Enter the string\n");
    scanf("%c",&str);
    int i=0;
    int length=0;
    while (str[i]!='\0')
    {
        length++;
        i++;
    }
  //  printf("%d",length);
    seperateChar(str,i,length);
    return 0;
}