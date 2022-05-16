//doubt hai recursion me 
//doubt hai recursion me 
//doubt hai recursion me 
//doubt hai recursion me ------->note krte time krna
//doubt hai recursion me 
//doubt hai recursion me 
//doubt hai recursion me 
//doubt hai recursion me 
//doubt hai recursion me 
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
Node* takeInput(Node* head,int data){
   while (data!=0)
   {
       printf("Do u want to add new nodes?press 0 to exit\n");
       scanf("%d",&data);

   }
   

}

int main(){
    int data;
    printf("Enter data for first node\n");
    scanf("%d",&data);
    Node *n1=new Node(data);
    Node *head=n1;

    takeInput(head,data);
    return 0;
}
    
