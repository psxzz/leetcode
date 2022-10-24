#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int findNumberOfLIS(vector<int>& nums) {
		int							res = 0;
		int							lenLIS = 0;
		vector<std::pair<int, int>> dp(nums.size(), std::make_pair(1, 1));

		for (int i = nums.size() - 1; i >= 0; --i) {
			int maxLen = 1, maxCount = 1;
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] < nums[j]) {
					if (dp[j].first + 1 > maxLen) {
						maxLen = dp[j].first + 1;
						maxCount = dp[j].second;
					} else if (dp[j].first + 1 == maxLen) {
						maxCount += dp[j].second;
					}
				}
			}

			if (maxLen > lenLIS) {
				lenLIS = maxLen;
				res = maxCount;
			} else if (lenLIS == maxLen) {
				res += maxCount;
			}

			dp[i].first = maxLen;
			dp[i].second = maxCount;
		}

		return res;
	}
};

int main() {
	Solution s;

	vector<int> v1 = {1, 3, 5, 4, 7}, v2 = {2, 2, 2, 2, 2};

	std::cout << s.findNumberOfLIS(v1) << std::endl;
	std::cout << s.findNumberOfLIS(v2) << std::endl;

	return 0;
}