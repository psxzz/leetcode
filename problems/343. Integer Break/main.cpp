#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 1);
		dp[2] = 2;

		for (int i = 2; i < n + 1; ++i) {
			dp[i] = (i == n) ? 0 : i;

			for (int j = 1; j < i; ++j)
				dp[i] = std::max(dp[j] * dp[i - j], dp[i]);
		}

		return dp[n];
	}
};

int main() {
	Solution s;

	std::cout << s.integerBreak(2) << std::endl;
	std::cout << s.integerBreak(10) << std::endl;

	return 0;
}