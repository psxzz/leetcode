#include <bits/stdc++.h>

using std::vector;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    void recursive(Node* root, vector<int>& pre) {
        if (root == NULL) return;

        pre.push_back(root->val);
        for (auto child : root->children) {
            recursive(child, pre);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> childs;
        recursive(root, childs);

        return childs;
    }
};

int main() {
    Solution s;

    return 0;
}