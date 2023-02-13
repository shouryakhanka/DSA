#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time: O(nlogn) and space: O(n)
// simply consider the partitions and take the sum, sort and then subs.
long long putMarbles(vector<int> &weights, int k)
{
    if (k == 1)
        return 0;
    vector<long long> ans;
    for (int i = 1; i < weights.size(); i++)

        ans.push_back(weights[i - 1] + weights[i]);
    sort(ans.begin(), ans.end());
    long long l = 0, r = 0;
    for (int i = 0; i + 1 < k; i++)
        l += ans[i], r += ans[ans.size() - 1 - i];
    return (r - l);
}

int main()
{
    vector<int> weights = {1, 3, 5, 1};
    int k = 2;
    cout << putMarbles(weights, k) << endl;
    return 0;
}