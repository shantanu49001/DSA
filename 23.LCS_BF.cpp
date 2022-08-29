/*
->two strinf given by user
->we hae to return longest common substring b/w the two
->order must be same
//continuous hona zaroori nhi hai lekin order must be same
abcd---->ad->true     adb->x
badeab

abcde  -> cde,abe,ade
cadbe

braking the recursion teps

first elemnt pr hum karemge baaki recursion kaega

S->xazy-->match the first letters and ask the recursion sto find longest sunseq of remaining and the anser world be +1
t->xzd


case where firt letter match ->->matlb aage hume milega hummaage wale ke loye rcursion se bolenge jaake nikalo and save that int T ->  answer T+1
//dono answer me nhi ayenge else ordr kharab ho jayega


case where first doen't match->
case will be either one orno as if bith ->order kharab ho jahega

if dono hi nhi ayye 1.x->discrd->
                    2.z->discard->     9:04
                    3.bith discard->



*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string s,string t){
    //base case
    if (s.length()==0||t.length()==0)
    {
        return 0;
    }
    
   
    //whe first mach
    if (s[0]==t[0])
    {
        return 1+lcs(s.substr(1),t.substr(1));//if first case match->ask recursion to do what we want in bith 
    }
    

    //recursive->whe first doen't matched
    int a=lcs(s.substr(1),t);//14:15
    int b=lcs(s,t.substr(1));
    int c=lcs(s.substr(1),t.substr(1));
    return max(a,max(b,c));
}
int main()
{   string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;  
    return 0;
}