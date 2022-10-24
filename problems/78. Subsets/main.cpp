#include <bits/stdc++.h>

using std::vector;

class Solution {
    void dfs(int i, vector<int> &nums, vector<vector<int>> &res,
             vector<int> &sub) {
        if (i >= nums.size()) {
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        dfs(i + 1, nums, res, sub);

        sub.pop_back();
        dfs(i + 1, nums, res, sub);
    }

    vector<vector<int>> my_solution(vector<int> &nums) {
        vector<vector<int>> res;
        res.emplace_back(std::initializer_list<int>{});

        for (auto &num : nums) {
            int sz = res.size();
            res.emplace_back(std::initializer_list<int>{num});

            for (int i = 1; i < sz; ++i) {
                res.emplace_back(res[i]);
                res.back().push_back(num);
            }
        }

        return res;
    }

    vector<vector<int>> dfs_solution(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int>         subset;
        dfs(0, nums, res, subset);
        return res;
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        return dfs_solution(nums);
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, 2, 3};
    auto        res = s.subsets(v1);

    return 0;
}