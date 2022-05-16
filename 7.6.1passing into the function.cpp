#include <bits\stdc++.h>
class Node
{
public:
    int data;
    Node *next;//objects are nodes
    Node(int data)
    {
        this->data = data;//jis object ko ye point kr rha uske.....
        this->next = NULL;
    }
};
// int print(int *a){
void print(Node *a)
{ // node data type hai ye pointer int ko nhi node to point kr rhi hai
    // it is advisable to use a temp pointer instead of head coz head lost ho akte hai
    while (a != NULL) // a->next != NULL /otherwise last waal node print hohaga hi nhi wo jaise hi wo wlae node me ayega jiska next null hai exit ho jayega wahan se
    {
        printf("%d ", a->data);
        a = a->next;
    }
}
int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    print(head);
    return 0;
}