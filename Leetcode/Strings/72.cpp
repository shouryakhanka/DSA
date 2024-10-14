#include <iostream>

using namespace std;

// amazon, microsoft, linkedin, bloomberg
class Solution
{
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i == word1.length())
            return word2.length() - j;

        if (j == word2.length())
            return word1.length() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if (word1[i] == word2[j])
            ans = solve(word1, word2, i + 1, j + 1, dp);

        else
        {
            // insert op
            int insertAns = 1 + solve(word1, word2, i, j + 1, dp);

            // delete op
            int deleteAns = 1 + solve(word1, word2, i + 1, j, dp);

            // replace op
            int replaceAns = 1 + solve(word1, word2, i + 1, j + 1, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2)
    {
        // using recursion

        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
t

    int
    main()
{
    EditDistance edit;

    string word1 = "horse";
    string word2 = "ros";
    cout << edit.minDistance(word1, word2) << endl;
}