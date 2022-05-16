//doubt -->reursions se how do we paas then to functions
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
// function me input kaise le,return type head?
int length(Node *n,int length){

}
int main()
{
    int data;
    int index = 0;
    printf("Enter data of first node\n");
    scanf("%d", &data);
    Node *n1 = new Node(data, index);
    index++;
    Node *head = n1;
    Node *temp = n1;
    Node *print = n1;
    while (data != 0)

    {
        if (data == 0)
        {
            break;
        }
        printf("Do u wan to add new nodes?enetr data or press 0 to exit\n");
        scanf("%d", &data);
        Node *n = new Node(data, index);
        temp->next = n;
        temp = temp->next; // temp used in linking
        index++;
    }
    printf("You enetered\n");
    while (print != NULL)
    {
        printf("%d:%d ", print->data, print->index);
        print = print->next;
    }
    int length=0;
    int val=length(head,length);
    return 0;
}