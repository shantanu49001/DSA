#include<bits\stdc++.h>
//private property to class ke bahar acess nhi kar sakte
//protected->only by child
//but friend function are friend of main classes that have special acess to any data member of  class
class Bus
{
public:
    void print();//yahan bas define krna hota hai
};
void test();//yahan declare karna hota hai
class Truck{
private:
int x;
protected:
int y;
friend void Bus::print();//doosri class ka function jo ki private of truck to acess krne chahta hai
//but compiler error dega bus kya hai?
//bus ko upar dalo
friend void test();
friend class Bus;//poori class ko hi friend bana diya
};
void Bus::print(){//yahan use aro
Truck t;
t.x=10;
t.y=20;
printf("%d %d\n",t.x,t.y);
}
void test(){//ab ye ek function hai jo ki kisi class se koi nata nhi rakhta to isme kase hoga wo dekho

}
int main(){
    Bus b;
    b.print();
    return 0;
}