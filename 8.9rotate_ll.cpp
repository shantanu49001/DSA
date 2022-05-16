/***
 *
 *optimised solution is circular linked list.
 *
 *
 * */
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
    printf("Enter data of 1st node\n");
    scanf("%d", &data);
    Node *n1 = new Node(data, index);
    Node *head = n1;
    Node *temp = head;
    Node *rotations = n1;
    Node *print = n1;
    index++;
    while (data != 0)
    {
        printf("Do u want to add new nodes?Enyter the data or press 0 to exit\n");
        scanf("%d", &data);
        Node *n = new Node(data, index);
        temp->next = n;
        temp = temp->next;
        index++;
    }
    int length = 0;
    while (print != NULL)
    {
        printf("%d->", print->data, print->index);
        print = print->next;
        length++;
    }
    printf("\n");
    //  printf("%d",length);
    int rot;
    printf("Enter no of rotaions\n");
    scanf("%d", &rot);
    int i = 0;
    while (length - rot > i + 1)
    {
        rotations = rotations->next;
        i++;
    }
    //   printf("%d",rotations->data);
//CODE IS FINE IT HERE.
    Node *p=rotations;
    Node *q=rotations->next;//new head
    p->next=NULL;
    //problem arising here----------------------------------------------------------------------------------------------
    while (i-length>=1)//next ko null rakhne se pehele
    {
        q=q->next;//end tak pohich gye
        i++;
    }
  //  printf("%d",q->data);
    q->next=n1;
   // printf("%d",q->data);
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    
    

    return 0;
}