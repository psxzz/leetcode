#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size() + 3, 0);
        vector<int> dp2(nums.size() + 3, 0);

        for (int i = nums.size() - 2; i >= 0; --i) {
            dp1[i] = nums[i] + std::max(dp1[i + 2], dp1[i + 3]);
        }

        int max1 = std::max(dp1[0], dp1[1]);

        for (int i = nums.size() - 1; i >= 1; --i) {
            dp2[i - 1] = nums[i] + std::max(dp2[i + 2 - 1], dp2[i + 3 - 1]);
        }

        int max2 = std::max(dp2[0], dp2[1]);

        return std::max(max1, max2);
    }
};

int main() {
    Solution s;

    vector<int> v1 = {2, 3, 2};
    vector<int> v2 = {1, 2, 3, 1};
    vector<int> v3 = {1, 2, 3};
    vector<int> v4 = {1, 2, 1, 1};

    std::cout << s.rob(v1) << std::endl;
    std::cout << s.rob(v2) << std::endl;
    std::cout << s.rob(v3) << std::endl;
    std::cout << s.rob(v4) << std::endl;

    return 0;
}