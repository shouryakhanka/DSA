#include <iostream>
#include <vector>

using namespace std;

// linear search for multiple occurence of a number
vector<int> arr;

vector<int> linearSearch(int A[], int index, int target, int end)
{

    while (index < end)
    {
        if (A[index] == target)
            arr.push_back(index);

        return linearSearch(A, index + 1, target, end);
    }
    return arr;
}

// linear search in case of strings

bool linearSearch(string st, char ch)
{
    if (st.size() == 0)
        return false;

    for (int i = 0; i < st.size(); i++)
    {
        if (ch == st[i])
            return true;
    }
    return false;
}

int minNo(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            min = arr[i];
    }
    return min;
}

// search in 2d arrays

vector<int> search2D(int arr[][3], int target, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (target == arr[i][j])
                return {i, j};
        }
    }
    return {-1, -1};
}

int MaxIn2D(int arr[][3], int r, int c)
{
    int max = INT8_MIN;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}

int main()
{
    int arr[3][3] = {{-1, 0, 3}, {12, 5, 6}, {7, 8, 9}};

    int r = sizeof(arr) / sizeof(arr[0]);

    int c = sizeof(arr[0]) / sizeof(arr[0][0]);

    cout << MaxIn2D(arr, r, c) << endl;
    // vector<int> ans = search2D(arr, 6, r, c);

    // for (int i : ans)
    // {
    //     cout << i << " ";
    // }

    // cout << minNo()
    //             cout
    //      << linearSearch("shourya", 'c') << endl;
    // int A[] = {8, 5, 5, 5, 8, 2, 2};

    // int n = sizeof(A) / sizeof(A[0]);

    // vector<int> arr = linearSearch(A, 0, 8, n);

    // for (int i : arr)
    // {
    //     cout << i << " ";
    // }

    return 0;
}