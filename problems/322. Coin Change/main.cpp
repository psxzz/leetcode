#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;

		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;

		for (int i = 1; i < dp.size(); ++i) {
			for (auto& c : coins) {
				if (i - c >= 0) {
					dp[i] = std::min(dp[i], 1 + dp[i - c]);
				}
			}
		}

		return (dp[amount] == amount + 1) ? -1 : dp[amount];
	}
};

int main() {
	Solution	s;
	vector<int> v1 = {1, 2, 5}, v2 = {2}, v3 = {1};

	std::cout << s.coinChange(v1, 11) << std::endl;
	std::cout << s.coinChange(v2, 3) << std::endl;
	std::cout << s.coinChange(v3, 0) << std::endl;

	return 0;
}