#include<bits\stdc++.h>
inline int max(int a,int b){//ye functon comile se pehle saari jagah copy kr diya jata hai
    return a>b?a:b;
}
int main(){
    int a,b;
  // int c=a>b?----:------;  
  //why wo we arite this agai na nd again?
  //alternate 1->function ban do bt then again usme bhi purana function pause hota hai aur argument copy hota hai
   int c=max(a,b);
    return 0;
    //inline smaller function pr chalta hai
}