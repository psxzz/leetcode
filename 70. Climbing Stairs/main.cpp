#include <bits/stdc++.h>

class Solution {
   public:
    int climbStairs(int n) {
        int curr = 1;
        int next = 1;

        for (int i = n - 2; i >= 0; --i) {
            int tmp = curr;
            curr += next;
            next = tmp;
        }
        return curr;
    }

    int recursive(std::vector<int>& dp, int n) {
        if (n <= 2) return n;

        if (dp[n] == -1) dp[n] =
                             recursive(dp, n - 1) + recursive(dp, n - 2);

        return dp[n];
    }
    int climbStairsDP(int n) {
        std::vector<int> dp(n + 1, -1);
        return recursive(dp, n);
    }
};

int main() {
    Solution s;

    std::cout << s.climbStairs(5) << std::endl;
    std::cout << s.climbStairsDP(5) << std::endl;

    return 0;
}