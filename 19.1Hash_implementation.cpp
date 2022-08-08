// key will be string here and value a template
// as of now
// we are having a array and array has head of ll
// array will ne doble pounter
//  int *data=new int[]
//  int **data =node containing wichich is a pointr
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class MapNode
{
public: // we can also use friend class
    string key;
    int value;
    MapNode *next;
    MapNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~MapNode()
    {
        delete next; // if we want poora list delete ho
    }
};

class OurMap
{
    MapNode **buckets; // MapNode<V>* *buckets
    int count;
    int numBuckets;

public:
    OurMap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode *[numBuckets];
        // int *data =new int[n]
        // int **data=new (int/dattype)*[num]
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL; // initially bucket array has null heads
        }
    }
    ~OurMap()
    {
        // array ko disrupt krne se pehle saara heads o dlete
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i]; // distruontruto of map node call
        }
    }
    int getsize()
    {
        return count;
    }
    int getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }

            head = head->next;
        }
        return 0; // nhi mila
    }

    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoeff = 1; // weight of last p
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;         // to prevent it going out of range
            currentCoeff *= 37;                       // p=37 here
            currentCoeff = currentCoeff % numBuckets; // to make it in range
        }

        return hashCode % numBuckets;
    }
    void rehash()
    {
        MapNode **temp = buckets;
        buckets = new MapNode *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2; // numbuckets hanged
        count = 0;
        // hum nodes k=e heads ko direct copy nhi kr sakte as each element ka location change ho chuka hai
        for (int i = 0; i < oldBucketCount; i++)
        { // traversoing
            MapNode *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                int value = head->value;
                Insert(key, value); // addig in new
                head = head->next;
            }
        }
        // int *arr-->arr->first location pr jo bhi place kiya,hw=ere integer
        // int **arr--> first location pr jo bhi hai here another pointer array
        // delting old
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode *head = temp[i];
        }
        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (1.0 * count / numBuckets);
    }
    void Insert(string key, int value)
    {
        int bucketIndex = this->getBucketIndex(key);
        MapNode *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                // agar wo key already hui
                head->value = value;
                return;
            }
            head = head->next;
        }
        // yahan tak agar aaye matlb nhi nila head
        head = buckets[bucketIndex];
        MapNode *node = new MapNode(key, value);
        node->next = head;
        buckets[bucketIndex] = node; // naya head
        count++;
        // rehasjhing part
        //   double loadFactor=count/numBuckets-->gif retun higa we want exact number
        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }
    int remove(string key)
    {
        // index pe jao fir list ke beechme kahin hoga wo use deete karna hai
        int bucketIndex = getBucketIndex(key);
        MapNode *head = buckets[bucketIndex];
        MapNode *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev->next = NULL)
                {
                    buckets[bucketIndex] = head->next;
                    // parent head jo array me store hai use change
                }
                else
                {
                    prev->next = head->next;
                    // earlier i wad worried that it will be lost
                    // head is alrady a copy of parent isko aage move krna se koi farak nhi pagega last me array me to uska head hai hi bro!
                }
                int value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        /// we reached last of list/array
        return 0; // int-> 0 return pointer->null
    }
    void PrintTable(){
        for (int i = 0; i < this->numBuckets; i++)//numbuckets is number of buckets in buckets array
        {
           printf("%d:",buckets[i]->key); 
           if (buckets[i]->next!=NULL)
           {
            
            MapNode *head=this->buckets[i];
            while (head->next!=NULL)
            {
                printf("%d->",head->key);
                head=head->next;
            }
            
            
            
           }
           
        }
       
        

    }
};

int main()
{ // testing the code
    OurMap map;
 
    int choice = 0;
    while (choice != 5)
    {
        printf("1.Insert a key value\n");
        printf("2.Delete a key value\n ");
        printf("3.Get current Load factor\n");
        printf("4.Print hash Table\n");
        printf("5.Exit \n");
        if (choice == 1)
        {
            string key_n;
            int value_n;
            printf("Enter key and value\n");
            cin >> key_n;
            scanf("%d", &value_n);
            map.Insert(key_n, value_n);
        }
        else if (choice == 2)
        {
        string key_p;
        printf("Enter the key to delete\n");
        cin>>key_p;
        map.remove(key_p);
        }
        else if (choice == 3)
        {
            printf("%d\n",map.getLoadFactor());
        }
        else if (choice == 4)
        {
            printf("HashTable is\n");
            map.PrintTable();
        }
        else if (choice == 5)
        {
            printf("Thanks for Using\n");
        }
        printf("Enter ur choice\n");
        scanf("%d",&choice);
    }

    return 0;
}