#include <iostream>
using namespace std;

  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class InvertBinaryTree {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* right = invertTree(root -> right);
        TreeNode* left = invertTree(root -> left);
        root -> left = right;
        root -> right = left;
        return root;
    }
};

int main()
{
    InvertBinaryTree invert;

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

TreeNode* invertedTree = invert.invertTree(root);

    return 0;
}