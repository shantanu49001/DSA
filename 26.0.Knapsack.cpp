#include <bits/stdc++.h>
using namespace std;
/**
 * we are give weights and value of n items an it is to be inserted in knackcack of wieght w we have to retun max value
 *
 * W,V ->array
 * 2:18
 *
 * W-> .......
 * V-> .......
 *
 * W(max)->given
 * we have to aarrorach problems in recur array as do it for first index and rest leave for recursion
 *
 * first element include->Wleft->W(max)-Frs element and value =value of first
 *
 * now we can either add or not add the elemnt
 * second case we don't add first elemnt ->wleft unchanged value=0
 *
 * and out of these two cases return the case that yields max value
 *
 * BF->
 */
int knapSack(int *weight, int *values, int n, int maxWeight)
{
    //we can add a element or leave that element
    //Base Case
    if (n==0||maxWeight==0)
    {
        return 0;
    }
    //recursive call
    //what what if first element greater ho capacity ke?-.
    if (weight[0]>maxWeight)
    {
      return knapSack(weight+1,values+1,n-1,maxWeight);
    }
                   //next pr move        //changing max weight on adding                
    int x=knapSack(weight+1,values+1,n-1,maxWeight-weight[0]+values[0]);//adding the first->new maxWeight
                                         //unchnaged coz nothing added
    int y=knapSack(weight+1,values+1,n-1,maxWeight);//leaving the first

    return max(x,y);

    
}
int main()
{
    return 0;
}