#include <iostream>
#include <queue>
using namespace std;

vector<int> findCoordinates(int curr, int n)
{
    int r = n - (curr - 1) / n - 1;
    int c = (curr - 1) % n;
    if (r % 2 == n % 2)
    {
        return {r, n - 1 - c};
    }
    else
    {
        return {r, c};
    }
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    int steps = 0;
    queue<int> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push(1);
    visited[n - 1][0] = true;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x = q.front();
            q.pop();
            if (x == n * n)
                return steps;
            for (int k = 1; k <= 6; k++)
            {
                if (k + x > n * n)
                    break;
                vector<int> pos = findCoordinates(k + x, n);
                int r = pos[0];
                int c = pos[1];
                if (visited[r][c] == true)
                    continue;
                visited[r][c] = true;
                if (board[r][c] == -1)
                {
                    q.push(k + x);
                }
                else
                {
                    q.push(board[r][c]);
                }
            }
        }
        steps++;
    }
    return -1;
}

int main()
{
    vector<vector<int>> board = {{-1, -1}, {-1, 3}};
    cout << snakesAndLadders(board) << endl;
    return 0;
}