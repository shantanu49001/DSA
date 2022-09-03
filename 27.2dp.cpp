#include <bits/stdc++.h>
using namespace std;
//here i just need to have effieceint filling of elements
int dp(int input[],int N){
int *outtput=new int[N];
//least dpenedent fill first
outtput[0]=input[0];//they have found out their answer
outtput[1]=max(input[1],outtput[0]);

//now filling the rest
for (int i = 2; i < N; i++)
{
    //previous wale apna answer nikal le laa chuke hai mujhe un dono ke answer m se max wala choose krna hai
    int a=input[i]+outtput[i-2];
    int b=outtput[i-1];
    outtput[i]=max(a,b);
}
return outtput[N-1];

}
int main()
{   int N;
    cout<<"Enter number of elements"<<endl;
    cin>>N;
    int *input=new int[N];
    cout<<"Enter array elements"<<endl;
    for (int i = 0; i < N; i++)
    {
        cin>>input[i];
    }
    //final answer will be the last index as max last tak maintain 
   int val= dp(input,N);
    cout<<val<<endl;
    return 0;
}