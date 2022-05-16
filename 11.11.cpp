#include<bits\stdc++.h>
class Student{
public:
int age;
const int rollNumber;
Student(int r):rollNumber(r){//jaise hi object banega ye call higa roll no assign higa aur wo freeze ho jayega
//Student(int r,int a):rollNumber(r),age a{//jaise hi object banega ye call higa roll no assign higa aur wo freeze ho jayega
//ye bhi allowed hai
}
};
int main(){
    Student s1(101);
    s1.age=20;
    return 0;
}