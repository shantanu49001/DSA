#include<bits\stdc++.h>
class Student{
int age;
//char *name=new char[10];--->abhi size nhi pta hai
char *name;
public:
Student(int age,char *name){//we have argument and dat type both as age so we use this to diffrerentiate between the two that we are changing value only for this object
this->age=age;
//shallow copy
//this->name=name;
//DEep copy
this->name=new char[strlen(name)+1];//naye length ka array
strcpy(this->name,name);//us namye array ko copy kr do har object ke liye alag ayya
//us object ke aka this->

}
void display(){  
    printf("%s %d\n",name,age);
}
};
int main(){
    //Student s1;--->this is wromg as we have our parameterised constructor and default constructor is now not present
    char name[]="abcd";
    Student s1(20,name);//ye sahi hai
    s1.display();
    name[3]='e';//name =abce
    Student  s2(24,name);
    s2.display();
    s1.display();//we are expecting abcd and 20 but since name is changed it will be abce
    //aosa is liye hua coz dono objects same array ko copy krta hai
    //this is called shallow copy same array ki new image nahi ban rhi thi
    //ab s1 ka s1 hi change kr sakta hai
    return 0;
}