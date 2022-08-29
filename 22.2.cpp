/*Min steps to one(Brute force)
we are given number that we need to reduce it to 1
steps allowed are->
1.decrement by 1
2.divide by 2->only if it is completly div
3.divide  by 3
 we need to retun min number of steps


 let's say we get n=7

 7 pr sirf -1
 6 pr -1,%2,%3
 5 pr
 4 pr
 3 pr     2:57 graph note
 2 pr


we are thinking of a looping method first div by 3 then by 2 then dec by  1
but it is not correct in case of 10 metid voilated
 memoization applies only when our cases overlap




 n=12 
 1.-1=11->ask rescursion now repaeting these 3 min steps to one for 11(x)
 2./2=6->similar(y)
 3./3=2->similar(z)

 return min(min(x,y),z)+1(pehlw wala to we did on our own)
 */

#include<bits/stdc++.h>
using namespace std;
int minSteps(int n){
    //us number ke next numbers jo ayenge by 3 oprn unke steps ka minumum will be our anser
    int y,z=INT_MAX;//coz min se actaul value aa jaye in case only one operation happerns
    if (n<=1)
    {
        return 0;//assume that the number is just reachable to 1 
    }
    //recursion--->pattern of code wheneve paths come to recursion
    int x=minSteps(n-1);
    if (n%2==0)
    {
        int y = minSteps(n / 2);
    }
    if (n%3==0)
    {
        int z = minSteps(n / 3);
    }
    
   return min(min(x,y),z);
   /*
   
   
   
   
   
   
   */
    
}
int main()
{   
    return 0;
}