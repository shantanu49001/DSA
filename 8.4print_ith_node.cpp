#include <bits\stdc++.h>
class Node//virtual array
{   public:
    int data;
    int index;
    Node *next;
    Node(int data, int index)//user defined data structure
    {
        this->data = data;
        this->index = index;
        this->next = NULL;
    }
};
 int main()
{
    int data;
    int index=0;
    
    printf("Enter value at node 1\n");
    scanf("%d",&data);
    Node *head = NULL;
    Node *n1=new Node(data,index);//is node me 2 data hai 1 address hai
    

    head=n1;//ab head to yahi chod do;
    Node *temp=head;
    Node *ind=head;
    while (data!=0)
    {   Node *n=new Node(data,index);
        temp->next=n;
        
        temp=temp->next;//loop ke baad temp lost ho jayega
    
        printf("Do you want to add new node?enetr data or press 0 to exit\n");
        scanf("%d",&data);
        index++;
    }
    printf("you enetered-:\n");
    while (ind!=NULL)//loop ke baad ind lost ho jayega
    {
        printf("%d ",ind->data);
        ind=ind->next;
    }
    printf("\n");
    
    printf("Enter index to print value\n");
    int add;
    scanf("%d",&add);
    while (head!=NULL)
    {
        if(head->index==add){
        printf("vale at index is %d",head->data);
        
        }
        head=head->next;
        
    }
    
    
    
    return 0;
}