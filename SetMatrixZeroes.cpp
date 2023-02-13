#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> setZeroes1(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    vector<int> xr;
    vector<int> yr;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                xr.push_back(i);
                yr.push_back(j);
            }
        }
    }

    for (auto row : xr)
    {
        for (int col = 0; col < n; col++)
        {
            arr[row][col] = 0;
        }
    }

    for (auto col : yr)
    {
        for (int row = 0; row < m; row++)
        {
            arr[row][col] = 0;
        }
    }
    return arr;
}

// solution with O(M x N) time complexity and O(1) space

vector<vector<int>> setZeroes1(vector<vector<int>> &arr)
{
    bool isCol = false;

    int r = arr.size();
    int c = arr[0].size();

    for (int i = 0; i < r; i++)
    {
        /* code */
    }

    int main()
    {
        return 0;
    }