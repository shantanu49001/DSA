#include <stdio.h>
#include <stdlib.h>
int func1(int a[])//int *a we can also write like this
{
    int size = sizeof(a);
    printf("%d", size); //here answe will be 8
}
int main()
{
    int arr[10];
    int size = sizeof(arr);
    printf("%d", size); //here answer will be 40
    func1(arr);         //bcoz aray is passed onot as an arry but as a pointer

    return 0;
}