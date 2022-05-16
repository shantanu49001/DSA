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
    int data1,data2;
    Node *head=NULL;
    printf("Enter data for node1\n");
    scanf("%d",&data1);
    Node *n1=new Node(data1);
    printf("Enter data for node2\n");
    scanf("%d",&data2);
    Node *n2=new Node(data2);
    head=n1;//iske pass first node ka acess hai wo rehne do
    //ab is node  kahin bhi poora ll  acess ho jata hai
    Node *temp=head;//isse head aur n1 link ho gya
    temp->next=n2;//isse n1 and n2 link kr diya=>ye hai temp next ka matlb;ab ise n2 k equal kr do jiska add copy karn ahai
    while (temp!=NULL)//JAB TAK YEMP ADD NULL NA HO
    {
      printf("%d ",temp->data);//temp jis node ko point kr rha usa daya   
      temp=temp->next;
    }
    
    return 0;
}