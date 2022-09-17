#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0, max_sum = -1e5, min_sum = 1e5;
        int curr_max = -1e5, curr_min = 1e5;

        for (auto& num : nums) {
            curr_max = std::max(num, curr_max + num);
            max_sum = std::max(max_sum, curr_max);
            curr_min = std::min(num, curr_min + num);
            min_sum = std::min(min_sum, curr_min);
            total_sum += num;
        }

        if (max_sum < 0) return max_sum;

        return std::max(max_sum, (total_sum - min_sum));
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, -2, 3, -2};
    vector<int> v2 = {5, -3, 5};
    vector<int> v3 = {-3, -2, -3};

    std::cout << s.maxSubarraySumCircular(v1) << std::endl;
    std::cout << s.maxSubarraySumCircular(v2) << std::endl;
    std::cout << s.maxSubarraySumCircular(v3) << std::endl;

    return 0;
}