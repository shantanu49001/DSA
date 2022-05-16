#include<bits\stdc++.h>
#include "10.5pair_template.cpp"
//pari <int,int>p1;
//  x   y
// int  int --->this is the structure created for p1 object
//    p1      
//now here(s,d,t) ther can be a template also that can be taken as input


int main(){
   //Pair <Pair<int,int>,int> p1---->making a 3 var template by 2 var template 
    //  x    y
    // a,b  int  c
    //    p1
    //p2.setY(10)
    //p2.setX(p4)       pair<int ,int> p4
                      //p4.setX(15)
                    //p4.setY(10)
//p2.getY
//p2.getX().getX()--->pair ki bhi x val chahiye thi                    
Pair<Pair<int, int>, int> p2;
p2.setY(10);
Pair<int,int> p4;
p4.setX(5);
p4.setY(16);
p2.setX(p4);
printf("%d",p2.getX().getX());//coz x ek templte tha jo ki ek template me input hai to uske x ka x 
/*
   p2
 x(5)   y(16)     y(10) 

  p4
 5  ,16 
*/
return 0;
}