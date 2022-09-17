#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    bool recursive(TreeNode *root, int target, int curr) {
        if (!root) return false;
        curr += root->val;
        if (!root->left && !root->right) return curr == target;

        return recursive(root->left, target, curr) ||
               recursive(root->right, target, curr);
    }

   public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        return recursive(root, targetSum, 0);
    }
};

int main() {
    Solution s;

    TreeNode *t1 = new TreeNode(
        5,
        new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)),
                     nullptr),
        new TreeNode(8, new TreeNode(13),
                     new TreeNode(4, nullptr, new TreeNode(1))));

    std::cout << std::boolalpha << s.hasPathSum(t1, 22) << std::endl;

    return 0;
}