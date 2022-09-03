/*
on investigation->our array size if also the same

we are storing the max sized square array possible maxing the index as top left corner of our arry
boundary or least depenedent case is the last row elementd as the cormerr using them 0 sized square possible as fi=uther no arry possible
left side col->also 0 on same argument

now where ever the inut index=0 we atore o as we don't wnt corne with value 0 as we are making it to be of obe so o size squre at hat inde xtoo

now filling the between indees -> just bottok daigonal and just right index ka min+1->bcoz out of these the min sized 
square restructs the index to make boggest sized squre ->argument int nptes

*/
#include <bits/stdc++.h>
using namespace std;
//this problem will be solved from dp only
int main()
{   int N;
    cout<<"Enter the size of the arrray "<<endl;
    cin>>N;
    int **input=new int*[N];
    cout<<"Enter array of 0 and 1 only"<<endl;
    for (int i = 0; i < N; i++)
    {  // cout<<""
        input[i]=new int[N];
        for (int j = 0; j < N; j++)
        {   cout<<"Enter the value at"<<i<<" "<<j<<endl;
            cin>>input[i][j];
        }
        
    }
    
    //now w are storing 0 where ever 0 storing the last row and rights most col 
    //to check whther the other indexes are filled we initlaise the array with int+max
    //as ultimatly we are taiking min so our answer isn't hampered.
    int **output=new int*[N];
    for (int i = 0; i < N; i++)
    {
        output[i]=new int[N];
        for (int j = 0; j < N; j++)
        {
            output[i][j]=INT_MAX;//initilase to differentiate
        }
        
    }

     int maxx=INT_MIN;//final answer reuurn krne k liye
     for (int i = 0; i < N; i++)//copying the zero where ever zero
     {
        for (int j = 0; j < N; j++)
        {
            if (input[i][j]==0)
            {
                output[i][j]=input[i][j];
            }
            
        }
        
     }

//filling thr ;ast row and ;ast clol don't change where it is zero
int col=N-1;
for (int i = 0; i < N; i++)//filling the right most col
{
    if (output[i][col]==INT_MAX)
    {
        //these are the paes which are not zero and these are having defualt values
        output[i][col]=1;//at thus only 1 sizes max square possibe
    }
    
    
}
int row=N-1;
for (int  j = 0; j <N ; j++)
{
    if (output[row][j]==INT_MAX)
    {
        output[row][j]=1;
    }
    
}

//now filling the rest of the array indexes
for (int  i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        int a=output[i+1][j];
        int b=output[i][j+1];
        int c=output[i+1][j+1];

        if (output[i][j]==INT_MAX)
        {
            output[i][j]=min(a,min(b,c))+1;
        }
        
    }
    
}

//find ig tje max value
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N;j++)
    {
        if (output[i][j]>maxx)
        {
            maxx=output[i][j];
        }
        
    }
    
}

cout<<"Max sized squre possible is"<<maxx<<endl;
     
    
    return 0;
}