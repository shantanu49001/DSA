/*
problem-> there are two players in a game a and b 
a start s to play the game

n coins are given -1 x y ->moves allowed to remove the coin

a player wins if he performa a move and perfectly vanishes the coins in his move


solution->

let's say there are n coins and i am player A

for me to win->       n--->  last step
              1.n-1   2.n-x   3.n-y-->one before move-->cins left --. if i win here then at final step i will loose as after me b will do the last move perfectly and he will win
  basically i will check my win value out of these and i will do xor to check win possiblity from doind last move and select the path where after xor it is 1
  if penultimat step has all 1 hn surely i will looose


if any of the penultimate step is a loose then i will suely win at last step.

at each index i am calculating the value at i-1 i-x and i-y and do xor of ll the three and then do or of all and store the value and value at last index determines my win probability


in these problems assume yourself to be the startig player and make urself win the game.

store the win possiblity at each index 

base case if n'-1==0||n'-y==0||n'-z==0-->true-->at this step i am winning
*/

#include <bits/stdc++.h>
using namespace std;
bool recursion(int N,int x,int y){
if (N==0||N==1)
{
    return true;
}

if ((N<x||N<y)&&(N!=1||N!=0))
{
    return false;//in that case i am not in a perfect move to win
}


bool a=recursion(N-1,x,y);
bool b=recursion(N-x,x,y);
bool c=recursion(N-y,x,y);

bool answer=(a^1||b^1||c^1);//if one move before i was winning then by performing a by xor i will loose at my final and by cheking all final answer if any step result true then i will win

return answer;

}
int main()
{   
    int num_coins,x,y;
    cout<<"Enter num of coins"<<endl;
    cin>>num_coins;
    cout<<"Enter move x and y"<<endl;
    cin>>x>>y;
    bool val=recursion(num_coins,x,y);
    if (val==true)
    {
        cout<<"A will win"<<endl;
    }
    else if (val==false)
    {
        cout<<"A looses"<<endl;
    }
    
    
    
    
    return 0;
}