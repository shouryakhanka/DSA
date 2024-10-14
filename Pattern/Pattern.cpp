#include <iostream>
#include <cmath>
using namespace std;

// *
// * *
// * * *
// * * * *

/* void pattern2()
{
    for (int row = 1; row <= 5; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int row = 1; row <= 4; row++)
    {
        for (int col = 1; col <= 4 - row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
*/

void pattern21(int n)
{
    for (int row = 1; row <= 2 * n - 1; row++)
    {
        int totalColsInRow = row > n ? 2 * n - row : row;
        for (int col = 1; col <= totalColsInRow; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int row = 1; row <= 2 * n - 1; row++)
    {
        int totalColsInRow = row > n ? 2 * n - row : row;
        int spaces = n - totalColsInRow;

        for (int s = 1; s <= spaces; s++)
        {
            cout << " ";
        }

        for (int col = 1; col <= totalColsInRow; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern1(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern3(int n)
{
    for (int row = 1; row <= 2 * n - 1; row++)
    {
        int totalColsInRow = row > n ? 2 * n - row : row;

        int spaces = n - totalColsInRow;

        for (int s = 1; s <= spaces; s++)
        {
            cout << "  ";
        }

        for (int col = totalColsInRow; col >= 1; col--)
        {
            cout << col << " ";
        }

        for (int col = 2; col <= totalColsInRow; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}

void pattern17(int n)
{
    for (int row = 1; row <= 2 * n - 1; row++)
    {
        int spaces = n - row;

        for (int s = 1; s <= spaces; s++)
        {
            cout << "  ";
        }

        for (int col = row; col >= 1; col++)
        {
            cout << col << " ";
        }

        for (int col = 2; col <= row; col++)
        {
            cout << col << " ";
        }
    }
}

/*void pattern3(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
*/

void pattern4(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}

void pattern31(int n)
{
    int originalN = n;
    n = 2 * n;
    for (int row = 0; row <= n; row++)
    {
        for (int col = 0; col <= n; col++)
        {
            int valueAtEveryIndex = originalN - min(min(row, col), min(n - row, n - col));

            cout << valueAtEveryIndex << " ";
        }
        cout << endl;
    }
}

// pattern with recursion

void RPattern1(int row, int col)
{
    if (row == 0)
        return;

    if (col < row)
    {
        cout << "* ";
        RPattern1(row, col + 1);
    }

    else
    {
        cout << endl;
        RPattern1(row - 1, 0);
    }
}

// int *bubbleSort(int arr[], int r, int c)
// {
//     if (r == 0)
//         return;

//     if (c < r)
//     {
//         // swap
//         if (arr[c] > arr[c + 1])
//         {
//             int temp = arr[c];
//             arr[c] = arr[c + 1];
//             arr[c + 1] = temp;
//         }
//         bubbleSort(arr, r, c + 1);
//     }

//     else
//     {
//         bubbleSort(arr, r - 1, 0);
//     }
// }

void RPattern2(int row, int col)
{
    if (row == 0)
        return;

    if (col < row)
    {
        RPattern2(row, col + 1);
        cout << "* ";
    }

    else
    {
        RPattern2(row - 1, 0);
        cout << endl;
    }
}

void selectionSort(int arr[], int r, int c, int max)
{
    if (r == 0)
        return;

    if (c < r)
    {
        if (arr[c] > arr[max])
        {
            selectionSort(arr, r, c + 1, c);
        }
        else
        {
            selectionSort(arr, r, c + 1, max);
        }
    }

    else
    {
        int temp = arr[r - 1];
        arr[r - 1] = arr[max];
        arr[max] = temp;
        selectionSort(arr, r - 1, 0, 0);
    }
}
int main()
{
    int arr[] = {1, 3, -5, 0, 7, 9};

    selectionSort(arr, 4, 0, 0);

    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
};