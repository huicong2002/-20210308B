#_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[100010];

void Find(int arr[], int x, int n)
{
    int min = 0, max = n - 1, mid = (min + max) / 2;
    if (x<arr[min] || x>arr[max])
    {
        printf("NO\n");
        return;
    }
    while (min < max)
    {
        mid = (min + max) / 2;
        if (x == arr[mid])
        {
            printf("YES\n");
            return;
        }
        else if (x > arr[mid])
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    if (arr[min] == x || arr[max] == x)
    {
        printf("YES\n");
        return;
    }
    else
    {
        printf("NO\n");
        return;
    }
}
void QuickSort(int* a, int low, int high)
{
    int i = low;
    int j = high;
    int key = a[low];
    int temp;
    if (low >= high)
    {
        return;
    }
    while (low < high)
    {
        while (low < high && key <= a[high])
        {
            --high;
        }
        if (key > a[high])
        {
            temp = a[high];
            a[high] = a[low];
            a[low] = temp;
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low;
        }
        if (key < a[low])
        {
            temp = a[high];
            a[high] = a[low];
            a[low] = temp;
            --high;
        }
    }
    QuickSort(a, i, low - 1);
    QuickSort(a, low + 1, j);
}
int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    int i, j, x, temp;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 0, n - 1);

    for (i = 0; i < m; i++)
    {
        scanf("%d", &x);

        Find(arr, x, n);
    }

    return 0;
}