#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    vector<int> sumEvenAfterQueries(vector<int>&         nums,
                                    vector<vector<int>>& queries) {
        vector<int> res;
        int         sum = 0;
        std::for_each(nums.begin(), nums.end(), [&sum](auto const& num) {
            if (num % 2 == 0) sum += num;
        });

        for (auto& q : queries) {
            int value = q[0];
            int idx = q[1];
            int prev = nums[idx];
            nums[idx] += value;

            if (nums[idx] % 2 == 0) {
                if (prev % 2 == 0)
                    sum += value;
                else
                    sum += nums[idx];
            } else {
                if (prev % 2 == 0) {
                    sum -= prev;
                }
            }

            res.push_back(sum);
        }

        return res;
    }

    void printVector(vector<int>& v) {
        for (auto& n : v) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    vector<int>         nums = {1};
    vector<vector<int>> queries = {
        {4, 0},
    };

    auto res = s.sumEvenAfterQueries(nums, queries);

    s.printVector(res);

    return 0;
}