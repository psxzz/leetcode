#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

class Solution {
  public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>>		res;
		vector<int>				perm;
		unordered_map<int, int> m;

		for (auto& num : nums) {
			if (!m[num])
				m[num] = 1;
			else
				m[num]++;
		}

		std::function<void()> backtrack = [&backtrack, &res, &perm, &nums,
										   &m]() {
			if (perm.size() == nums.size()) {
				res.emplace_back(perm);
				return;
			}

			for (auto& freq : m) {
				if (freq.second > 0) {
					perm.push_back(freq.first);
					freq.second--;
					backtrack();
					freq.second++;
					perm.pop_back();
				}
			}
		};

		backtrack();
		return res;
	}
};

int main() {
	Solution s;

	vector<int> v1 = {1, 1, 2};

	auto res = s.permuteUnique(v1);

	return 0;
}