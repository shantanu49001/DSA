#include<bits\stdc++.h>
//during notes time see yt for how to create polynomail class---->vry vry imp.
class Vehicle{
private:
int maxSpeed;
protected:
int numTyres;
public:
char color;
};
class Car:public Vehicle{//copy me car class ki structure bana lo
//private property nhi aayi
//protected wali protected me copy
//public wali public me copy

};
class bike:protected Vehicle{
    //protected wale protected
    //public wale protected
    //private wale acess nhi hinge
    //iske baad wahi bas isi class me focus
};
class scooter:private Vehicle{
//
};
int main(){
    return 0;
}

/**
 * Encapsulaton->data and function clubbing by classes
 * Abstraction ->hiding,process in background,inbuilt functions
 *             ->STL-:stck,queue,hashmap etc.
 *             ->private var in a class
 *             ->changes and upadtation protection
 *             ->avoid errors
 * Inheritance -> Vehicle
 *             ->car->colour,maxspeed,numgears
 *             ->bicycle->color,maxspeed,foldable
 *             ->Truck->colour,maxspeed
 * kuch common properies vehicle se specific khud se
 * reuse the code
 * OBJECT--------------------------------------------------------
 * private->too restricted--->KOI NHI
 * public->too linient-->SAB
 * protected->PROPERIES ACEESABLE ONLY BY CHILD CLASSES
 *-------------------------------------------------------------------------
 * /