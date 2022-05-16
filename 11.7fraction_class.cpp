//similarly we can find complex classes  
#include<bits\stdc++.h>
//wo work upon  12/5
//two data member req nr dr
class Fraction{
 private:
 int numerator;
 int denominator;
 public:
 Fraction(int numerator,int denominator){
     this->numerator=numerator;//jisse object jo hai usi k value me change ho sirf is function k liye nhi
     this->denominator=denominator;

 }
 void print(){//f1.print--->this me is object ka current addresa aa jata hai
 printf("%d/%d\n",this->numerator,this->denominator);
  //by defaut jab koi obj function ko call krta hai this me uska ddress aa jata hai
  //hence agar sirf ye likha hai denominator-->wo apne aap samaj jayega k f1 k baat ho rhi hai
  }
  void add(Fraction f2){
  int lcm=denominator* f2.denominator;
  int x=lcm/denominator;//jahan jahan nhi likha ksiks wo uska hai isko object leke function ko call kara tha.
  int y=lcm/f2.denominator;
  int num=x*numerator+(y*f2.numerator);
  numerator=num;
  denominator=lcm;
  }
  Fraction operator*(Fraction f1){//operator overloading
  int n=numerator*f1.numerator;
  int d=denominator*f1.denominator;
  Fraction (n,d);
  }
  Fraction operator+(Fraction f2){//argment and return type both RE Object
   
  }
  bool operator==(Fraction f2){//f1 this me f2 argument me
  return(numerator==f2.numerator&&denominator==f2.denominator);
  }
};

int main(){
    
    Fraction f1(4,5);//-->//f1 ka num and denr set ho jayega by this
    Fraction f2(3,7);//-->same
    //we are tring to store f1=f1+f2;
     f1.add(f2);
     f1.print();
     f2.print();
     Fraction f5=f1*f2;//ye multiply wala fuctin call hogya operator overload wala
     if(f1==f2){//ye equal wala call ho gya

     }
    return 0;
}