// making the stack generic
// now we will make our new satck worth it/
#include <bits\stdc++.h>
template <typename T>
class Stack
{
    // int *data;
    T *data;//data jispr work hoga uski jagah pr t
    int NextIndex;
    int capacity;

public:
    Stack()
    { // constructor creates the data type
      // data = new int[4];
        data = new T[4];
        NextIndex = 0;
        capacity = 4;
    }
    int size()
    {
        return NextIndex;
    }
    bool IsEmpty()
    {
        return NextIndex == 0;
    }
    void push(int element)
    { // sabse pehle check------->main coding to be done here
        if (NextIndex == capacity)
        {
            //  int *newData=new int[2*capacity];
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData; // data is now pointing t new array first index
        }
        data[NextIndex + 1] = element; // agar array fill hai to pehle badha lo nahi to uahi sahi
        NextIndex++;
    }
    // int pop()
    T pop()
    { // sabse pehle check
        if (IsEmpty())
        {
            printf("Stck empty\n");
            return 0;
        }
        int val = data[NextIndex];
        NextIndex--;
        return val;
        
    }
    T top()
    // int top()
    { // sabse pehle check
        if (IsEmpty())
        {
            printf("Stck Empty\n");
            return 0; // yahan se break krne k  liye
        }
        return data[NextIndex];
    }
};
int main()
{   Stack<int> s;
    int data;
    printf("Enter data foe oth index\n");
    scanf("%d",&data);
    int n=0;
    while (data!=0)
    {
        s.push(data);
        printf("Do you want more data?0 to exit\n");
        scanf("%d",&data);
        n++;
    }
    printf("u entered\n");
    while (n>=0)
    {
        printf("%d ",s.pop());
        n--;
    }
    printf("\n");
    return 0;
}