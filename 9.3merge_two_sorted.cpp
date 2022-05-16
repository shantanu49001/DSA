#include<bits\stdc++.h>
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
Node *takeInput(Node *head)
{
    int data;
    printf("Enter data for next node\n");
    scanf("%d", &data);
    Node *temp = head;
    while (data != 0)
    {
        Node *n = new Node(data);
        temp->next = n;
        temp = temp->next;
        
        printf("Do u want new nodes?enter data or press 0 to exit\n");
        scanf("%d", &data);
    }
}
Node *printLL(Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}
Node* merge(Node* &head1,Node* &head2 ){//hume changes krne hai actual me bhi 
  Node *p1=head1;
  Node *p2=head2;
  Node *dummyNode=new Node(-1);
  Node *p3=dummyNode;
  while (p1!=NULL &&p2!=NULL)//koi bhi hoga exit ho jayega
  {
      if (p1->data<p2->data)
      {
          p3->next=p1;
          p1=p1->next;//p1 ko age badha do;p2 ko nhi coz wo agli p1 se bada ya chota ho skata hai
      }
      else{
          p3->next=p2;
          p2=p2->next;
      }
      p3=p3->next;//uske baad p3 ko bhi badha do
      
  }
  while (p1!=NULL)//agar koi bhi finish ho jaye to
  {
      p3->next=p1;
      p1=p1->next;
      p3=p3->next;
  }
  while (p2!=NULL)
  {
      p3->next=p2;
      p2=p2->next;
      p3=p3->next;
  }

  printLL(dummyNode);
  
}
int main()
{
    int data;
    
    Node *n1 = new Node(data);

    printf("Enter data of 1st Node of 1st LL\n");
    scanf("%d", &data);
    Node *head1 = n1;
    takeInput(head1);
    printf("Enter data of 1st Node of second LL\n");
    scanf("%d", &data);
    Node *n2 = new Node(data);
    Node *head2 = n2;
    takeInput(head2);
    printf("You entered 1st ll as\n");
    printLL(head1);
    printf("You entered second ll as\n");
    printLL(head2);
    printf("Now merging the two sorted arrays\n");
    //we are not creating new nodes just links are changing.
    merge(head1,head2);
    
    return 0;
}