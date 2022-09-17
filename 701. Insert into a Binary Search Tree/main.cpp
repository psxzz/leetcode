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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);

        TreeNode *tmp = root;
        while (true) {
            if (tmp->val > val) {
                if (!tmp->left) {
                    tmp->left = new TreeNode(val);
                    break;
                }
                tmp = tmp->left;
            } else {
                if (!tmp->right) {
                    tmp->right = new TreeNode(val);
                    break;
                }
                tmp = tmp->right;
            }
        }

        return root;
    }
};

int main() {
    Solution s;

    return 0;
}