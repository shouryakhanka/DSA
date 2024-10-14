#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colors(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (colors[i])
                continue;

            colors[i] = 1;
            q.push(i);

            while (!q.empty())
            {
                int temp = q.front();

                for (auto neighbor : graph[temp])
                {

                    // Color neighbor with opposite color
                    if (!colors[neighbor])
                    {
                        colors[neighbor] = -colors[temp];
                        q.push(neighbor);
                    }

                    // If the neighbor has the same color - can't bipartite.
                    else if (colors[neighbor] == colors[temp])
                        return false;
                }
                q.pop();
            }
        }
        return true;
    }

    bool isBipartite2(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colours(n);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            // colours[0] = 1;
            if (!colours[i])
            {
                // checkBipartite(i, graph, colours, q);
                colours[i] = 1;
                q.push(i);

                while (!q.empty())
                {
                    int temp = q.front();

                    for (int neighbour : graph[temp])
                    {
                        // check if the neighbour is not coloured
                        if (!colours[neighbour])
                        {
                            colours[neighbour] = -colours[temp];
                            q.push(neighbour);
                        }

                        // check if neighbour colour is equal to temp node's colour
                        else if (colours[neighbour] == colours[temp])
                        {
                            return false;
                        }
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << sol.isBipartite(graph);
    return 0;
}