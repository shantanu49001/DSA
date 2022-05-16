//const--> that can't be hanged
//define-->substituted
//global-->can be changed
#include<bits\stdc++.h>
using namespace std;
int main(){
const int i=10;//isko idhar hi initialise krna padega
int j=18;
const int &k=j;//raskta fixed hai j ko reachkrne ka
//k++;-->isse dekkat hai
j++;//-->isse nhi
//k ke trough nhi change kr sakte lekin j ke through kr sakte hai;path const hai value nhi
const int j2=10;
const int &k2=j2;//rasta aur value dono fixed ho gye
//read only path se ek writeable path nhi bna sakte
}
    
