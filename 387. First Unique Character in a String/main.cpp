#include <bits/stdc++.h>

using std::string;

class Solution {
   public:
    int firstUniqChar(string s) {
        std::unordered_map<char, int> m;
        size_t firstUnique = INT_MAX;
        for (auto& ch : s) {
            m[ch]++;
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == 1) {
                firstUnique = std::min(firstUnique, s.find_first_of(it->first));
            }
        }

        return (firstUnique == INT_MAX) ? -1 : firstUnique;
    }
};

int main() {
    Solution s;

    string s1 = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";

    std::cout << s.firstUniqChar(s1) << std::endl;
    std::cout << s.firstUniqChar(s2) << std::endl;
    std::cout << s.firstUniqChar(s3) << std::endl;

    return 0;
}