#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
  public:
	int minDistance(string word1, string word2) {
		int					m = word1.length(), n = word2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		for (int j = 0; j < n + 1; ++j) dp[m][j] = n - j;
		for (int i = 0; i < m + 1; ++i) dp[i][n] = m - i;

		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (word1[i] == word2[j]) {
					dp[i][j] = dp[i + 1][j + 1];
				} else {
					dp[i][j] =
						1 + std::min(dp[i + 1][j + 1],
									 std::min(dp[i + 1][j], dp[i][j + 1]));
				}
			}
		}

		return dp[0][0];
	}
};

int main() {
	Solution s;

	std::cout << s.minDistance("horse", "ros") << std::endl;
	std::cout << s.minDistance("intention", "execution") << std::endl;

	return 0;
}