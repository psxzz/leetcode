#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<std::pair<int, int>> v;

        for (int i = 0; i < nums.size(); ++i) v.push_back({nums[i], i});

        std::sort(v.begin(), v.end());

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (target == v[l].first + v[r].first)
                return std::vector<int>({v[l].second, v[r].second});
            if (target > v[l].first + v[r].first)
                l++;
            if (target < v[l].first + v[r].first)
                r--;
        }

        return vector<int>();
    }
};

int main() {
    Solution s;

    vector<int> v1 = {2, 7, 11, 15};
    vector<int> v2 = {3, 2, 4};
    vector<int> v3 = {3, 3};

    vector<int> res1 = s.twoSum(v1, 9);
    vector<int> res2 = s.twoSum(v2, 6);
    vector<int> res3 = s.twoSum(v3, 6);

    std::cout << std::endl;
    return 0;
}