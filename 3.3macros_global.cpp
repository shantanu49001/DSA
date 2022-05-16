#include<bits\stdc++.h>
#define pi 3.14//ye compile se pehle pi k jagah 3.14 put krdega
int a=5;//--->this is a global var;it can be use dby anu function
//any function can change the value globally for all other functins as well
int main(){
    //if wewant to use 3.14 ;now if we have used it multiple times and then if we want to change it we will have to do at every place
//if we use a var then if it is changed in between then our code will be affected 
//mutiple def+any change or even reduce multiple var space-->prevented by define
int r=1;
int ar=pi*r*r;
printf("%f",ar);
//main ke andar defined var global nhi hote
}
//global var-->most devastating concept