// 1.GENERATION OF HASHCODE=================
// making our own hashmap
// key goes through the hash function that generates a integr where we place our key
/*
Hash function->hash code+compression function
              (this is not necc within size)
              ->hashcode passed through comp function that gives index at which we will plce

int->hascode->output---->easier
abc->hashcode(it can be sum of ascii/stc)->output
             problem here is abc cba give same hash code
   ->some other hash function needs to be taken
 abc=a*p^3+....    p->generally a prime no


another best hascode is student->find it's address in hexa converto to integer and pass to compression function
to get the index

key-->hash functon-->index
     (hascodde)->cf




========================================*/
/*
2.COLLISSION HANDLING==============================================
what if two key yiedl 105 205 as integer after hash funion
and hese two pass to compression function
105%20=5
205%20=5===>now where to place them?????

to resolve this we make two paths->
a.closed hashing/seperate chaining
here both the keys go to same loc and the bucket isn't an array but a collection of hads of ll
when two val have same index that ll extendes further to store n repreted indexded keys

b.open addressing
here let H(abc)=n H(cdf)=n=>alreday placed
now for abc  if tht index is empty place abc else we make n attemps to check the next alternative to place abc and no of attempts decided it's location

Hi(abc)=H(abc)+f(i)==>ith attemt ==>location
here f(0)=0
now this f functon can be a linear probig->f(i)=i
                           Quadratic pri->f(i)=i^2
                           Double Hashing->f(i)=i*h'(a)==>some other has function combination


But in general we make use of seperate chaining and easier to implement


*/
#include <bits\stdc++.h>
#include <map>
#include <string>
using namespace std;
template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()//for deleting whiole node
    {
        delete next;
    }
};
template <typename V>
class ourmap
{
    //we want an array that is collection of heads of ll
    //array of pointers
    MapNode<V>** buckets;
    int size;
    int numBuckets;
    public:
    size=0;
    numBuckets=new MapNode<V>*[numBuckets];
    for (int  i = 0; i < numBuckets; i++)
    {
        buckets[i]=NULL;
    }
    ~ourmap(){
        for (int i = 0; i < numBuckets; i++)
        {
            //deleting all ll
            delete buckets[i];
        }
        delete [] buckets;//then the array of ll heads
    }

int size(){
    return count;
}
private:
//compression function
int getBucketIndex(string key){//this gives index by calculting hascode and compression
int hasCode=0;
int currentCoeff=1;
for (int i = key.length()-1; i >=0; i--)
{
    hashCode+=key[i]*currentCoeff;
    hashCode=hashCode%numBuckets;
    currentCoef*=37;
    currentCoeff=currentCoef%numBuckets;//to make it within range
}

return hasCode%numBuckets;
}
public:
void insert(string key,V value){
    int bucketIndex=getBucketIndex(string key);
    MapNode<V>* head=buckets[bucketIndex];
    while (head!=NULL)
    {
        if (head->key==key)//checking if already present
        {
            head->value=value;
        }
        head=head->next;
        
    }
head=buckets[bucketIndex];
MapNode<V>* node=new MapNode<V>(key,value);
node->next=head;
buckets[bucketIndex]=node;
count++;  
}
void getValue(string key){


}
V remove(string key){
    

}
};
int main()
{

    return 0;
}