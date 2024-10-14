#include <iostream>
#include <queue>
#include <climits>
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

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int maxSum = INT_MIN;
        int maxLevel = 1;

        queue<TreeNode *> q;
        q.push(root);

        for (int level = 1; !q.empty(); level++)
        {
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }

            if (sum > maxSum)
            {
                maxSum = sum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }

    // This code recursively adds up the values at each level of the tree.
    int maxLevelSum4(TreeNode *root)
    {
        // Create a vector to store the sums at each level.
        std::vector<int> levelSums;
        // Call the dfs function on the root node.
        dfs(root, levelSums, 0);
        // Find the index of the maximum element in the levelSums vector.
        int maxLevel = std::distance(levelSums.begin(), std::max_element(levelSums.begin(), levelSums.end()));
        // Return the index of the maximum element plus 1.
        return maxLevel + 1;
    }

    // This function recursively adds up the values at each level of the tree.
    void dfs(TreeNode *node, std::vector<int> &levelSums, int level)
    {
        // If the node is nullptr, then return.
        if (node == nullptr)
        {
            return;
        }
        // If the levelSums vector has only level elements, push_back the node's value.
        if (levelSums.size() == level)
        {
            levelSums.push_back(node->val);
        }
        // Otherwise, add the node's value to the sum of the current level.
        else
        {
            levelSums[level] += node->val;
        }
        // Recursively call dfs on the left and right subtrees.
        dfs(node->left, levelSums, level + 1);
        dfs(node->right, levelSums, level + 1);
    }

    int maxLevelSum4(TreeNode *root)
    {
        std::vector<int> levelSums;
        dfs(root, levelSums, 0);
        int maxLevel = std::distance(levelSums.begin(), std::max_element(levelSums.begin(), levelSums.end()));
        return maxLevel + 1;
    }

    void dfs(TreeNode *node, std::vector<int> &levelSums, int level)
    {
        // If the node is nullptr, then return.
        if (node == nullptr)
        {
            return;
        }
        // If the levelSums vector has only level elements, push_back the node's value.
        if (levelSums.size() == level)
        {
            levelSums.push_back(node->val);
        }
        // Otherwise, add the node's value to the sum of the current level.
        else
        {
            levelSums[level] += node->val;
        }
        // Recursively call dfs on the left and right subtrees.
        dfs(node->left, levelSums, level + 1);
        dfs(node->right, levelSums, level + 1);
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    /* Constructed Binary tree is:
                1
            / \
            2	 3
        / \	 \
        4 5	 8
                    / \
                 6	 7 */

    cout << "Maximum level sum is " << sol.maxLevelSum2(root) << endl;

    // Clean up allocated memory
    // delete root->right->right->right;
    // delete root->right->right->left;
    // delete root->right->right;
    // delete root->left->right;
    // delete root->left->left;
    // delete root->right;
    // delete root->left;
    // delete root;

    return 0;
}
