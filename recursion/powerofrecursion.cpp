#include <stdio.h>
int powerRecursion(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        return powerRecursion(m * m, n / 2);
    }
    else
        return m * powerRecursion(m * m, (n - 1) / 2);
}

int powerRecursion2(int m, int n)
{
    if (n == 0)
        return 1;
    return powerRecursion2(m, n - 1) * m;
}

int main()
{
    int r;
    r = powerRecursion(3, 3);
    printf(" %d ", r);
    r = powerRecursion2(3, 3);
    printf("%d", r);
    return 0;
}