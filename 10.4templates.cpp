//when we don't know the data type
//our function must run for all int /float/char/,....
/*class Pair{
int x;
int y;
public:
void setX(int x){
    this->x=x;
}
};
*/
//T x ;T y
 
 template <typename T>//just to tell cmpiler that T kuch bhi ho sakta hai
 class Pair{
     T x;
     T y;
     public:
     void setX(T x){
         this->x=x;
     }
     T getX(){
         return x;
     }
     void setY(T y){
         return y;
     }
 };
