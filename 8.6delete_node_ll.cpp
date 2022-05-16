#include <bits\stdc++.h>
class Node
{
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
    printf("Enter value at node1\n");
    scanf("%d", &data);
    Node *n1 = new Node(data, index);
    Node *print = n1;
    Node *print1 = n1;
    Node *head = n1;
    Node *temp = n1;
    while (data != 0)
    {
        Node *n = new Node(data, index);
        temp->next = n;
        temp = temp->next;
        printf("Do u want to add new Node?enter data or press 0 to exit\n");
        scanf("%d", &data);
        index++;
    }
    printf("U enetered:\n");
    while (head != NULL)
    {
        printf("%d:%d ", head->data, head->index);
        head = head->next;
    }
    printf("\n");
    int add;
    printf("Enter index of node u want to dlelete node\n");
    scanf("%d", &add);
    while (print->index != add - 1)
    {
        print = print->next;
    }
   // printf("%d", print->data);
    
  //  1->2->3->4->5
  //head at 2==>temp=head;
  //a=temp->next=>a me 3 ka address
  //a->next=b==>4 ka address b me hai
  //temp=b;==>2 ko 4 se link;
  //function me pass strut Node *head
  printf("New ll after deletion is\n");
  //ek baar head ka next kisi me store kr diya fir head ke aaram se age lega sakta hu
  // 1:200 2:300 3:400  4:NULL
  //         p   q             q wale ko delete krna hai
  // 100   200   300    400

  //p->next=300 changed to 400 now
  Node *p=print;//this musr be before the deleting node
  Node *q=print->next;//ye to bohit simple ho gya
  p->next=q->next;//q ek step aage hai
  free(q);//3:400  wala free
  while (print1!=NULL)
  {
      printf("%d ",print1->data);
      print1=print1->next;
  }
 

  return 0;
}