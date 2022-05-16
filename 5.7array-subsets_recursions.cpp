#include<bits\stdc++.h>
//total no of subsets=2^n.
//BCase
//recursive call
//sw
int Subsets(int a[],int index,int length){
    

}
int main(){
    int length;
    printf("Enter size of array\n");
    scanf("%d",&length);
    int arr[length];
    printf("Enter %d elements\n");
    int i=0;
    while (i<length)
    {
        scanf("%d",&arr[i]);
        i++;
    }
    int j=0;
    Subsets(arr,j,length);
    
    
    return 0;
}