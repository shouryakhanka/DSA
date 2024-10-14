#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

class ArrayToArray {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
long long sum = 0;
int x = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            sum += num[i] * x;
            x *= 10;
        }
        
       long long c = sum + k; 

       vector<int> ans;

while (c > 0)
{
        int rem = c % 10;

c /= 10;
        ans.push_back(rem);
}

    if (ans.empty()) ans.push_back(0); // handle case when the sum is 0

        reverse(ans.begin(), ans.end());

return ans;
}

};

int main()
{
    vector<int> num = {1,2,0,0};
    int k = 34;

    ArrayToArray array;

    vector<int> res = array.addToArrayForm(num, k);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
    return 0;
}