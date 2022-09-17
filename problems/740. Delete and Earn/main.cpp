#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        std::unordered_map<int, int> m;
        std::set<int> s;

        for (auto& num : nums) {
            s.insert(num);
            m[num]++;
        }

        nums.assign(s.begin(), s.end());
        std::sort(nums.begin(), nums.end());

        int earn1 = 0;
        int earn2 = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i] * m[nums[i]];
            if (i > 0 && nums[i] == nums[i - 1] + 1) {
                int tmp = earn2;
                earn2 = std::max(curr + earn1, earn2);
                earn1 = tmp;
            } else {
                int tmp = earn2;
                earn2 = curr + earn2;
                earn1 = tmp;
            }
        }

        return earn2;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {3, 4, 2};
    vector<int> v2 = {2, 2, 3, 3, 3, 4};
    vector<int> v3 = {8, 10, 4, 9, 1, 3, 5, 9, 4, 10};  // 36 || 27

    std::cout << s.deleteAndEarn(v1) << std::endl;
    std::cout << s.deleteAndEarn(v2) << std::endl;
    std::cout << s.deleteAndEarn(v3) << std::endl;

    return 0;
}