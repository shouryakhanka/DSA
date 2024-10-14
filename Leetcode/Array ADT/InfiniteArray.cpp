#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int start, int end)
{
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
    return -1;
}

int ans(int arr[], int target)
{
    // first find the range
    // start with a box of size 2
    int start = 0;
    int end = 1;

    while (target > arr[end])
    {
        int temp = end + 1;
        // double the box size

        end = end + (end - start + 1) * 2;
        start = temp;
    }
    return binarySearch(arr, target, start, end);
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int target = 5;

    cout << ans(arr, target) << endl;
    return 0;
}