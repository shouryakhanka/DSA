//https://practice.geeksforgeeks.org/contest/mega-job-a-thon-hiring-challenge-for-freshers/problems/#     

#include <iostream>
#include<vector>
using namespace std;


class Toggle {
  public:
    int toggle(int n, vector<int> &arr) {
        int i = 0;
        int ma = 0;
        int lone = 0;

        while (i < n)
        {
            if (arr[i] == 1) {
            lone++;
            i++;
        }

        else {
            int zero = 0;
            int j = i;
            while (j < n && arr[j] == 0) {
                zero++;
                j++;
            }

            int rone = 0;
            i = j;
            while (j < n && arr[j] == 1)
            {
                rone++;
                j++;
            }
            
            ma = max(ma, zero + rone + lone);
            lone = 0;
        }
        }
        return max(ma, lone);
    }
};

int main()
{
    Toggle tog;
    vector<int>arr = {1, 0, 1, 0, 1, 0};
int n = 6;
    cout << tog.toggle(n, arr) << endl;
    return 0;
}