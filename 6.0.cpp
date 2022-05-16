#include<bits\stdc++.h>
int removeDuplicate(char a[],int index){
    if (a[index]!='\0')
    {
        if (a[index]==a[index+1])
        {
            removeDuplicate(a,index+1);
        }
        else{
            printf("%c",a[index]);
            removeDuplicate(a,index+1);
        }
        
    }
    else{
        return 0;
    }
    


}
int main(){
     char string[]={"xxxyyz"};
     int i=0;
     removeDuplicate(string,i);
    return 0;
}