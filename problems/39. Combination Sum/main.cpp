#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;

		std::function<void(int, vector<int>&, int)> backtrack =
			[&backtrack, &res, &candidates, &target](int i, vector<int>& curr,
													 int total) {
				if (total == target) {
					res.emplace_back(curr);
					return;
				}

				if (i >= candidates.size() || total > target) return;

				curr.push_back(candidates[i]);
				backtrack(i, curr, total + candidates[i]);
				curr.pop_back();
				backtrack(i + 1, curr, total);
			};

		vector<int> curr;
		backtrack(0, curr, 0);

		return res;
	}
};

int main() {
	Solution s;

	vector<int> v1 = {2, 3, 6, 7};
	auto		res = s.combinationSum(v1, 7);

	return 0;
}