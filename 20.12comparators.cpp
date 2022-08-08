#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include<vector>
using namespace std;
bool comparator(){//our made comparator

}
int main()
{
    vector <int> a;
    // default comparator-->agar swap krna hai to false return nhi krna to true
    sort(a.begin(),a.end(),false);
    //our own comarator using inbuilt library
    
    return 0;
}