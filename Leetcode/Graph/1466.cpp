#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &al, vector<bool> &visited, int from)
{
    auto change = 0;
    visited[from] = true;
    for (auto to : al[from])
        if (!visited[abs(to)])
            change += dfs(al, visited, abs(to)) + (to > 0);
    return change;
}
int minReorder(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> al(n);
    for (auto &c : connections)
    {
        al[c[0]].push_back(c[1]);
        al[c[1]].push_back(-c[0]);
    }
    int ans = dfs(al, vector<bool>(n) = {}, 0);
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};

    cout << minReorder(n, connections) << endl;

    return 0;
}