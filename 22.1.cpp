/**
 * @file 22.1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-16
 *
 * @copyright Copyright (c) 2022
 *
 * using iteration methid rather than recursions
 *
 * nth index ke value k liye n-1th and n-2th ka value lena hai bas
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int fibo_3(int n){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for (int i = 2; i < n; i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
    
}
int main()
{   
    return 0;
}
/**
 * first was raw solution recursion
 * second was previos saving in array ->memoization->O(n)
 * array methid->dynamic programming.->iterations methid->O(n)
 *
 * 
 * first write the recursive methid.
 * then the iterative arrya method. 
 */