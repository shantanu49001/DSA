#include <bits/stdc++.h>
using namespace std;
//recursion ka solution copy just consider size of array needed
//3:42->idexes where to save our results
//unique calls->(max array size)->note th index changes (mn) (00)->m+1 n+1  
//what to save ->out[i][j]->output[s.legth][t.length]
int editDistance_mem(string s,string t,int **output){
   int m=s.size();
   int n=t.size();
    if (s.size()==0||t.size()==0)
    {
        return max(s.size(),t.size());
    }
    
  if (output[m][n]!=-1)
  {
    return output[m][n];
  }
  
int ans;
    if (s[0] == t[0])
    { // recursion will do the same
        int ans= editDistance_mem(s.substr(1), t.substr(1));
        
    }
    else
    {
        // insert->s=abc t=bcd => s=abc t=abcd => ab first first match ho gye ecursion me first ke baad se use s=>bc t=bcd
        int x = editDistance_mem(s.substr(1), t) + 1;
        // delete->s=abc  t=bcd => s=abc t=cd=.nw next wale kaam recursion
        int y = editDistance_mem(s, t.substr(1)) + 1;
        // replace  s=abc t=bcd => s=abc t=acd =>first match ho gye an next index se last tk dno me call
        int z = editDistance_mem(s.substr(1), t.substr(1));

      ans=  min(x, min(y, z));
    }
    output[m][n]=ans;
    return ans;
}
int editDistance_mem(string s,string t){ //to have array here warna usme recursion me baar baar nhi daal sakte
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for (int i = 0; i <= m; i++)
    {
        ans[i]=new int[n+1];
        for (int j = 0; j <= n; j++)
        {
            ans[i][j]=-1;
        }
        
    }
    return editDistance_mem(s,t,ans);
}
int main()
{
    return 0;
}