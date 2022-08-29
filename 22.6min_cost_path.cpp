/*
A matrix is given to us 
wewant to move from 00 to m-1,n-1
allowed moves right down daigonal
we are given numbers in the mstrix cost of crossing that cell=A[i]


similar to previous questions 3 choices to ove\
we are at first index we move to one of the next cell and ask it to get it's min path and save it

select to minimum of all thee three and add a[0 ] to it


[BF]

*/
#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input,int m,int n,int i,int j){
    //we will ask the next cells to find their min paths whil movinf from 0,0 to m,n and we will return min of al those
    //case 1: 01 ->m-1,n-1
    //case 2: 1,1 ->m-1,n-1
    //case 3: 1,0  ->m-1,n-1
    //only probem rcursion to statrting points batane padenge
//recursion only has three parts base recursion small calculation

//base case--->last cell se last cell or corner cells pe chale gye wahanse to kahain pe bhi nhi jaa sakte 9:48
if (i==m-1,j==n-1)//trivial or border case
{
    return input[i][j];
}

if (i>=m||j>=n)//dono me se koi bhi out of limit agar chala jaye
{
    return INT_MAX;//x=inf y=info z=k min=k
}




//recursive call
int x=minCostPath(input,m,n,i,j+1);//movinf to cell 1
int y=minCostPath(input,m,n,i+1,j+1);
int z=minCostPath(input,m,n,i+1,j);

//small calculations
int ans=min(x,min(y,z))+input[i][j];
return ans;
}
int minCostPath(int **input,int m,int n){
    return minCostPath(input,m,n,0,0);
}
int main()
{   int m,n;
    cin>>m>>n;
    int **input=new int*[m];
    for (int i = 0; i < m; i++)
    {
        input[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            cin>>input[i][j];
        }
        
    }
    cout<<minCostPath(input,m,n);
    
    return 0;
}