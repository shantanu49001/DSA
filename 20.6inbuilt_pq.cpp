#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<queue>
//IsEmpty<->empty()->to be used
//getSize()<-> size()->to be used
//void insert<->void push
//getMin()<->T top()
//T removeMin()<->void pop()
using namespace std;
int main()
{   priority_queue<int> pq;
    pq.push(16);
    pq.push(1);
    pq.push(672);
    pq.push(7);
    pq.push(45);
    pq.push(32);
    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Top:"<<pq.top()<<endl;
    return 0;
}