#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3};
    char b[] = "abc";
    cout << a;       //ye to first element ka address deta hai but
    cout << b;       //ye poora array print karta hai
    char *c = &b[0]; //char pointer expectation hai k address but ye bhi poora aay print karta hai
    char c1 = 'a';
    char *pc = &c1;
    cout << pc; //ye bhi a ko print krta hai/
    //char *pstr="abcd"--->isko temprory box me daal dete hai aur pstr us box ko point karta jai
    //char str[]="abcd"-->ab ye ek array me stroe hot hai
    return 0;
}
/*
char s[]="hello";
char *p=s;
cout <<s[0]<<p[0]====>s[0] h print -->coz ye array ko stor kata hai
p[0]-->poora aayr coz wo box ko point karta hai



*/