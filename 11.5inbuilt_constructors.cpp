#include<bits\stdc++.h>
/*//default-->wahi jo object k saath free milta hai 
  //copy --->Student s1(10,100)
         --->Student s2(s1);--->object s2 ne saari prop s1 k  le li
    Student *s3=new Student(20,1001)     
    stdudent s4(*s3)--->yahan copy constructor me derf karke karna hoga
    student *s5=new Student(*s3)
    student *s6=new student(s1)

    ek object k liye ek hi constructor call ho sakta hai
    agar student s2(10,20 ) hai then we can't use stdudent s2(s1) after that
    we can also use s1=s2 for using copy constructor
 */
//destructor-->no return type
/*          -->no arguments
            -->object memory to deallocate krta hai
            -->called automaticaally when objec scope is getting to be over
  //apna banae pr default wala nhi hota call
  ~Studen(){
    //iske baad object khtam ho jayega 
    //ya ye object ke ssare kaam ho jane k baad call hota hai
  }          
*/            
int main(){
   //Student s1(10,1001);---->destructor apne aap call hoga
   //Student s2(20,1002);---->destructor apne aap call
   // Student *s3=new student(30,31110)--->isme delet s3 karne par hi destructor call hoga
    //constructor sabme apne aap call hota hai
    return 0;
}