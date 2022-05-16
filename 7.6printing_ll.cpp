#include <bits\stdc++.h>
class Node
{
public:
    int data;
    Node *next; // pointer to point the nodes
    Node(int data)
    {
        this->data = data; // structure of node
        next = NULL;
    }
};
int main()
{
    /*
      1|200   2|300   3|400   4|500   5|Null
      (100)   (200)   (300)   (400)   (500)
      daigram of all nodes pointers draw
    */
    // Node n1(1)
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3); // ceating node
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *head = n1; //&n1-->wrong ;coz n1 khud ek pointer hai
    // abhi head k paas pehle ka hi addrss hai
    // n1.next=&n2
    n1->next = n2; // ab n1 ke next me n2 ka addrss hai.
    n2->next = n3; // linking nodes
    n3->next = n4;
    n4->next = n5;
    // next-->address storrer of first node has address of n2 node
    // head=head->next-->head ek address store krta hau ;next hai add stored in n1 whi h is of n2;head to ab n2 k address se point kardo
    while (head->next != NULL)
    {
        printf("%d",head->data);//ek pointer var hai jo node ko point kr rha hai to ->
        head = head->next;//point to next node's address
        printf("\n");
    }

    return 0;
}