#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 3, 0);

        for (int i = nums.size() - 1; i >= 0; --i) {
            dp[i] = nums[i] + std::max(dp[i + 2], dp[i + 3]);
        }

        return std::max(dp[0], dp[1]);
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {2, 7, 9, 3, 1};
    vector<int> v3 = {1, 3, 1};

    std::cout << s.rob(v1) << std::endl;
    std::cout << s.rob(v2) << std::endl;
    std::cout << s.rob(v3) << std::endl;

    return 0;
}