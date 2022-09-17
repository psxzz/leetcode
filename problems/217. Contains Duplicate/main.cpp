#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> m;

        for (auto num : nums) {
            if (m.find(num) == m.end()) {
                m[num] = 1;
            } else
                m[num]++;
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > 1) return true;
        }

        return false;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {1, 2, 3, 4};
    vector<int> v3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    std::cout << std::boolalpha << s.containsDuplicate(v1) << std::endl;
    std::cout << std::boolalpha << s.containsDuplicate(v2) << std::endl;
    std::cout << std::boolalpha << s.containsDuplicate(v3) << std::endl;

    return 0;
}