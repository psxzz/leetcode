#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;

		std::function<void(int, vector<int>&, int)> backtrack =
			[&backtrack, &res, &candidates, &target](int i, vector<int>& curr,
													 int total) {
				if (total == target) {
					res.emplace_back(curr);
					return;
				}
				if (total > target) return;

				int prev = -1;
				for (int k = i; k < candidates.size(); ++k) {
					if (prev == candidates[k]) continue;

					curr.push_back(candidates[k]);
					backtrack(k + 1, curr, total + candidates[k]);
					curr.pop_back();
					prev = candidates[k];
				}
			};

		vector<int> curr;
		backtrack(0, curr, 0);

		return res;
	}
};

int main() {
	Solution s;

	vector<int> v1 = {10, 1, 2, 7, 6, 1, 5};

	auto res = s.combinationSum2(v1, 8);

	return 0;
}