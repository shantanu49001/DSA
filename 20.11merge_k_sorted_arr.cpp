/*let us cinsider k=2
approach->2-2 array leke as we built in ll



k ayyas->
1.har baar initillay insert elements in the priority quwu
2.remove the min at new array we got the minimum
3.then insert the new element if the arrau of which we got minimum earler
4.repeat the process
5.each ekemnt must have index at which they are removed + in which array they belong
6.Triplet maiantain of these values
7.in pririty queues we have to insert this triplet

mainatin a check if the array finishes

study insert a triplet in priority queue
-->amian part

comparator->custom sorting algo


the function that defines when should we swap


ear;ier let's say it was for 1 1 element
now we wan to sort for 1,2   and 3,4
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
bool should_i_swap(pair<int,int> a,pair<int ,int> b){
    if (a<b)
    {
        return false;
    }
    
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > a(n);//vector of pairs
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if (should_i_swap(a[i],a[j]))
            {
                swap(a[i],a[j]);
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i].first<<" "<<a[i].second;
    }
    cout<<endl;
    
    return 0;
}
