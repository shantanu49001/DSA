#include <bits\stdc++.h>
int SumofDigits(int n, int s)
{
    while (n != 0)
    {
        return s + n % 10 + SumofDigits(n / 10, s);
    }
}
int main()
{
    int num;
    printf("Enter the no\n");
    scanf("%d",&num);
    int sum = 0;
    int value = SumofDigits(num, sum);
    printf("%d", value);
    return 0;
}