#include <bits\stdc++.h>
template <typename T>
//sirf cahnge hai first index ko circular move karne ka
//aur element ko wahan add karne ka jahan circular ho jaye space waste na hao.
class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }
    int getSize()
    {
        return size; // ye elementd bata hai
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            printf("Size full\n"); // ye limited queue hai
            return;
        }
        else
        {
            data[nextIndex] = element;
            //  nextIndex++;//but isse karne pr agar aage khali hua to wo nhi milega
            nextIndex = (nextIndex) % capacity; // elements cylic order me hi achalega so ab hume jo age vanacnt hua hoga use use karna hai
            if (firstIndex == -1)
            { // ye ek baar hi hoga oth se aa jayega
                firstIndex = 0;
            }
            size++;
        }
    }
    // theek hai dequeue next index ko change kr dega
    T front()
    {
        if (isEmpty())
        {
            printf("Queue Empty\n");
            return 0;
        }
        else
        {
            return data[firstIndex];
        }
    }
    T dequeue()
    {
        if (isEmpty())
        {
            printf("Queue empty\n");
            return;
        }
        else
        {
            T ans = data[firstIndex];
            //    firstIndex++;--->yahan bhi first size 4 ke baad  0 ona chahiye
            firstIndex = (firstIndex + 1) % capacity;
            size--;
            if (size == 0)
            {
                firstIndex = -1; // resetting the values
                nextIndex = 0;
            }
            return ans;
        }
    }
};

int main()
{   QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.front();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.getSize();
    q.isEmpty();
    return 0;
}