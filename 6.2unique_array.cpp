#include<bits\stdc++.h>
int unique(int a[],int b,int length){
    if(b=length-1)
    {
      for (int i = b; i < length; i++)
      {
          if(a[b]==a[i]){

          }
          else{
              printf("%d at index %d",a[i],i);
              break;
          }
      }
       
    }
    else{
        return 0;
    }
    printf("\n");
    unique(a,b+1,length);

}
int main(){
    int length;
    printf("Enter the length of array\n");
    scanf("%d",&length);
    int arr[length];
    int i=0;
    while (i<length)
    {
        scanf("%d",&arr[i]);
    }
    int a=0;
    
    unique(arr,a,length);
    
    return 0;
}