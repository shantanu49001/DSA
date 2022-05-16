//this skips only once.
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
    printf("Enter data for first node\n");
    scanf("%d",&data);
    Node *n1=new Node(data);
    Node *head=n1;
    Node *move=n1;
    Node *temp=n1;//used
    Node *print=n1;//used
    printf("Enter data for second node\n");
    scanf("%d",&data);
    while (data!=0)
    {
      Node *n=new Node(data);
      temp->next=n;
      temp=temp->next;
      printf("Do you want to add new node?press 0 toexit\n");
      scanf("%d",&data);
    }
  //approach--> m times age badhi
  //Node* ptr/Node *ptr
  //poimter me head ka next dalo head nhi haead ka next
  //fir usko n times move krdo
  //uske baad head->next me new node ka addrss daal do
  //head dalna matlb usi node ka add dena
  //head->next dalna matlb agle wale ka dena. 
   int length=0;
   printf("You entered\n");
   while (print!=NULL)
   {
       printf("%d->",print->data);
       print=print->next;
       length++;
   }
   printf("\n");
   int location;
   int times;
   printf("enter at what location u want to skip\n");
   scanf("%d",&location);
   printf("How many nodes to skip\n");
   scanf("%d",&times);
   if(location>length||times>length||location+times>length){
       printf("Not possible\n");
       printf("You skipped whole ll\n");
   }
   else{
     int i=1;
     while (i!=location)
     {
         move=move->next;
         i++;
     }
     Node *p=move;//p move ka add store
     Node *q=p->next;//q age move
     int j=1;
     while (j!=times)
     { 
          q=q->next;
          j++;
     }
     p->next=q->next;//p aur q connect;
     while (head!=NULL)
     {
         printf("%d->",head->data);
         head=head->next;
     }
     
     
     

   }
   return 0;
}