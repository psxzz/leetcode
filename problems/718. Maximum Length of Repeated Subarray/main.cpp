#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n = nums1.size(), m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                res = std::max(res, dp[i][j]);
            }
        }

        return res;
    }
};

int main() {
    Solution    s;
    vector<int> nums1{1, 2, 3, 2, 1}, nums2{3, 2, 1, 4, 7};

    std::cout << s.findLength(nums1, nums2) << std::endl;

    return 0;
}