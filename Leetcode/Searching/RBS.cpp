#include <iostream>
using namespace std;

bool Rbs(int arr[], int target, int start, int end)
{
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return true;

    if (arr[start] <= arr[mid])
    {
        if (target >= arr[start] && target <= arr[mid])
        {
            return Rbs(arr, target, 0, mid - 1);
        }
        else
        {
            return Rbs(arr, target, mid + 1, end);
        }
    }

    // now the other half of the array

    if (target >= arr[mid] && target <= arr[end])
    {
        return Rbs(arr, target, mid + 1, end);
    }

    else
    {
        return Rbs(arr, target, start, mid - 1);
    }
}

int main()
{
    int arr[] = {4,5,6,7,0,1,2};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << Rbs(arr, 0, 0, n - 1) << endl;
    return 0;
}