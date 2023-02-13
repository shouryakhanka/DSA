#include <iostream>
using namespace std;

bool isArraysorted(int A[], int index, int n)
{
    // base condition
    if (index == n - 1)
        return true;

    return A[index] < A[index + 1] && isArraysorted(A, index + 1, n);
}

int main()
{
    int A[] = {1, 2, 4, 5, 6, 8, 9};

    int n = sizeof(A) / sizeof(A[0]);

    cout << isArraysorted(A, 0, n) << endl;

    return 0;
}