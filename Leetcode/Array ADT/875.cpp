#include <iostream>
using namespace std;

// return min integer, constraints like complete within this many hours
// try binary search in this case

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = 1000000000;
    int mid = 0;

    while (low <= high)
    {
        int cnt = 0;
        mid = low + (high - low) / 2;

        for (int i = 0; i < piles.size(); i++)
        {
            cnt += piles[i] / mid;
            if (piles[i] % mid != 0)
                cnt++;
        }

        if (cnt <= h)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    return 0;
}