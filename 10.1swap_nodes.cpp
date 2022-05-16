// swap nodes.
#include <bits\stdc++.h>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int main()
{
    int data;
    printf("Enter data for first node\n");
    scanf("%d", &data);
    Node *n1 = new Node(data);
    Node *loc = n1;//used.
    Node *head = n1;//used.
    Node *temp = n1;  // used.
    Node *print = n1; // used.
    printf("Enter data for second Node\n");
    scanf("%d", &data);
    while (data != 0)
    {
        Node *n = new Node(data);
        temp->next = n;
        temp = temp->next;
        printf("Do u want to add new Node?enter data or press 0\n");
        scanf("%d", &data);
    }
    printf("you entered\n");
    while (print!=NULL)
    {
        printf("%d->", print->data);
        print = print->next;
    }
    printf("\n");
    int location;
    printf("Enter location to swap\n");
    scanf("%d",&location);
    int i = 1;
    while (i < location)
    {
        loc = loc->next;
        i++;
    }
  //  printf("%d", loc->data);
    Node *p=loc;
    Node *q=p->next;
    Node *r=q->next;
    p->next=r;          //sucessfully swapped elements.
    q->next=r->next;
    r->next=q;
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    
   delete(p,q,r);
  
    return 0;
    /*
    loc 
    p    q    r
    p->next=r;
    q->next=r->next;
    r->next=q.
    
    //connections banane k liye new nodes and saving of address pehle hona chahiye.
    */
   //bubble sort me just we have to iternte again and agau n,initialise head node after each traersal .
}