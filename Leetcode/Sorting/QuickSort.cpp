#include <iostream>
#include <vector>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(vector<int> nums, int l, int h)
{
    int pivot = nums[l];
    int i = l;
    int j = h;

    do
    {
        do
        {
            i++;
        } while (nums[i] <= pivot);

        do
        {
            j--;
        } while (nums[j] > pivot);

        if (i < j)
            swap(&nums[i], &nums[j]);
    } while (i < j);

    swap(&nums[l], &nums[j]);

    return j;
}

void QuickSort(vector<int> nums, int l, int h)
{
    if (l < h)
    {
        int j = partition(nums, l, h);

        QuickSort(nums, l, j);
        QuickSort(nums, j + 1, h);
    }
}

int main()
{
    vector<int> nums = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    QuickSort(nums, 0, 10);
    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}