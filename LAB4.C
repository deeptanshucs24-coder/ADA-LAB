#include <stdio.h>
#include <time.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(1)
    {
        while(i <= high && arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;

    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Elements:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    printf("\nExecution Time = %lf seconds\n",
           time_taken);

    return 0;
}
