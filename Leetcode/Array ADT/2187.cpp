#include <iostream>
#include <vector>

using namespace std;

long long minimumTime(vector<int> &time, int totalTrips)
{
    long long low = 0;
    long long high = 50;
    long long ans = high;

    while (low < high)
    {
        long long cnt = 0;

        long long mid = low + (high - low) / 2;

        for (int i = 0; i < time.size(); i++)
        {
            cnt += (mid / time[i]);
        }

        if (cnt >= totalTrips)
        {
            ans = min(ans, mid);
            high = mid;
        }

        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> time = {1, 2, 3};
    int totalTrips = 5;

    cout << minimumTime(time, totalTrips) << endl;
    return 0;
}