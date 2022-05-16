#include<bits\stdc++.h>
void pireplace(char s[],int index,int length){
    while (index!=length-1)
    {
      if(s[index]!='p'||'P'){
      printf("%c",s[index]);
      pireplace(s,index+1,length);
      }
      else if (s[index]=='P'||s[index]=='p'&&s[index+1]=='i'||s[index+1]=='I')
      {
          
          printf("3.14");
          pireplace(s,index+1,length);
      }
      else{
      printf("%c",s[index]);
      pireplace(s,index+1,length);
      }
      
    }
    

}
int main(){
    char str[]={"2pipi12pi"};
    int length=0;
    int i=0;
    while(str[i]!='\0'){
        i++;
        length++;
    }
    printf("Length of string is\n");
    printf("%d",length);
    pireplace(str,i,length);
    return 0;
}