#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Insertion(int A[], int n)
{
    int i, j, x, n1 = 0;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            n1++;

            j--;
        }
        A[j + 1] = x;
    }
    printf("n%d", n1);
}

int main()
{
    int A[] = {5, 2, 7, 3, 4};
    int n = 5, i;

    Insertion(A, n);

    for (i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
