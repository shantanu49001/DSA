// check in which prog input was well taken by functions.
//not working properly.
//note kr lena problems of.
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
Node *printll(Node *head)
{
    while (head)
    {
        printf("%d->", head->data);
        head = head->next;
    }

    printf("\n");
}
Node *takeInput(Node *head)
{
    int data;

    do
    {
        printf("Do u want to add new Node?press 0 to exit\n");
        scanf("%d", &data);
        Node *n = new Node(data);
        head->next = n;
        head = head->next;

    } while (data != 0);
}
Node *printNodes()
{
}
int main()
{
    int data;
    printf("Enter data of first node\n");
    scanf("%d", &data);
    Node *n1 = new Node(data);
    Node *head = n1; // presrve.
    takeInput(head);
    printf("You entered\n");
    printll(head);
    printf("Now arranging\n");
    Node *odd = NULL;
    Node *even = NULL;
    Node *e = NULL;
    Node *o = NULL;
    while (head != NULL)
    {
        if ((head->data) % 2 == 0)
        {
            if (even == NULL)
            {
                even->next = head;
                e = even; // ye pehle even ka address karega--->join
                even = even->next;
            }
            else
            {
                even->next = head;
                even = even->next;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd->next = head;
                o = odd; // for printing
                odd = odd->next;
            }
            else
            {
                odd->next = head;
                odd = odd->next;
            }
        }
        head = head->next;
    }
    odd->next = e; // for linking
    while (o!=NULL)
    {
        printf("%d->",o->data);
        o=o->next;
    }
    

    return 0;
}