#include <iostream>
#include <vector>

using namespace std;

vector<int> direction = {0, -1, 0, 1, 0};

void DFS(vector<vector<int>> grid, int row, int col)
{
    grid[row][col] = -1;

    for (int d = 0; d < 4; d++)
    {
        int r = row + direction[d];
        int c = col + direction[d + 1];

        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 0)
            DFS(grid, r, c);
    }
}

int closedIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    if (m == 0)
        return 0;
    int n = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == 0)
            DFS(grid, 0, i);
        if (grid[m - 1][i] == 0)
            DFS(grid, m - 1, i);
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[i][0] == 0)
            DFS(grid, i, 0);
        if (grid[i][n - 1] == 0)
            DFS(grid, i, n - 1);
    }

    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == -1 || grid[i][j] == 1)
                continue;
            result++;
            DFS(grid, i, j);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 1, 0}};

    cout << closedIsland(grid) << endl;
    return 0;
}