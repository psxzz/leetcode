#include <bits/stdc++.h>

using std::string;

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
   public:
    string tree2str(TreeNode *root) {
        string res = "";
        if (!root) return res;

        res += std::to_string(root->val);

        string left = "(" + tree2str(root->left) + ")";
        string right = "(" + tree2str(root->right) + ")";

        if ("()" == left && "()" != right)
            res += left;
        else if ("()" != left)
            res += left;

        if ("()" != right) res += right;

        return res;
    }
};

int main() {
    Solution s;

    TreeNode *t1 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr),
                                new TreeNode(3));

    TreeNode *t2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)),
                                new TreeNode(3));

    std::cout << s.tree2str(t1) << std::endl;
    std::cout << s.tree2str(t2) << std::endl;

    return 0;
}