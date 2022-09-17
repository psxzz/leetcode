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
    // left, right, root
    vector<int> postorderTraversal(TreeNode *root) {
        std::stack<TreeNode *> s;
        vector<int> res;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode *curr = s.top();
            if (curr->left) {
                s.push(curr->left);
                curr->left = 0;
                continue;
            }
            if (curr->right) {
                s.push(curr->right);
                curr->right = 0;
                continue;
            }

            res.push_back(curr->val);
            s.pop();
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

    TreeNode *t1 = new TreeNode(
        1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));

    TreeNode *t2 =
        new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    s.printVector(s.postorderTraversal(t1));
    s.printVector(s.postorderTraversal(t2));

    return 0;
}