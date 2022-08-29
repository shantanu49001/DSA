/*
complexity of previous code->2:25


overlapping points->4:25
now if rows are 4 rws and 5 columns 
we can go to max 3,4 
unoques combinations 0->3   m
                     0->4   n
m*n unque calls


2d arry indesed ka data 2-d array ki array me hi hoga save

complexity ->o(m*n)->unique calls
space comlexity ->O(m*n)->extra spae we ae taking
*/
#include <bits/stdc++.h>
using namespace std;
int minCostPath_Mem(int **input,int m,int n,int i,int j,int **output){
    //two steps extar cehck if it already exists 
    //if not fidn and save
    if (i == m - 1, j == n - 1) 
    {
        return input[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT_MAX; //valid value nhi de sakte wo value do jo leminate ho jaye
    }
  if(output[i][j]!=-1){
    return output[i][j];
  }
    //don tabhi aayenge jab nhi higa so furst ca and then save
    int x = minCostPath_Mem(input, m, n, i, j + 1,output); 
    int y = minCostPath_Mem(input, m, n, i + 1, j + 1,output);
    int z = minCostPath_Mem(input, m, n, i + 1, j,output);

    int a=min(x,min(y,z))+input[i][j];
    output[i][j]=a;
    //int ans = min(x, min(y, z)) + input[i][j];
    return a;
}
int minCostPath(int **input, int m, int n,int **output)
{
  return minCostPath_Mem(input, m, n, 0, 0,output);
}
int main()
{
  int m, n;
  cin >> m >> n;
  int **input = new int *[m];
  for (int i = 0; i < m; i++)
  {
    input[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      cin >> input[i][j];
    }
  }
  int **output=new int*[m];
  for (int i = 0; i < n; i++)
  {
     *output=new int[n];
     for (int j = 0; j < n; j++)
     {
      output[i][j]=-1;
     }
     
  }
  
  cout << minCostPath(input, m, n,output);

  return 0;
}
int main()
{
    return 0;
}