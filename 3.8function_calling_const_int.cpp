#include<bits\stdc++.h>
void g(int const &a){//ye allowed hai coz this function gurantess value constan rahegi
a++;
}
void f(int *p){//not lllowed it might cange value of const
    *p++;
}
int main(){
    int const i=20;
    int const *p=&i;//p is a pointer to constant integer
  f(p);
  g(p);
    return 0;
}