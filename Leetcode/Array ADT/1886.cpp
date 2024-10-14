#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>> &mat, vector<vector<int>> &target)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = i; j < mat[0].size(); j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < mat.size(); i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
{
    if (mat == target)
        return true;

    for (int i = 0; i < 3; i++)
    {

        rotate(mat, target);

        if (mat == target)
            return true;
    }
    return false;
}

bool findRotation2(vector<vector<int>> &mat, vector<vector<int>> &target)
{
    int n = mat.size();
    if (mat == target)
    { // rotation by 0 degree.
        return true;
    }

    int deg = 3; // more rotations with 90, 180, 270 degree's.

    while (deg--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]); // transpose of matrix.
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end()); // reverse each row.
        }
        if (mat == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> mat = {{1, 1}, {0, 1}};
    vector<vector<int>> target = {{1, 1}, {1, 0}};

    cout << findRotation(mat, target);

    return 0;
}