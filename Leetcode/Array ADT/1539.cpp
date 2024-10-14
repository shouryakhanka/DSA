#include <iostream>
#include <vector>
#include <set>

using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    set<int> s(arr.begin(), arr.end());
    int i = 1;
    while (k > 0)
    {
        if (!s.count(i))
        {
            k--;
        }
        if (k == 0)
        {
            return i;
        }
        i++;
    }
    return -1; // This line should never be reached
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << findKthPositive(arr, k) << endl;
    return 0;
}