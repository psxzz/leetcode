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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        std::stack<TreeNode *> s;
        vector<int> res;
        if (root) s.push(root);

        while (!s.empty()) {
            TreeNode *curr = s.top();
            res.push_back(curr->val);
            s.pop();

            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
        }

        return res;
    }

    void printVector(vector<int> v) {
        for (auto &num : v) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    TreeNode *t1 =
        new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    auto res = s.preorderTraversal(t1);

    s.printVector(res);

    return 0;
}