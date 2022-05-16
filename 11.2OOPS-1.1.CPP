#include <bits\stdc++.h>
class Student
{   public:
    int rollNo;
    int age; // only two properties of student which functins work upon
 void print(){
     printf("%d,%d",rollNo,age);
 }
};
int main()
{//STATIC Creation
    // int a--->var a of data type integer(4 bytes ka block create hota hai)
    Student s1; //   crete var of user  data type stduent
    //(ye memory block 4+4 bytes ka hai)
    s1.rollNo=10;//s1 ka roll no
    s1.age=12;//s1 ka age---->actual mem block aata idhar
    s1.print();//s1 ka print m s1 k hi value hogi by default
//DYNAMIC CREATION--->pointer pointer to mem block is given
//int *a=new int
    Student *s3=new Student; //us box ko ab s3 point kr rha hai
    s3->rollNo=10;//s3 ka roll no
    s3->age=11;//s3 ka age
    s3->print();
    delete s3;
    return 0;
}
/*
Acess Modifiers(default private)-->data ko hum public rakte hai or unko work karne k liye functins private 
-->public-:kahin pr bhi 
-->private-:sirf usi class tak use kr sakte hai
-->protected-:
*/