#include <iostream>
#include <vector>
#include <algorithm>

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

class MinDistBST
{
public:
    vector<int> inorderNodes;

    void inorderTraversals(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorderTraversals(root->left);
        inorderNodes.push_back(root->val);
        inorderTraversals(root->right);
    }

    int minDiffInBST(TreeNode *root)
    {
        int minDist = INT8_MAX;
        inorderTraversals(root);

        for (int i = 1; i < inorderNodes.size(); i++)
        {
            minDist = min(minDist, inorderNodes[i] - inorderNodes[i - 1]);
        }
        return minDist;
    }
};

int main()
{
    return 0;
}