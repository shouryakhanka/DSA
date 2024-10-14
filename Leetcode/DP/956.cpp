#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int> rods, int r1, int r2, int index)
{
    if (index == rods.size())
    {
        if (r1 == r2)
        {
            return r1;
        }
        return 0;
    }

    int op1 = helper(rods, r1 + rods[index], r2, index + 1);
    int op2 = helper(rods, r1, r2 + rods[index], index + 1);
    int op3 = helper(rods, r1, r2, index + 1);

    return max(op1, max(op2, op3));
}

int tallestBillboard(vector<int> &rods)
{
    return helper(rods, 0, 0, 0);
}

int main()
{
    vector<int> rods = {5, 5, 10};
    cout << tallestBillboard(rods);
    return 0;
}