#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class MaxDepthBinary
{
public:
    int maxDepth(TreeNode *root)
    {
        // base case
        if (root == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // the depth is equal to 1 + max depth of its subtrees
        return 1 + max(leftDepth, rightDepth);
    }
};

int main()
{
    MaxDepthBinary max;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);

    cout << "Max depth of the tree:" << max.maxDepth(root) << endl;

    return 0;
}