// https://leetcode.com/problems/same-tree/description/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val)
{
    struct TreeNode *temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// recursive approach with O(n) time and O(n) space

// bool isSameTree(TreeNode *p, TreeNode *q)
// {
//     if (p == NULL && q == NULL)
//         return true;
//     else if (p == NULL && q != NULL)
//         return false;
//     else if (p != NULL && q == NULL)
//         return false;

//     bool left = isSameTree(p->left, q->left);
//     bool right = isSameTree(p->right, q->right);

//     bool curr = p->val == q->val;

//     if (left && right && curr)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// iterative approach with O(n) time and O(1) space

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    stack<TreeNode *> sp, sq;

    sp.push(p);
    sq.push(q);

    while (!sp.empty() && !sq.empty())
    {
        auto tp = sp.top();
        auto tq = sq.top();

        sp.pop();
        sq.pop();

        if (tp->val != tq->val)
        {
            return false;
        }

        if (tp->right || tq->right)
        {
            if (tp->right && tq->right)
            {
                sp.push(tp->right);
                sq.push(tq->right);
            }
            else
            {
                return false;
            }
        }

        if (tp->left || tq->left)
        {
            if (tp->left && tq->left)
            {
                sp.push(tp->left);
                sq.push(tq->left);
            }
            else
            {
                return false;
            }
        }
    }
    return sp.empty() && sq.empty();
}

int main()
{
    struct TreeNode *p = newNode(1);
    p->left = newNode(2);
    p->right = newNode(3);

    struct TreeNode *q = newNode(1);
    q->left = newNode(2);
    q->right = newNode(3);

    cout << isSameTree(p, q) << endl;

    return 0;
}