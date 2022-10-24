#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		if (nums.size() < 3) return 0;
		int			res = 0;
		vector<int> dp(nums.size(), 0);

		for (int i = 2; i < nums.size(); ++i) {
			int left = nums[i] - nums[i - 1];
			int right = nums[i - 1] - nums[i - 2];

			if (left == right) {
				dp[i] = dp[i - 1] + 1;
				res += dp[i];
			}
		}

		return res;
	}
};

int main() {
	Solution s;

	vector<int> v1{1, 2, 3, 4}, v2{1};

	std::cout << s.numberOfArithmeticSlices(v1) << std::endl;
	std::cout << s.numberOfArithmeticSlices(v2) << std::endl;

	return 0;
}