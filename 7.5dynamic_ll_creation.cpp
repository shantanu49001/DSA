#include<bits\stdc++.h>
class Node{
    public:
int data;
Node *next;
Node(int data){
    this->data=data;
    next=NULL;
}
};
int main(){
    //static declaration
    Node n1(2);
    Node n2(3);
    Node n3(6);//actual var se node acess 
    n1.next=&n2;
    n2.next=&n3;
    //dyanamic 
    Node *n4=new Node(10);//ye pointer var hai jo ki new created node ka address store kr rhe hai
    Node *head = n4;//pointer var se node acess
    Node *n5=new Node(20);
    n4->next=n5;
   
    
    return 0;
}