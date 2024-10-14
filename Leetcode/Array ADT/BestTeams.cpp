// https://leetcode.com/problems/best-team-with-no-conflicts/description/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    vector<vector<int>> v;
    int n = scores.size();
    for (int i = 0; i < n; i++)
    {
        v.push_back({-ages[i], -scores[i]});
    }
    sort(v.begin(), v.end());

    int dp[n];
    int ans = 0;

    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (-v[i][1] <= -v[j][1])
            {
                dp[i] = max(dp[i], dp[j] - v[i][1]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    vector<int> scores = {1, 3, 5, 10, 15};
    vector<int> ages = {1, 2, 3, 4, 5};

    cout << bestTeamScore(scores, ages) << endl;
    return 0;
}