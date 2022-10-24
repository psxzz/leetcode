#include <bits/stdc++.h>

using std::vector;

class Solution {
	int recursive(vector<int>& dp, vector<int>& nums, int i) {
		if (dp[i] == -1) {
			if (i + nums[i] >= nums.size()) {
				dp[i] = 1;
				return dp[i];
			}

			int min = 10001;
			for (int k = nums[i]; k >= 1; --k) {
				min = std::min(min, recursive(dp, nums, i + k));
			}

			dp[i] = min + 1;
		}

		return dp[i];
	}

  public:
	int jump(vector<int>& nums) {
		vector<int> dp(nums.size(), -1);
		dp[nums.size() - 1] = 0;

		return recursive(dp, nums, 0);
	}
};

int main() {
	Solution s;

	vector<int> v1 = {2, 3, 1, 1, 4};

	vector<int> v2 = {2, 3, 0, 1, 4};

	std::cout << s.jump(v1) << std::endl;
	std::cout << s.jump(v2) << std::endl;

	return 0;
}