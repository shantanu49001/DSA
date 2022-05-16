#include <bits\stdc++.h>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL; // jo bhi node banegi uska next null hoga
    }
};
Node *takeInput()
{
    int data; // 1.ek node ko starting me bana deta hai.
    printf("Enter the value at node\n");
    scanf("%d", &data);
    Node *head = NULL; // 2.head node create
    while (data != 0)  // termination condition
    {
        Node *newNode = new Node(data); // data entered set hai aur next=null hai new node ka    3.new node created.
        if (head == NULL)               // ha null hai pehli baar                                              4.head node initailly null ko point
        {                               // second baar head null nhi hai
            head = newNode;             // linking first node                                                5.head ka address new node ka address
            // head k paas first nide ka link hai
        } // first k link k baad head nhi chalega
        else
        {                              // jab first wali link ho chuki ai
            Node *temp = head;         // temp me head ka upfated address                                6.temp ka node head ka address
            while (temp->next != NULL) //  7.temp head ko point kr rha hai head node jiska address le rha hai --->this is to aquire first node ka addrss to temp by head
            {
                temp = temp->next; //   8.temp=temp->next--->next node ko jodo-->ye tab tak nhi tha jab tak temp pehle node ko aquire nhi kr paa rha tha
            }
            temp->next = newNode;
        }
        printf("Do you want more nodes? press 0 toexit\n");
        scanf("%d", &data);
    }
    return head;
}
void print(Node *head)
{ // yahan hum head ko chala sakte hai last tak coz ye ;ast kaam hai
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main()
{
    Node *head = takeInput();
    printf("Now printing the values enterred\n");
    print(head);
    return 0;
}