#include<bits\stdc++.h>
//we want ttgat k humare har object ka roll no unique ho+change na ho sake
class Student{
int age;
const int rollNumber;
//const int roll_no;--->isme problem hai ye const sabka same karga to agle k liye new value nhi de payega
//hence ye kaam constructor ko krne do
Student(int r){
    rollNumber=r;//--->ye bhi gaalt haicoz yahan bhi ab roll no me garbage store ho chuka hai and hum usko ovrride kr rhe hai
}
};
int main(){

    return 0;
}