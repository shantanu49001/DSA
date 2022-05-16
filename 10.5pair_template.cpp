#include<bits\stdc++.h>
//#include "templates.cpp"
//template <typename t,typename v>//x=t y=v
template <typename T,typename v> // just to tell cmpiler that T kuch bhi ho sakta hai
class Pair
{
    T x;
    v y;   

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(v y)
    {
        return y;
    }
};

int main(){
    Pair<int ,double>p1;
    p1.setX(100);
    p1.setY(99.1);
  //  Pair<int,int> p1;
   // p1.setX(10);
    
    //Pair<double,int> p2;
    //p2.setY(20);
    return 0;
}