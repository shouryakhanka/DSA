//https://practice.geeksforgeeks.org/contest/mega-job-a-thon-hiring-challenge-for-freshers/problems/#

#include <iostream>
#include<vector>

using namespace std;

class MaximumPointsCovered {
  public:
    int maximumpoints(vector<vector<int> > arr, int n, int x, int y) {
        long int n = 10e3 + 3;

for(auto p : arr) {
a[p[0]p[1]]++;
}

for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i -1][j - 1];
    }
}

int ans = 0;

for(int i = x + 1; i < n; i++) {
    for(int j = y + 1; j < n; j++) {
        int count = a[]
    }
}
        int a[n][n];
        memset(a, 0, sizeof(a));
    }
};

int main()
{
    MaximumPointsCovered max;
    vector<vector<int>> arr = {(1,1), (2,3), (3,4), (2,4), (5,5)};
int x = 2, y = 2;
int n = 5;
    
    return 0;
}