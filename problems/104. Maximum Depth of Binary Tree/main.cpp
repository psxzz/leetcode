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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;

        return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};

int main() {
    Solution s;

    TreeNode *t1 =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    TreeNode *t2 = new TreeNode(1, nullptr, new TreeNode(2));

    std::cout << s.maxDepth(t1) << std::endl;
    std::cout << s.maxDepth(t2) << std::endl;

    return 0;
}