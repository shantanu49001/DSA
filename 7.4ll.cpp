#include <bits\stdc++.h>
class Node
{
public:
    int data;
    Node *next;  //class ke do variable hai
    Node(int data) //function se object banenge aur wo object hi nodes hai
    {
        this->data = data;
        next = NULL;
    }
};
int main()
{ // n1->head node;n2->tail node
    //  Node n1;-->sirf itn likenge to default constructor cal hoga but humne to apna banaya hai constructor
    Node n1(1); // data and next must be public here,data 1 add null
    Node n2(2); // data 2 add null
    // n1 and n2 are blocks
    n1.next = &n2; // actual object pr dot ;->when we want to cess the data mem by pointers
    printf("%d and %d ", n1.data, n2.data);
    // n2 ka address n1 ke paas hai
    // n1 ka add store->ek pointer me
    Node *head = &n1; // this is just a pointer var that stores address of node n1 and both these node and var belong to class node.
   //pointer var created just *next aka *head;
   //is amay hae k paas n1 ka addrsss hai
 
   printf("%d ",head->data);//node to actual object se nhi ek pointer var se acess kr rhe hai so ->
 
    return 0;
}