#include <iostream>
using namespace std;

int floor(int arr[], int target, int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (target > arr[mid])
            start = mid + 1;

        else if (target < arr[mid])
        {
            end = mid - 1;
        }

        else
        {
            return mid;
        }
    }
    return end;
}

int main()
{
    int arr[] = {2, 3, 5, 9, 14, 16, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << floor(arr, 1, n) << endl;
    return 0;
}