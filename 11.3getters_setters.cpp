//but hum log ise change directly nhi kr paa rhe .
#include<bits\stdc++.h>
class Student{
    public:
int rollNumber;
private:
int age;//private hai magar wo class ke andear functions se acess ho sakta hai
public:
void display(){
    //yahan pr age ko change krne wala password bhi lga sakta hu
    printf("%d,%d",age,rollNumber);
}

};
//getter ka matb hai k koi data type private hai
//amagar wo class k andar ek public function me call hua so wo private hone k baad bhi coz function public tha call hi gya class k bahar bhi
int main(){
    
    return 0;
}