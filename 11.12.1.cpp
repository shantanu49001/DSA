#include<bits\stdc++.h>

class Student{
public:
int roll_no;
int age;
static int totalStudents;//ab agr ye private hoga to function ke andar daal do
//aur wo function bhi static hoga wo object se cal nhi hoga
Student(){
    totalStudents++;//jab jab object call hoga const toal students badha dega
    //ab saare object banne ke baad toal students sare object ke liye same hogi
}
int getRoll(){
    //coz ye sabka alag alag hina chahiye
}
static int getstudents(){//is property ko acess karne k liye onject ki zaroorat nh hai
    return totalStudents;
}
};
int Student::totalStudents=0;//this is only initialisation
//static functions ke through sirf static data acess kr sakte hai aur usme this-> useless hota hai
int main(){
    Student s1;
    printf("%d",s1.totalStudents);
    
    Student s2;
    printf("%d",s2.totalStudents);//2 
    printf("%d",s1.totalStudents);//1 hi hai
    Student s3,s4,s5;
    //object banega constructor call hoga aur har baar value badha dega 
    printf("%d",s1.totalStudents);//5
    printf("%d",s2.totalStudents);//5
    printf("%d",s3.totalStudents);//5
    printf("%d",s4.totalStudents);//5
    printf("%d",s5.totalStudents);//5
    printf("%d",Student::totalStudents);//ye bhi 5 hoga 
    printf("%d",Student::getstudents());
    return 0;
} 