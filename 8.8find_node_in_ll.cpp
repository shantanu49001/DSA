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
    
    printf("Enter data of first Node\n");
    scanf("%d", &data);
    Node *n1 = new Node(data, index);
    index++;
    Node *head = n1;
    Node *temp = n1;
    Node *print = n1;
    while (data != 0)
    {
        Node *n = new Node(data, index);
        temp->next = n;
        temp = temp->next;
        index++;
        printf("Do u want to add new nodes?enter data or press 0 to exit\n");
        scanf("%d", &data);
    }
    printf("You entered\n");
    while (print != NULL)
    {
        printf("%d:%d ", print->data, print->index);
        print=print->next;
    }
    printf("\n");
    int element;
    printf("Now enter the element u want to search\n");
    scanf("%d", &element);
    while (head != NULL)
    {
        if (head->data == element)
        {
            printf("Element found at location %d\n", head->index);
        }
        head=head->next;
    }
    

    return 0;
}