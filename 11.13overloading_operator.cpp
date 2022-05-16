#include<bits\stdc++.h>
//+ - * /-->inme ek this wala aur ek argument wala chaiye hota hai but 
//++ isme ek hi operator chahiye hota hai-->aur wo this me chala jayega
class Fraction{
    public:
//void operator++(){//overloaded operator
Fraction operator++(){//ab ye ek object return kr rha hai
//fraction&  ->then main sirf this ko return kr sakta hu
numerator=numerator+denimonator;//this ka matlb jo object iske call kr rhe wo
return *this;//-->this had addres of object calling this function *this return whole copy of object properties
}
};
int main(){
Fraction f1(10,20);
++f1;//operator functon called
    Fraction f3=++f1;//error here as function ka returntype to void hai
}
