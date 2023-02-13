//https://practice.geeksforgeeks.org/contest/mega-job-a-thon-hiring-challenge-for-freshers/problems/

#include <iostream>
#include<vector>
#include<map>
using namespace std;

class FindGoodPairs {
  public:
    long long findGoodPairs(vector<int> a, int n, int k) {
        map<int, int> ma;
        long long ans = 0;

        for (int i = k; i < n; i++)
        {
            ma[a[i - k]]++;
            ans += ma[a[i]];
        }
        return ans;
    }
};

int main()
{
    FindGoodPairs find_good_pairs;
    vector<int> a = {1, 2, 2, 1, 2};

    int n = 5, k = 2;

    cout << find_good_pairs.findGoodPairs(a, n, k) << endl; 

    return 0;
}

