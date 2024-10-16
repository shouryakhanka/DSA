#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// OJ: https://leetcode.com/contest/weekly-contest-240/problems/largest-color-value-in-a-directed-graph/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution
{
    typedef array<int, 26> T;

public:
    int largestPathValue(string C, vector<vector<int>> &E)
    {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(C.size());
        for (auto &e : E)
        {
            G[e[0]].push_back(e[1]); // build graph
            indegree[e[1]]++;        // count indegrees
        }
        vector<T> cnt(C.size(), T{}); // cnt[i][j] is the maximum count of j-th color from the ancester nodes to node i.
        queue<int> q;
        for (int i = 0; i < C.size(); ++i)
        {
            if (indegree[i] == 0)
            { // if this node has 0 indegree, we can use it as a source node
                q.push(i);
                cnt[i][C[i] - 'a'] = 1; // the count of the current color should be 1
            }
        }
        int ans = 0, seen = 0;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            int val = *max_element(begin(cnt[u]), end(cnt[u])); // we use the maximum of all the maximum color counts as the color value.
            ans = max(ans, val);
            ++seen;
            for (int v : G[u])
            {
                for (int i = 0; i < 26; ++i)
                {
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (i == C[v] - 'a')); // try to use node `u` to update all the color counts of node `v`.
                }
                if (--indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return seen < C.size() ? -1 : ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> E = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    string colours = "abaca";
    cout << s.largestPathValue(colours, E) << endl;
    return 0;
}