#include <bits/stdc++.h>

using std::vector;

/*
// Definition for a Node.
*/
class Node {
   public:
    int           val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    // DFS approach
    void dfs(vector<vector<int>>& v, Node* root, int level) {
        if (!root) return;
        if (v.size() <= level) v.push_back(vector<int>());
        v[level].push_back(root->val);
        for (auto child : root->children) {
            dfs(v, child, level + 1);
        }
    }

    // BFS approach
    void bfs(vector<vector<int>>& res, Node* root) {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();

            vector<int> level;
            while (k--) {
                Node* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);

                for (auto child : tmp->children) {
                    q.push(child);
                }
            }
            res.push_back(level);
        }
    }

   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root) dfs(res, root, 0);
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}