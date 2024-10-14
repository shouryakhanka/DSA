//https://leetcode.com/problems/maximum-ice-cream-bars/

// O(nlogn) time, O(logn) space

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MaxIceBar {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        int n = costs.size();
        int icecream = 0;

        while (icecream < n&& coins >= costs[icecream])
        {
coins -= costs[icecream];
            icecream++;
        }
        return icecream;
        }
    };


int main()
{
    MaxIceBar max;
    vector<int> costs = {1,3,2,4,1};
    int coins = 7;
cout << max.maxIceCream(costs, coins) << endl;
    
    return 0;
}