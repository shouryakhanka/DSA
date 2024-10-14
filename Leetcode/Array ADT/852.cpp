#include <iostream>
#include <vector>
using namespace std;

class MountainArray
{
public:
    // The mountain increases until it doesn't. The point at which it stops increasing is the peak.
    // time: O(n) && space: O(1)
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int i = 0;
        while (arr[i] < arr[i + 1])
        {
            i++;
        }
        return i;
    }

    // using the binary search apporach
    int peakIndexInMountainArray2(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid + 1])
                end = mid;

            if (arr[mid] < arr[mid + 1])
                start = mid + 1;
        }
        return start;
    }
};

int main()
{
    MountainArray peak;
    vector<int> arr = {1, 2};
    cout << peak.peakIndexInMountainArray(arr) << endl;

    return 0;
}