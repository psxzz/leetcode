#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
  public:
	int minDistance(string word1, string word2) {
		int					m = word1.length(), n = word2.length();
		vector<vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i == 0 | j == 0)
					dp[i][j] = i + j;
				else if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = 1 + std::min(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[m][n];
	}
};

int main() {
	Solution s;

	std::cout << s.minDistance("leetcode", "etco") << std::endl;
	std::cout << s.minDistance("sea", "eat") << std::endl;

	return 0;
}