#include <bits/stdc++.h>
using namespace std;


int dp(int num_coims,int x,int y){
bool *output=new bool[num_coims+1];
//filling the base cases
output[0]=output[1]=true;
for (int  i = 2; i <= num_coims; i++)
{
    if ((i < x || i < y))
    {
        return false; // in that case i am not in a perfect move to win
    }
   else
   {
       bool a = output[num_coims-1];
       bool b = output[num_coims-x];
       bool c = output[num_coims-y];

       bool s=(a^1||b^1||c^1);//previos 3 setep ke result ko leke current cell me win possibilty determine krne k liye
       output[i]=s;
   }
   
}

return output[num_coims];
}
int main()
{
    int num_coins, x, y;
    cout << "Enter num of coins" << endl;
    cin >> num_coins;
    cout << "Enter move x and y" << endl;
    cin >> x >> y;
  bool val=  dp(num_coins,x,y);
    if (val==true)
    {
        cout<<"A wins"<<endl;
    }
    else if (val==false)
    {
        cout<<"A looses"<<endl;
    }
    
    
    return 0;
}