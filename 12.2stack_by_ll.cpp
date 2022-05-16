#include <bits\stdc++.h>
// push,pop,top,size,isEmpty all were working in order of O(0)when we used stack by array
template <typename T>
class Node
{ //---->ye to hai node ka structure
public:
    Node<T> *next;
    T data;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// hum head to new node se point karemge aur new node to previous se attach
// unlike ll
// since hume kuch bhi karne k liye ek step hi consider karna hai
// to 3 pointers se kaam chal jayega humara
// head,prev,tail
// basically we will have to link the nodes in reverse way
template <typename T>
class Stack
{                  // isem data members Node ka head aur sze hai
    Node<T> *head; // Node class ka pointer public tha
    int size;      // ye don
public:
    Stack()
    { // initialise data members
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(T element)
    {                                            // kuch return nhi karna hai just add
        Node<T> *newNode = new Node<T>(element); // Node *n=newnOde(data);
        newNode->next = head;
        head = newNode;
        size++;
    }
    int pop()
    {
        if (head != NULL)
        {
            T ans = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return ans;
        }
        else
        {
            printf("Already empty\n");
            return 0;
        }
    }
    int top()
    {
        if (head != NULL)
        {
            return head->data;
        }
        else
        {
            printf("Stack Empty\n");
            return 0;
        }
    }
};
int main()
{
    Stack<char> s;
    int data;
    printf("Enter data for first node of stack\n");
    scanf("%d", &data);
    int l = 0;
    while (data != 0)
    {
        s.push(data);
        printf("Do u want more nodes?press 0 to exit\n");
        scanf("%d", &data);
    }
    char ch;
    printf("Do u want to push elements Y or N?\n");
   
    scanf("%c", &ch);
    while (ch == 'Y' || ch == 'y')
    {
        if (ch != 'n' || ch != 'N')
        {
            s.pop();
            printf("Pop more?\n");
            scanf("%c", &ch);
        }
        else if (ch == 'N' || ch == 'n')
        {
            break;
        }
    }
    printf("\n");

    return 0;
}