#include <iostream>
using namespace std;
int main()
{
    int i = 65;
    char c = i;//impicit type casting
    cout << c << "\t";
    int *p1 = &i; //pointer1 is pointing to a int value
    //    char *p2=p1;//char pointing to a int pointer
    //here it is not allowed a char pointer is not allowed to point to a int pointer
   char *p2=(char *)p1;//explicit typ casting
   //isse p2 point karega char value wrt int val at p1 =>p1 me int hoga wo sirf p2 me type cast hoga =>
    
    return 0;
}
//stat from pass by val/reference