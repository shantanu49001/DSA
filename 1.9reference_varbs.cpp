#include<iostream>
using namespace std;
int main(){
    int i=10;//i alag memory hai
    int j=i;//j alag memory hai
    i++;
    cout<<i<<endl;//-->i change hoga
    cout<<j<<endl;//j change nhi hoga
    int k=10;
    k++;
    int &a=k;//a is a var that is just a reference to older memory,wo usi memory ka doosra name hai
    cout<<k<<endl;//yahan dono chage hoge
    cout<<a<<endl;//a ke liye alag memory nhi hai
//int &j
//j=i   --->not allowed batana padega k ye ref kiski memory ka ref le rha hai
}

