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
  public:
	TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
		TreeNode *res = 0;
		int		  val1 = 0, val2 = 0;
		TreeNode *lnext1 = 0, *rnext1 = 0;
		TreeNode *lnext2 = 0, *rnext2 = 0;

		if (!root1 && !root2) return nullptr;

		if (root1) {
			val1 = root1->val;
			lnext1 = root1->left;
			rnext1 = root1->right;
		}

		if (root2) {
			val2 = root2->val;
			lnext2 = root2->left;
			rnext2 = root2->right;
		}

		res = new TreeNode(val1 + val2);

		res->left = mergeTrees(lnext1, lnext2);
		res->right = mergeTrees(rnext1, rnext2);

		return res;
	}
};

int main() {
	Solution s;

	return 0;
}