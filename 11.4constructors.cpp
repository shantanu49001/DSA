#include<bits\stdc++.h>
//same as class name
//no return type
//no input argument
class Student{
    public:
    int rollNumber;
    private:
    int age;
    public:
    Student(){//default constructor(inbuilt wala ab gayab)
    printf("HEllo\n");
    }
    Student(int r){//overloading(parameterized constructor)
       // return r;--->constructor kuch return nhi karta
    }
    void display(){
        printf("%d,%d",age,rollNumber);
    }
    int getAge(){
        return age;
    }
    void setAge(int a,int password){
        if (password!=123)
        {
            return;
        }
        age=a;//indirectly we changed private elemnt by outside(setter)
        
    }
    Student(int rollNumber){
        rollNumber=rollNumber;//ye usi ka roll no chage karega jo object use call kr rha hoga
        //now yahan to local wala hi change hoga 
        //but what if we want to change the roll no of class ?
        //
    }
};
int main(){
//jab bhi class ka object banta hai constructor apne aap call hota hai
    Student s1;//yahan constructor call
    s1.display();//random garbage given by constructor will come
    Student s2;//yahan pr bhi --->yahan pr default call
    Student s2(10);//yahan pr doosra wala constructor call hoga
    Student *s3=new Student;//yahan bhi
    s3->display();
    return 0;
}