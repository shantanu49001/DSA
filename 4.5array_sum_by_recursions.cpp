#include <bits\stdc++.h>

int printSum(int a[], int index, int length)
{
    if(index>=length){//exit condition sabse pehle code
        return 0;//to avoid garbage to be added to prevent while loop added
    }
    else{
        return a[index]+printSum(a,index+1,length);
    }
   
}
int main()
{
    int length;
    printf("Enter the size of array\n");
    scanf("%d", &length);
    int arr[length];
    printf("Enter %d elements\n", length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    int index = 0;
    printf("array sum is\n");
    int val = printSum(arr, index, length);
    printf("%d", val);
    return 0;
}