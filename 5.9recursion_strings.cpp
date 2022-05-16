#include <bits\stdc++.h>
// input->abxzxc
// output->abzc
int removeChar(char a[], int index)
{
    if (a[index] != '\0')
    {
        if (a[index] != 'x')
        {
            printf("%c", a[index]);
            removeChar(a, index + 1);
        }
        else if (a[index] == 'x')
        {
            removeChar(a, index + 1);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    char string[] = {"abxzxc"};
    int i = 0;
    removeChar(string, i);

    return 0;
}