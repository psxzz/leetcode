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
    void getLeft(std::stack<int> &s, TreeNode *root) {
        if (root) {
            s.push(root->val);
            getLeft(s, root->left);
            getLeft(s, root->right);
        } else
            s.push(-101);
    }
    void getRight(std::stack<int> &s, TreeNode *root) {
        if (root) {
            s.push(root->val);
            getRight(s, root->right);
            getRight(s, root->left);
        } else
            s.push(-101);
    }

   public:
    bool isSymmetric(TreeNode *root) {
        std::stack<int> left, right;
        getRight(right, root->right);
        getLeft(left, root->left);

        return left == right;
    }
};

int main() {
    Solution s;

    TreeNode *t1 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)),
                                new TreeNode(2, nullptr, new TreeNode(3)));

    std::cout << std::boolalpha << s.isSymmetric(t1) << std::endl;

    return 0;
}