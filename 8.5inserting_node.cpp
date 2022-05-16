// inserting the node at index
// naya connection banane pr purana apne aap chala jata hai
// 1.index tak temp chalao
// 2.us index ke ek peh;e pr temp me address new node la daal do
// 3.ye karne se uske baad wali node ka conn toot gya;
// so pehle baad wali node ka add link krna padega new node se
// pehle ith-1 tak reach kr jao

// us location pr pohoch kr temp ko move karmna hota hai bas
// node *a=temp->next-->baad wala k address save kr liya hau
// temp->next=new node;=>ek pehle ka link
// new node=a;==>third ka link
#include <bits\stdc++.h>
class Node // user defined data type
{       //virtual array.
public:
    int data;
    int index;
    Node *next;
    Node(int data, int index)
    {
        this->data = data;
        this->index = index;
        this->next = NULL;
    }
};
int main()
{
    int data;
    int index = 0;
    Node *head = NULL; // finding index
    printf("Enter data for 1st node\n");
    scanf("%d",&data);
    Node *n1 = new Node(data, index);
    head = n1;
    Node *print = head;  // for printing
    Node *temp = head;   // for lunking
    Node *print2 = head; // after linking print

    while (data != 0)
    {
        Node *n = new Node(data, index + 1);
        index++;
        temp->next = n;
        temp = temp->next;
        printf("Do u want to add new node?Enter data aur press 0 for exit\n");
        scanf("%d", &data);
    }
    printf("Now printing the values\n");
    while (print!=NULL)
    {
        printf("%d:%d ",print->data,print->index);
        print=print->next;
    }
    printf("\n");
    int add;
    printf("Enter index after which u want to add node\n");
    scanf("%d",&add);
    while (head->index!=add)
    {
        head=head->next;//head ko jiske baad add karna hai uspr rok diya
        
    }
  //  printf("%d\n",head->data);
    int val;
    printf("Enter data at node to be addes\n");
    scanf("%d",&val);
    Node *n2=new Node(val,add+1);//node to be added
    Node *a=head->next;//a me head jahan tak gya tha uske next ka add a me aa gya
    head->next=n2;//head to new node pr point
    n2->next=a;//new node to next node se point.
    while (print2!=NULL)
    {
      printf("%d ",print2->data);
      print2=print2->next;
    }
    delete a;
    return 0;
}