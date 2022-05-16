#include<bits\stdc++.h>
//copy constructor inbuilt shallow copy karta hai
//Student s2(s1)--->ab s2 wahi s1 wala hi lega apna nhi banaega
//we  must create apna own copy constrictor
/*
Student(Stduent s){
    thi->age=s.age;//s2 ka structure ban rha hai with s1 as input
    this->name=new char[str(s.name)+1];
    strcpy(this->name,s.name);//khud ka naya aaray banalo

}

//class me bhi const value wahin pr krte hai initialise
*/
class Student{
    int age;
    public:
    char *name;
    Student(int age,char *name){//thid was to create new array for every object
        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    //now for Student s(s1)--->ab s1 ke liye bhi s k name ka aaye apna khud kaaye
            //        s kijagah pr-->warna jab bhi copy cobtr call hoga wo pehle s ka object banaega aur chalta jaega
    Student (Student &s){//copy constructor mine,ab default wala nhi hoga
        this->age=s.age;//argument is an object here so to break infinite calling of object for creatin s1 we pass by reference
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
    }
};
int main(){
//int &j=i--->same add given
//int *p=&a--->copy of add given

    return 0;
}