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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *recursive(TreeNode *root) {
        if (!root) return nullptr;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        root->left = recursive(root->left);
        root->right = recursive(root->right);

        return root;
    }

    TreeNode *invertTree(TreeNode *root) { return recursive(root); }
};

int main() {
    Solution s;

    return 0;
}