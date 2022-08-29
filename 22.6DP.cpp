#include <bits/stdc++.h>
using namespace std;
//0,0 cell has 3 deepndies
//m,n cell has 0 dependincies'
//the uske baga k wae k deendency 2 ki nhi ai sirf ek hai jo k m,n cel hai that we have alredy found off
//first fill the clumns bottom and last and then daginally finf krte karehnge coz uske values already aa chuki hai
//11:08
//dp=>memoiazation +strting with min depency solution to upper problems and fill th arra with least depensocy casees first hat helps other cases 

int minCostPath(int **input,int m,int n){
    int **output=new int*[m];
    for (int  i = 0; i < n; i++)
    {
        output[i]=new int[n];
       //imtilaisation notneded in dp as hummorder whi follow krte hi
        
    }
    //fill the last cell
    output[m-1][n-1]=input[m-1][n-1];//last cell fill
    //fillig the last row
    for (int j = n-2; j>=0;j--)
    {
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    }
    //last column fiill
    for (int i = m-2;  i>=0; i--)
    {
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }
    
    //fill remaing cells--->by other filled ones
    for (int i = m-2; i >=0; i--)
    {
        for (int j = n-2; j>=0; j--)
        {  //17:54
            output[i][j]=min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]))+input[i][j];
        }
        
    }
    
return output[0][0];//final answer by lowe cells
}
int main()
{    
    return 0;
}