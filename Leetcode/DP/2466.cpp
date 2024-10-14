#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
const int MOD = 1e9 + 7;

class Solution
{

public:
    vector<int> dp;

    int countGoodStrings(int low, int high, int zero, int one)
    {
        const int mod = 1000000007;
        vector<long long> dp(100001, 0);
        dp[0] = 1;

        for (int i = 1; i <= 100000; i++)
        {
            if (i - zero >= 0)
            {
                dp[i] += dp[i - zero];
            }
            if (i - one >= 0)
            {
                dp[i] += dp[i - one];
            }
            dp[i] %= mod;
        }

        long long ans = 0;
        for (int i = low; i <= high; i++)
        {
            ans += dp[i];
        }

        return static_cast<int>(ans % mod);
    }

    int WaysToMakeLengthX(int len, const int zro, const int one)
    {
        if (len == 0)
            return 1;
        if (len < 0)
            return 0;

        int &result = dp[len];
        if (result != -1)
            return result;

        result = (WaysToMakeLengthX(len - zro, zro, one) + WaysToMakeLengthX(len - one, zro, one)) % MOD;
        return result;
    }

    int countGoodStrings1(int low, int high, int zero, int one)
    {
        dp.clear();
        dp.resize(high + 1, -1);

        ll result = 0;
        for (int len = low; len <= high; len++)
            result = (result + WaysToMakeLengthX(len, zero, one)) % MOD;
        return result;
    }
};

int main()
{
    Solution s;
    int low = 3, high = 3, zero = 1, one = 1;
    int ans = s.countGoodStrings1(low, high, zero, one);
    cout << ans << endl;
    return 0;
}
