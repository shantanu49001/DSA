// balacnf->cbt studied
// heap oder ->here
//every root in the tree is either greater or lower than it's both children
//insert me sabse pehle cbt property satisfy krna hai islye ;ast me add
//then heapify
//comare that with it's parent if elemet added is in odd index parent->2i+1 se find
//until swap karo jab tak parent root satify na karde or wo root ya 0th index tak aa jaye
//worst case me root tak jana hai O(h) aka O(logn)  bcoz it is h=logn
//this process is caleed up heapify



//now deletion
//min heap me min is at root ->root delete
//root and last ko swap
//index--
//then down heapify-->comparing and swapping
//here size is decreaing by one
//complexity->zyada smaller wale se swap hoga if min heap
//worst case ->O(h)
//getfunction ->O(1)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{   
    return 0;
}