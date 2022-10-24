#include <bits/stdc++.h>

using std::vector;

class Solution {
    void backtrack(int i, vector<vector<int>> &res, vector<int> &sub,
                   vector<int> &nums) {
        if (i == nums.size()) {
            res.emplace_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        backtrack(i + 1, res, sub, nums);
        sub.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;

        backtrack(i + 1, res, sub, nums);
    }

  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        vector<int> subset;

        backtrack(0, res, subset, nums);

        return res;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, 2, 2}, v2 = {0};

    auto res = s.subsetsWithDup(v1);

    return 0;
}