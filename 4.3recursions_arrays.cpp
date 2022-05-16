#include<bits\stdc++.h>
//check by recursion that the aray is sorted or not
//proper proffessional code is written here
//sample code for future reference
bool is_sorted2(int a[],int size){//boolean function returning boolean values
if(size==0||size==1){
    return true;
}
bool isSmallerOutput=is_sorted2(a+1,size-1);//increasing index of array for recursion to worf
if(!isSmallerOutput){
    return false;
}
if(a[0]>a[1]){
    return false;
}
else{
    return true;
}
}
bool is_sorted(int a[],int size){
    if (size==0||size==1){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    bool isSmallerSorted=is_sorted(a+1,size-1);
    return isSmallerSorted;
 }
int main(){
    int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    

    return 0;
}