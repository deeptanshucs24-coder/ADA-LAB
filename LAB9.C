#include <stdio.h>

struct Item
{
    float weight;
    float profit;
    float ratio;
};

int main()
{
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%f %f", &item[i].profit, &item[i].weight);
        item[i].ratio = item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    float maxProfit = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(capacity >= item[i].weight)
        {
            capacity -= item[i].weight;
            maxProfit += item[i].profit;
        }
        else
        {
            maxProfit += item[i].profit *
                        (capacity / item[i].weight);
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", maxProfit);

    return 0;
}
