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
    TreeNode *searchBST(TreeNode *root, int val) {
        TreeNode *tmp = root;
        while (tmp != nullptr) {
            if (tmp->val == val)
                break;
            else if (tmp->val > val)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }

        return tmp;
    }
};

int main() {
    Solution s;

    TreeNode *t1 = new TreeNode(
        4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));

    auto res = s.searchBST(t1, 2);

    return 0;
}