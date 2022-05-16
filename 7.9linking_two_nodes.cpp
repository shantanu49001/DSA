
//not working
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
//head=head->next==>next node k addess ko head me dedo
//head->next=new node==>head ji s node ko holfd kr rha tha uske next me new node ka address daal do
int main(){
    int data1;
    int data2;
    Node *head=NULL;
    printf("Enter first data at node 1\n");
    scanf("%d",data1);
    Node *n1=new Node(data1);
    printf("Enter data at node 2\n");
    scanf("%d",&data2);
    Node *n2=new Node(data2);
    head = n1;
    n1->next=n2;
    Node *temp=head;//to avoid head loss;head pehle se hilinked tha ;ab head k through tem ko move kr sakte hai
    while (head->next!=NULL)//HEAD-100 100TH ADD WALE NODE PR JAO USKE NEXT TO NULL CHECK
    {
        printf("%d ",head->data);
        head=head->next;
    }
    


    return 0;
}