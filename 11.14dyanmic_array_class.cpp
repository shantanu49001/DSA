// user jab chache jitne chahe elements add kr sake
#include <bits\stdc++.h>
class DynamicArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    DynamicArray(DynamicArray const &d){//deep copy
    //this->data=d.data;//shallo2
    this->data=new int[d.capacity];//deep
    for (int i = 0; i < d.nextIndex; i++)
    {
        this->data[i]=d.data[i];
    }//deep
    
    this->nextIndex=d.nextIndex;
    this->capacity=d.capacity;
    }
    void add(int element)
    { // equal hone se pehle naya array banan hai
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i]; // copying in new
            }
            delete[] data;
            // data wapas live ho gya new array ke saath
            data = newData; // new array allocated
            capacity *= 2;
        }
        data[nextIndex] = element; // double karne ke baad aad
        nextIndex++;
    }
    int get(int i)
    {
        if (i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
    void add(int i, int element)
    {
        if (i < nextIndex)
        {
            data[i] = element;
        }
        else if (i == nextIndex)
        {
            add(element); // array double +add
        }
        else
        {
            return;
        }
    }
    void print(){
        for (int i = 0; i < nextIndex; i++)
        {
            printf("%d ",data[i]);
        }
        printf("\n");
        
    }
};
int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();
    d1.add(0,100);
    DynamicArray d2(d1);//copy constructor called-->ye shallow copy karta hai
    //d2 me d1 ka data copy ho gya-->d1 me change karenge to d2 me bhi hoga
    d2.print();//ye kyon change hua????
    DynamicArray d3;
    d3=d1;//ye bhi shallow copy
    d3.print();
       
    return 0;
}