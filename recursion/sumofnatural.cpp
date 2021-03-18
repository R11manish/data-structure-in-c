#include <stdio.h>
int sumOfNatural(int n)
{
    if (n == 0)
        return 0;
    return sumOfNatural(n - 1) + n;
}

int linearSum(int n)
{
    int s = 0;
    s = n * (n + 1) / 2;
    return s;
}

int iterativeSum(int n)
{
    int s = 0;
    for (int i = 0; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}

int main()
{
    int r;
    r = sumOfNatural(5);
    printf("%d", r);
    r = linearSum(5);
    printf(" %d ", r);
    r = iterativeSum(5);
    printf(" %d ", r);
    return 0;
}