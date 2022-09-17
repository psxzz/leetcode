#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool recursive(TreeNode *root, long lesser, long greater) {
        bool res = true;

        if (!(lesser < root->val && root->val < greater)) return false;

        if (root->left) {
            res &= recursive(root->left, lesser, root->val);
        }
        if (root->right) {
            res &= recursive(root->right, root->val, greater);
        }
        return res;
    }

    bool isValidBST(TreeNode *root) {
        return recursive(root, -LONG_MAX, LONG_MAX);
    }
};

int main() {
    Solution s;

    TreeNode *t1 = new TreeNode(5, new TreeNode(4), new TreeNode(6));

    std::cout << std::boolalpha << s.isValidBST(t1) << std::endl;

    return 0;
}