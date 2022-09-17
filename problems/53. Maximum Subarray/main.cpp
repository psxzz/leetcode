#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int prefix = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (prefix < 0) prefix = 0;
            prefix += nums[i];
            max = std::max(max, prefix);
        }

        return max;
    }

    int kadaneAlgo(std::vector<int>& nums) {
        int local_sum = 0, global_sum = INT_MIN;

        for (auto& num : nums) {
            local_sum = std::max(num, local_sum + num);

            global_sum = std::max(global_sum, local_sum);
        }

        return global_sum;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v2 = {1};
    vector<int> v3 = {5, 4, -1, 7, 8};

    std::cout << s.maxSubArray(v1) << std::endl;
    std::cout << s.maxSubArray(v2) << std::endl;
    std::cout << s.maxSubArray(v3) << std::endl;

    return 0;
}