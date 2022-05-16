#include<bits\stdc++.h>
using namespace std;
#include<stack>
/**
 * (a+b)--->non redundant
 * ((a+b))->redundant
 *  (a+(b+c))-->non redundant
 */
//logic-: brackets and operators keep on pushing them
//jaise hi closing brackets aaye we need to ensure k usse pehle stack me koi operator hona chahiye
int main(){
    bool ans=false;
    string s="((a+b))";
  //  int length=sizeof(s)/sizeof(char);
    stack<char> st;
    for (int i = 0; i < s.size(); i++)//iterating through the string
    {
        if(s[i]=='+'or s[i]=='-'or s[i]=='*'or s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){//main logic
          if(st.top()=='('){
              ans=true;
          }
            while(st.top()=='+'or st.top()=='-' or st.top()=='*' or st.top()=='/'){
            st.top();//operators ko bhi pop
            }
            st.top();//bracket ko bhi pop
        }

    }
    printf("%d",ans);
    
    return 0; 
}