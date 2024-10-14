#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// time: O(n), space: O(1)
int maxProfit(vector<int> &prices)
{
    int left = 0, currentPrice = 0, maxProfit = 0;
    int right = 1;

    while (right < prices.size())
    {

        currentPrice = prices[right] - prices[left];
        if (prices[left] < prices[right])
        {
            maxProfit = max(maxProfit, currentPrice);
        }

        else
        {
            left = right;
        }
        right = right + 1;
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}