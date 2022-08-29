/**
 * for fibonacci n<=1  anser 1 return
 * and for nth we need to know f(n-1)+f(n-2)
 * by using the recursion time complexity method
 * we can figure out the time complexity requires in it
 *
 * firts video dp-1 2:19
 *
 * it's complexity comes out to be 2^n
 *
 *                 6
 *           5         4
 *        4    3     3   2
 *      3  2  2  1
 *
 * here we ca avoid repetition as 6 ke liye jo 4 find kiya wo 5 ke liye direct use kr akte hai
 *
 *
 * but how do we save the results in run time
 * now observe that unique calls for 6 are from 0->6 only
 * so n+1 results are to be required o save for future
 *
 *
 * so we craete the array and save the answers
 * and use that in futher steps
 * and pick that if it is present int the array
 * if not present calculate it use it and save it
 *
 *
 * 
 * use hindi in recursions writethe steps you want to do
 * 
 * this is called memoization->using previous results to improve time complexities 
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//new fibonacci code
int fibbo_helper(int n,int *ans){//pointer 
if (n<=1)
{
    return n;//coz ye to krna hi padega ye array me hoga bhi nhi
}
//checking already present or not
//nth fibocacci no is at nth index
//is location pr garbage bhi ho sakta hai for this answer[i]=-1 assign krdo for all 
if (ans[n]!=-1)
{
    return ans[n];
}
//we reached here coz a[i] nhi hai 
int a=fibbo_helper(n-1,ans);
int b=fibbo_helper(n-2,ans);
//saving it for future use
ans[n]=a+b;

return ans[n];

}
int fibbo_d(int n){
    int *ans=new int[n+1];
    //but by using recursion here it would disrut
    //by making a new array each time 
    //we want to avoid it.
    for (int i = 0; i <=n; i++)
    {
        ans[i]=-1;
    }
    
    return fibbo_helper(n,ans);


}



//raw fibonacci code
int fibbo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fibbo(n - 1);
    int b = fibbo(n - 2);
    return a + b;
}

int main()
{
    int n;
    cin >> n;
    cout << fibbo(n) << endl;
    return 0;
}
