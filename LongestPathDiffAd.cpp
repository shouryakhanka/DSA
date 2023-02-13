// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/

#include <iostream>
using namespace std;

int longestPath(vector<int> &parent, string s)
{
    int n = parent.size();
    vector<vector<int>> adj;

    for (int i = 1; i < n; i++)
    {
        adj.push_back(parent[i]);
    }
}

int main()
{
    return 0;
}