#include <bits\stdc++.h>
//how to end programme in between.
//perfect.
//block daigrams prefer.
//ARRAY K ELEM TO SWAP KRNE KE LIYE ADD PASS KARTE HAI SWAPPING FUNCTION ME.

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
int End(){
    printf("Exiting\n");
    return 0;
}
int main()
{
    int data;
    int index = 0;
    printf("Enter data for first node\n");
    scanf("%d", &data);
    Node *n1 = new Node(data, index);
    Node *temp = n1;//used
    Node *head = n1;

    Node *print = n1;//used
    index++;
    while (data != 0)
    {
        printf("Do u want to enter new node?enter data or press 0\n");
        scanf("%d", &data);
        if (data != 0)
        {
            Node *n = new Node(data, index);
            temp->next = n;
            temp = temp->next;
            index++;
        }
    }
    while (print != NULL)
    {
        printf("%d:%d->", print->data, print->index);
        print = print->next;
    }
    printf("\n");
    // printf("%d",head->next->data);thus is working
  /*  while (sorted != NULL)
    {
        if (sorted->data > sorted->next->data)
        {
            printf("please enter a sorted data\n");
         // apne aap exit ho rha jo sahi hai
            End();
        }
        sorted = sorted->next;
    }
    */
    printf("Now removing duplicates\n");
    Node *p=head;
    Node *q=head->next;
    while (q->next!=NULL)
    {
        if(p->data==q->data){
            q=q->next;
            p->next=q;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    
    

    return 0;
}