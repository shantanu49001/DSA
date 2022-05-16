/*
struct node{
    struct node *prv;
    struct node *next;
    int data;
}


*/
//we can also reverse ll using double ll.
#include<bits\stdc++.h>
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
int main(){
    int data;
    printf("Enter data for first Node\n");
    scanf("%d",&data);
    Node *n1=new Node(data);
    Node *head=n1;
    Node *temp=head;
    while (data!=0)
    {   printf("Do u want to add new Node?enter data or 0 to exit\n");
        scanf("%d",&data);
        
        if (data!=0)
        { 
          Node *n=new Node(data);
          n->prev=temp;
          temp->next=n;//linking indouble;
          
        }
        temp=temp->next;//temp to badha diya
        
    }
    printf("You entered\n");
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    
    return 0;
}