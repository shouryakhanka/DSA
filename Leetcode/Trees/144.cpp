#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val)
{
    TreeNode *temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

vector<int> a;

vector<int> preorderTraversal(TreeNode *root)
{
    if (root)
    {
        a.push_back(root->val);

        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    return a;
}

int main()
{
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    vector<int> a = preorderTraversal(root);

    for (int b : a)
    {
        cout << b << endl;
    }
    return 0;
}