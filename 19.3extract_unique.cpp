#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
vector<int> Output;
string s;
printf("Enter the string\n");
cin>>s;
map<int,bool> seen;
for (int i = 0; s[i]!='\0'; i++)
{
   if (seen.count(s[i])>0)//apne ap dekh lega
   {
    continue;
   }
   seen[s[i]]=true;//here it adds//method to insert

   Output.push_back(s[i]);

   
}

return 0;
}

