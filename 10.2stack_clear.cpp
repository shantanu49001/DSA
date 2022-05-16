#include <bits\stdc++.h>
class StackUsingArray
{
    int *data;
    int nextIndex; 
    int capacity;

public:
    StackUsingArray(int totalSize)
    {                              
        data = new int[totalSize]; 
        nextIndex = 0;
        capacity = totalSize;
    }
    
    int size()
    {
        return nextIndex;
    }
    
    bool isEmpty()
    {
        
        return nextIndex == 0; 
    }
    
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            printf("Stack full\n");
            return;  
        }
        data[nextIndex] = element; 
        nextIndex++;
    }
    
    int pop()
    {
        if (isEmpty())
        {
            printf("Stack empty\n");
            return INT_MIN; 
        }
        nextIndex--; 
        return data[nextIndex];
    }
    
    int top()
    {
        if (isEmpty())
        {
            printf("Stack empty\n");
            return INT_MIN;
        }
        return data[nextIndex];
    }
};
int main()
{                         
    StackUsingArray s(4); 
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    printf("%d\n", s.top()); 
    printf("%d\n", s.pop()); 
    printf("%d\n", s.pop()); 
    printf("%d\n", s.pop());
    printf("%d\n", s.size()); 
    printf("%d\n", s.isEmpty());
    return 0;
}
