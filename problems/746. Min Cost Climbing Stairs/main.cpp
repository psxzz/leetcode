#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[n - 1] = cost[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            dp[i] = cost[i] + std::min(dp[i + 1], dp[i + 2]);
        }

        return std::min(dp[0], dp[1]);
    }
};

int main() {
    Solution s;
    vector<int> v1 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << s.minCostClimbingStairs(v1) << std::endl;

    return 0;
}