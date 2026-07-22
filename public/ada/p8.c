#include <stdio.h>
#include <stdlib.h>

int *s, *x;
int n, d;

void sumOfSub(int sum, int k, int remaining)
{
    if (k > n)
        return;

    x[k] = 1;

    if (sum + s[k] == d)
    {
        for (int i = 1; i <= k; i++)
        {
            if (x[i])
                printf("%d ", s[i]);
        }
        printf("\n");
    }
    else if (k < n && sum + s[k] + s[k + 1] <= d)
    {
        sumOfSub(sum + s[k], k + 1, remaining - s[k]);
    }

    if (k < n && (sum + remaining - s[k] >= d) && (sum + s[k + 1] <= d))
    {
        x[k] = 0;
        sumOfSub(sum, k + 1, remaining - s[k]);
    }
}

int main()
{
    int total = 0;

    printf("Enter the n value: ");
    scanf("%d", &n);

    s = (int *)malloc((n + 1) * sizeof(int));
    x = (int *)calloc(n + 1, sizeof(int));

    printf("Enter the set in increasing order: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
        total += s[i];
    }

    printf("Enter the max subset value: ");
    scanf("%d", &d);

    if (total < d || s[1] > d)
    {
        printf("No subset possible\n");
    }
    else
    {
        sumOfSub(0, 1, total);
    }

    free(s);
    free(x);

    return 0;
}