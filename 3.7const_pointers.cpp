#include <bits\stdc++.h>
int main()
{
    int const i = 10;
    //  int *p=&i;--->this is not allowed as pointer must promise that it will not ry to chnge value of const integer
    int const *p = &i; //-->ths is allowed
    //p is a pointer to constant integer
    return 0;
}