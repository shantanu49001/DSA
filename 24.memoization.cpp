#include <bits/stdc++.h>
using namespace std;
//3:30-.verifuy if dp and mem can be applied
//steps->agar case hai to use karo
//nhi hai to size kodefine karo aur cal culate karke save
//size->humesha length of strings delete ho rhe hai
//and we are oving from 0,0 to m/n ->which ever is greater
//s->0->m  ->m+1 unique combinations
//t->0->n  ->n+1
//total inique combinations->(m+1)*(n+1)
//what are we storing in the array->9:00
//final value will be at answer[m][n]
int lcs_mem(string s,string t,int **output){
   int m=s.size();
   int n=t.size();
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }
    if (output[m][n]!=-1)
    {
        return output[m][n];
    }
    int ans;
    // whe first mach
    if (s[0] == t[0])
    {
        int ans= 1 + lcs_mem(s.substr(1), t.substr(1),output); // if first case match->ask recursion to do what we want in bith
    }
    else
    {
        // recursive->whe first doen't matched
        int a = lcs_mem(s.substr(1), t,output); // 14:15
        int b = lcs_mem(s, t.substr(1),output);
        int c = lcs_mem(s.substr(1), t.substr(1),output);
        return max(a, max(b, c));
    }
    //saving the calculation
    output[m][n]=ans;
    return ans;
  
}
int lcs_mem(string s,string t){
    int m=s.size();
    int n=s.size();
    int **output=new int*[m+1];
    for (int i = 0; i <=m; i++)
    {
        output[i]=new int[n];
        for (int  j = 0; j <=n; j++)
        {
            output[i][j]=-1;
        }
        
    }
    return lcs_mem(s,t,output);
    
}

int main() 
{    string s,t;
cin>>s>>t;
cout<<lcs_mem(s,t)<<endl;
    return 0;
}

/*
abcd   ->ad ac bc ->all of lenght 2.
badce




*/