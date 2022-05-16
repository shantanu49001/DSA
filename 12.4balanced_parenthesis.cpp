//{a+(b-c)*d}-->balanced
//{a+(b-c+[e-f)]}
// problem ye hai k {[( iske bad check kaise kare k next wla }]) inmese koi hai
// DIRECT STACK LEMENTS USED HERE
#include <bits\stdc++.h> //we used in built stack here
using namespace std;
bool isValid(string s)
{
    int n = s.size();
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!(st.empty()) && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!(st.empty()) && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!(st.empty()) && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    string s = "{([])}";
    if (isValid(s))
    {
        printf("Valid string\n");
    }
    else
    {
        printf("Invalid string\n");
    }
    return 0;
}