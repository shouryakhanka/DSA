#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];
        sum += mat[n - 1 - i][i];
    }

    return n % 2 == 0 ? sum : sum - mat[n / 2][n / 2];
}

int diagonalSum2(vector<vector<int>> &mat)
{
    int sum = 0;
    for (int i = 0; 2 * i < mat.size(); i++)
    {                                                                                                                             // IMPROVEMENT IS THAT WE ONLY DO HALF ROW IN THE FOR LOOP
        sum += mat[i][i] + mat[mat.size() - i - 1][mat.size() - i - 1] + mat[i][mat.size() - i - 1] + mat[mat.size() - i - 1][i]; // COUNT INTO OTHER CORRESPONDING THREE ELEMENT
    }

    return mat.size() % 2 == 1 ? sum -= mat[mat.size() / 2][mat.size() / 2] * 3 : sum;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    cout << diagonalSum2(mat);
    return 0;
}