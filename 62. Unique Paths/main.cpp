#include <bits/stdc++.h>

using matrix_t = std::vector<std::vector<int>>;

class Solution {
   public:
    int uniquePaths(int m, int n) {
        matrix_t dp(m + 1, std::vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
    }

    void printMatrix(matrix_t& m) {
        for (auto row : m) {
            for (auto col : row) {
                std::cout << col << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    std::cout << s.uniquePaths(3, 7) << std::endl;

    return 0;
}