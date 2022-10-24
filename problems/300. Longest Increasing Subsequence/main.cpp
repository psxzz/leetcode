#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int lengthOfLIS(vector<int>& nums) {
		int			maxLen = 1;
		vector<int> dp(nums.size(), 1);

		for (int i = nums.size() - 2; i >= 0; --i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] < nums[j]) {
					dp[i] = std::max(dp[i], 1 + dp[j]);
					maxLen = std::max(maxLen, dp[i]);
				}
			}
		}

		return maxLen;
	}
};

int main() {
	Solution	s;
	vector<int> v1 = {10, 9, 2, 5, 3, 7, 101, 18};
	std::cout << s.lengthOfLIS(v1) << std::endl;

	return 0;
}