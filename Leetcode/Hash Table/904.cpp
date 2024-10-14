#include <iostream>
#include <vector>
#include <set>

using namespace std;

// brute force approach, TLE error
// time: O(n^3) because of three nested looops
// space: O(n) because set can have the max. no. of elements = fruits.size()
int totalFruit(vector<int> &fruits)
{
    // maximum no. of fruits we can pick
    int maxPicked = 0;

    int left = 0;
    int right = 0;

    for (int left = 0; left < fruits.size(); left++)
    {
        for (int right = 0; right < fruits.size(); right++)
        {
            set<int> basket;

            for (int currentIndex = left; currentIndex <= right; currentIndex++)
            {
                basket.insert(fruits[currentIndex]);
            }

            if (basket.size() <= 2)
            {
                maxPicked = max(maxPicked, right - left + 1);
            }
        }
    }

    return maxPicked;
}

int totalFruit2(vector<int> &fruits)
{
    // Maximum number of fruits we can pick
    int maxPicked = 0;

    // Iterate over the left index left of subarrays.
    for (int left = 0; left < fruits.size(); ++left)
    {
        // Empty set to count the type of fruits.
        set<int> basket;
        int right = left;

        // Iterate over the right index right of subarrays.
        while (right < fruits.size())
        {
            // Early stop. If adding this fruit makes 3 types of fruit,
            // we should stop the inner loop.
            if (basket.find(fruits[right]) == basket.end() && basket.size() == 2)
                break;

            // Otherwise, update the number of this fruit.
            basket.insert(fruits[right]);
            right++;
        }

        // Update maxPicked.
        maxPicked = max(maxPicked, right - left);
    }

    // Return maxPicked as the maximum length of valid subarray.
    // (maximum number of fruits we can pick).
    return maxPicked;
}

int main()
{
    vector<int> fruits = {1, 2, 1};
    cout << totalFruit2(fruits) << endl;
    return 0;
}