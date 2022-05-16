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
    int length=1;
    printf("Enter vaue at node1\n");
    scanf("%d",&data);
    Node *head=NULL;
    Node *n=new Node(data);
    head=n;
    Node *temp=head;
    
    while (data!=0)
    {   Node *n=new Node(data);
        temp->next=n;
        temp=temp->next;
        length++;
        printf("Do u want to add new node?,press 0 to exit or enter value at node\n");
        scanf("%d",&data);
        
    }//yaham tak nodes coonect ho gyi by temp
    printf("Data entered is\n");
    while (head!=NULL)//head 1 se hi start hoga aur linked nodes tak move karega
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
    printf("And length is %d\n",length);
    
    return 0;
}