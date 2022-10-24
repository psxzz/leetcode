#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int		  val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
		: val(x), left(left), right(right) {}
};

class Solution {
	bool isEqual(TreeNode *root, TreeNode *sub) {
		if (root && sub)
			return (root->val == sub->val) && isEqual(root->left, sub->left) &&
				   isEqual(root->right, sub->right);
		else if (!root && !sub)
			return true;

		return false;
	}

  public:
	bool isSubtree(TreeNode *root, TreeNode *subRoot) {
		if (root && subRoot)
			return isEqual(root, subRoot) || isSubtree(root->left, subRoot) ||
				   isSubtree(root->right, subRoot);

		return false;
	}
};

int main() {
	Solution s;

	return 0;
}