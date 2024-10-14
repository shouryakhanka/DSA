#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();

        vector<pair<int, int>> pro;

        for (int i = 0; i < n; i++)
        {
            pro.emplace_back(capital[i], profits[i]);
        }

        sort(pro.begin(), pro.end());
        int ptr = 0;
        priority_queue<int> q;

        for (int i = 0; i < k; i++)
        {
            while (ptr < n && pro[ptr].first <= w)
            {
                q.push(pro[ptr++].second);
            }

            if (q.empty())
                break;

            w += q.top();
            q.pop();
        }
        return w;
    }
};

int main()
{
    return 0;
}