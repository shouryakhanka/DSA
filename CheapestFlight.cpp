#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto &e : flights)
    {
        adj[e[0]].push_back({e[1], e[2]});

        vector<int> dist(n, numeric_limits<int>::max());

        int stops = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});

        while (stops <= k && !q.empty())
        {
            int sz = q.size();

            // iterate on the current level
            while (sz--)
            {
                auto [node, distance] = q.front();
                q.pop();
            }

            int main()
            {
                return 0;
            }