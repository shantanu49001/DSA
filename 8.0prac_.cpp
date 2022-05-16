//working perfelty.
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
    int data1;
    int data2;
    Node *head=NULL;
    printf("Enter data for node1\n");
    scanf("%d",&data1);
    Node *n1=new Node(data1);
    printf("Enter data for node2\n");
    scanf("%d",&data2);
    Node *n2=new Node(data2);
   // printf("%d %d",n1->data,n2->data);
    head=n1;//link head and n1
    head->next=n2;//link n1 and n2
    printf("now printing the values by loop by head\n");
    while (head!=NULL)//head->next mat likna coz wo ek step aage chlta hai last node print nhi hoga
    {
        printf("%d ",head->data);
        head=head->next;
        //pehli baar head me 1st node ka add tha
        //second time head me 2nd node ka addre aa jayega
        //jo ki null hai
    }
    
    
    return 0;
}