//CONCEPT AND BRUTE FORCE
#include <bits/stdc++.h>
using namespace std;
/**(Best and properly done)
 * we are given two strings and we have to make both strings equal
 * insert a char 
 * delete a char
 * update and replace char
 * 
 * we have to retun min count 
 * 
 * abc   dcb
 * 1. d->a c->b b->c =>3 operations
 * 2. d,b delete ab insert=> 4 operations
 * 3. d->a  b issert bw and last b dlete => 3 opeartiosn
 * 
 * we don't have to actually change we just have to return the count
 * 
 * s=abcd
 * t=axdze(let)
 * 
 * we have to focus only on first char and rest recursion does
 * 
 * a.if they match-: done ke nex se last tak recurson me daal denge to ind it
 * b.if they don't match-: s=abcd t=zxcd
 *only i have 3 opeartions to do
 * we have inserted a before z->now we have ,ade t same now proceed the recusion to do on next to last index and ans=recursion+1
 * we if we are deleting->s=abcd t=xcd(z remove )
 * still ew have not got the same now we will ask recursion to do and +1 to it's answer and here string length of one of the string a reduced
 * we can also replace z<->a se replace abcd axcd->now we got first same and now we will sak recursion to do +1 to it's answe
 * 
 * 
 * but we don't know which oone will return min->min of all three is our answer
 * 
 * 
 */
int editDistance(string s,string t){//hypothetically assume string is changing we don't hav to chane it
//base case->jab koi bhi ek emtry 
//s=abc t=0  =>insert char to t or delte all of s
//answer will be either of them's lwngth
if (s.size()==0||t.size()==0)
{
    return max(s.size(),t.size());
}




if (s[0]==t[0])
{   //recursion will do the same
    return editDistance(s.substr(1),t.substr(1));
}
else
{
   //insert->s=abc t=bcd => s=abc t=abcd => ab first first match ho gye ecursion me first ke baad se use s=>bc t=bcd 
   int x=editDistance(s.substr(1),t)+1;
   //delete->s=abc  t=bcd => s=abc t=cd=.nw next wale kaam recursion
   int y= editDistance(s,t.substr(1))+1;
   //replace  s=abc t=bcd => s=abc t=acd =>first match ho gye an next index se last tk dno me call
   int z=editDistance(s.substr(1),t.substr(1));

   return min(x,min(y,z));
}


}
/*\
time and space complexity 
7:20
*/
int main()
{   
    return 0;
}