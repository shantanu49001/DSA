

#include <bits/stdc++.h>
using namespace std;

int recursion(int a[], int index, int c)
{
    if (a[index] == 0) // base
    {
        return 1;
    }
    if (a[index] == 1) // base
    {
        if (a[index - 1] < a[index])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
 //two choices if it is increasing or if it is not
 int option1=0;//recursion me jab bhi if else ke andar returning var ho do this.
 if (a[index-1]<a[index])
 {
    option1=1+recursion(a,index+1,c);
 }
 int option2=0+recursion(a,index+1,c);
 return max( option1,option2);
 

   // return e;
}
int main()
{
    int N;
    cout << "Enter size of array" << endl;
    cin >> N;
    int *arr = new int[N];
    cout << "Enter array elements" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int c = 0;
    int val = recursion(arr, 0, c);
    cout << val;
    return 0;
}