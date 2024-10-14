#include <iostream>
using namespace std;

struct Array
{
    int A[9];
    int size;
    int length;
};

void Display(Array arr)
{
    cout << "The elements are:" << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

int deleteArray(Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index];

        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{

    int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid - 1, key);
        else
            return RBinSearch(a, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    cout << RBinSearch(arr.A, 0, 8, 2) << endl;
    Display(arr);
    return 0;
}