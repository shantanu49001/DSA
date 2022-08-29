// we know the size we know where to insert we just need to add effieciet insertion n array
#include <bits/stdc++.h>
using namespace std;
// final answer will be at m+1,n+1 last cell
/*
s=abc t=xyca =>matrix ka size 0,0->3,4 ->increased bcoz size zero also considerd
now if match->original answer at 3,4 depends on reursive anser of 3,2->direc recursion case
if not matched -> 2,4   3,3     2,3 ->wale pe depend 2:41


now checkin ght depenedied of min cell ->0,0
also kisi ke bhi zero hui direct nswe -> first row and cl saare fill
then we can fill our whole array based on recursons

dp->no recrusions just ietrations
*/
int editDistance_Dp(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    // fill first row
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = j; // non zeros tring k length is the anse coz either we are adding thse char or deleting
    }
    for (int i = 0; i <= m; i++)
    {
        output[i][0] = i;
    }
    // remaing fill

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // if first first match ->s=abc t=axcd(3,4)
            // then hum size decrease kr ke 2,3 me add
            if (s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            { // the rest three

                int a = output[i - 1][j - 1];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];

                output[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }

    return output[m][n];
}
int main()
{
    return 0;
}