#include<iostream>
#include<map>
#include<vector>

using namespace std;

// bloomberg, amazon

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class FindDulplicateSubtrees {
public:
    map<string, int> mp;

string solve(TreeNode* &root, vector<TreeNode*> &ans) {

if (!root)
return "#";

string s = solve(root -> left, ans) + solve(root -> right, ans) + to_string(root -> val);
mp[s]++;

if (mp[s] == 2)
ans.push_back(root);

return s;
}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       vector<TreeNode*> ans;
solve(root, ans);
return ans; 
    }
};

int main()
{
    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(22);
    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(12);
        root -> right -> left = new TreeNode(1);
    root -> right -> right = new TreeNode(1);

FindDulplicateSubtrees find;

vector<TreeNode*> res = find.findDuplicateSubtrees(root);

for (TreeNode* node : res) {
    cout << node -> val << " ";
}
cout << endl;

 return 0;
}