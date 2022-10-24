#include <bits/stdc++.h>

const int p = 1e9 + 7;

using std::vector;

class Solution {
  public:
	int numRollsToTarget(int n, int k, int target) {
		vector<vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
		dp[0][0] = 1;
		for (int dice = 1; dice <= n; ++dice) {
			for (int val = 0; val <= target; ++val) {
				for (int face = 1; face <= k; ++face) {
					if (val < face) continue;

					dp[dice][val] =
						(dp[dice][val] + dp[dice - 1][val - face]) % p;
				}
			}
		}

		return dp[n][target];
	}
};

int main() {
	Solution s;

	std::cout << s.numRollsToTarget(1, 6, 3) << std::endl;
	std::cout << s.numRollsToTarget(2, 6, 7) << std::endl;
	std::cout << s.numRollsToTarget(30, 30, 500) << std::endl;

	return 0;
}