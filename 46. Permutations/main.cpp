#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 1) {
            res.push_back(nums);
            return res;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[0];
            nums.erase(nums.begin());
            auto perms = permute(nums);

            for (auto perm : perms) {
                perm.push_back(n);
                res.push_back(perm);
            }
            nums.push_back(n);
        }
        return res;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, 2, 3};

    vector<vector<int>> res = s.permute(v1);

    return 0;
}