#include <bits/stdc++.h>
using namespace std;
bool recursion(int N, int x, int y,bool output[])
{
    if (N == 0 || N == 1)
    {
        return true;
    }

    if ((N < x || N < y) && (N != 1 || N != 0))
    {
        return false; // in that case i am not in a perfect move to win
    }
    if (output[N]!=0)//intantionally to handle false and 0 .
    {
        return output[N];
    }
    
    bool a = recursion(N - 1, x, y,output);
    bool b = recursion(N - x, x, y,output);
    bool c = recursion(N - y, x, y,output);

    bool answer = (a ^ 1 || b ^ 1 || c ^ 1); // if one move before i was winning then by performing a by xor i will loose at my final and by cheking all final answer if any step result true then i will win
    output[N]=answer;
    return output[N];
}
int main()
{
    int num_coins, x, y;
    cout << "Enter num of coins" << endl;
    cin >> num_coins;
    cout << "Enter move x and y" << endl;
    cin >> x >> y;
    bool *output=new bool[num_coins+1];
    for (int i = 0; i <=num_coins; i++)
    {
        output[i]=0;
    }
    
    bool val = recursion(num_coins, x, y,output);
    if (val == true)
    {
        cout << "A will win" << endl;
    }
    else if (val == false)
    {
        cout << "A looses" << endl;
    }

    return 0;
}