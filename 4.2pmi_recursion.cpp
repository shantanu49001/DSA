/*pmi
 * F(o)-->true prove
 * assume F(k)-->to be true
 * using the fact that F(k) is true prove F(k+1)-->true
 * recurson is just pmi
 * base case ka true leke n ke liye statement solve krni hai for next n
 *
 * */
#include <bits\stdc++.h>
int power(int a, int b)
{
    while (b>1)
    {
        return a * power(a, b - 1);
    }
}
int main()
{
    int base, p;
    printf("Enter the number\n");
    scanf("%d", &base);
    printf("Enter the power\n");
    scanf("%d", &p);
    int val = power(base, p);
    printf("Value is %d \n", val);
    return 0;
}