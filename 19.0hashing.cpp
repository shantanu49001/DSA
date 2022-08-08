// our won hashmaps using hashtable
// keys and values
/*
aces and storing dono me time nhi lagna chahiye
1.array->most initial though
2.key ,value->we need to store and for each key we want a location
3.key goes through hash function to et a location
4.one integer corresponding to key->we get a hashcode
5.but no gaurantee that hashcode can give a index
6.it goes through compression function to get range within array
7.perfect compression function is %bucket size

 KEY->HASHCODE->COMPRESSION FUNCTION.
 HASHFUNCTION->HASHCODE+COMPRESSION FUNCTION.
once we get hashcode we get compree function easily
we want unifom spread 
now we have many types of keys
integer ,char ,.....->
for int it is easy to get hascode 
for string-> ascii sum but problm is abc bac cba give same
-> we want greater range and uniform spread but less collisions
->method 2->treat abc as number with base p
->p if it is a prime no gives best distribution


But what if final index of two are same ?-->COLLISION

COLLISSION HANDLING---------------------
1.closed hasing->dono wahi jayenge ek index ko 1 se zyaga hadle krna padega array ki har entry ll ka head hai
2.open addressing->agar jagah khli hai to theek warn ek alternate dhoodho
                 ->Hi(a)=Hf(a)+f(i)
                 ->base i=0
each step pe compression funcion lga denge jisse kisis tsep pe agar bahar gya hi to sahi ho jaye
3.now we have two cases i.linear probing f(i)=i
                       ii.quad probing f(i)=i^2->clutering se bhagne kikoshing karega
                      iii.Double hasinh-> f(i)=i*produnct with other hash function.
                      ...
4.in practise ,seperate chaing works as well as any other open chaiing and also very good in comp to open add
5.we will use seperate chaing only
6.



*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{   
    return 0;
}