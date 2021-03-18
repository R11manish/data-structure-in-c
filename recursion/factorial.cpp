#include <stdio.h>
int recursiveFactorial(int n)
{
    if (n == 0)
        return 1;
    return recursiveFactorial(n - 1) * n;
}

int iterativeFactorial(int n)
{
    int s = 1;
    for (int i = 1; i <= n; i++)
    {
        s = s * i;
    }
    return s;
}
int main()
{
    int r;
    r = recursiveFactorial(0);
    printf("%d", r);
    r = iterativeFactorial(1);
    printf(" %d ", r);
    return 0;
}