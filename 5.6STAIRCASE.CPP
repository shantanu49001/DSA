#include <bits\stdc++.h>
// no of recursions =no of base cases required
// now here 1,2,3 are possib;e steps he cantake
// n starirs->count(n);count(n-1);count(n-2)//--->for 1 step csases=1;2 steps->2 cases ->3 steps 4 cases
// previous 3 ka sum chahiye hai baaki ke steps k liye
// base cases->jahan tak given data use ho rha ho
int countways(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }
    return countways(n - 1) + countways(n - 2) + countways(n - 3);//jitne data utna base cases me use hona chahiye;jitne base cases utne recursive calls at final end
}
int main()
{
    int steps;
    printf("Enter no of steps required\n");
    scanf("%d", &steps);
    int val = countways(steps);
    printf("Total ways are %d ", val);
    return 0;
}