#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Time complexity: O(n+e)O(n + e)O(n+e).

// The complexity would be similar to the standard BFS algorithm since we’re iterating at most twice over each node.
// Each queue operation in the BFS algorithm takes O(1)O(1)O(1) time, and a single node can only be pushed onto the queue twice, leading to O(n)O(n)O(n) operations for nnn nodes. We iterate over all the neighbors of each node that is popped out of the queue, so for an undirected edge, a given edge could be iterated at most twice, resulting in O(e)O(e)O(e) operations total for all the nodes. As a result, the total time required is O(n+e)O(n + e)O(n+e).
// Space complexity: O(n+e)O(n + e)O(n+e).

// Building the adjacency list takes O(e)O(e)O(e) space.
// The BFS queue takes O(n)O(n)O(n) because each vertex is added at most twice in the form of triplet of integers.
// The other visit and answers arrays take O(n)O(n)O(n) space.

vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    vector<vector<pair<int, int>>> adj(n);

    for (auto &redEdge : redEdges)
    {
        adj[redEdge[0]].push_back({redEdge[1], 0});
    }

    for (auto &blueEdge : blueEdges)
    {
        adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
    }

    vector<int> ans(n, -1);
    queue<vector<int>> q;
    vector<vector<bool>> visit(n, vector<bool>(2));
    visit[0][0] = true, visit[0][1] = true;

    ans[0] = 0;
    q.push({0, 0, -1});

    while (!q.empty())
    {
        auto element = q.front();

        int node = element[0], steps = element[1], prevColour = element[2];
        q.pop();

        for (auto &elem : adj[node])
        {
            int neighbour = elem.first;
            int colour = elem.second;

            if (!visit[neighbour][colour] && colour != prevColour)
            {
                visit[neighbour][colour] = true;
                q.push({neighbour, steps + 1, colour});

                if (ans[neighbour] == -1)
                    ans[neighbour] = steps + 1;
            }
        }
    }
    return ans;
}

int main()
{
    int n = 3;
    vector<vector<int>> redEdges = {{0, 1}};
    vector<vector<int>> blueEdges = {{2, 1}};

    vector<int> res = shortestAlternatingPaths(n, redEdges, blueEdges);

    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}