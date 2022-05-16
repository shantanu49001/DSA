// printing array by recursion
#include <bits\stdc++.h>
// always in recursion think of end and base condition frst
int printArray(int a[], int index, int length)
{
    if (index <= length)//exit condition
    {
        printf("%d\t", a[index]);

        printArray(a, index + 1, length);
    }
    else{
        printf("");
    }
}
int main()
{
    int length;
    printf("Enter array size\n");
    scanf("%d", &length);
    int arr[length];
    printf("Enter %d elements\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    int index = 0;
    printArray(arr, index, length);
    return 0;
}