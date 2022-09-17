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
    bool dfs(std::unordered_set<int> &s, TreeNode *root, int target) {
        if (!root) return false;

        int y = target - root->val;
        if (s.count(y))
            return true;
        else
            s.insert(root->val);

        return dfs(s, root->left, target) || dfs(s, root->right, target);
    }

   public:
    bool findTarget(TreeNode *root, int k) {
        std::unordered_set<int> s;
        return dfs(s, root, k);
    }
};

int main() {
    Solution s;

    TreeNode *t1 =
        new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)),
                     new TreeNode(6, nullptr, new TreeNode(7)));

    std::cout << std::boolalpha << s.findTarget(t1, 9) << std::endl;

    return 0;
}