#include<bits\stdc++.h>
int printIndex(){

}
int RepeatedIndex(int a[],int index,int length,int element,int count){
    if (index!=length)
    {
        if(a[index]==element){
            
            count++;
            if(count>0){

              return index;
             
            }
            else{
                RepeatedIndex(a, index + 1, length, element, count); 
            }
        }
        else{
            printf("Element is not repeated it is occuring in index %d ",index);
            RepeatedIndex(a, index + 1, length, element, count); // yahan count increase nhi hoga
        }
    }
    else{
        return 0;
    }
    


}
int main(){
    int length;

    printf("Enter size of array\n");
    scanf("%d",&length);
    int arr[length];
    printf("Enter %d elements",length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d",&arr[i]);
    }
    int element;
    printf("Enter the elemnt you want to print first index\n");
    scanf("%d",&element);
    int index=0;
    int count=0;
    RepeatedIndex(arr,index,length,element,count);
    return 0;
}