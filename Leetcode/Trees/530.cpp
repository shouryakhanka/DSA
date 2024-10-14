#include <iostream>
using namespace std;

#include <climits>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int minVal = INT_MAX;
    int *prev = nullptr;

public:
    int getMinimumDifference(TreeNode *root)
    {
        if (root == nullptr)
            return minVal;

        getMinimumDifference(root->left);

        if (prev != nullptr)
        {
            minVal = min(minVal, root->val - *prev);
        }
        prev = &(root->val);

        getMinimumDifference(root->right);

        return minVal;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(48);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(49);

    Solution obj;
    cout << "The minimum difference is " << obj.getMinimumDifference(root) << endl;
    return 0;
}