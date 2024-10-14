#include <iostream>
#include <vector>

using namespace std;

void swap(int arr[], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

// perform cycle sort as question coz its 0 to n
// time: O(n), space: O(1)
int MissingNo(int arr[], int n)
{
    // first sorting
    int i = 0;
    while (i < n)
    {
        int correct = arr[i];
        if (arr[i] < n && arr[i] != arr[correct])
        {
            swap(arr, i, correct);
        }

        else
        {
            i++;
        }
    }

    // sorting done, searching starts
    for (int index = 0; index < n; index++)
    {
        if (arr[index] != index)
        {
            return index;
        }
    }
    return n;
}

int main()
{
    int arr[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << MissingNo(arr, 9) << endl;

    return 0;
}