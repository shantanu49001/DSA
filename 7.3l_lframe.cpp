//array ka size fixed ho jata hai;athough dynamic arrays me ho jata hai but normal me nhi hota hai ye .
//array me cont otahai to add name ad acess kr lete hai
//but linked list me har ek ka address strore krna padega so we use ptr.
//we will have address of only first one then we ask 1st to store add of second';second to store address of third;third to stor addres of fourth

/*

1|780   2|460    3|670   4|null ==>structure of a linked list
(100)   (780)     (460)  (670)
classes are used to form user defined data types as we didn't had a data typr that has oth data and address
gar ek var int dtabtype ka add store krta hai to int *next
but ye node datatype ka address store krta hai 
node *next
*/
#include<bits\stdc++.h>//for null to work
class Node{//node data type
public:
int data;//usme data hoga
Node *next;//usme address hoga
Node(int data){//constructor of this node jo ki is node k var ko change kr sakta hai
    this->data=data;//is node k data ko 
    next=NULL;
}
};
