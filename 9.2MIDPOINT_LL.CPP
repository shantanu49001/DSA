#include<bits\stdc++.h>
class Node{
    public:
    int data;
    int index;
    Node *next=NULL;
    Node(int data,int index){
        this->data=data;
        this->index=index;
        this->next=NULL;
    }
};
int main(){
    int length=0;
    int data;
    int index=0;
    printf("Enter data of 1st index\n");
    scanf("%d",&data);
    Node *n1=new Node(data,index);
    Node *temp=n1;
    Node *head=n1;
    Node *print=n1;

    index++;
    length++;
    while (data!=0)
    {
        printf( "Do u want new node?enter data or press 0 to exit\n");
        scanf("%d",&data);
        if(data!=0){
        Node *n=new Node(data,index);
        temp->next=n;
        temp=temp->next;
        index++;
        length++;
        }
    }
    printf("You entered\n");
    while (print!=NULL)
    {
        printf("%d:%d->",print->data,print->index);
        print=print->next;
    }
    printf("\n");
    //more modifications can be done such as inputs must be odd
    printf("Now finding the mid value\n");
    int i=1;
    while (i<=length/2)
    { 
        head=head->next;
        i++;
    }
    printf("%d",head->data);
    
    return 0;
}