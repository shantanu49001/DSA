// stl template.
// map->ordered->by bst->qll logn
// unordered ->hashtable->all O(1).
#include <bits\stdc++.h>
#include <map> //tmplate
#include <string>
using namespace std;

int main()
{
    map<string, int> OurMap;
    // insert
    pair<string, int> p("abc", 1);
    OurMap.insert(p);//thcan do insertion is does insertion
    OurMap["def"]=2;//we can do insertion by hti too
    //acess
    printf("%d",OurMap["abc"]);
    printf("%d",OurMap.at("abc"));//by builtin function
  //  printf("%d",OurMap.at("ghi"));//not allowed as it is not present
    printf("%d",OurMap["ghi"]);//this will not return error as it will assign default key 0 to it
    //checking presence
    if (OurMap.count("ghi")>0)//()-->tabhi use krna hai jab ho alredy []-->kabhi bhi 
    {
        //ek key ek baar hi aa sakti hai
       printf("Present"); 
    }
    
    printf("%d",OurMap.size());//prints no of key value paris
    //erase
    OurMap.erase("ghi");//removed the key

    return 0;
}
