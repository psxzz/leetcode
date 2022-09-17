#include <bits/stdc++.h>

using std::vector;

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
    void dfs(TreeNode *root, vector<vector<int>> &v, int level) {
        if (!root) return;
        if (v.size() == level) v.push_back(vector<int>());
        v[level].push_back(root->val);

        dfs(root->left, v, level + 1);
        dfs(root->right, v, level + 1);
    }

   public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double>      res;
        vector<vector<int>> levels;
        dfs(root, levels, 0);

        for (auto &level : levels) {
            double sum = 0;
            for (auto num : level) {
                sum += static_cast<double>(num);
            }
            res.push_back(sum / level.size());
        }

        return res;
    }

    template <typename T>
    void printVector(vector<T> &v) {
        for (auto &x : v) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    TreeNode *t1 =
        new TreeNode(INT_MAX, new TreeNode(INT_MAX), new TreeNode(INT_MAX));

    auto res = s.averageOfLevels(t1);

    s.printVector(res);

    return 0;
}