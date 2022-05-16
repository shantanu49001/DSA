/**
 a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
 *
 */
//ERROR
//ERROR
//ERROR
//ERROR

#include<bits\stdc++.h>
int stringMatch(char a[],int n){
    while (a[n]!='\0')
    {
        if(a[n]!='a'){

            printf("False\n");
            return 0;
        }
        else if(a[n]=='a'&&a[n+1]=='b'&&a[n+2]=='b'){

        
        }
        
    }
    

}
int main(){
    
    char c[50];
    printf("Enter the string\n");
    scanf("%c",&c); 
    int i=0;
    stringMatch(c,i);
    return 0;
}