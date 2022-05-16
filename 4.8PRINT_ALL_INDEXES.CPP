#include<bits\stdc++.h>
int printArray(int a[],int index,int length){
    if (index<=length)
    {
        printf("%d ",a[index]);
        printArray(a,index+1,length);
    }
    
    

}
int printIndexes(int a[],int index,int length,int element){
if(index<=length){
    if(a[index]==element){
        
        printf("%d ",index+1);
        printIndexes(a,index+1,length,element);
    }
    else{
        printIndexes(a,index+1,length,element);
    }
}
}
int main(){
    int length;
    printf("Enter the length of array\n");
    scanf("%d",&length);
    int arr[length];
    int index=0;
    printf("Enter %d elements ",length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("You entered\n");
    printArray(arr,index,length);
    int element;
    printf("Now enter the element to find the indexes for\n");
    scanf("%d",&element);
    printIndexes(arr,index,length,element);
    return 0;
}