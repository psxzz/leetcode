#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    // Bottom up O(1) space
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n < 2) return 1;

        int curr = 1, prev = 1, prevprev = 0;

        for (int i = 2; i < n; ++i) {
            int tmp = curr, prevtmp = prev;
            curr += prev + prevprev;
            prev = tmp;
            prevprev = prevtmp;
        }

        return curr;
    }

    // DP Memoization
    int recursive(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        if (dp[n] == -1)
            dp[n] = recursive(n - 3, dp) +
                    recursive(n - 2, dp) +
                    recursive(n - 1, dp);

        return dp[n];
    }
    int tribonacci_dp(int n) {
        vector<int> dp(n + 1, -1);
        return recursive(n, dp);
    }
};

int main() {
    Solution s;

    std::cout << s.tribonacci(4) << std::endl;
    std::cout << s.tribonacci(25) << std::endl;
    std::cout << s.tribonacci_dp(4) << std::endl;
    std::cout << s.tribonacci_dp(25) << std::endl;

    return 0;
}