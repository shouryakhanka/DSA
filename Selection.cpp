#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// selection sort performs min no. of swaps i.e. O(n)
// intermediate result of selection sort is useful, k passes gives k smallest elements
void selectionSort(int arr[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(&arr[i], &arr[k]);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 3, 4, 5};
    int n = 6;
    selectionSort(arr, n);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}