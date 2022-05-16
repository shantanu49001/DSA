#include <bits\stdc++.h>
#include <stack>
// length odd-->-1 return coz we can't balace it
using namespace std;

// logic-->sabse pehle jitne balance ho rhe hai unko pop kardo
//{{{{}}-->{->{->{->}==>pop=>}
//{{=>}==>now agar top ke do ka ascii same hai that means ek ko rreverse karenge to ho jayega ..similarly count maintain.
//}{-->count+2
//{{-->count+1

int main()
{
    string s = "{{{{}}";
    stack<char> c;
    if (s.length()%2!=0)
    {
        printf("Cn't balance this\n");//working
        return 0;
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        if(c.empty()==1){
            c.push(s[i]);
        }
        else if(c.top()=='{'&&s[i]=='}'||c.top()=='}'&&s[i]=='{'){
            c.pop();
        }
        else{
            c.push(s[i]);
        }
    }//popping done
    printf("Scanned once now refining\n");//working
    int times=0;
    if (c.empty()==1)
    {
        printf("Now balanced already\n");//working
        printf(" 0 reversals requied\n");
    }
    else {
        while (c.empty()!=1)
        {
            char ch=c.top();
            c.pop();
            if (ch=='{'&&c.top()=='{'||ch=='}'&&c.top()=='}')//}{   
            {
                times+=1;
            }
            else if(ch=='}'&&c.top()=='{'){
                times+=2;
            }
        }
    //daigram of everystep is important to make.    

    }
    printf("%d",times);
    
     return 0;
}