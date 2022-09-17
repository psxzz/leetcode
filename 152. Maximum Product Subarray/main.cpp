#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0], min = nums[0];
        int maxProduct = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) std::swap(max, min);

            max = std::max(nums[i], max * nums[i]);
            min = std::min(nums[i], min * nums[i]);
            maxProduct = std::max(maxProduct, max);
        }

        return maxProduct;
    }
};

int main() {
    Solution s;
    vector<int> v1 = {2, 3, -2, 4};
    vector<int> v2 = {-2, 0, -1};
    vector<int> v3 = {-2, 3, -4};

    std::cout << s.maxProduct(v1) << std::endl;
    std::cout << s.maxProduct(v2) << std::endl;
    std::cout << s.maxProduct(v3) << std::endl;

    return 0;
}