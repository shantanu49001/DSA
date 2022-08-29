//memoization problem
/*
dp solution 1:53 image->basic solution video
this video 0:59 code->we are checking the repertoion

2:48

repetion =overlpping sub problems

(stesp)
how many answers to save->   let n=12
12->0||12->1  ->n unique calls are required here

n+1 sized array required

how what to save at ans[i]->min stps req to reach i ->1

answer will be at number=index

at each step check if it is in the array ;if yes use it if not calculte save and then return

(steps)


*/


#include <bits/stdc++.h>
using namespace std;
int minStepsHelper(int n,int *ans){
    if (n<=1)
    {
        return 0;//we ared iretly returning no need to save
    }
    //checking the existence
    if (ans[n]!=-1)//present
    {
        /* code */
    
    return ans[n];}
    int x=minStepsHelper(n-1,ans);
    int y,z=INT_MAX;
    if (n%2==0)
    {
        y=minStepsHelper(n/2,ans);
    }
    if (n%3==0)
    {
        z=minStepsHelper(n/3,ans);
    }
    
    int output=min(x,min(y,z))+1;//we need to save the finalanswer not the answer generated between the steps in recursons
    
    //now save the ouput for this number
    ans[n]=output;
    return output;
//11:46->best explanantion
//ths has complexity O(n)-->very very important->

}
int minSteps(int n){
    int *answer=new int[n];
    for (int  i = 0; i <=n; i++)
    {
        answer[i]=-1;//to check if it is answer or garbage -1 can't be a vlue at any codr

    }
    return minStepsHelper(n,answer);
    
}
int main()
{   int n;
cin>>n;
    return 0;
}