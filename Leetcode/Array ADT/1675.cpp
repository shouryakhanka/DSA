#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int minimumDeviation(vector<int> &nums)
{
    int res = INT_MAX, min_n = INT_MAX;
    priority_queue<int> pq;
    for (auto n : nums)
    {
        n = n % 2 ? n * 2 : n;
        pq.push(n);
        min_n = min(min_n, n);
    }
    while (pq.top() % 2 == 0)
    {
        res = min(res, pq.top() - min_n);
        min_n = min(min_n, pq.top() / 2);
        pq.push(pq.top() / 2);
        pq.pop();
    }
    return min(res, pq.top() - min_n);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << minimumDeviation(nums) << endl;

    return 0;
}