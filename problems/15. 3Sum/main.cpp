#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.emplace_back(
                        std::initializer_list<int>{nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r) l++;
                }
                if (sum > 0) r--;
                if (sum < 0) l++;
            }
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {-1, 0, 1, 2, -1, -4};

    auto res = s.threeSum(v1);

    return 0;
}