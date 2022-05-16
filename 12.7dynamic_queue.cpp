//stacks me wapas ane ka need nhi tha coz peeche se add aue peeche se hi remove th
//queue me peeche se dd tha lekin age se remove kr rhe the. 
#include <bits\stdc++.h>
template <typename T>
//COPYING PART EK BAAR FIRSE DEKH LENA AUR WO %CAPACITY WALA BHI
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
        return size; 
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T element)
    //30 40 50 10 20
    //10 20 30 40 50-->afer copying data
    //
    {
        if (size == capacity)
        {
        T *newData=new T[2*capacity];
        int j=0;
        for (int i = firstIndex; i < capacity; i++)
        {
            newData[j]=data[i];
            j++;
        }
        for (int i = 0; i < firstIndex; i++)
        {
            newData[j]=data[i];
            j++;
        } 
           //data-> 30 40 50 10 20   ni=2 fi=2
           //not want->10 20 30 40 50 60 x
        
           //new data-> ab ye fi se copy karega
        
        delete [] data;
        data=newData;
        firstIndex=0;
        nextIndex=capacity;
        capacity*=2;
        }
        
        
            data[nextIndex] = element;
            
            nextIndex = (nextIndex) % capacity; 
            if (firstIndex == -1)
            { 
                firstIndex = 0;
            }
            size++;
        
    }
    
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
          
            firstIndex = (firstIndex + 1) % capacity;
            size--;
            if (size == 0)
            {
                firstIndex = -1; 
                nextIndex = 0;
            }
            return ans;
        }
    }
};

int main()
{
    QueueUsingArray<int> q(5);
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