#include<bits\stdc++.h>
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
    this->data=data;
    this->next=NULL;
    }
};
int main(){
    int data;
    printf("Enter data of first Node\n");
    scanf("%d",&data);
    Node *n1=new Node(data);
    Node *temp=n1;//used
    Node *head=n1;
    Node *print=n1;//used

    Node *skip_location=n1;//used
    
    printf("Enter data of second Node\n");
    scanf("%d",&data);
    while (data!=0)
    {
        Node *n=new Node(data);
        temp->next=n;
        temp=temp->next;
        printf("Do u want need node? enter data or press 0 to exit\n");
        scanf("%d",&data);

    }
    int length=0;
    while (print!=NULL)
    {
        printf("%d->",print->data);
        print=print->next;
        length++;
    }
    printf("\n");
    
    int times;
    int location;
    printf("Enter location to start skipping\n ");
    scanf("%d",&location);
    int i=1;
    while (i!=location)
    {
        skip_location=skip_location->next;
        i++;
    }
  //  printf("%d",skip_location->data);
    Node *p=skip_location;
    Node *q=p->next;
    printf("How many nodes to skip at a time?\n");
    scanf("%d",&times);
    int skip_times=-0;
    while (skip_times!=(length-i)/times)//assigns connection after each skipp steps
    {
        for (int i = 0; i <times; i++)//skps nodes
        {
            q=q->next;
        }
        p->next=q;//p ko q th skippes se link
        p=p->next;//usko q pe aa jaygea p
        skip_times++; 
        
    }
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    
    
    
    
    return 0;
}