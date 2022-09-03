//we need to just copy the recusion code
//returning line isn't changes
//array size and place of saving result only needed to be known
#include <bits/stdc++.h>
using namespace std;
int recursion(int input[], int index,int output[])
{
    if (index == 0) // base
    {   
        return 1;
    }
    if (index == 1) // base
    {
        if (input[index - 1] < input[index])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (output[index]!=-1)
    {
        return output[index];
    }
    
    //checking if the answer is present
    // two choices if it is increasing or if it is not
    int option1 = 0; // recursion me jab bhi if else ke andar returning var ho do this.
    if (input[index - 1] < input[index])
    {
        option1 = 1 + recursion(input, index + 1,output);
    }
    int option2 = 0 + recursion(input, index + 1,output);
    int ans=max(option1,option2);
    output[index]=ans;
    return ans;
    

    
}

int main(){
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
    int *output=new int[N];
    int val = recursion(arr, 0,output);
    cout << val;
    return 0;
}