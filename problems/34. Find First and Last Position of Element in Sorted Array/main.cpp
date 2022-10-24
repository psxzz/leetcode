#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start_it = std::lower_bound(nums.begin(), nums.end(), target);
        if (start_it == nums.end() || *start_it != target)
            return std::vector<int>({-1, -1});

        auto end_it = std::upper_bound(start_it, nums.end(), target);

        int start_idx = std::distance(nums.begin(), start_it);
        int end_idx = std::distance(nums.begin(), end_it) - 1;

        return std::vector<int>({start_idx, end_idx});
    }

    void printVector(vector<int>& v) {
        for (auto& num : v) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {};

    auto res = s.searchRange(v1, 0);

    s.printVector(res);

    return 0;
}