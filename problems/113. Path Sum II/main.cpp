#include <bits/stdc++.h>

using std::vector;

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
  private:
	void recursive(vector<vector<int>> &res, vector<int> nodes, TreeNode *root,
				   int targetSum) {
		if (!root || abs(targetSum - root->val) < 0) return;

		nodes.push_back(root->val);

		if ((!root->left && !root->right) && targetSum - root->val == 0) {
			res.push_back(nodes);
			return;
		}

		recursive(res, nodes, root->left, targetSum - root->val);
		recursive(res, nodes, root->right, targetSum - root->val);
	}

  public:
	vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
		vector<vector<int>> res;
		vector<int>			nodes;

		recursive(res, nodes, root, targetSum);
		return res;
	}

	void printPaths(vector<vector<int>> v) {
		std::cout << '[';
		for (auto &path : v) {
			std::cout << '[';
			for (auto &node : path) {
				std::cout << node << ' ';
			}
			std::cout << "], ";
		}
		std::cout << ']' << std::endl;
	}
};

int main() {
	Solution s;

	TreeNode *t1 = new TreeNode(1, new TreeNode(2), nullptr);

	auto res = s.pathSum(t1, 1);
	s.printPaths(res);

	return 0;
}