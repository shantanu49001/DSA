#include <bits\stdc++.h>
// mechanism to sahi hai lekin code me dikkat hai.
// isme aage move karne par data loss nhi hota.
template <typename T>
class Node
{   public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class Queue
{
    Node<T> *head; // think in a very simple way pointer >1 choose karo for reducing time complexity otherwise we will have to traverse long

    Node<T> *tail;
    int size;

public:
    Queue()
    {
       head=NULL;
       tail=NULL;
       size=0; 
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        if(size==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    void enqueue(T elment)
    {
        Node<T> *n = new Node<T>(elment);
        if (head == NULL)
        {
            head = n; // ye fix ho gya
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n; // tail ko n pr le aao coz tail =tail ka next koi logic nhi leta coz aglinode hai kahan
        }
        size++;
    }
    T front()
    {
        if (!isEmpty())
        {
            printf("%d", head->data); // segmentation error jab head me none
        }
        else
        {
            printf("Nothing here\n");
            
        }
    }
    T dequeue()
    {
        if (isEmpty())
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head; // pointer pointing to head
        head = head->next;    // head ko aage
        delete temp;          // purane head ko delete
        size--;
        return ans;
    }
};
int main()
{   Queue<int> q;
    printf("What operation u want to do\n");
    printf("1.Size of queue\n");
    printf("2.Front data\n");
    printf("3.enqueue\n");
    printf("4.dequeue\n");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
   // int s=q.getSize();
    printf("Size is%d\n",q.getSize());
        break;
    
    case 2:
        q.front();
        break;
    
    case 3:
        int data;
        printf("Enter data for node\n");
        scanf("%d",&data);
        q.enqueue(data);
        break;
    
    case 4:
        q.dequeue();
        break;
    
    default:
    printf("Can't do\n");
        break;
    }
    int ch;
    printf("repeat? (1->yes) or (0-No )\n");
    scanf("%d",&ch);
    if(ch==1){
        main();
    }
    else if(ch==0){
    printf("Thanks for using\n");
    printf("Have a nice day\n");
    }
   
    
    return 0;
}