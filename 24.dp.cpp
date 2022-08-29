#include <bits/stdc++.h>
using namespace std;
//pleas verify the working first in the vdeo and wriyte the solution
//time and space complexity of our code->O(mn)
/*
solve the samllest non dependent case firsto  get the finalbig answer
we generlly use iterations  not recursions

last cell is the answer 3,3 let
now to get that 1.  if first match ->2,2 pr next sve
                2.                 ->2,3  3,2 2,2 ->calculate thie max and save at 3,3
                3.ye wale cells bhi fill ho rhe hai 11:50
                4.but last cell has 3 deepnedencies as we saw 12:38
                5.but first cell 0,0 has zero dependency so fill it first 
                6.oth wale row and coloumn bhi zero depe wale hai coz dono me se koi bhi zero hai to direct zero retun
                7.aft er doing that 1,1 ki sari depenediencies clread 13:51
                8.similarly we can get answer at m,n*/
int lcs_dp(string s,string t){
    int m=s.size();
    int n=t.size();
    int **output=new int*[m+1];
    for (int  i = 0; i <=m; i++)
    {
        output[i]=new int[n+1];
        //no need to initilse as we fill the array in same manner we are using those values
 }
 //fill first row and first col
 for (int j = 0; j <= n; j++)
 {
    output[0][j]=0;
 }
 for (int i = 0; i <= m; i++)
 {
    output[i][0]=0;
 }
 for (int i = 1; i <= m; i++)//i->length of s
 {
    for (int j = 1; j <= n; j++)//j->length of t
    {
        //fist first match to ans direct
        if (s[m-i]==t[n-j])
        {
            output[i][j]=1+output[i-1][j-1];
        }
        
       
        //first first match nhi ho rha to max of other 3 cases where we red s ka first , t ka first or bith ka first
        else
        {
            int a=output[i-1][j];
            int b=output[i][j-1];
            int c=output[i-1][j-1];
            output[i][j]=max(a,max(b,c));
        }
        
    }
    
 }
 return output[m][n];
 
    

}
int main()
{   string s,t;
cin>>s>>t;
lcs_dp(s,t);
    return 0;
}