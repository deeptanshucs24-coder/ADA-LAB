#include <stdio.h>
#include <stdlib.h>

int x[20];
int count = 0;

int place(int k, int i)
{
    for(int j = 1; j < k; j++)
    {
        if((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }
    return 1;
}

void nQueens(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                count++;

                printf("\nSolution %d:\n", count);

                for(int r = 1; r <= n; r++)
                {
                    for(int c = 1; c <= n; c++)
                    {
                        if(x[r] == c)
                            printf(" Q ");
                        else
                            printf(" . ");
                    }
                    printf("\n");
                }
            }
            else
            {
                nQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    nQueens(1, n);

    if(count == 0)
        printf("\nNo solution exists.\n");
    else
        printf("\nTotal Solutions = %d\n", count);

    return 0;
}
