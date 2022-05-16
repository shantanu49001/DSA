#include <bits\stdc++.h>
int SearchArray(int a[], int index, int length, int element)
{

       if (index<=length)
       {
           /* code */
        if (a[index]==element)
        {
            printf("Element found at index %d",index+1);
            return 0;//breaking the function
        }
        else{
            SearchArray(a,index+1,length,element);
        }
        
       }
       else{
       printf("Element not found\n");
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
    int element;
    printf("Enter the element u want to find\n");
    scanf("%d", &element);
    int index = 0;
    SearchArray(arr, index, length, element);

    return 0;
}