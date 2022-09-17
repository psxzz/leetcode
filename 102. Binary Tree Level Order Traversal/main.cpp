#include <bits/stdc++.h>

using std::vector;

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
    void recursive(TreeNode *root, vector<vector<int>> &tree, int level) {
        if (root == NULL) return;
        if (tree.size() <= level) tree.push_back(std::vector<int>());

        tree[level].push_back(root->val);

        if (root->left != NULL) recursive(root->left, tree, level + 1);
        if (root->right != NULL) recursive(root->right, tree, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> tree;

        recursive(root, tree, 0);

        return tree;
    }
};

int main() {
    Solution s;

    return 0;
}