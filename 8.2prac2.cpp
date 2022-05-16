//using loops
//completly done by me.
//neche se upar code kro 
#include<bits\stdc++.h>
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
    this->data=data;
    this->next=NULL;//this=>"is node ka"
    }
};
int main(){
    int data;
    printf("Enter data for first node-:");
    scanf("%d",&data);
    Node *n1=new Node(data);
    Node *head=n1;//ab isko reserve rakho
    Node *temp=head;//lhs=rhs=address
    if (temp!=NULL)
    {
        while (data!=0)
    {   Node *n=new Node(data);
    //basically temp aage badhta hai aur link krta jata hai
        temp->next=n;//temp jis node to point kr rha us node to new node se link kr do
        temp=temp->next;//temp ko age badha do.
        printf("Do u wan to add more nodes?,press 0 to exit\n");
        scanf("%d",&data);
    }
    
    
    } 
    printf("Now printing values\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}